%{
 #include <stdio.h>
 #include "cgen.h"
 #include <string.h>

 extern int yylex(void);
 extern char* yytext;

 extern int line_num;

 char* comp_type;
 char* comp_func;
 char* null;
 char* func_names;
 char* ident;
 char* new_ident;
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

%token KEYWORD_DEF
%token KEYWORD_ENDDEF	
%token KEYWORD_MAIN
%token KEYWORD_RETURN
%token KEYWORD_COMP

%token KEYWORD_ENDCOMP
%token KEYWORD_OF

%token DELIM_SEMICOLON
%token DELIM_COMMA
%token DELIM_COLON
%token OP_HASHTAG

%token <str> CONST_INTEGER 
%token <str> CONST_FLOAT 
%token <str> CONST_STRING 
%token <str> IDENTIFIER

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
%type <str> instruction
%type <str> comp_members_var
%type <str> comp_members_method
%type <str> member_var
%type <str> member_method
%type <str> member_var_identifiers
%type <str> expr
%type <str> func_call
%type <str> n_expr
%type <str> expression
%type <str> statements
%type <str> method_arg
%type <str> method_n_expr
%type <str> expr_identifiers
%type <str> expr_identifiers_dot

%start input

%left DELIM_DOT DELIM_LPAR DELIM_RPAR DELIM_LBRAC DELIM_RBRAC
%right OP_POWER
%right OP_SIGN
%left OP_PROD OP_DIV OP_MOD
%left OP_PLUS OP_MINUS
%left OP_SMALLER OP_SMALLER_EQ OP_BIGGER OP_BIGGER_EQ
%left OP_EQUALS OP_NOT_EQUALS
%right KEYWORD_NOT
%left KEYWORD_AND
%left KEYWORD_OR
%right OP_ASSIGN OP_ASSIGN_PLUS OP_ASSIGN_MINUS OP_ASSIGN_PROD OP_ASSIGN_DIV OP_ASSIGN_MOD OP_ASSIGN_ARR

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

program:
	%empty {$$ = template("");}
	|program declare_comp DELIM_SEMICOLON{$$ = template("%s\n%s", $1, $2);}
	|program declare_const DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
	|program declare_var DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
	|program declare_func DELIM_SEMICOLON{$$ = template("%s\n\n%s", $1, $2);}
	;

program_main:	
	%empty {$$ = template("");}
	|program declare_main DELIM_SEMICOLON {$$ = template("%s\n\n%s\n", $1, $2);}
	;
 
declare_comp:
	KEYWORD_COMP IDENTIFIER DELIM_COLON comp_members_var { comp_type = $2; } comp_members_method KEYWORD_ENDCOMP 
	{	
		$$ = template("#define SELF struct %s *self\ntypedef struct %s {\n%s%s}%s;\n\n%s\n%s ctor_%s = {%s};\n#undef SELF\n",$2, $2, $4,comp_func,$2, $6, $2, $2, func_names);
		comp_func = template("");
		func_names = template("");}
	;
	|KEYWORD_COMP IDENTIFIER DELIM_COLON comp_members_var KEYWORD_ENDCOMP 
	{$$ = template("#define SELF struct %s *self\ntypedef struct %s {\n%s}%s;\n#undef SELF\n",$2, $2, $4,$2);}
	;

comp_members_var:	
	member_var {$$ = template("%s;\n", $1);}
	|comp_members_var member_var {$$ = template("%s%s;\n", $1, $2);}	
	;

comp_members_method:
	member_method {$$ = template("%s;\n", $1);}
	|comp_members_method member_method {$$ = template("%s\n%s;\n", $1, $2);}
	;

member_method:
	KEYWORD_DEF IDENTIFIER DELIM_LPAR method_arg DELIM_RPAR OP_MINUS OP_BIGGER data_type DELIM_COLON func_body KEYWORD_RETURN expression KEYWORD_ENDDEF DELIM_SEMICOLON
	{$$ = template("%s %s(SELF%s){%s\nreturn %s\n}", $8, $2, $4, $10, $12);
	if (comp_func != null) {
		comp_func = template("%s (*%s) (SELF%s);\n%s", $8, $2, $4, comp_func);
		func_names = template(".%s = %s,%s", $2, $2, func_names);
	}else{
		comp_func = template("%s (*%s) (SELF%s);\n", $8, $2, $4);
		func_names = template(".%s = %s", $2, $2);
	}	
	}
	|KEYWORD_DEF IDENTIFIER DELIM_LPAR method_arg DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF DELIM_SEMICOLON
	{$$ = template("void %s(SELF%s){%s\n}", $2, $4, $7);
	if (comp_func != null) {
		comp_func = template("void (*%s) (SELF%s);\n%s", $2, $4, comp_func);
		func_names = template(".%s = %s,%s", $2, $2, func_names);
	}else{
		comp_func = template("void (*%s) (SELF%s);\n", $2, $4);
		func_names = template(".%s = %s", $2, $2);
	}
	}
	;

member_var:
	member_var_identifiers DELIM_COLON data_type DELIM_SEMICOLON {$$ = template("%s %s", $3, $1);}
	|OP_HASHTAG IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON {$$ = template("%s* %s", $6, $2);}	
	|OP_HASHTAG IDENTIFIER DELIM_LBRAC CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON {$$ = template("%s %s[%s]", $7, $2, $4);}
	;

member_var_identifiers:
	OP_HASHTAG IDENTIFIER {$$ = $2;}
	|member_var_identifiers DELIM_COMMA OP_HASHTAG IDENTIFIER {$$ = template("%s, %s", $1, $4);}
	;

method_arg:
	%empty {$$ = template("");}
	|IDENTIFIER DELIM_COLON data_type {$$ = template(" ,%s %s", $3, $1);}	
	|IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template(" ,%s* %s", $5, $1);}	
	|func_arg DELIM_COMMA IDENTIFIER DELIM_COLON data_type {$$ = template(" ,%s, %s %s", $1, $5, $3);}
	|func_arg DELIM_COMMA IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template(" ,%s, %s* %s", $1, $7, $3);}	
	;

