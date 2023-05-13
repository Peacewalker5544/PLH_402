%{
#include <stdio.h>
%}

IDENTIFIER [a-zA-Z][0-9a-zA-Z_]*

KEYWORD_INTEGER (integer)
KEYWORD_SCALAR (scalar)
KEYWORD_STR (str)
KEYWORD_BOOL (boolean)
KEYWORD_TRUE (True)

KEYWORD_FALSE (False)
KEYWORD_CONST (const)
KEYWORD_IF (if)
KEYWORD_ELSE (else)
KEYWORD_ENDIF (endif)

KEYWORD_FOR (for)
KEYWORD_IN (in)
KEYWORD_ENDFOR (endfor)
KEYWORD_WHILE (while)
KEYWORD_ENDWHILE (endwhile)

KEYWORD_BREAK (break)
KEYWORD_CONTINUE (continue)
KEYWORD_NOT (not)
KEYWORD_AND (and)
KEYWORD_OR (or)

KEYWORD_DEF (def)
KEYWORD_ENDDEF (enddef)
KEYWORD_MAIN (main)
KEYWORD_RETURN (return)
KEYWORD_COMP (comp)

KEYWORD_ENDCOMP (endcomp)
KEYWORD_OF (of)

CONST_INTEGER (0|[1-9][0-9]*)
CONST_FLOAT {CONST_INTEGER}((\.){CONST_INTEGER})(([eE]([\+\-]?){CONST_INTEGER})?)
ESC_CHAR (\\)[ntr\\\"]

/*not sure yet for , and . chars*/
CONST_STRING (\")([\ a-zA-Z0-9\-\+\*\/\:\_\$\%\!\#\@\&\~\^\(\)\,\.]|{ESC_CHAR})*(\") 

OP_PLUS (\+)
OP_MINUS (\-)
OP_PROD (\*)
OP_DIV (\/)
OP_MOD (\%)
OP_POWER (\*)(\*)


OP_EQUALS (\=)(\=)
OP_NOT_EQUALS (\!)(\=)	
OP_SMALLER (\<)
OP_SMALLER_EQ (\<)(\=)
OP_BIGGER (\>)
OP_BIGGER_EQ (\>)(\=)

OP_ASSIGN (\=)
OP_ASSIGN_PLUS (\+)(\=)
OP_ASSIGN_MINUS (\-)(\=)
OP_ASSIGN_PROD (\*)(\=)
OP_ASSIGN_DIV (\/)(\=)
OP_ASSIGN_MOD (\%)(\=)

DELIM_SEMICOLON (\;)
DELIM_LPAR (\()
DELIM_RPAR (\))
DELIM_COMMA (\,)
DELIM_LBRAC (\[)
DELIM_RBRAC (\])
DELIM_COLON (\:)
DELIM_DOT (\.)

%x line_comment
LINE_COMMENT (\-)(\-)

%%

{KEYWORD_INTEGER} { printf("token\t\tKEYWORD_INTEGER\t\t%s\n", yytext); }
{KEYWORD_SCALAR} { printf("token\t\tKEYWORD_SCALAR\t\t%s\n", yytext); }
{KEYWORD_STR} { printf("token\t\tKEYWORD_STR\t\t%s\n", yytext); }
{KEYWORD_BOOL} { printf("token\t\tKEYWORD_BOOL\t\t%s\n", yytext); }
{KEYWORD_TRUE} { printf("token\t\tKEYWORD_TRUE\t\t%s\n", yytext); }
{KEYWORD_FALSE} { printf("token\t\tKEYWORD_FALSE\t\t%s\n", yytext); }
{KEYWORD_CONST} { printf("token\t\tKEYWORD_CONST\t\t%s\n", yytext); }
{KEYWORD_IF} { printf("token\t\tKEYWORD_IF\t\t%s\n", yytext); }
{KEYWORD_ELSE} { printf("token\t\tKEYWORD_ELSE\t\t%s\n", yytext); }
{KEYWORD_ENDIF} { printf("token\t\tKEYWORD_ENDIF\t\t%s\n", yytext); }
{KEYWORD_FOR} { printf("token\t\tKEYWORD_FOR\t\t%s\n", yytext); }
{KEYWORD_IN} { printf("token\t\tKEYWORD_IN\t\t%s\n", yytext); }
{KEYWORD_ENDFOR} { printf("token\t\tKEYWORD_ENDFOR\t\t%s\n", yytext); }
{KEYWORD_WHILE} { printf("token\t\tKEYWORD_WHILE\t\t%s\n", yytext); }
{KEYWORD_ENDWHILE} { printf("token\t\tKEYWORD_ENDWHILE\t%s\n", yytext); }
{KEYWORD_BREAK} { printf("token\t\tKEYWORD_BREAK\t\t%s\n", yytext); }
{KEYWORD_CONTINUE} { printf("token\t\tKEYWORD_CONTINUE\t%s\n", yytext); }
{KEYWORD_NOT} { printf("token\t\tKEYWORD_NOT\t\t%s\n", yytext); } 
{KEYWORD_AND} { printf("token\t\tKEYWORD_AND\t\t%s\n", yytext); }
{KEYWORD_OR} { printf("token\t\tKEYWORD_OR\t\t%s\n", yytext); } 
{KEYWORD_DEF} { printf("token\t\tKEYWORD_DEF\t\t%s\n", yytext); }
{KEYWORD_ENDDEF} { printf("token\t\tKEYWORD_ENDDEF\t\t%s\n", yytext); }
{KEYWORD_MAIN} { printf("token\t\tKEYWORD_MAIN\t\t%s\n", yytext); }
{KEYWORD_RETURN} { printf("token\t\tKEYWORD_RETURN\t\t%s\n", yytext); }
{KEYWORD_COMP} { printf("token\t\tKEYWORD_COMP\t\t%s\n", yytext); }
{KEYWORD_ENDCOMP} { printf("token\t\tKEYWORD_ENDCOMP\t\t%s\n", yytext); }
{KEYWORD_OF} { printf("token\t\tKEYWORD_OF\t\t%s\n", yytext); }

{OP_PLUS} { printf("token\t\tOP_PLUS\t\t\t%s\n", yytext); }
{OP_MINUS} { printf("token\t\tOP_MINUS\t\t%s\n", yytext); }
{OP_PROD} { printf("token\t\tOP_PROD\t\t\t%s\n", yytext); }
{OP_DIV} { printf("token\t\tOP_DIV\t\t\t%s\n", yytext); }
{OP_MOD} { printf("token\t\tOP_MOD\t\t\t%s\n", yytext); }
{OP_POWER} { printf("token\t\tOP_POWER\t\t%s\n", yytext); }

{OP_EQUALS} { printf("token\t\tOP_EQUALS\t\t%s\n", yytext); }
{OP_NOT_EQUALS} { printf("token\t\tOP_NOT_EQUALS\t\t%s\n", yytext); }
{OP_SMALLER} { printf("token\t\tOP_SMALLER\t\t%s\n", yytext); }
{OP_SMALLER_EQ} { printf("token\t\tOP_SMALLER_EQ\t\t%s\n", yytext); }
{OP_BIGGER} { printf("token\t\tOP_BIGGER\t\t%s\n", yytext); }
{OP_BIGGER_EQ} { printf("token\t\tOP_BIGGER_EQ\t\t%s\n", yytext); }

{OP_ASSIGN} { printf("token\t\tOP_ASSIGN\t\t%s\n", yytext); }
{OP_ASSIGN_PLUS} { printf("token\t\tOP_ASSIGN_PLUS\t\t%s\n", yytext); }
{OP_ASSIGN_MINUS} { printf("token\t\tOP_ASSIGN_MINUS\t\t%s\n", yytext); }
{OP_ASSIGN_PROD} { printf("token\t\tOP_ASSIGN_PROD\t\t%s\n", yytext); }
{OP_ASSIGN_DIV} { printf("token\t\tOP_ASSIGN_DIV\t\t%s\n", yytext); }
{OP_ASSIGN_MOD} { printf("token\t\tOP_ASSIGN_MOD\t\t%s\n", yytext); }

{DELIM_SEMICOLON} { printf("token\t\tDELIM_SEMICOLON\t\t%s\n", yytext); }
{DELIM_LPAR} { printf("token\t\tDELIM_LPAR\t\t%s\n", yytext); }
{DELIM_RPAR} { printf("token\t\tDELIM_RPAR\t\t%s\n", yytext); }
{DELIM_COMMA} { printf("token\t\tDELIM_COMMA\t\t%s\n", yytext); }
{DELIM_LBRAC} { printf("token\t\tDELIM_LBRAC\t\t%s\n", yytext); }
{DELIM_RBRAC} { printf("token\t\tDELIM_RBRAC\t\t%s\n", yytext); }
{DELIM_COLON} { printf("token\t\tDELIM_COLON\t\t%s\n", yytext); }
{DELIM_DOT} { printf("token\t\tDELIM_DOT\t\t%s\n", yytext); }

{CONST_INTEGER} { printf("token\t\tCONST_INTEGER\t\t%s\n", yytext); }
{CONST_FLOAT} { printf("token\t\tCONST_FLOAT\t\t%s\n", yytext); }
{CONST_STRING} { printf("token\t\tCONST_STRING\t\t%s\n", yytext); }

{IDENTIFIER} { printf("token\t\tIDENTIFIER\t\t%s\n", yytext); }

{LINE_COMMENT} {BEGIN(line_comment);}
<line_comment>[^\n]*    /*Exculde everything except \n*/
<line_comment>\n {BEGIN(INITIAL);}

[ \r\t\n] /*skip spaces*/

%%
int main() {
yylex();
}