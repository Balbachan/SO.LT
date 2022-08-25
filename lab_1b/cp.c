/*
Sistemas Operacionais 
Laboratório 2 - Execício 2

Alunos:
Laura Carolina Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

*/

#include <stdio.h>

int main(int argc, char *argv[]){
    char letras;
    FILE *fileptr1, *fileptr2;

    if((fileptr1 = fopen(argv[1], "r")) == NULL){ 
        printf("\nArquivo %s não encontrado!", argv[1]);
        exit(1);
    }
    
    if((fileptr2 = fopen(argv[2], "r+")) != NULL){
        printf("\nNão foi possível criar o arquivo %s.", argv[2]);
        exit(1);
    }
    else{
        printf("\nArquivo %s criado com sucesso!", argv[2]);
    }
    
    
    while(1){ 
        letras = fgetc(fileptr1);
        if(letras != EOF){
            fprintf(fileptr2, letras);
        }
        else{ 
            break;
        }
    }

    fclose(fileptr1);
    fclose(fileptr2);
    return 0;
}