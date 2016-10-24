%{
#include <stdio.h>
#include "int_code.tab.h"
%}
%option noyywrap

%%
[0-9]+ {yylval.dval = yytext[0]; return NUM;}
\n {return 0;}
. {return yytext[0];}
%%
