#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct filmes{
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


int main (){


    return 0;
}
