%{
 #include <stdio.h>
 #include "cgen.h"
	
 extern int yylex(void);
 extern int line_num;
%}

%union {
	char* str;
}

%token <str> TK_IDENT 
%token <str> TK_INT 
%token <str> TK_REAL 
%token TK_ASSGN 
%token KW_IF   
%token KW_ELSE 

%start input

%type <str> listOfExprs expr

%left '+' '-' 
%left '*' '/'

%%

input: 
	listOfExprs  
	{
		if (yyerror_count == 0) {
			//puts(c_prologue);
			printf("%s\n", $1);	
		}
	}
	;

listOfExprs: 
	expr 
	| listOfExprs ',' expr { $$ = template("%s\n%s", $1, $3);}
	;
	
expr:
	TK_INT
	| TK_REAL 
	| TK_IDENT
	| expr '+' expr { $$ = template("%s %s +", $1, $3); }
	| expr '-' expr { $$ = template("%s %s -", $1, $3); }
	| expr '*' expr { $$ = template("%s %s *", $1, $3); }
	| expr '/' expr { $$ = template("%s %s /", $1, $3); }
	| '(' expr ')' { $$ = template("%s", $2); }
	;
	
%%
int main ()
{
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}