declare_const:
	KEYWORD_CONST expr DELIM_COLON data_type {$$ = template("%s %s", $4, $2);}
	;

declare_var:
	var_identifiers DELIM_COLON data_type {
		if ( !strcmp($3,"int") || !strcmp($3,"char*") || !strcmp($3,"double") ){
			$$ = template("%s %s", $3, $1);
		}else{
			$$ = template("%s %s = %s", $3, $1, comp_type);
		};}
	|IDENTIFIER DELIM_LBRAC DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s* %s", $5, $1);}	
	|IDENTIFIER DELIM_LBRAC CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type {$$ = template("%s %s[%s]", $6, $1, $3);}
	;

declare_func:
	KEYWORD_DEF IDENTIFIER DELIM_LPAR func_arg DELIM_RPAR OP_MINUS OP_BIGGER data_type DELIM_COLON func_body KEYWORD_RETURN expression KEYWORD_ENDDEF
	{$$ = template("%s %s(%s){%s\nreturn %s\n}", $8, $2, $4, $10, $12);}
	|KEYWORD_DEF IDENTIFIER DELIM_LPAR func_arg DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF
	{$$ = template("void %s(%s){%s\n}", $2, $4, $7);}
	;

declare_main:
	KEYWORD_DEF KEYWORD_MAIN DELIM_LPAR DELIM_RPAR DELIM_COLON func_body KEYWORD_ENDDEF {$$ = template("void main() {%s\n}", $6);}
	;	

func_body:	
	%empty {$$ = template("");}
	|func_body declare_const DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
	|func_body declare_var DELIM_SEMICOLON {$$ = template("%s\n%s;", $1, $2);}
  |func_body instruction  {$$ = template("%s\n%s", $1, $2);}
	;

