%{
	#include "bisonFile.tab.h"
%}

%option yylineno

sp [!@$%^&*()-_=+{}\[\]:;<>,.?\/\\|]
anything ([a-zA-Z0-9]|(\n)|(\t)|{sp}|[ ])*

%%
"addHeader"	{return headerStart;}

["][a-zA-Z.]+["] {
	yylval.txt = strtok(yytext, " \"");
	return headerName;
}

"sin"		{return SIN;}
"ceil"		{return CEIL;}
"floor"		{return FLOOR;}
"len"		{return len;}
"compare"	{return compare;}
"copy"		{return copy;}
"concat"	{return concat;}
[`]			{return qt;}
"func"		{return FUNC;}
"inc"		{return INC;}
"dec"		{return DEC;}
"=="		{return isEqual;}
">="		{return isLargeEqual;}
">"			{return isLarge;}
"<="		{return isSmallerEqual;}
"<"			{return isSmaller;}
"!="		{return isNotEqual;}
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
"loop"		{return LOOP;}
"if"		{return IF;}
"else"		{return ELSE;}
"show" 		{return show;}
"purno" 	{return purno;}
"shuru" 	{return shuru;}
"sesh" 		{return sesh;}
"vogno" 	{return vogno;}
"shobdo" 	{return shobdo;}
"eval"		{return eval;}
"%"			{return mod;}

[a-zA-Z_][a-zA-Z0-9_]* { yylval.txt = strdup(yytext); return varName; }
[0-9]+ {yylval.num = atoi(yytext);return number;}
[0-9]+\.[0-9]+ { yylval.numd = strtod(yytext, NULL); return numberd; }

(#){anything}(#)	{return comment;}

(\n)	{}
[ ]		{}
[\t] 	{}
.	{printf("ERROR %s\n",yytext);}
%%

int yywrap(){}