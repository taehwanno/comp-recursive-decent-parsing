#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void error(char *msg) {
	printf("Error: %s\n", msg);
	exit(1);
}

int LA;

int yylex() {
	return getchar();
}

void match(int t) {
	if (LA == t)
		LA = yylex();
	else
		error("lexical error");
}

bool eof() {
	return LA == EOF;
}

void A();
void B();
void C();
void L();
void S();

// A: eof | LA
void A() {
	if (eof()) {
		exit(0);
		puts("A -> eof");
	} else {
		L(); A();
		puts("A -> L A");
	}
}

// L : S '\n'
void L() {
	S(); match('\n');
	puts("L -> S");
}

// S: (S)S |
void S() {
	if (LA == '(') {
		match('('); S(); match(')'); S();
		puts("S -> (S)S");
	} else {
		puts("S -> ");
	}
}

int main() {
	LA = yylex();
  A();
	return 0;
}
