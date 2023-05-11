%{
#include <stdio.h>
%}
NUMBER [+|-]?([0-9]+\.?|[0-9]*\.[0-9]+)
ID [a-zA-Z_][0-9a-zA-Z_]*
%%
{NUMBER} { printf("Found the number %s\n", yytext); }
{ID} { printf("Found the identifier %s\n", yytext); }
. { printf("Error\n"); }
%%
int main() {
yylex();
}