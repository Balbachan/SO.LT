*****

Sistemas Operacionais 
Laboratório 2a  

Alunos:
Laura Carolina Balbachan dos Santos (32173008)
Tiago Caspirro Cardoso (32165978)

*****

Execício 1) 
Não, as mensagens nem sempre estão ordenadas pelo valor de i.
Apesar das ID's dos processos respeitarem a lógica que as cabe maioria das vezes, 
sendo essao processo-pai ser a ID decrementada do processo correspondente e 
o processo-filho a ID incrementada do processo, há duas exceções:
1. O processo-pai, às vezes, resulta em 9 ou 10;
2. O último processo tem como zero a ID do processo-filho.

Execício 2) 
Nenhuma mudança de saída foi observada entre a chamada sys.stdout e sys.stderr. Ao usar o sys.stderr, por não se tratar de um erro, imprimiu os resultados normalmente.
