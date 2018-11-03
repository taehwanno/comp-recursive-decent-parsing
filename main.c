#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void error(char *msg) {
  printf("Error: %s\n", msg);
  exit(1);
}

int LA;

int yylex() {
  int c;
  do {
    c = getchar();
  } while (c == ' ');
  return c;
}

void match(int t) {
  if (LA == t) {
    LA = yylex();
  } else {
    error("lexical error");
  }
}

void matchDigit(int t) {
  if (t >= '0' && t <= '9') {
    LA = yylex();
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
  return T() + E1();
}

// E1 ->
// E1 -> + T E1
int E1() {
  if (LA == '+') {
    int t = 0, e1 = 0;
    match('+'); t = T(); e1 = E1();
    return t + e1;
  } else {
    return 0;
  }
}

// T -> F T1
int T() {
  int f = 0, t1 = 0;
  f = F(); t1 = T1();
  return f * t1;
}

// T1 ->
// T1 -> * F T1
int T1() {
  if (LA == '*') {
    int f = 0, t1 = 0;
    match('*'); f = F(); t1 = T1();
    return f * t1;
  } else {
    return 1;
  }
}

// F -> ( E )
// F -> num
int F() {
  int result = 0;
  if (LA == '(') {
    match('('); result = E(); match(')');
  } else {
    result = LA - '0';
    matchDigit(LA);
  }
  return result;
}

int main() {
  LA = yylex();
  printf("%d\n", E());
  return 0;
}
