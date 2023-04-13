%{
%}

%%
[ \t\n]+                { }
[\/\**\*\/]             {}
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
">="                    { return GEQ; }
"<="                    { return LEQ; }
"<<"                    { return LSHIFT; }
">>"                    { return RSHIFT; }
"&&"                    { return LAND; }
"||"                    { return LOR; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
">"                     { return GT; }
"<"                     { return LT; }
"+"                     { return PLUS; }
"-"                     { return MOINS; }
"*"                     { return MUL; }
"/"                     { return DIV; }
"!"                     { return NOT; }
"&"                     { return BAND; }
"|"                     { return BOR; }
[0-9]+                  { return CONSTANTE; }
[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFICATEUR; }
.       { return yytext[0]; } 
%%