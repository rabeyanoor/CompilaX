%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int line_num;
void yyerror(const char* s);

ASTNode* root;
%}

%union {
    char* sval;
    struct ASTNode* nval;
}

%token <sval> IDENTIFIER NUMBER STRING_LITERAL
%token LET IF ELSE WHILE PRINT RETURN FN FOR TYPE MOD COUT LSHIFT
%token ASSIGN PLUS MINUS MULT DIV LT GT EQ NE LE GE AND OR INC DEC NOT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

%type <nval> program statement_list statement var_decl declarator_list declarator assignment if_stmt while_stmt print_stmt func_decl return_stmt for_stmt update expression term unary factor block params args func_call cout_stmt cout_expr_list type_specifier

%start program

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV MOD

%precedence THEN
%precedence ELSE

%%

program:
    statement_list { root = create_node(NODE_PROGRAM, NULL, $1, NULL, NULL); }
    ;

statement_list:
    statement { 
        ASTNode* last = $1;
        while (last->next) last = last->next;
        $$ = $1; 
    }
    | statement statement_list { 
        ASTNode* last = $1;
        while (last->next) last = last->next;
        last->next = $2; 
        $$ = $1; 
    }
    ;

statement:
    var_decl { $$ = $1; }
    | assignment { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | print_stmt { $$ = $1; }
    | cout_stmt { $$ = $1; }
    | func_decl { $$ = $1; }
    | return_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | func_call SEMICOLON { $$ = $1; }
    | block { $$ = $1; }
    ;

cout_stmt:
    COUT cout_expr_list SEMICOLON { $$ = $2; }
    ;

cout_expr_list:
    LSHIFT expression { 
        $$ = create_node(NODE_PRINT, NULL, $2, NULL, NULL); 
    }
    | LSHIFT expression cout_expr_list { 
        ASTNode* p = create_node(NODE_PRINT, NULL, $2, NULL, NULL); 
        p->next = $3; 
        $$ = p; 
    }
    ;

type_specifier:
    TYPE { $$ = NULL; }
    | TYPE type_specifier { $$ = NULL; }
    ;

var_decl:
    LET declarator_list SEMICOLON { $$ = $2; }
    | type_specifier declarator_list SEMICOLON { $$ = $2; }
    ;

declarator_list:
    declarator { $$ = $1; }
    | declarator COMMA declarator_list { $1->next = $3; $$ = $1; }
    ;

declarator:
    IDENTIFIER { $$ = create_node(NODE_VAR_DECL, $1, NULL, NULL, NULL); }
    | IDENTIFIER ASSIGN expression { $$ = create_node(NODE_VAR_DECL, $1, $3, NULL, NULL); }
    ;

assignment:
    IDENTIFIER ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, $3, NULL, NULL);
    }
    | IDENTIFIER INC SEMICOLON {
        /* Pseudo-assignment for x++ */
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
    | IDENTIFIER DEC SEMICOLON {
        /* Pseudo-assignment for x-- */
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
    | IDENTIFIER ADD_ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, $3), NULL, NULL);
    }
    | IDENTIFIER SUB_ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, $3), NULL, NULL);
    }
    | IDENTIFIER MUL_ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "*", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, $3), NULL, NULL);
    }
    | IDENTIFIER DIV_ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "/", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, $3), NULL, NULL);
    }
    | IDENTIFIER MOD_ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "%", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, $3), NULL, NULL);
    }
    ;

if_stmt:
    IF LPAREN expression RPAREN statement %prec THEN {
        $$ = create_node(NODE_IF, NULL, $3, $5, NULL);
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        $$ = create_node(NODE_IF, NULL, $3, $5, $7);
    }
    ;

while_stmt:
    WHILE LPAREN expression RPAREN statement {
        $$ = create_node(NODE_WHILE, NULL, $3, $5, NULL);
    }
    ;

for_stmt:
    FOR LPAREN var_decl expression SEMICOLON update RPAREN statement {
        /* var_decl already includes SEMICOLON */
        ASTNode* tail = create_node(NODE_PROGRAM, NULL, $6, $8, NULL);
        $$ = create_node(NODE_FOR, NULL, $3, $4, tail);
    }
    | FOR LPAREN assignment expression SEMICOLON update RPAREN statement {
        /* assignment already includes SEMICOLON */
        ASTNode* tail = create_node(NODE_PROGRAM, NULL, $6, $8, NULL);
        $$ = create_node(NODE_FOR, NULL, $3, $4, tail);
    }
    ;

