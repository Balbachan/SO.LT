/*
Sistemas Operacionais 
Laboratório 2 - Execício 1

Alunos:
Laura Carolina Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

*/

#include <stdio.h>

int main(int argc, char *argv[]){
    char letras;
    FILE *fileptr;

    fileptr = fopen(argv[1], "r");

    if(fileptr == NULL || argc != 2){ 
        printf("Arquivo não encontrado!");
        return 0;
    }

    while(1){ 
        letras = fgetc(fileptr);
        if(letras == EOF){
            break;
        }
        printf("%c", letras);
    }
    fclose(fileptr);
    return 0;
}