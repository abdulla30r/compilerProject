%{
#include<stdio.h>
#include <string.h>
int yyerror(char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;

#define MAX_SYMBOLS 100

typedef struct {
    char* name;
    char* type;
    int intValue;
    double doubleValue;
} SymbolEntry;

SymbolEntry symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
int ifcount = 0;

void add(char* name,char* type,int a,double b) {
    SymbolEntry entry;
    entry.name = strdup(name);
    entry.type = strdup(type);
    entry.intValue = a;  
    entry.doubleValue = b;
    symbolTable[symbolCount++] = entry;
}

void update(int i,int a,double b){    
        symbolTable[i].intValue = a;
        symbolTable[i].doubleValue = b;
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
    printf("\nSymbol Table:\n");
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
        
    }
}

int isPurno = 0;

%}

%union {
    int num;
    char* txt;
    double numd;
}

%token headerStart comment purno EOL vogno eval mod show shuru sesh IF ELSE
%token isEqual isLarge isLargeEqual isSmaller isSmallerEqual isNotEqual
%token <txt> headerName
%type <txt> header
%token <txt> varName
%token <num> number
%token <numd> numberd
%type <numd> expr
%type <numd> val
%type <txt> condition
%left '+' '-'
%left '/' '*'
%left mod

%%
input:headers program
    | cmnt input

cmnt: comment {printf("This is a comment\n");}

headers: header headers
        | header 
        | header cmnt

header: headerStart headerName {{printf("Included: %s\n",$2);}}

program:
        |start statements end

start : shuru {printf("-------------Program started--------------\n");}
end : sesh {printf("-------------Program Ended--------------\n");}


statements : statement statements
        | statement

statement: cmnt
        | multiVariable
        | variableValueAssign
        | eval expr EOL {printf("Evaluated result is : %f\n",$2);}
        | show value EOL
        | ifshuru '(' condition ')' '{' statements '}' ELSE '{' statements '}' {
                ifcount++;
                printf("Finished: %d.IF-ELSE - %s \n",ifcount,$3);
        }

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
        if($1 > $3){
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

value: varName {
    int i = find($1);
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    printf("%d\n",symbolTable[i].intValue);
                }
                else{
                    printf("%f\n",symbolTable[i].doubleValue);
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
    | varName {
            int i = find($1);
            if(i!=-1){
                if(!strcmp(symbolTable[i].type, "purno")){    
                    $$ = symbolTable[i].intValue * 1.0;
                }
                else{
                    $$ = symbolTable[i].doubleValue;
                }
            
            }
        }


multiVariable: dataType varNames

dataType : purno {isPurno = 1;}
        | vogno {isPurno = 0;}

varNames: oneVar ',' varNames
        |oneVar EOL

oneVar: varName {
            if (find($1) != -1) {
                    printf("Already declared: Variable %s \n", $1);
            } 
            else{
                if(isPurno){
                    add($1,"purno",0,0.0);
                    printf("Created: %s => purno\n", $1);
                }
                else{
                    add($1,"vogno",0,0.0);
                    printf("Created : %s =>  vogno\n",$1);
                }
            }
        }

        | varName '=' number {
                    if (find($1) != -1) {
                        printf("Already declared: Variable %s \n", $1);
                    } 
                    else{
                        if(isPurno){
                            add($1,"purno",$3,0.0);
                            printf("Created: %s: %d => purno\n", $1,$3);
                        }
                        else{
                            printf("Mismatch: %s => vogno , value %d: purno\n",$1, $3);
                        }
                    }
                }
        | varName '=' numberd {
                    if (find($1) != -1) {
                        printf("Already declared: Variable %s \n", $1);
                    } 
                    else{
                        if(!isPurno){
                            add($1,"vogno",0,$3);
                            printf("Created: %s: %f => vogno\n", $1,$3);
                        }
                        else{
                            printf("Mismatch: %s => purno , value %f: vogno\n",$1,$3);
                        }
                    }
        }


variableValueAssign : varName '=' number EOL {
                                        int i = find($1);
                                        if(i!=-1){
                                            if(!strcmp(symbolTable[i].type, "purno")){
                                                update(i,$3,0.0);
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
                                                update(i,0,$3);                                                    
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
                                                update(i,0,$3);
                                                printf("Assign: %f => variable %s\n",$3,$1);
                                            }
                                            else {
                                                int val = (int)$3;
                                                update(i,val,0.0);
                                                printf("Assign: %d => variable %s\n",val,$1);
                                            }
                                        }
                                        else{
                                            printf("Not Declared : variable %s\n",$1);
                                        }
                                    }

%%


int yyerror(char *s) {
    printf("%s\n", s);
    return 0;
}

int main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    yyparse();

    printSymbolTable();
}