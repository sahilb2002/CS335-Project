# read the parse.y file and generate the actions for each rule
import os
import re
from sys import argv


# parameters:
indent = 4
Replace_code = True
only_format_code = True
infile = open(argv[1], "r")
outfile = open("parse_annotated.y", "w")

terminals = []

def beatify_code(code):
    extra_indent = 0
    for i,line in enumerate(code):
        code[i] = " "*extra_indent + line
        if line.startswith("}"):
            extra_indent -= indent
        
        if line.endswith("{"):
            extra_indent += indent
    return code

def get_lexeme(terminal,pos=1):
    if terminal[:3] == "KEY":
        return terminal[4:].lower()
    elif terminal in ["STRING", "INT", "LONG", "FLOAT", "DOUBLE", "CHAR", "ASSIGN_OP", "ID"]:
        return f"*${pos}"
    else:
        return terminal
    
def generate_action(lhs, rhs):
    if only_format_code:
        return []
    actions = []
    if len(rhs) == 1:
        if rhs[0] in terminals:
            
            actions.append(f'$$ = makeleaf("{get_lexeme(rhs[0])}");')
        elif rhs[0] == "%empty":
            actions.append("$$ = NULL;")
        else:
            actions.append("$$ = $1;")
    else:
        actions.append("vector<data> v;")
        i = 1
        for tok in rhs:
            if tok in terminals:
                actions.append(f'insertAttr(v,makeleaf("{get_lexeme(tok,i)}"));')
            elif tok[0] == "'":
                actions.append(f'insertAttr(v, makeleaf("{tok[1]}"));')
            else:
                actions.append(f'insertAttr(v, ${i});')
            i+=1
        actions.append(f'$$ = makenode("{lhs}");')
    return actions

maxlen = 0
lineno = 0
count_brace = 0

code_region = False
rules_stared = False

last_nonterminal = ""

code = []
non_terminals = []
all_rules_and_actions = []

lines = infile.readlines()

if only_format_code:
    Replace_code = False

for line in lines:
    lineno+=1
    if re.match(r"[ \t]*\n", line):
        outfile.write("\n")
        continue
    if line.startswith("%%"):
        if not rules_stared:
            rules_stared = True
        else:
            break
        outfile.write(line)
        continue
    
    if not rules_stared:
        if line.startswith("%token"):
            tokens = line.split(' ')
            terminals.append(tokens[1].strip())
        outfile.write(line)

    if rules_stared:
        # if line contains { then we are in the code region
        if not code_region:
            if re.match(r"[ ]*\|[ ]*\n", line):
                continue
            if re.match(r"[ ]*;[ ]*\n", line):
                        continue
            linenew = line
            if line.find(':') !=-1:
                i = line.find(':')
                linenew = linenew[:i] + linenew[i+1:]
                last_nonterminal = linenew.split(' ')[0]
                non_terminals.append(last_nonterminal)
                linenew = linenew.replace(last_nonterminal,'')
            i = linenew.find('{')
            if i!=-1:
                linenew = linenew[:i]
            i = linenew.find('|')
            if i!=-1:
                linenew = linenew[:i] + linenew[i+1:]
            if (not re.match(r"[ \t]*\n", linenew)) and len(linenew) != 0:
                tokens = [t for t in linenew.split(' ') if len(t)!=0]
                rule = [last_nonterminal] + tokens
                all_rules_and_actions.append([rule, generate_action(last_nonterminal, tokens),[]])
        flag = False
        if line.find('{') != -1 :
            if not code_region:
                code_region = True
                i = line.find('{')
                if not re.match(r"[ ]*", line[i+1:]):
                    code.append(line[i+1:])
            else:
                code.append(line.strip())
            count_brace+=1
            flag = True
        if line.find('}') != -1:
            count_brace -= 1
            if count_brace == 0:
                code_region = False
                i = line.find('}')
                subline = line[:i]
                if (not re.match(r"[ ]*", subline)) and len(subline)!=0:
                    code.append(subline)
                all_rules_and_actions[-1][2] = code
                code = []
        if code_region and not flag:
            code.append(line.strip())


maxlen_term = max([len(rule[0]) for rule, actions,code in all_rules_and_actions ]) + 1
maxlen_term = (maxlen_term//indent + 2)*indent

maxlen = max([len(" ".join(rule[1:])) + maxlen_term + 1 for rule, actions, code in all_rules_and_actions])
maxlen = (maxlen//indent + 2)*indent


last_nonterminal = ""
for rule, actions, code in all_rules_and_actions:
    leng = 0
    if rule[0] != last_nonterminal:
        if last_nonterminal != "":
            outfile.write(";\n")
        outfile.write(f"{rule[0]}:")
        outfile.write(" "*(maxlen_term - len(rule[0])-1))
        last_nonterminal = rule[0]
    else:
        outfile.write("|")
        outfile.write(" "*(maxlen_term-1))
    outfile.write(" ".join(rule[1:]))
    leng = len(" ".join(rule[1:])) + maxlen_term
    outfile.write(" "*(maxlen-leng-indent))
    outfile.write("{\n")
    if not Replace_code:
        actions = beatify_code(code) + actions
    outfile.write("\n".join([" "*maxlen + action for action in actions]))
    outfile.write("\n")
    outfile.write(" "*(maxlen-indent))
    outfile.write("}\n\n")

outfile.write(";\n\n\n")
for line in lines[lineno-1:]:
    outfile.write(line)