update:
    IDENTIFIER ASSIGN expression {
        $$ = create_node(NODE_ASSIGN, $1, $3, NULL, NULL);
    }
    | IDENTIFIER INC {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "+", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
    | IDENTIFIER DEC {
        $$ = create_node(NODE_ASSIGN, $1, create_node(NODE_BINARY_OP, "-", create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL), NULL, create_node(NODE_NUMBER, "1", NULL, NULL, NULL)), NULL, NULL);
    }
    ;

print_stmt:
    PRINT LPAREN expression RPAREN SEMICOLON {
        $$ = create_node(NODE_PRINT, NULL, $3, NULL, NULL);
    }
    ;

func_decl:
    FN IDENTIFIER LPAREN params RPAREN block {
        $$ = create_node(NODE_FUNC_DECL, $2, $4, $6, NULL);
    }
    | type_specifier IDENTIFIER LPAREN params RPAREN block {
        $$ = create_node(NODE_FUNC_DECL, $2, $4, $6, NULL);
    }
    ;

params:
    /* empty */ { $$ = NULL; }
    | IDENTIFIER { $$ = create_node(NODE_PARAM_LIST, $1, NULL, NULL, NULL); }
    | IDENTIFIER COMMA params {
        $$ = create_node(NODE_PARAM_LIST, $1, NULL, NULL, $3);
    }
    | type_specifier IDENTIFIER { $$ = create_node(NODE_PARAM_LIST, $2, NULL, NULL, NULL); }
    | type_specifier IDENTIFIER COMMA params {
        $$ = create_node(NODE_PARAM_LIST, $2, NULL, NULL, $4);
    }
    ;

return_stmt:
    RETURN expression SEMICOLON {
        $$ = create_node(NODE_RETURN, NULL, $2, NULL, NULL);
    }
    ;

block:
    LBRACE statement_list RBRACE {
        $$ = create_node(NODE_BLOCK, NULL, $2, NULL, NULL);
    }
    | LBRACE RBRACE {
        $$ = create_node(NODE_BLOCK, NULL, NULL, NULL, NULL);
    }
    ;

expression:
    term { $$ = $1; }
    | expression PLUS term { $$ = create_node(NODE_BINARY_OP, "+", $1, NULL, $3); }
    | expression MINUS term { $$ = create_node(NODE_BINARY_OP, "-", $1, NULL, $3); }
    | expression LT term { $$ = create_node(NODE_BINARY_OP, "<", $1, NULL, $3); }
    | expression GT term { $$ = create_node(NODE_BINARY_OP, ">", $1, NULL, $3); }
    | expression LE term { $$ = create_node(NODE_BINARY_OP, "<=", $1, NULL, $3); }
    | expression GE term { $$ = create_node(NODE_BINARY_OP, ">=", $1, NULL, $3); }
    | expression EQ term { $$ = create_node(NODE_BINARY_OP, "==", $1, NULL, $3); }
    | expression NE term { $$ = create_node(NODE_BINARY_OP, "!=", $1, NULL, $3); }
    | expression AND term { $$ = create_node(NODE_BINARY_OP, "&&", $1, NULL, $3); }
    | expression OR term { $$ = create_node(NODE_BINARY_OP, "||", $1, NULL, $3); }
    ;

term:
    unary { $$ = $1; }
    | term MULT unary { $$ = create_node(NODE_BINARY_OP, "*", $1, NULL, $3); }
    | term DIV unary { $$ = create_node(NODE_BINARY_OP, "/", $1, NULL, $3); }
    | term MOD unary { $$ = create_node(NODE_BINARY_OP, "%", $1, NULL, $3); }
    ;

unary:
    factor { $$ = $1; }
    | MINUS unary { $$ = create_node(NODE_UNARY_OP, "-", $2, NULL, NULL); }
    | NOT unary { $$ = create_node(NODE_UNARY_OP, "!", $2, NULL, NULL); }
    ;

factor:
    NUMBER { $$ = create_node(NODE_NUMBER, $1, NULL, NULL, NULL); }
    | STRING_LITERAL { $$ = create_node(NODE_STRING, $1, NULL, NULL, NULL); }
    | IDENTIFIER { $$ = create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL); }
    | func_call { $$ = $1; }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

func_call:
    IDENTIFIER LPAREN args RPAREN {
        $$ = create_node(NODE_CALL, $1, $3, NULL, NULL);
    }
    ;

args:
    /* empty */ { $$ = NULL; }
    | expression { $$ = create_node(NODE_ARG_LIST, NULL, $1, NULL, NULL); }
    | expression COMMA args {
        $$ = create_node(NODE_ARG_LIST, NULL, $1, NULL, $3);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}
