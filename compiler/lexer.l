%{
#include "ast.h"
#include "parser.tab.h"
#include <string.h>

void store_token(const char* type, const char* value);
int line_num = 1;
int suppress_tokens = 0;
%}

%option noyywrap

DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+(\.{DIGIT}+)?
STRING      \"(\\.|[^\"\\])*\"

%%

"let"           { store_token("KEYWORD", "let"); return LET; }
"if"            { store_token("KEYWORD", "if"); return IF; }
"else"          { store_token("KEYWORD", "else"); return ELSE; }
"while"         { store_token("KEYWORD", "while"); return WHILE; }
"print"         { store_token("KEYWORD", "print"); return PRINT; }
"return"        { store_token("KEYWORD", "return"); return RETURN; }
"fn"            { store_token("KEYWORD", "fn"); return FN; }
"for"           { store_token("KEYWORD", "for"); return FOR; }
"int"           { store_token("KEYWORD", "int"); return TYPE; }
"bool"          { store_token("KEYWORD", "bool"); return TYPE; }
"void"          { store_token("KEYWORD", "void"); return TYPE; }
"float"         { store_token("KEYWORD", "float"); return TYPE; }
"true"          { yylval.sval = strdup("1"); store_token("KEYWORD", "true"); return NUMBER; }
"false"         { yylval.sval = strdup("0"); store_token("KEYWORD", "false"); return NUMBER; }

{ID}            { yylval.sval = strdup(yytext); store_token("IDENTIFIER", yytext); return IDENTIFIER; }
{NUMBER}        { yylval.sval = strdup(yytext); store_token("NUMBER", yytext); return NUMBER; }
{STRING}        { 
                    // Strip quotes
                    yytext[strlen(yytext)-1] = '\0';
                    yylval.sval = strdup(yytext + 1); 
                    store_token("STRING", yytext + 1); 
                    return STRING_LITERAL; 
                }

"="             { store_token("OPERATOR", "="); return ASSIGN; }
"+="            { store_token("OPERATOR", "+="); return ADD_ASSIGN; }
"-="            { store_token("OPERATOR", "-="); return SUB_ASSIGN; }
"*="            { store_token("OPERATOR", "*="); return MUL_ASSIGN; }
"/="            { store_token("OPERATOR", "/="); return DIV_ASSIGN; }
"%="            { store_token("OPERATOR", "%="); return MOD_ASSIGN; }
"+"             { store_token("OPERATOR", "+"); return PLUS; }
"-"             { store_token("OPERATOR", "-"); return MINUS; }
"*"             { store_token("OPERATOR", "*"); return MULT; }
"/"             { store_token("OPERATOR", "/"); return DIV; }
"%"             { store_token("OPERATOR", "%"); return MOD; }
"<"             { store_token("OPERATOR", "<"); return LT; }
">"             { store_token("OPERATOR", ">"); return GT; }
"=="            { store_token("OPERATOR", "=="); return EQ; }
"!="            { store_token("OPERATOR", "!="); return NE; }
"<="            { store_token("OPERATOR", "<="); return LE; }
">="            { store_token("OPERATOR", ">="); return GE; }
"&&"            { store_token("OPERATOR", "&&"); return AND; }
"||"            { store_token("OPERATOR", "||"); return OR; }
"++"            { store_token("OPERATOR", "++"); return INC; }
"--"            { store_token("OPERATOR", "--"); return DEC; }
"!"             { store_token("OPERATOR", "!"); return NOT; }

"("             { store_token("SYMBOL", "("); return LPAREN; }
")"             { store_token("SYMBOL", ")"); return RPAREN; }
"{"             { store_token("SYMBOL", "{"); return LBRACE; }
"}"             { store_token("SYMBOL", "}"); return RBRACE; }
";"             { store_token("SYMBOL", ";"); return SEMICOLON; }
","             { store_token("SYMBOL", ","); return COMMA; }

"//".*          { /* skip single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* skip multi-line comments */ }
"#".*           { /* skip preprocessor directives */ }

\n              { line_num++; }
[ \t\r]+        { /* skip whitespace */ }

.               { if (!suppress_tokens) fprintf(stderr, "Unknown character: %s at line %d\n", yytext, line_num); }

%%

// We will implement token storage in the main.c or here
void store_token(const char* type, const char* value) {
    if (suppress_tokens) return;
    // For now, we print to stderr so the backend can capture it separately
    // Or we store in a global list. Let's use stderr for quick bridge access.
    fprintf(stderr, "TOKEN:%s:%s\n", type, value);
}
