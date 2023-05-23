%{
 #include <stdio.h>
 #include "cgen.h"
	
 extern int yylex(void);
 extern char* yytext;

 extern int line_num;
%}

%union {
	char* str;
	double dbl;
}

%token KEYWORD_INTEGER
%token KEYWORD_SCALAR
%token KEYWORD_STR
%token KEYWORD_BOOL
%token KEYWORD_TRUE

%token KEYWORD_FALSE
%token KEYWORD_CONST
%token KEYWORD_IF
%token KEYWORD_ELSE
%token KEYWORD_ENDIF

%token KEYWORD_FOR
%token KEYWORD_IN
%token KEYWORD_ENDFOR
%token KEYWORD_WHILE
%token KEYWORD_ENDWHILE

%token KEYWORD_BREAK
%token KEYWORD_CONTINUE
%token KEYWORD_NOT
%token KEYWORD_AND
%token KEYWORD_OR

%token KEYWORD_DEF
%token KEYWORD_ENDDEF	
%token KEYWORD_MAIN
%token KEYWORD_RETURN
%token KEYWORD_COMP

%token KEYWORD_ENDCOMP
%token KEYWORD_OF

%token OP_PLUS
%token OP_MINUS
%token OP_PROD
%token OP_DIV
%token OP_MOD
%token OP_POWER

%token OP_EQUALS
%token OP_NOT_EQUALS
%token OP_SMALLER
%token OP_SMALLER_EQ
%token OP_BIGGER
%token OP_BIGGER_EQ

%token OP_ASSIGN
%token OP_ASSIGN_PLUS
%token OP_ASSIGN_MINUS
%token OP_ASSIGN_PROD
%token OP_ASSIGN_DIV
%token OP_ASSIGN_MOD

%token DELIM_SEMICOLON
%token DELIM_LPAR
%token DELIM_RPAR
%token DELIM_COMMA
%token DELIM_LBRAC
%token DELIM_RBRAC
%token DELIM_COLON
%token DELIM_DOT
%token OP_HASHTAG

%token <str> CONST_INTEGER 
%token <str> CONST_FLOAT 
%token <str> CONST_STRING 
%token <str> IDENTIFIER

//%type <str> program_comp
//%type <str> program_var
//%type <str> program_const
//%type <str> program_func
%type <str> program_main
%type <str> program

%type <str> data_type
%type <str> data_const
%type <str> declare_comp
%type <str> declare_const
%type <str> declare_var
%type <str> declare_func
%type <str> declare_main
%type <str> var_identifiers
%type <str> func_body
%type <str> func_arg
%type <str> expression
%type <str> instruction
%type <str> comp_members
%type <str> member_var
%type <str> member_method

%start input

%%

input: program_main
  {
     if (yyerror_count == 0) {
       puts(c_prologue);
       printf("%s", $1);
     }else{
     	 printf("Error num: %d",yyerror_count);
     }
 	}
 ;

/*
program_comp:
	%empty {$$ = template("");}
	//|declare_comp DELIM_SEMICOLON program_comp{$$ = template("%s\n%s", $1, $3);}
	;
program_const:
	%empty {$$ = template("");}
	|program_const declare_const program_var {$$ = template("%s%s\n%s", $1, $2, $3);}
	;
program_var:
	%empty {$$ = template("");}
	|program_var declare_var program_func {$$ = template("%s%s\n%s", $1, $2, $3);}
	;
program_func:
	%empty {$$ = template("");}
	|program_func declare_func program_main {$$ = template("%s%s\n%s", $1, $2, $3);}
	;
*/

/*WARNING DEN EINAI ME THN SEIRA POU ZHTAEI*/
program:
	%empty {$$ = template("");}
	|program declare_comp DELIM_SEMICOLON{$$ = template("%s\n%s;", $1, $2);}
	|program declare_const DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
	|program declare_var DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
	|program declare_func DELIM_SEMICOLON{$$ = template("%s\n\n%s", $1, $2);}
	;

program_main:	
	%empty {$$ = template("");}
	|program declare_main DELIM_SEMICOLON {$$ = template("%s\n\n%s\n", $1, $2);}
	;
 
declare_comp:
	KEYWORD_COMP IDENTIFIER DELIM_COLON comp_members KEYWORD_ENDCOMP {$$ = template("typedef struct %s {\n%s} %s", $2, $4, $2);}
	;

/*ERWTHSH ginetai na exw types xwris member variables*/
comp_members:	
	//%empty {$$ = template("");}
	member_var {$$ = template("%s;\n", $1);}
 	|member_method {$$ = template("%s;\n", $1);}
	|comp_members member_var {$$ = template("%s%s;", $1, $2);}
	|comp_members member_method {$$ = template("%s%s;", $1, $2);}
	;

/*LEIPEI TO COMP PWS TO BAZW EKEI MESA DHLADH PWS MPORW NA DW TA YPARXONTA COMPS*/
member_var:
	member_var_identifiers DELIM_COLON data_type {$$ = template("%s %s", $3, $1);}
	|OP_HASHTAG IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s* %s", $5, $1);}	
	|OP_HASHTAG IDENTIFIER DELIM_LBRAC CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s %s[%s]", $6, $1, $3);}
	;

