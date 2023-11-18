%{
	#include "bisonFile.tab.h"
%}

sp [!@$%^&*()-_=+{}\[\]:;<>,.?\/\\|]
anything ([a-zA-Z0-9]|(\n)|(\t)|{sp}|[ ])*

%%
"addHeader"	{return headerStart;}

["][a-zA-Z.]+["] {
	yylval.txt = strtok(yytext, " \"");
	return headerName;
}

"=="		{return isEqual;}
">="		{return isLargeEqual;}
">"			{return isLarge;}
"<="		{return isSmallerEqual;}
"<"			{return isSmaller;}
"!="		{return isNotEqual;}
"if"		{return IF;}
"else"		{return ELSE;}
"("         {return '(';}
")"         {return ')';}
"{"         {return '{';}
"}"         {return '}';}
"+"			{return '+';}
"-"			{return '-';}
"/"			{return '/';}
"*"			{return '*';}
";" 		{return EOL;}
"=" 		{return '=';}
","			{return ',';}
"show" 		{return show;}
"purno" 	{return purno;}
"shuru" 	{return shuru;}
"sesh" 		{return sesh;}
"vogno" 	{return vogno;}
"eval"		{return eval;}
"%"			{return mod;}

[a-zA-Z_][a-zA-Z0-9_]* { yylval.txt = strdup(yytext); return varName; }
[0-9]+ {yylval.num = atoi(yytext);return number;}
[0-9]+\.[0-9]+ { yylval.numd = strtod(yytext, NULL); return numberd; }


(#){anything}(#)	{return comment;}

(\n)	{}
[ ]	{}
[\t] {}
.	{printf("ERROR %s\n",yytext);}
%%

int yywrap(){}