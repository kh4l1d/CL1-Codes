%{
#include<stdio.h>
#include<math.h>
int flag = 0;
int yyerror(const char *msg);
int yylex();
%}

%union
{
float fval;
}
%token SIN COS TAN SI CI TI LOG LN SQRT EXP
%token <fval> num
%type <fval> E

%left '+' '-' '*' '/'

%%
S: E'\n' {flag=1; printf("\nValue is: %f", $1); printf("\n");}
;
E: num'+'num {$$ = $1+$3;}
| num'-'num {$$ = $1-$3;}
| num'*'num {$$ = $1*$3;}
| num'/'num {$$ = $1/$3;}
| SIN'('num')' {$$ = sin((3.1416/180)*$3);}
| COS'('num')' {$$ = cos((3.1416/180)*$3);}
| TAN'('num')' {$$ = tan((3.1416/180)*$3);}
| SI'('num')' {$$ = (180/3.1416)*(asin($3));}
| CI'('num')' {$$ = (180/3.1416)*(acos($3));}
| TI'('num')' {$$ = (180/3.1416)*(atan($3));}
| LOG'('num')' {$$ = log10($3);}
| LN'('num')' {$$ = log($3);}
| num'^'num {$$ = pow($1,$3);}
| SQRT'('num')' {$$ = sqrt($3);}
| EXP num {$$ = exp($2);}
;
%%

int main()
{
printf("\nEnter expression:\n");
yyparse();
}

int yyerror(const char *msg)
{
if(flag == 0)
printf("\nInvalid format!\n");
}
