CC = gcc
LEX = C:\flex\win_flex.exe
YACC = C:\flex\win_bison.exe
CFLAGS = -Wall

all: sentinel

sentinel: lex.yy.c sentinel.tab.c main.c symbol_table.c quads.c
	$(CC) $(CFLAGS) lex.yy.c sentinel.tab.c main.c symbol_table.c quads.c -o sentinel

lex.yy.c: sentinel.l sentinel.tab.h
	$(LEX) sentinel.l

sentinel.tab.c sentinel.tab.h: sentinel.y
	$(YACC) -d sentinel.y

clean:
	rm -f sentinel lex.yy.c sentinel.tab.c sentinel.tab.h
