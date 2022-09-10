#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <regex.h>

void regex_error(){
    printf("Could not compile regex\n");
    exit(1);
}

int isInteger(char* str){
    regex_t regex;
    int regex_not_match;

    /* Tenta compilar o código em regex para reconhecer um inteiro*/
    regex_not_match = regcomp(&regex, "[0-9]+", REG_EXTENDED);
    if(regex_not_match) regex_error; // Se o código não conseguir ser compilado terminamos o programa com um erro
    regex_not_match = regexec(&regex, str, 0, NULL, 0); // Tentamos aplicar o regex na string de entrada
    if(regex_not_match) return 0;// Caso não dê certo a string não é um inteiro
    return 1; // A string representa um inteiro
}

int isFloat(char* str){
    regex_t regex;
    int regex_not_match;

    /* Tenta compilar o código em regex para reconhecer float*/
    regex_not_match = regcomp(&regex, "[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)", REG_EXTENDED);
    if(regex_not_match) regex_error; // Se o código não conseguir ser compilado terminamos o programa com um erro
    regex_not_match = regexec(&regex, str, 0, NULL, 0); // Tentamos aplicar o regex na string de entrada
    if(regex_not_match) return 0; // Caso não dê certo a string não é um float
    return 1; // A string representa um float
}

int is_attr(char* str){
    /* Verifica se é um operador de atribuição */
    if (str == "<-") return 1;
    return 0;
}

int is_artm(char* str){
    /* Verifica se é um operador aritimetico */
    if (str == "+" |
        str == "-" |
        str == "*" |
        str == "/") return 1;
    return 0;
}

int is_relational(char* str){
    /* Verifica se é um operador relacional */
    if (str == "==" |
        str == "!=" |
        str == ">"  |
        str == "<"  |
        str == ">=" |
        str == "<=") return 1;
    return 0;
}

int main(){
    printf("%d\n", isInteger("1000"));      //1
    printf("%d\n", isInteger(".001"));      //1
    printf("%d\n", isInteger("100"));       //1
    printf("%d\n", isInteger("10.10"));     //1
    printf("%d\n", isInteger(".90"));       //1
    printf("%d\n", isInteger("90."));       //1
}

