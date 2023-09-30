#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int lerFrase(char *string){
    printf("Digite a frase que deseja criptografar/descriptografar: ");
    fgets(string, MAX, stdin);
    return strlen(string);
}


void imprimir(char *string, int quant){
    int i;
    for(i = 0; i < quant; i++){
        printf("%c", string[i]);
    }
}


void primeiraEtapa(char *string, int quant){
    int i;
    for(i = 0; i < quant; i++){
        switch (string[i]) {
            case 'o':
            case 'O':
                string[i] = '0';
                break;

            case '0':
                string[i] = 'o';
                break;

            case 'a':
            case 'A':
                string[i] = '@';
                break;

            case '@':
                string[i] = 'a';
                break;

            default:
            break;
        }     
    }
}

int fraseParOuImpar(char *str){
    int val;
    val = strlen(str);
    if (val % 2 == 0){
        return 1; 
    }
    else{
        return 0;
    }
}

void segundaEtapa(char *string, int quant, char *string1, char *string2){
    int i, j, res;
    j = 0;
    res = fraseParOuImpar(string);
    for (i = 0; i < quant; i = i + 2){
        string1[j] = string[i]; //Salva as letras impares
        string2[j] = string[quant -(i + res)]; //Salva as letras pares na ordem inversa
        j++;
    }
}


void terceiraEtapa(char *frase,  int quant, char *string1, char *string2){
    int i, j;
    j = 0;
    for (i = 0; i < quant; i = i + 2){
        frase[i + 1] = string1[j];
        frase[i] = string2[j];
        j++;
    }
}


int main(){
    int tamanho;
    char frase[MAX], posicaoImpar[MAX], posicaoPar[MAX];
    tamanho = lerFrase(frase);
    primeiraEtapa(frase, tamanho);
    segundaEtapa(frase, tamanho, posicaoImpar, posicaoPar);
    terceiraEtapa(frase, tamanho, posicaoImpar, posicaoPar);
    imprimir(frase, tamanho);
    return 0;
}