member_var_identifiers:
	OP_HASHTAG IDENTIFIER {$$ = $1;}
	|member_var_identifiers DELIM_COMMA OP_HASHTAG IDENTIFIER {$$ = template("%s, %s", $1, $4);}
	;

/*ERWTHSH PWS TO FTIAXNW NA EXEI PROSBASH MONO STA MEMBER VARIABLES*/
member_method:
	%empty {$$ = template("");}
	;

declare_const:
	KEYWORD_CONST IDENTIFIER OP_ASSIGN data_const DELIM_COLON data_type {$$ = template("%s %s = %s", $6, $2, $4);}
	;

/*LEIPEI TO COMP PWS TO BAZW EKEI MESA DHLADH PWS MPORW NA DW TA YPARXONTA COMPS*/
declare_var:
	var_identifiers DELIM_COLON data_type {$$ = template("%s %s", $3, $1);}
	|IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s* %s", $5, $1);}	
	|IDENTIFIER DELIM_LBRAC CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s %s[%s]", $6, $1, $3);}
	;

declare_func:
	KEYWORD_DEF IDENTIFIER DELIM_LPAR func_arg DELIM_RPAR OP_MINUS OP_BIGGER data_type DELIM_COLON func_body KEYWORD_RETURN expression KEYWORD_ENDDEF
	{$$ = template("%s %s(%s){%s\nreturn %s}", $8, $2, $4, $10, $12);}
	|KEYWORD_DEF IDENTIFIER DELIM_LPAR func_arg DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF
	{$$ = template("void %s(%s){%s\n}", $2, $4, $7);}
	;

declare_main:
	KEYWORD_DEF KEYWORD_MAIN DELIM_LPAR DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF {$$ = template("void main() {%s\n}", $6);}
	;	

/*ERWTHSH exei simasia to order sto func_body? sthn C, den exei px*/
/*Episis afou oi entoles einai ipoxretikes pws isxuei to paradeigma 1,2 sto v) afto den exei entoles*/
func_body:	
// instruction {$$ = template("%s;", $1);}
	%empty {$$ = template("");}
	|func_body declare_const DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
	|func_body declare_var DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
  |func_body instruction DELIM_SEMICOLON{$$ = template("%s\n%s", $1, $2);}
	;

expression:
	%empty {$$ = template("");}
	;

instruction:
	%empty {$$ = template("");}
	;

/*ERWTHSH: How to ensure that two args don't have the same name ?/*/
/*LEIPEI TO COMP PWS TO BAZW EKEI MESA DHLADH PWS MPORW NA DW TA YPARXONTA COMPS*/
func_arg:
	%empty {$$ = template("");}
	|IDENTIFIER DELIM_COLON data_type {$$ = template("%s %s", $3, $1);}	
	|IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s* %s", $5, $1);}	
	|func_arg DELIM_COMMA IDENTIFIER DELIM_COLON data_type {$$ = template("%s, %s %s", $1, $5, $3);}
	|func_arg DELIM_COMMA IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s, %s* %s", $1, $7, $3);}	
	;

var_identifiers:
	IDENTIFIER {$$ = $1;}
	|var_identifiers DELIM_COMMA IDENTIFIER {$$ = template("%s, %s", $1, $3);}
	;

/*LEIPEI TO COMP PWS TO BAZW EKEI MESA DHLADH PWS MPORW NA DW TA YPARXONTA COMPS*/
data_type:
	KEYWORD_INTEGER {$$ = template("int");}
	|KEYWORD_SCALAR {$$ = template("double");}
	|KEYWORD_STR {$$ = template("char*");}
	|KEYWORD_BOOL {$$ = template("int");}
	;

data_const:
	CONST_INTEGER {$$ = $1;}
	|CONST_FLOAT {$$ = $1;}
	|CONST_STRING {$$ = $1;}
	|KEYWORD_TRUE {$$ = template("1");}
	|KEYWORD_FALSE {$$ = template("0");}
	;
	
	
%%
int main ()
{	
   if ( yyparse() == 0 )
		printf("Accepted!\n");
	else
		printf("Rejected!\n");
}

//ERWTHSH PWS KANW KATI YPOXREOTIKO H PROERTIKO

//ERWTHSH PWS KOITAW AN TO INTEGER EINAI THETIKO

//ERWTHSH PWS KANW POIO AKRIBH TA DIAGNWSTIKA MINIMATA PX THELOUME NA LEEI MONO
//SE POIA GRAMMH HPARXEI TO ERROR H KAI ALLA PRAGRMATA
 
//ERWTHSH TI KANW ME TO PLHN EINAI KAI TELESTHS PROSIMOU
//KAI ARITHIMITIKOS TELESTHS

//ERWTHSH PWS KANW ENSURE TIN SEIRA 

//ERWTHSH TA ARGS EINAI MONO data_type KAI EMPTY PINAKAS STO FUNCTION INPUT?