expression:
	expr DELIM_SEMICOLON {$$ = template("%s;", $1);}
	;

expr_identifiers:
	IDENTIFIER {$$ = $1;}
	|OP_HASHTAG IDENTIFIER {$$ = template("self->%s", $2);}
	|OP_HASHTAG IDENTIFIER DELIM_LBRAC expr DELIM_RBRAC {$$ = template("self->%s[%s]", $2, $4);}
	|IDENTIFIER DELIM_LBRAC expr DELIM_RBRAC {$$ = template("%s[%s]", $1, $3);}
	;

expr_identifiers_dot:
	OP_HASHTAG IDENTIFIER {$$ = template("%s", $2);}
	|expr_identifiers_dot DELIM_DOT OP_HASHTAG IDENTIFIER {$$ = template("%s.%s", $1, $4);}
	;

expr:
	data_const {$$ = template("%s", $1);}
	|expr_identifiers {$$ = template("%s", $1);}
	|func_call {$$ = template("%s",$1);}
  |expr_identifiers DELIM_DOT	expr_identifiers_dot {$$ = template("%s.%s", $1, $3);}
	|expr_identifiers DELIM_DOT IDENTIFIER DELIM_LPAR method_n_expr DELIM_RPAR  {$$ = template("%s.%s(&%s%s)", $1, $3, $1, $5);}
	|DELIM_LPAR expr DELIM_RPAR {$$ = template("(%s)",$2);}
	|expr OP_POWER expr {$$ = template("pow(%s, %s)", $1, $3);}
	|OP_PLUS expr %prec OP_SIGN {$$ = template("+%s",$2);}
	|OP_MINUS expr %prec OP_SIGN {$$ = template("-%s",$2);}
	|expr OP_PROD expr {$$ = template("%s * %s", $1, $3);}
	|expr OP_DIV expr {$$ = template("%s / %s", $1, $3);}
	|expr OP_MOD expr {$$ = template("%s %% %s", $1, $3);}
	|expr OP_PLUS expr {$$ = template("%s + %s", $1, $3);}
	|expr OP_MINUS expr {$$ = template("%s - %s", $1, $3);}
	|expr OP_SMALLER expr {$$ = template("%s < %s", $1, $3);}
	|expr OP_SMALLER_EQ expr {$$ = template("%s <= %s", $1, $3);}
	|expr OP_BIGGER expr {$$ = template("%s > %s", $1, $3);}
	|expr OP_BIGGER_EQ expr {$$ = template("%s >= %s", $1, $3);}
	|expr OP_EQUALS expr {$$ = template("%s == %s", $1, $3);}
	|expr OP_NOT_EQUALS expr {$$ = template("%s != %s", $1, $3);}
	|KEYWORD_NOT expr {$$ = template("!%s", $2);}
	|expr KEYWORD_AND expr {$$ = template("%s && %s", $1, $3);}
	|expr KEYWORD_OR expr {$$ = template("%s || %s", $1, $3);}
	|expr OP_ASSIGN expr {$$ = template("%s = %s", $1, $3);}
	|expr OP_ASSIGN_PLUS expr {$$ = template("%s += %s", $1, $3);}
	|expr OP_ASSIGN_MINUS expr {$$ = template("%s -= %s", $1, $3);}
	|expr OP_ASSIGN_PROD expr {$$ = template("%s *= %s", $1, $3);}
	|expr OP_ASSIGN_DIV expr {$$ = template("%s /= %s", $1, $3);}
	|expr OP_ASSIGN_MOD expr {$$ = template("%s %= %s", $1, $3);}
	;

method_n_expr:
	%empty {$$ = template("");}
	|expr {$$ = template(", %s", $1);}
	|n_expr DELIM_COMMA expr {$$ = template(", %s, %s", $1, $3);}
	;

func_call:
	IDENTIFIER DELIM_LPAR n_expr DELIM_RPAR  {$$ = template("%s(%s)", $1, $3);}
	;

