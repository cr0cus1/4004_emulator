lexer: lexer.flex assembler.c
	flex lexer.flex && gcc lex.yy.c assembler.c -lfl -o lexer
