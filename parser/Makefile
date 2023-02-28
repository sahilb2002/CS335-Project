compile:
	bison -d -t parse.y
	flex ../lexer/lex.l
	g++ parse.tab.c lex.yy.c AST.cpp -o a
	./a
	dot -Tpdf AST.dot -o AST.pdf