n_expr:
	%empty {$$ = template("");}
	|expr {$$ = template("%s", $1);}
	|n_expr DELIM_COMMA expr {$$ = template("%s, %s", $1, $3);}
	;

statements:
	%empty {$$ = template("");}
	|statements instruction {$$ = template("%s%s", $1, $2);}

instruction:
	KEYWORD_IF DELIM_LPAR expr DELIM_RPAR DELIM_COLON statements KEYWORD_ENDIF DELIM_SEMICOLON {$$ = template("if (%s){\n%s};", $3, $6);}
	|KEYWORD_IF DELIM_LPAR expr DELIM_RPAR DELIM_COLON statements KEYWORD_ELSE DELIM_COLON statements KEYWORD_ENDIF DELIM_SEMICOLON 
	{$$ = template("if (%s){\n%s}else{\n%s}", $3, $6, $9);}
	|KEYWORD_FOR IDENTIFIER KEYWORD_IN DELIM_LBRAC expr DELIM_COLON expr DELIM_COLON expr DELIM_RBRAC
	DELIM_COLON statements KEYWORD_ENDFOR  DELIM_SEMICOLON
	{$$ = template("for (int %s = %s ; %s < %s ; %s += %s){\n%s}", $2, $5, $2, $7, $2, $9, $12);}
	|KEYWORD_FOR IDENTIFIER KEYWORD_IN DELIM_LBRAC expr DELIM_COLON expr DELIM_RBRAC
	DELIM_COLON statements KEYWORD_ENDFOR DELIM_SEMICOLON
	{$$ = template("for (int %s = %s ; %s < %s ; %s += 1){\n%s;}", $2, $5, $2, $7, $2, $10);}
	|IDENTIFIER OP_ASSIGN_ARR DELIM_LBRAC expr KEYWORD_FOR expr DELIM_COLON CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON
	{$$ = template("%s* %s = (%s*)malloc(%s * sizeof(%s)); \nfor (int %s = 0; %s < %s; ++%s){\n%s[%s] = %s;\n}", $11, $1, $11, $8, $11, $6, $6, $8, $6, $1, $6, $4);}
	|IDENTIFIER OP_ASSIGN_ARR DELIM_LBRAC expr KEYWORD_FOR expr DELIM_COLON data_type KEYWORD_IN IDENTIFIER KEYWORD_OF CONST_INTEGER DELIM_RBRAC DELIM_COLON data_type DELIM_SEMICOLON
	{$$ = template("%s* %s = (%s*)malloc(%s * sizeof(%s)); \nfor (int array_i = 0; array_i < %s; ++array_i){\n%s[array_i] = %s[array_i];\n}", $15, $1, $15, $12, $15, $12, $1, $10);}
	|KEYWORD_WHILE DELIM_LPAR expr DELIM_RPAR DELIM_COLON statements KEYWORD_ENDWHILE DELIM_SEMICOLON {$$ = template("while (%s){\n%s}", $3, $6);}
	|KEYWORD_BREAK DELIM_SEMICOLON {$$ = template("break;");}
	|KEYWORD_CONTINUE DELIM_SEMICOLON {$$ = template("continue;");}
	|KEYWORD_RETURN DELIM_SEMICOLON {$$ = template("return;");}
	|KEYWORD_RETURN expr DELIM_SEMICOLON {$$ = template("return %s;", $2);}
	|DELIM_SEMICOLON {$$ = template("");}
	|expression {$$ = template("%s", $1);}
	;

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

data_type:
	KEYWORD_INTEGER {$$ = template("int");}
	|KEYWORD_SCALAR {$$ = template("double");}
	|KEYWORD_STR {$$ = template("char*");}
	|KEYWORD_BOOL {$$ = template("int");}
	|IDENTIFIER {$$ = template("%s", $1);
	comp_type = template("ctor_%s", $1);}
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
   if ( yyparse() == 0 ){
   	//printf("Accepted!\n");
   }
	else
		printf("Rejected!\n");
}