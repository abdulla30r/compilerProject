%{
	#include "bisonFile.tab.h"
%}

sp [!@$%^&*()-_=+{}\[\]:;<>,.?\/\\|]
anything ([a-zA-Z0-9]|(\n)|{sp}|[ ])*

%%
"addHeader"	{return headerStart;}

["][a-zA-Z.]+["] {
	yylval.txt = strtok(yytext, " \"");
	return headerName;
}

"purno" 	{return purno;}
"vogno" 	{return vogno;}

[a-zA-Z_][a-zA-Z0-9_]* { yylval.txt = strdup(yytext); return varName; }
[0-9]+ {yylval.num = atoi(yytext);return number;}
[0-9]+\.[0-9]+ { yylval.numd = strtod(yytext, NULL); return numberd; }


(#){anything}(#)	{return comment;}
(;) {return EOL;}
(=) {return '=';}
(,) {return ',';}
(\n)	{}
[ ]	{}
[\t] {}
.	{printf("ERROR %s\n",yytext);}
%%

int yywrap(){}