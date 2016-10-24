%{
  #include<stdio.h>
  #include<stdlib.h>
%}
%%
#[a-zA-Z]+ { fprintf(yyout, "%s\t\tPreprocessor directive\n", yytext); }
[a-zA-Z]+.h { fprintf(yyout, "%s\t\tHeader file\n", yytext); }
"main"|"printf"|"scanf" { fprintf(yyout, "%s\t\tInbuilt function\n", yytext); }
"int"|"char"|"float"|"double"|"void"|"return" { fprintf(yyout, "%s\t\tKeyword\n", yytext); }
[<|>|{|}|;|=|+|-|*|/|,|"|(|)] { fprintf(yyout, " "); }
[a-zA-Z]+[0-9a-zA-Z]* { fprintf(yyout, "%s\t\tIdentifier\n", yytext); }
[0-9]+ { fprintf(yyout, "%s\t\tConstant\n", yytext); }
%%

int main()
{
  yyin = fopen("sample.txt", "r");
  yylex();
}

int yywrap()
{
  return 1;
}
