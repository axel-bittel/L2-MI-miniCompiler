%{
%}

%%
"extern"                { return EXTERN; }
"int"                   { return INT; }
"void"                  { return VOID; }
"for"                   { return FOR; }
"while"                 { return WHILE; }
"if"                    { return IF; }
"then"                  { return THEN; }
"else"                  { return ELSE; }
"switch"                { return SWITCH; }
"case"                  { return CASE; }
"default"               { return DEFAULT; }
"break"                 { return BREAK; }
"return"                { return RETURN; }
"("                     { return LPAR; }
")"                     { return RPAR; }
"{"                     { return LBRACK; }
"}"                     { return RBRACK; }
"["                     { return LBRACE; }
"]"                     { return RBRACE; }
";"                     { return SEMICOLON; }
"/*"                    { return BEG_COMMENT; }
"*/"                    { return END_COMMENT; }
">="                    { return GTE; }
"<="                    { return LTE; }
"<<"                    { return LSHIFT; }
">>"                    { return RSHIFT; }
"&&"                    { return AND; }
"||"                    { return OR; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
">"                     { return GT; }
"<"                     { return LT; }
"="                     { return EQUAL; }
"+"                     { return ADD; }
"-"                     { return MIN; }
"*"                     { return MULT; }
"/"                     { return DIV; }
"!"                     { return NOT; }
"&"                     { return BITAND; }
"|"                     { return BITOR; }
","                     { return COMMA; }
[0-9]+                  { return CONST; }
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; }
[ \t\n]+                { }
%%