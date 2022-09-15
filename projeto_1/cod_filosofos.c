/*
Projeto 01 - Sistemas Operacionais 
O jantar dos filósofos 

Alunos: 
Laura C. Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

*/  
  
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
 
// essencialmente, o número de threads
#define total_filo 5

// possíveis estados dos filósofos 
#define comendo 0
#define faminto 1
#define pensando 2
