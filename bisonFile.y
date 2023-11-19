%{
#include<stdio.h>
#include <string.h>
int yyerror(char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;

#define MAX_SYMBOLS 100

char *myArray[] = {"purno", "vogno","shobdo","if", "else", "addHeader", "func","loop","shuru","sesh","inc","dec","eval","show"};
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
            printf("Name: %s,Type: %s,Value: %d\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].intValue);
        }

        if(!strcmp(symbolTable[i].type, "vogno")){
            printf("Name: %s,Type: %s,Value: %f\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].doubleValue);
        }

        if(!strcmp(symbolTable[i].type, "shobdo")){
            printf("Name: %s,Type: %s,Value: %s\n",
               symbolTable[i].name,symbolTable[i].type,
               symbolTable[i].strValue);
        }
        
    }
}

int isPurno = 0;

%}


%union {
    int num;
    char* txt;
    double numd;
}

%token headerStart comment purno EOL vogno shobdo eval mod show shuru sesh IF ELSE
%token isEqual isLarge isLargeEqual isSmaller isSmallerEqual isNotEqual qt
%token LOOP INC DEC FUNC
%token <txt> headerName
%type <txt> header
%token <txt> varName
%token <num> number
%token <numd> numberd
%type <numd> expr
%type <numd> val
%type <txt> condition
%type <txt> changer
%type <txt> loopOP
%left '+' '-'
%left '/' '*'
%left mod

%%
input:headers program
    | headers functions program
    | cmnt input

functions: func functions
        |func
func: FUNC varName '(' ')' '{'statements'}' {printf("%s Function declared\n",$2);}
cmnt: comment {printf("This is a comment\n");}

headers: header headers
        | header 
        | header cmnt

header: headerStart headerName {{printf("Included: %s\n",$2);}}

program:
        |start statements end

start : shuru {printf("-------------Started: Main--------------\n\n");}
end : sesh {printf("\n-------------Ended: Main--------------\n");}


statements : statement statements
        | statement

statement:
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
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp($4,">=")){
                                        for(int m = x;m>=y;m+=incSize){
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp($4,">")){
                                        for(int m = x;m>y;m+=incSize){
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                    if(!strcmp($4,"<")){
                                        for(int m = x;m<y;m+=incSize){
                                            printf("Loop executed for %d\n",m);
                                        }
                                    }
                                }
                            }
        | varName '(' ')' EOL {printf("%s Function Called\n",$1);}
        
        changer: INC {$$ = "inc";}
                |DEC {$$ = "dec";}

        loopOP: isLarge {$$ = ">";}
            | isLargeEqual {$$ = ">=";}
            | isSmaller {$$ = "<";}
            | isSmallerEqual {$$ = "<=";}


ifshuru: IF {printf("Started: IF BLOCK\n");}
condition : expr isEqual expr {
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



value: varName {
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
                printf("Not Exist: Variable %s\n",$1);
            }
}
        
expr: val {$$ = $1;}
    | expr '+' expr {$$ = $1 + $3;}
    | expr '-' expr {$$ = $1 - $3;}
    | expr '*' expr {$$ = $1 * $3;}
    | expr '/' expr {$$ = $1 / $3;}
    | expr mod expr {
        int val1 = (int)$1;
        int val2 = (int)$3;
        float val3 = (val1%val2)*1.0;
        $$ = val3;
    }

val: number {$$ = $1*1.0;}
    | numberd {$$ = $1;}
    | qt varName qt {
                printf("Not a number: %s => shobdo\n",$2);
                $$ = 0.0;
            }
    | varName {
            int i = find($1);
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    $$ = symbolTable[i].intValue * 1.0;
                }
                if(!strcmp(symbolTable[i].type, "vogno")){    
                    $$ = symbolTable[i].doubleValue;
                }
                else{
                    printf("Not a number: %s => shobdo \n",$1);
                    $$ = 0.0;
                }           
            }
            else{
                printf("Not Declared: Variable %s\n",$1);
            }
        }


multiVariable: dataType varNames

dataType : purno {isPurno = 1;}
        | vogno {isPurno = 0;}
        | shobdo {isPurno = -1;}

varNames: oneVar ',' varNames
        |oneVar EOL

oneVar: varName {
            if (find($1) != -1) {
                    printf("Already declared: Variable %s \n", $1);
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
            }
        }

        | varName '=' number {
                    if (find($1) != -1) {
                        printf("Already declared: Variable %s \n", $1);
                    } 
                    else{
                        if(isPurno==1){
                            add($1,"purno",$3,0.0,"");
                            printf("Created: %s: %d => purno\n", $1,$3);
                        }
                        else if(isPurno==0){
                            printf("Mismatch: %s => vogno , value %d: purno\n",$1, $3);
                        }
                        else if(isPurno==-1){
                            printf("Mismatch: %s => shobdo , value %d: purno\n",$1, $3);
                        }
                    }
                }
        | varName '=' numberd {
                    if (find($1) != -1) {
                        printf("Already declared: Variable %s \n", $1);
                    } 
                    else{
                        if(isPurno==0){
                            add($1,"vogno",0,$3,"");
                            printf("Created: %s: %f => vogno\n", $1,$3);
                        }
                        else if(isPurno == 1){
                            printf("Mismatch: %s => purno , value %f: vogno\n",$1,$3);
                        }
                        else if(isPurno ==-1) {
                            printf("Mismatch: %s => shobdo , value %f: vogno\n",$1,$3);
                        }
                    }
            }

        | varName '=' qt varName qt {
                    if (find($1) != -1) {
                        printf("Already declared: Variable %s \n", $1);
                    } 
                    else{
                        if(isPurno==-1){
                            add($1,"shobdo",0,0.0,$4);
                            printf("Created: %s: %s => shobdo\n", $1,$4);
                        }
                        else if (isPurno==1){
                            printf("Mismatch: %s => purno , value %s: shobdo\n",$1,$4);
                        }
                        else if (isPurno==0){
                            printf("Mismatch: %s => vogno , value %s: shobdo\n",$1,$4);
                        }
                    }
        }

variableValueAssign : varName '=' number EOL {
                                        int i = find($1);
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "purno")){
                                                update(i,$3,0.0,"");
                                                printf("Assign: %d => variable %s\n",$3,$1);
                                            }
                                            else{
                                                printf("Mismatch: %d is purno =>variable %s is %s\n",$3,$1,symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("Not Declared : variable %s\n",$1);
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
                                                printf("Mismatch: %f is vogno =>variable %s is %s\n",$3,$1,symbolTable[i].type);
                                            }
                                        }
                                        else{
                                            printf("Not Declared : variable %s\n",$1);
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
                                            printf("Not Declared : variable %s\n",$1);
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
                                            printf("Mismatch: %s is shobdo =>variable %s is %s\n",$4,$1,symbolTable[i].type);
                                        }
                                        
                                    }
                                    else{
                                        printf("Not Declared : variable %s\n",$1);
                                    }
                    }

%%


int yyerror(char *s) {
    printf("Error at line %d: => %s\n",yylineno,s);
    return 0;
}

int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    yyparse();

    //printSymbolTable();
    //printKeywords();
}