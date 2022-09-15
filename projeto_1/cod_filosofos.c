/*
Projeto 01 - Sistemas Operacionais 
O jantar dos filósofos 

Alunos: 
Laura C. Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

--------------------------------------------------------------------------------------------------
b. Explique, em cada trecho do seu programa, como é resolvido o problema da comunicação inter processos (IPC).
   De maneira categórica, o problema da comunicação inter processos é resolvida através da utilização dos 
   semáforos, que através da operação "wait()" e "post()" garante, respectivamente, que o filósofo tenha que 
   esperar a sua vez de pegar os talheres e, depois de comer, colocá-los de volta na mesa.

*/ 

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>

// CONSTANTES 
#define TOTAL 5    // essencialmente, o número de filósofos e garfos

#define COMENDO  0  // identificação do estado "comendo"
#define FAMINTO  1  // identificação do estado de fome
#define PENSANDO 2  // identificação do estado pensativo
 
#define DIREITA (filo_num + 1) % TOTAL   // encontra o filósofo à direita  
#define ESQUERDA (filo_num + 4) % TOTAL  // encontra o filósofo à esquerda

// VARIÁVEIS 
int filo_estado[TOTAL];                  //estado de cada filósofo
int filo_id[TOTAL] = {0, 1, 2, 3, 4};    // ID de cada filósofo
sem_t S[TOTAL];                          // utilização de semáforos para representar os talheres
sem_t semaforo;                          // utilização de semáforos para representar filósofos

// PROTOTIPAÇÃO 
void * filosofo(void *num);  // "estrutura" das ações do filósofo
void testar_vizinhos (int);  // checa se os vizinhos estão comento 
void pegar_garfo(int);       // ação de pegar os talheres 
void devolver_garfo(int);    // ação de devolver os talheres 

// ----------------------------------------------------------------------------------------------

void testar_vizinhos(int filo_num){
    if(filo_estado[filo_num] == FAMINTO && filo_estado[ESQUERDA] != COMENDO && filo_estado[DIREITA] != COMENDO){
         
        filo_estado[filo_num] = COMENDO;  // define o estado do filósofo como "comendo"
            
        sem_wait(&S[filo_num]);  // tenta pegar o garfo que está na mesma posição 
        printf("O filósofo %d pegou o garfo %d.\n", filo_num, filo_num);

        sleep(1);  // pausa de 1 segundo

        sem_wait (&S[(filo_num + 1) % TOTAL]);  // tenta pegar o garfo à sua direita 
        printf("O filósofo %d pegou o garfo %d\n.", filo_num,(filo_num + 1) % TOTAL);
        printf("O filósofo %d está comendo.\n", filo_num); // pegou os talheres, consegue comer
        
        sem_post(&S[filo_num]);  // volta para o estado original
    }
}


void pegar_garfo(int filo_num){
    sem_wait(&semaforo);  // filósofo solicita o garfo

    filo_estado[filo_num] == FAMINTO; // define o estado do filósofo como "faminto"
    printf("O filósofo %d está com fome.\n", filo_num); // o filósofo começa com fome
    
    sleep(1);  // pausa de 1 segundo
    
    testar_vizinhos(filo_num);  // checa se os vizinhos não estão comendo 
    
    sem_post(&semaforo);  // solicitação do filósofo termina
    
    sem_wait(&S[filo_num]);  // caso não dê para comer, espera
    
    sleep(1);  // pausa de 1 segundo
}


void devolver_garfo(int filo_num){
    sem_wait(&semaforo);  // filósofo solicita o garfo
    
    sem_post(&S[filo_num]);  // sinaliza que vai devolver o garfo
    printf("O filósofo %d devolveu o garfo %d.\n", filo_num, filo_num);
    sem_post (&S[(filo_num + 1) % TOTAL]); // devolve o segundo garfo
    printf("O filósofo %d devolveu o garfo %d.\n", filo_num,(filo_num + 1) % TOTAL);
    
    sleep(1);  // pausa de 1 segundo
    filo_estado[filo_num] = PENSANDO;
    printf("O filósofo %d está pensando.\n", filo_num); // filósofo volta a pensar 
    
    testar_vizinhos(ESQUERDA);  // testa o vizinho da esquerda
    testar_vizinhos(DIREITA);   // testa o vizinho da direita
    
    sem_post(&semaforo);  // solicitação do filósofo termina
}


// neste problema, todo filósofo é "composto" por 5 fases: estar com fome, pegar os talheres,
// comer, devolver os talheres e pensar. 
void * filosofo(void *num){
    while(1){
        int *i = num;
        pegar_garfo(*i);     // aqui ele está com fome, pega os talheres e come
        devolver_garfo(*i);  // aqui ele devolve os talheres e volta a pensar
    }
}


int main(){
    int i;
    pthread_t thread_id[TOTAL];  // permite identificar threads 
    
    sem_init(&semaforo, 0, 1);   // inicialização do semáforo semaforo
    
    for(i = 0; i < TOTAL; i++)   // inicialização do semáforo S
        sem_init(&S[i], 0, 1);

    for(i = 0; i < TOTAL; i++){  // inicia as threads 
        pthread_create(&thread_id[i], NULL, filosofo, &filo_id[i]); 
    }

    for(i = 0; i < TOTAL; i++)  // suspende a execução das threads
        pthread_join(thread_id[i], NULL);

}
