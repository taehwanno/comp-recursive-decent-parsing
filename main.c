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

void skipSpaces() {
  while (LA == ' ') {
    LA = yylex();
  }
}

void match(int t) {
	if (LA == t) {
    LA = yylex();
    skipSpaces();
  } else {
		error("lexical error");
  }
}

void matchDigit(int t) {
  if (t >= '0' && t <= '9') {
    LA = yylex();
    skipSpaces();
  } else {
    error("lexical error");
  }
}

int E();
int E1();
int F();
int T();
int T1();

// E -> T E1
int E() {
  puts("E -> T E1");
  return T() + E1();
}

// E1 ->
// E1 -> + T E1
int E1() {
  if (LA == '+') {
    int t = 0, e1 = 0;
    puts("E1 -> + T E1");
    match('+'); t = T(); e1 = E1();
    return t + e1;
  } else {
    puts("E1 -> ");
    return 0;
  }
}

// T -> F T1
int T() {
  int f = 0, t1 = 0;
  puts("T -> F T1");
  f = F(); t1 = T1();
  return f * t1;
}

// T1 ->
// T1 -> * F T1
int T1() {
  if (LA == '*') {
    int f = 0, t1 = 0;
    puts("T -> * F T1");
    match('*'); f = F(); t1 = T1();
    return f * t1;
  } else {
    puts("T1 -> ");
    return 1;
  }
}

// F -> ( E )
// F -> num
int F() {
  int result = 0;
  if (LA == '(') {
    puts("F -> ( E )");
    match('('); result = E(); match(')');
  } else {
    result = LA - '0';
    puts("F -> num");
    matchDigit(LA);
  }
  return result;
}

int main() {
	LA = yylex();
  printf("Result: %d\n", E());
	return 0;
}
