/*
Sistemas Operacionais 
Laboratório 1b - Execício 2

Alunos:
Laura Carolina Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

*/

#include <stdio.h>

int main(int argc, char *argv[]){
    char letras;
    FILE *fileptr1, *fileptr2;
    
    fileptr1 = fopen(argv[1], "r");
    fileptr2 = fopen(argv[2],"w");
    
    if(fileptr1 == NULL || argc != 3){ 
        printf("\nArquivo %s não encontrado!", argv[1]);
        return 0;
    }
    else{
        printf("\nArquivo %s criado com sucesso!", argv[2]);
    }
    
    while(1){ 
        letras = fgetc(fileptr1);
        if(letras != EOF){
            putc(letras, fileptr2);
        }
        else{ 
            break;
        }
    }

    fclose(fileptr1);
    fclose(fileptr2);
    return 0;
}