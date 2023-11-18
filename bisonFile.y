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

%token headerStart comment purno EOL vogno
%token <txt> headerName
%type <txt> header
%token <txt> varName
%token <num> number
%token <numd> numberd

%%
input:headers program

headers: 
        header headers
        |header 

header: headerStart headerName {{printf("Included: %s\n",$2);}}

program:
        | statements

statements : statement statements
        |   statement

statement: comment {printf("This is a comment\n");}
        | multiVariable
        | variableValueAssign

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
                            printf("Created: %s => purno\n", $1);
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
                            printf("Created: %s => vogno\n", $1);
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