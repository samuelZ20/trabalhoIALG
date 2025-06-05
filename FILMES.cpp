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

int contarlinhas(int n){
    string linha;
    int cont = 0;
    ifstream arq("filmes.csv");

    while(arq >> linha){
        cont++;
    }
    n = cont;

    return n;
}

int main (){


    return 0;
}
