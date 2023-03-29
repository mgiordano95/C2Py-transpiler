transpiler: parser.y lexer.l ast.h symboltable.h c2py.h
	gcc parser.tab.c lex.yy.c -lfl -lm

parser.tab.c: parser.y
	bison -d parser.yy

lex.yy.c: lexer.l
	flex lexer.l