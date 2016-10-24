%{
  #include "sci_calc.tab.h"
  #include<math.h>
  extern YYSTYPE yylval;
%}

num [0-9]+|[0-9]*"."[0-9]+

%%
{num} {yylval.fval = atof(yytext); return num;}
sin {return SIN;}
cos {return COS;}
tan {return TAN;}
"sin-1" {return SI;}
"cos-1" {return CI;}
"tan-1" {return TI;}
log {return LOG;}
ln {return LN;}
sqrt {return SQRT;}
e {return EXP;}
"+"|"-" {return *yytext;}
"*"|"/" {return *yytext;}
"("|")" {return *yytext;}
"^" {return *yytext;}
"\n" {return *yytext;}
%%

int yywrap() {return 1;}
