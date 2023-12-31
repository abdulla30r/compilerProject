%{
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
int yyerror(char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
void yyexit(const char *message);

#define MAX_SYMBOLS 100

int funcVarCount = 0;

char *myArray[] = {"purno", "vogno","shobdo","if", "else", "addHeader", "func","loop","shuru","sesh","inc","dec","eval","show","tan","log","log10","pow","cos","sin","ceil","floor","gcd","len","compare","copy","concat"};
int isKeyword(const char *target) {
    int size = sizeof(myArray) / sizeof(myArray[0]);
    for (int i = 0; i < size; ++i) {
        if (strcmp(myArray[i], target) == 0) {
            return 1;
        }
    }
    return 0;
}

void printKeywords(){
    printf("-----KeyWord list-----\n");
    for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); ++i) {
        printf("%s ", myArray[i]);
    }
}

typedef struct {
    char* name;
    char* type;
    int intValue;
    double doubleValue;
    char* strValue;
} SymbolEntry;

SymbolEntry symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
int ifcount = 0;
int isPurno = 0;

void add(char* name,char* type,int a,double b,char* str) {
    SymbolEntry entry;
    entry.name = strdup(name);
    entry.type = strdup(type);
    entry.intValue = a;  
    entry.doubleValue = b;
    entry.strValue = str;
    symbolTable[symbolCount++] = entry;
}

void update(int i,int a,double b,char* str){    
        symbolTable[i].intValue = a;
        symbolTable[i].doubleValue = b;
        symbolTable[i].strValue = str;
}

