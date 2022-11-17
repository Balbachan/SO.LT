/*
Sistemas Operacionais 
Professor Eduardo Ferreira dos Santos
Projeto 2 

Alunos: 
	Laura C. Balbachan dos Santos (32173008)
	Tiago Caspirro Cardoso (32165978)

*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx; 

struct Conta {
    int valorConta{100}; 
};

void transfValor(int valor, Conta& de, Conta& para) {
    mtx.lock();
    if(de.valorConta >= valor) {  
        cout << "Transferencia realizada com sucesso.\n";
        de.valorConta -= valor;
        para.valorConta += valor;
    }
    else {
        cout << "Não é possível realizar essa transferencia.\n";
    }
    mtx.unlock();
};

// Criar função de adicionar fundos em uma conta (alterar o 100 inicial)

int main() { 
    Conta contaDe;
    Conta contaPara; 

    thread thr1(transfValor, 80, ref(contaDe), ref(contaPara));
    thread thr2(transfValor, 120, ref(contaPara), ref(contaDe)); 

    thr1.join();
    thr2.join();

    cout << "Total conta De: " << contaDe.valorConta << endl;
    cout << "Total conta Para: " << contaPara.valorConta << endl;

    return 0;
}

     

