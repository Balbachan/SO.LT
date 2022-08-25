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

    if((fileptr = fopen(argv[1], "r")) == NULL){ 
        printf("Arquivo não encontrado!");
        exit(1);
    }

    while(1){ 
        letras = fgetc(fileptr);
        if(letras == EOF){
            break;
        }
        printf("\n%c", letras);
    }
    fclose(fileptr);
    return 0;
}