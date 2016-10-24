%{
#include<stdio.h>
char ch = 'A';
char intcode(char ch1, char first, char op, char second);
int yyerror(char *str);
int yyparse();
int yylex();
%}

%union
{
char dval;
}

%token <dval> NUM
%type <dval> E
%left '+' '-'
%left '*' '/'

%%
S : E
  ;
E : E'+'E {$$=intcode($$, $1, '+', $3);}
  | E'-'E {$$=intcode($$, $1, '-', $3);}
  | E'*'E {$$=intcode($$, $1, '*', $3);}
  | E'/'E {$$=intcode($$, $1, '/', $3);}
  | '('E')' {$$=$2;}
  | NUM {$$=$1;}
  ;
%%
int yyerror(char *str)
{
  printf("\n%s", str);
}

char intcode(char ch1, char first, char op, char second)
{
  printf("\n%c = %c %c %c\n", ch, first, op, second);
  return ch++;
}

int main()
{
  yyparse();
  return 0;
}