int find(char* name) {
    for (int i = 0; i < symbolCount; ++i) {
        if (symbolTable[i].name != NULL && strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printSymbolTable() {
    printf("\n-----Symbol Table-----\n");
    for (int i = 0; i < symbolCount; ++i) {
        if(!strcmp(symbolTable[i].type, "purno")){
            printf("Name: %s,Type: %s, Value: %d\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].intValue);
        }

        if(!strcmp(symbolTable[i].type, "vogno")){
            printf("Name: %s,Type: %s, Value: %f\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].doubleValue);
        }

        if(!strcmp(symbolTable[i].type, "shobdo")){
            printf("Name: %s,Type: %s,Value: %s\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].strValue);
        }
        if(!strcmp(symbolTable[i].type, "funcType")){
            printf("Name: %s,Type: Function, Parameter: %d\n",symbolTable[i].name, symbolTable[i].intValue);
        }
        
    }
}

%}

%union {
    int num;
    char* txt;
    double numd;
}

%token headerStart comment purno EOL vogno shobdo eval mod show shuru sesh IF ELSE concat
%token isEqual isLarge isLargeEqual isSmaller isSmallerEqual isNotEqual qt compare
%token LOOP INC DEC FUNC copy len FLOOR CEIL SIN COS TAN LOG POW LOG10 scan GCD
%token <txt> headerName varName
%token <num> number
%token <numd> numberd 

%type <numd> expr val numberParameter
%type <txt> changer funcShuru condition loopOP header dataType stringParameter

%left '+' '-'
%left '/' '*'
%left mod

%%
input:headers program
    | headers functions program
    | cmnt input

functions: function functions
        |function

function: funcShuru '(' parameters ')' '=' isLarge '(' Ret ')' '{'statements'}' {

                                int i = find($1);
                                if(i!=-1){  
                                    update(i,funcVarCount,0.0,"");

                                }
                                funcVarCount = 0;
                                printf("-------------Ended:%s Declaration-------------\n\n",$1);
                            }

parameters: {printf("No parameters");}
        | onePar 
        | onePar ',' parameters

Ret:    {
            printf("\nReturn: No Return\n");
            printf("--Statements inside function--\n");
        }
    | dataType varName {
        printf("\nReturn: %s %s\n",$1,$2);
        printf("--Statements inside function--\n");
        }
onePar: dataType varName    {
    funcVarCount++;
    printf("%s %s ,",$1,$2);
    }

funcShuru: FUNC varName{
            if (find($2) != -1) {
                printf("line %d => Already declared:  %s \n",yylineno, $2);
                yyexit("Error occured");
            } 
            else{
                add($2,"funcType",0,0.0,"");
                printf("\n-------------Started: %s Declaration-------------\n",$2);
                printf("Parameters: ");
                $$ = $2;

            }       
        
    }

cmnt: comment {printf("This is a comment\n");}

headers: header headers
        | header 
        | header cmnt

header: headerStart headerName 
{
   
    printf("Included: %s\n",$2);}

program:start statements end

start : shuru 
{
    printf("\n-------------Started: Main--------------\n\n");}
end : sesh 
{
    printf("\n-------------Ended: Main--------------\n");}

statements : statement statements
        | statement

statement:
        | scan varName EOL{
            if (find($2) != -1) {
                    printf("Waiting: User input in %s",$2);
            } 
            else{
                printf("line %d => Not exist: %s variable",yylineno,$2);
            }
        }
        | cmnt
        | multiVariable
        | variableValueAssign
        | eval expr EOL {printf("Evaluated result is : %f\n",$2);}
        | show value EOL
        | ifshuru '(' condition ')' '{' statements '}' ELSE '{' statements '}' {
                ifcount++;
                printf("Finished: %d.IF-ELSE - %s \n",ifcount,$3);
            }
        | LOOP '(' varName loopOP expr EOL changer expr ')' '{' statements '}'  {
                                int i = find($3);
                                int x;
                                int incSize;
                                int y = (int)$5;
                                if(!strcmp($7,"dec")){
                                    incSize = -1 * (int)$8;
                                }
                                else{
                                    incSize = (int)$8;
                                }
                                if(i!=-1){
                                    if(!strcmp(symbolTable[i].type, "purno")){    
                                        x = symbolTable[i].intValue;
                                    }
                                    else if(!strcmp(symbolTable[i].type, "vogno")){    
                                        x =(int) symbolTable[i].doubleValue;
                                    }
                                    else{
                                        x =0;
                                    }

                                    if(!strcmp($4,"<=")){
                                        for(int m = x;m<=y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp($4,">=")){
                                        for(int m = x;m>=y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp($4,">")){
                                        for(int m = x;m>y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp($4,"<")){
                                        for(int m = x;m<y;m+=incSize){
                                            printf("Loop: Executed for %d\n",m);
                                        }
                                    }
                                }
                            }
        | varName '(' ')' EOL {
                        int i = find($1);
                        if(i!=-1 && symbolTable[i].intValue == 0 && !strcmp(symbolTable[i].type, "funcType")){
                            printf("Call: %s Function called with 0 parameters.\n",symbolTable[i].name);
                        }
                        else{
                            printf("line %d => No Function Found for %s\n",yylineno,$1);
                        }                       
                    }
        | varName '(' callPar ')' EOL {
                        int i = find($1);
                        if(i!=-1 && !strcmp(symbolTable[i].type, "funcType")){
                            if(symbolTable[i].intValue == funcVarCount){
                                printf("Call: %s Function called with %d parameters.\n",symbolTable[i].name,funcVarCount);
                            }
                            else{
                                printf("line %d => Mismatch: Parameter Count =>%s has %d , called with %d\n",yylineno,$1,symbolTable[i].intValue,funcVarCount);
                            }
                        }
                        else{
                            printf("line %d => Not exist: Function %s\n",yylineno,$1);
                        }   

                        funcVarCount = 0;                    
                    }

        | varName '=' concat '(' stringParameter ',' stringParameter ')' EOL     {
                    int i = find($1);
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            char tmp[1000] = "";    
                            strcpy(tmp, $5);
                            strcat(tmp,$7);
                            symbolTable[i].strValue = tmp;
                            printf("Concatenation: %s => %s\n",symbolTable[i].name,symbolTable[i].strValue);
                        }
                    }
                }
        | varName '=' copy '(' stringParameter ')' EOL     {
                    int i = find($1);
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            symbolTable[i].strValue = $5;
                            printf("Copy: %s => %s\n",symbolTable[i].name,symbolTable[i].strValue);
                        }
                    }
                }
        
        | varName '=' compare '(' stringParameter ',' stringParameter ')' EOL     {
                    int i = find($1);
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            if(strcmp($5,$7)){
                                symbolTable[i].strValue = "false";
                            }
                            else{
                                symbolTable[i].strValue = "true";
                            }
                            
                            printf("Compare: %s and %s => %s\n",$5,$7,symbolTable[i].strValue);
                        }
                    }
                }

        | varName '=' len '(' stringParameter  ')' EOL     {
                int i = find($1);
                if(i==-1){
                    printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                }
                else{
                    if(strcmp(symbolTable[i].type, "purno")){    
                        printf("line %d => Mismatch: %s is not purno.\n",yylineno,symbolTable[i].name);
                    }
                    else{
                        symbolTable[i].intValue = strlen($5);
                        printf("Length: %s  => %d\n",$5,symbolTable[i].intValue);
                    }
                }
            }

        | varName '=' FLOOR '(' numberParameter ')' EOL {
                    int i = find($1);
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                    }
                    else{
                        double result;
                        if(!strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                        }
                        else{
                            result = floor($5);
                            if(!strcmp(symbolTable[i].type, "purno")){
                                symbolTable[i].intValue = (int) result;
                                printf("Floor: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                            }

                            if(!strcmp(symbolTable[i].type, "vogno")){
                                symbolTable[i].doubleValue = result;
                                printf("Floor: %f  => %0.0f\n",$5,symbolTable[i].doubleValue);
                            }
                        }
                    }
                }
        | varName '=' CEIL '(' numberParameter ')' EOL {
                int i = find($1);
                if(i==-1){
                    printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                }
                else{
                    double result;
                    if(!strcmp(symbolTable[i].type, "shobdo")){    
                        printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                    }
                    else{
                        result = ceil($5);
                        if(!strcmp(symbolTable[i].type, "purno")){
                            symbolTable[i].intValue = (int) result;
                            printf("Ceil: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                        }

                        if(!strcmp(symbolTable[i].type, "vogno")){
                            symbolTable[i].doubleValue = result;
                            printf("Ceil: %f  => %0.0f\n",$5,symbolTable[i].doubleValue);
                        }
                    }
                }
            }
        | varName '=' SIN '(' numberParameter ')' EOL {
            int i = find($1);
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,$1);
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    float ab = $5 * 3.1416/180;
                    result = sin(ab);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Sine: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Sine: %f  => %f\n",$5,symbolTable[i].doubleValue);
                    }
                }
            }
            }

        | varName '=' COS '(' numberParameter ')' EOL {
            int i = find($1);
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,$1);
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    float ab = $5 * 3.1416/180;
                    result = cos(ab);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Cos: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Cos: %f  => %f\n",$5,symbolTable[i].doubleValue);
                    }
                }
            }
            }

        | varName '=' TAN '(' numberParameter ')' EOL {
            int i = find($1);
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,$1);
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    float ab = $5 * 3.1416/180;
                    result = tan(ab);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Tan: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Tan: %f  => %f\n",$5,symbolTable[i].doubleValue);
                    }
                }
            }
            }

        | varName '=' LOG '(' numberParameter ')' EOL {
            int i = find($1);
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,$1);
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    result = log($5);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Log: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Log: %f  => %f\n",$5,symbolTable[i].doubleValue);
                    }
                }
            }
            }

        | varName '=' LOG10 '(' numberParameter ')' EOL {
            int i = find($1);
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,$1);
            }
            else{
                double result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    result = log10($5);
                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("Log10: %0.2f  => %d\n",$5,symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        symbolTable[i].doubleValue = result;
                        printf("Log10: %f  => %f\n",$5,symbolTable[i].doubleValue);
                    }
                }
            }
            }

        | varName '=' POW '(' numberParameter ',' numberParameter')' EOL {
                int i = find($1);
                if(i==-1){
                    printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                }
                else{
                    double result;
                    if(!strcmp(symbolTable[i].type, "shobdo")){    
                        printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                    }
                    else{
                        result = pow($5,$7);
                        if(!strcmp(symbolTable[i].type, "purno")){
                            symbolTable[i].intValue = (int) result;
                            printf("Power: %f  ^ %f => %d\n",$5,$7,symbolTable[i].intValue);
                        }

                        if(!strcmp(symbolTable[i].type, "vogno")){
                            symbolTable[i].doubleValue = result;
                            printf("Power: %f  ^ %f => %f\n",$5,$7,symbolTable[i].doubleValue);
                        }
                    }
                }
            }
        | varName '=' GCD '(' numberParameter ',' numberParameter')' EOL {
            int i = find($1);
            if(i==-1){
                printf("line %d => Not Exist: variable %s\n",yylineno,$1);
            }
            else{
                int result;
                if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("line %d => Mismatch: %s , type: Shobdo.\n",yylineno,symbolTable[i].name);
                }
                else{
                    int b = (int)$7;
                    int a = (int)$5;
                    while (b != 0) {
                        int temp = b;
                        b = a % b;
                        a = temp;
                    }

                    result = a;

                    if(!strcmp(symbolTable[i].type, "purno")){
                        symbolTable[i].intValue = (int) result;
                        printf("GCD: %d and %d => %d\n",(int)$5,(int)$7,symbolTable[i].intValue);
                    }

                    if(!strcmp(symbolTable[i].type, "vogno")){
                        printf("line %d => Mismatch: Datatype => GCD can only be purno\n",yylineno);
                    }
                }
            }
        }

