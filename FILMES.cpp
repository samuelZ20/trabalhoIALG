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

void moldura(filmes f){
 cout << "★══════════════════════════════════════════════════════════════════════★"<< endl;
    cout << "|Filme: " << f.nome << endl ;
    cout << "|Diretor: " << f.diretor << endl;
    cout << "|Ano do Oscar: " << f.ano << endl;
    cout << "|Sinopse: " << f.sinopse << endl; 
    cout << "★══════════════════════════════════════════════════════════════════════★" << endl;
}

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
