#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Filmes{
    int identificador;
    string nome;
    string diretor;
    int ano;
    string sinopse;
};


int contarlinhas(string linha){
    int cont = 0;
    ifstream arq("filmes.csv");

    while(getline(arq, linha)){
        cont++;
    }

    return cont;
}

int main (){


    return 0;
}