numberParameter : number {$$ = $1*1.0;}
                | numberd {$$ = $1;}
                | varName   {
                    int i = find($1);
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                    }
                    else{
                        if(!strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not number.\n",yylineno,symbolTable[i].name);
                        }
                        else if(!strcmp(symbolTable[i].type, "purno")){
                            $$ = symbolTable[i].intValue * 1.0 ;
                        }
                        else if(!strcmp(symbolTable[i].type, "vogno")){
                            $$ = symbolTable[i].doubleValue ;
                        }
                    }
                }

stringParameter : qt varName qt {$$ = $2;}
                | varName   {
                    int i = find($1);
                    if(i==-1){
                        printf("line %d => Not Exist: variable %s\n",yylineno,$1);
                    }
                    else{
                        if(strcmp(symbolTable[i].type, "shobdo")){    
                            printf("line %d => Mismatch: %s is not shobdo.\n",yylineno,symbolTable[i].name);
                        }

                        else{
                            if(!strcmp(symbolTable[i].strValue,"")){
                                printf("line %d => Missing value: %s is empty\n",yylineno,symbolTable[i].name);
                            }
                            else{
                                $$ = symbolTable[i].strValue;
                            }
                        }
                    }
                }
callPar: oneCall 
        | oneCall ',' callPar

