INC=include
default: main

main: parse.tab.o AST.o lex.yy.o symbol_table.o typecheck.o TAC.o codegen.o
	g++ -I $(INC) src/parse.tab.o src/AST.o src/lex.yy.o src/symbol_table.o src/typecheck.o src/TAC.o src/codegen.o -o main

lex.yy.o: lex.yy.c
	g++ -I $(INC) -c src/lex.yy.c -o src/lex.yy.o

lex.yy.c: src/lex.l include/AST.h parse.tab.c
	flex --outfile=src/lex.yy.c src/lex.l

parse.tab.o: parse.tab.c
	g++ -I $(INC) -c src/parse.tab.c -o src/parse.tab.o

parse.tab.c: src/parse.y include/TAC.h include/typecheck.h include/symbol_table.h include/AST.h
	bison -t src/parse.y --output=src/parse.tab.c --defines=include/parse.tab.h


AST.o: src/AST.cpp include/AST.h
	g++ -I $(INC) -c src/AST.cpp -o src/AST.o

symbol_table.o: src/symbol_table.cpp include/symbol_table.h
	g++ -I $(INC) -c src/symbol_table.cpp -o src/symbol_table.o

typecheck.o: src/typecheck.cpp include/typecheck.h
	g++ -I $(INC) -c src/typecheck.cpp -o src/typecheck.o

TAC.o: src/TAC.cpp include/TAC.h
	g++ -I $(INC) -c src/TAC.cpp -o src/TAC.o

codegen.o: src/codegen.cpp include/codegen.h
	g++ -I $(INC) -c src/codegen.cpp -o src/codegen.o

# main:
# 	bison -t src/parse.y --output=src/parse.tab.c --defines=include/parse.tab.h
# 	flex --outfile=src/lex.yy.c src/lex.l
# 	g++ -I $(INC) src/parse.tab.c src/AST.cpp src/lex.yy.c src/symbol_table.cpp src/typecheck.cpp src/TAC.cpp -o main
clean:
	rm -f main src/parse.tab.c src/parse.tab.h src/lex.yy.c include/parse.tab.h tac.txt
	rm -rf symbol_tables
	rm -f src/*.o
	rm -rf x86_code.*