/*
Sistemas Operacionais 
Laboratório 2 - Execício 2

Alunos:
Laura Carolina Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

*/

#include <stdio.h>

int main(int argc, char *argv1[], char *argv2[]){
    char letras;
    FILE *fileptr1, *fileptr2;

    if((fileptr1 = fopen(argv1[1], "r")) == NULL){ 
        printf("Arquivo não encontrado!");
        exit(1);
    }
    else{
        fileptr2 = fopen(argv2[1], "w");
    }

    while(1){ 
        letras = fgetc(fileptr1);
        if(letras == EOF){
            break;
        }
        printf("%c", letras);
    }

    fclose(fileptr1);
    return 0;
}