oneCall : dataType varName {
    funcVarCount++;
    }

changer: INC {$$ = "inc";}
        |DEC {$$ = "dec";}

loopOP: isLarge {$$ = ">";}
    | isLargeEqual {$$ = ">=";}
    | isSmaller {$$ = "<";}
    | isSmallerEqual {$$ = "<=";}


ifshuru: IF {printf("Started: IF BLOCK\n");}
condition : expr isEqual expr 
    {
        if($1 == $3){
            $$ = "true";  
        }
        else{
            $$ = "false";
        }
    }
    | expr isLarge expr {
        if($1 > $3){
            $$ = "true";  
        }
        else{
            $$ = "false";
        }
    }
    | expr isLargeEqual expr {
        if($1 >= $3){
            $$ = "true";  
        }
        else{
            $$ = "false";
        }
    }
    | expr isSmaller expr {
        if($1 < $3){
            $$ = "true";  
        }
        else{
            $$ = "false";
        }
    }
    | expr isSmallerEqual expr {
        if($1 <= $3){
            $$ = "true";  
        }
        else{
            $$ = "false";
        }
    }
    | expr isNotEqual expr {
        if($1 != $3){
            $$ = "true";  
        }
        else{
            $$ = "false";
        }
    }
    |expr {
        if($1>0){
            $$ = "true";
        }
        else{
            $$ = "false";
        }
    }



