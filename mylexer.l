%{
 #include <stdio.h>
 #include <string.h>
 #include "cgen.h"	
 #include "myanalyzer.tab.h"
 /*Dunno what math.h does maybe delete later*/
 #include <math.h>

 int line_num = 1;
 
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
OP_ASSIGN_ARR (\:)(\=)

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

OP_HASHTAG (\#)

%%

{KEYWORD_INTEGER} {return KEYWORD_INTEGER;}
{KEYWORD_SCALAR} {return KEYWORD_SCALAR;}
{KEYWORD_STR} {return KEYWORD_STR;}
{KEYWORD_BOOL} {return KEYWORD_BOOL;}
{KEYWORD_TRUE} {return KEYWORD_TRUE;}
{KEYWORD_FALSE} {return KEYWORD_FALSE;}
{KEYWORD_CONST} {return KEYWORD_CONST;}
{KEYWORD_IF} {return KEYWORD_IF;}
{KEYWORD_ELSE} {return KEYWORD_ELSE;}
{KEYWORD_ENDIF} {return KEYWORD_ENDIF;}
{KEYWORD_FOR} {return KEYWORD_FOR;}
{KEYWORD_IN} {return KEYWORD_IN;}
{KEYWORD_ENDFOR} {return KEYWORD_ENDFOR;}
{KEYWORD_WHILE} {return KEYWORD_WHILE;}
{KEYWORD_ENDWHILE} {return KEYWORD_ENDWHILE;}
{KEYWORD_BREAK} {return KEYWORD_BREAK;}
{KEYWORD_CONTINUE} {return KEYWORD_CONTINUE;}
{KEYWORD_NOT} {return KEYWORD_NOT;} 
{KEYWORD_AND} {return KEYWORD_AND;}
{KEYWORD_OR} {return KEYWORD_OR;} 
{KEYWORD_DEF} {return KEYWORD_DEF;}
{KEYWORD_ENDDEF} {return KEYWORD_ENDDEF;}
{KEYWORD_MAIN} {return KEYWORD_MAIN;}
{KEYWORD_RETURN} {return KEYWORD_RETURN;}
{KEYWORD_COMP} {return KEYWORD_COMP;}
{KEYWORD_ENDCOMP} {return KEYWORD_ENDCOMP;}
{KEYWORD_OF} {return KEYWORD_OF;}

{OP_PLUS} {return OP_PLUS;}
{OP_MINUS} {return OP_MINUS;}
{OP_PROD} {return OP_PROD;}
{OP_DIV} {return OP_DIV;}
{OP_MOD} {return OP_MOD;}
{OP_POWER} {return OP_POWER;}

{OP_EQUALS} {return OP_EQUALS;}
{OP_NOT_EQUALS} {return OP_NOT_EQUALS;}
{OP_SMALLER} {return OP_SMALLER;}
{OP_SMALLER_EQ} {return OP_SMALLER_EQ;}
{OP_BIGGER} {return OP_BIGGER;}
{OP_BIGGER_EQ} {return OP_BIGGER_EQ;}

{OP_ASSIGN} {return OP_ASSIGN;}
{OP_ASSIGN_PLUS} {return OP_ASSIGN_PLUS;}
{OP_ASSIGN_MINUS} {return OP_ASSIGN_MINUS;}
{OP_ASSIGN_PROD} {return OP_ASSIGN_PROD;}
{OP_ASSIGN_DIV} {return OP_ASSIGN_DIV;}
{OP_ASSIGN_MOD} {return OP_ASSIGN_MOD;}
{OP_ASSIGN_ARR} {return OP_ASSIGN_ARR;}

{DELIM_SEMICOLON} {return DELIM_SEMICOLON;}
{DELIM_LPAR} {return DELIM_LPAR;}
{DELIM_RPAR} {return DELIM_RPAR;}
{DELIM_COMMA} {return DELIM_COMMA;}
{DELIM_LBRAC} {return DELIM_LBRAC;}
{DELIM_RBRAC} {return DELIM_RBRAC;}
{DELIM_COLON} {return DELIM_COLON;}
{DELIM_DOT} {return DELIM_DOT;}
{OP_HASHTAG} {return OP_HASHTAG;}

{CONST_INTEGER} {yylval.str = strdup(yytext); return CONST_INTEGER;}
{CONST_FLOAT} {yylval.str = strdup(yytext); return CONST_FLOAT;}
{CONST_STRING} {yylval.str = strdup(yytext); return CONST_STRING;}
{IDENTIFIER} {yylval.str = strdup(yytext); return IDENTIFIER;}

{LINE_COMMENT} {BEGIN(line_comment);}
<line_comment>[^\n]*    /*Exculde everything except \n*/
<line_comment>\n {BEGIN(INITIAL);}

[ \r\t] /*skip spaces*/

\n ++line_num;

<<EOF>> {return EOF;}

. {yyerror("Lexical Error: Unrecognized literal '%s' at line '%d'\n", yytext, line_num);}
%%
