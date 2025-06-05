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

    cout << "+-------------------------------------------------------------------------------------------------------------------------------------+"<< endl;
    cout << "|Filme: " << endl << "                                                                                                                |"<< endl;
    cout << "|Diretor: " << "                                                                                                                      |" << endl;
    cout << "|Ano do Oscar: " << "                                                                                                                 |" << endl;
    cout << "|Sinopse: " << "                                                                                                                      |" << endl;
    cout << "+-------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}


int main (){


    return 0;
}