value: varName 
    {
            int i = find($1);
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    printf("SHOW: %s => %d\n",$1,symbolTable[i].intValue);
                }
                else if(!strcmp(symbolTable[i].type, "shobdo")){    
                    printf("SHOW: %s => %s\n",$1,symbolTable[i].strValue);
                }
                if(!strcmp(symbolTable[i].type, "vogno")){    
                    printf("SHOW: %s => %f\n",$1,symbolTable[i].doubleValue);
                }
            
            }

            else{
                printf("line %d => Not Exist: Variable %s\n",yylineno,$1);
            }
    }
        
expr: val {$$ = $1;}
    | expr '+' expr {$$ = $1 + $3;}
    | expr '-' expr {$$ = $1 - $3;}
    | expr '*' expr {$$ = $1 * $3;}
    | expr '/' expr {$$ = $1 / $3;}
    | expr mod expr 
        {
            int val1 = (int)$1;
            int val2 = (int)$3;
            float val3 = (val1%val2)*1.0;
            $$ = val3;
        }

val: number {$$ = $1*1.0;}
    | numberd {$$ = $1;}
    | qt varName qt 
        {
                printf("line %d => Not a number: %s => shobdo\n",yylineno, $2);
                $$ = 0.0;
            }
    | varName 
        {
            int i = find($1);
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    $$ = symbolTable[i].intValue * 1.0;
                }
                if(!strcmp(symbolTable[i].type, "vogno")){    
                    $$ = symbolTable[i].doubleValue;
                }
                else{
                    printf("line %d => Not a number: %s => shobdo \n",yylineno, $1);
                    $$ = 0.0;
                }           
            }
            else{
                printf("line %d => Not Declared: Variable %s\n",yylineno,$1);
            }
        }


multiVariable: dataType varNames

dataType : purno {isPurno = 1; $$ = "purno";}
        | vogno {isPurno = 0;$$ = "vogno";}
        | shobdo {isPurno = -1;$$ = "shobdo";}

varNames: oneVar ',' varNames
        |oneVar EOL

