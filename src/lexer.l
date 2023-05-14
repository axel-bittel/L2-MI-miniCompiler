D [0-9]
L [a-zA-Z_]
LD [a-zA-Z0-9_]
S [ \t\v\n\f]

%{
    #include <string.h>
    #include "compiler.h"
%}

%%

{S}                     {   if (yytext[0] == '\n')
                                yylineno++;
                        }
"/*"[^"*/"]*"*/"        { }
"extern"                { return EXTERN;    }    
"int"                   { return INT;       }
"void"                  { return VOID;      }
"for"                   { return FOR;       }
"while"                 { return WHILE;     }
"if"                    { return IF;        }
"then"                  { return THEN;      }
"else"                  { return ELSE;      }
"switch"                { return SWITCH;    }
"case"                  { return CASE;      }
"default"               { return DEFAULT;   }
"break"                 { return BREAK;     }
"return"                { return RETURN;    }
">="                    { return GEQ;       }
"<="                    { return LEQ;       }
"<<"                    { return LSHIFT;    }
">>"                    { return RSHIFT;    }
"&&"                    { return LAND;      }
"||"                    { return LOR;       }
"=="                    { return EQ;        }
"!="                    { return NEQ;       }
">"                     { return GT;        }
"<"                     { return LT;        }
"+"                     { return PLUS;      }
"-"                     { return MOINS;     }
"*"                     { return MUL;       }
"/"                     { return DIV;       }
"!"                     { return NOT;       }
"&"                     { return BAND;      }
"|"                     { return BOR;       }

{D}+                    { 
                            yylval.inttype = atoi(yytext);
                            return CONSTANTE; 
                        }
[\{\}\,\;\(\)\[\]\:\=]  { return yytext[0]; } 
{L}{LD}*                {             
                            yylval.id = strdup(yytext);
                            return IDENTIFICATEUR; 
                        }

{D}+[{L}\(\{\[]+        {   yyerror(); }
{L}+(^[{L}|{D}])+       {   yyerror(); }
.                       {   yyerror("lexical error"); }
%%