oneVar: varName 
        {
            if (find($1) != -1) {
                    printf("line %d => Already declared: Variable %s \n",yylineno, $1);
            } 
            else{
                if(isPurno==1){
                    add($1,"purno",0,0.0,"");
                    printf("Created: %s => purno\n", $1);
                }
                else if(isPurno==0){
                    add($1,"vogno",0,0.0,"");
                    printf("Created : %s =>  vogno\n",$1);
                }
                else if(isPurno==-1){
                    add($1,"shobdo",0,0.0,"");
                    printf("Created : %s =>  shobdo\n",$1);
                }
            }
        }

        | varName '=' number {
                    if (find($1) != -1) {
                        printf("line %d => Already declared: Variable %s \n",yylineno, $1);
                    } 
                    else{
                        if(isPurno==1){
                            add($1,"purno",$3,0.0,"");
                            printf("Created: %s: %d => purno\n", $1,$3);
                        }
                        else if(isPurno==0){
                            printf("line %d => Mismatch: %s => vogno , value %d: purno\n",yylineno,$1, $3);
                        }
                        else if(isPurno==-1){
                            printf("line %d => Mismatch: %s => shobdo , value %d: purno\n",yylineno,$1, $3);
                        }
                    }
                }
        | varName '=' numberd {
                    if (find($1) != -1) {
                        printf("line %d => Already declared: Variable %s \n",yylineno, $1);
                    } 
                    else{
                        if(isPurno==0){
                            add($1,"vogno",0,$3,"");
                            printf("Created: %s: %f => vogno\n", $1,$3);
                        }
                        else if(isPurno == 1){
                            printf("line %d => Mismatch: %s => purno , value %f: vogno\n",yylineno,$1,$3);
                        }
                        else if(isPurno ==-1) {
                            printf("line %d => Mismatch: %s => shobdo , value %f: vogno\n",yylineno,$1,$3);
                        }
                    }
            }

        | varName '=' qt varName qt {
                    if (find($1) != -1) {
                        printf("line %d => Already declared: Variable %s \n",yylineno, $1);
                    } 
                    else{
                        if(isPurno==-1){
                            add($1,"shobdo",0,0.0,$4);
                            printf("Created: %s: %s => shobdo\n", $1,$4);
                        }
                        else if (isPurno==1){
                            printf("line %d => Mismatch: %s => purno , value %s: shobdo\n",yylineno,$1,$4);
                        }
                        else if (isPurno==0){
                            printf("line %d => Mismatch: %s => vogno , value %s: shobdo\n",yylineno,$1,$4);
                        }
                    }
        }

variableValueAssign : varName '=' number EOL 
                        {
                                        int i = find($1);
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "purno")){
                                                update(i,$3,0.0,"");
                                                printf("Assign: %d => variable %s\n",$3,$1);
                                            }
                                            else{
                                                printf("line %d => Mismatch: %d is purno =>variable %s is %s\n",yylineno,$3,$1,symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("line %d => Not Declared : variable %s\n",yylineno,$1);
                                        }
                                    }
                    |varName '=' numberd EOL {
                                        int i = find($1);
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "vogno")){
                                                update(i,0,$3,"");                                                    
                                                printf("Assign: %f => variable %s\n",$3,$1);
                                            }
                                            else{
                                                printf("line %d => Mismatch: %f is vogno =>variable %s is %s\n",yylineno,$3,$1,symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("line %d => Not Declared : variable %s\n",yylineno,$1);
                                        }
                                    }
                    
                    |varName '=' expr EOL {
                                        int i = find($1);
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "vogno")){
                                                update(i,0,$3,"");
                                                printf("Assign: %f => variable %s\n",$3,$1);
                                            }
                                            else {
                                                int val = (int)$3;
                                                update(i,val,0.0,"");
                                                printf("Assign: %d => variable %s\n",val,$1);
                                            }
                                        }
                                        else{
                                            printf("line %d => Not Declared : variable %s\n",yylineno,$1);
                                        }
                                    }

                    |varName '=' qt varName qt EOL{
                                    int i = find($1);
                                    if(i!=-1){
                                        if(!strcmp(symbolTable[i].type, "shobdo")){
                                            update(i,0,0.0,$4);
                                            printf("Assign: %s => variable %s\n",$4,$1);
                                        }
                                        else {
                                            printf("line %d => Mismatch: %s is shobdo =>variable %s is %s\n",yylineno,$4,$1,symbolTable[i].type);
                                        }
                                        
                                    }
                                    else{
                                        printf("line %d => Not Declared : variable %s\n",yylineno,$1);
                                    }
                    }

%%

int yyerror(char *s) {
    printf("Error at line %d: => %s\n",yylineno,s);
    return 0;
}

void yyexit(const char *message) {
    fprintf(stderr, "Exit: %s\n", message);
    exit(EXIT_SUCCESS);
}

int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    yyparse();

    printSymbolTable();
    printKeywords();
}