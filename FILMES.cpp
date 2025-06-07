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

void menuInicial() {
    cout << "★══════════════════════════════════════════════════════════════════════★" << endl;
    cout << "|                              MENU PRINCIPAL                           |" << endl;
    cout << "├──────────────────────────────────────────────────────────────────────┤" << endl;
    cout << "| 1 - Registrar novo filme                                             |" << endl;
    cout << "| 2 - Importar/exportar                                                |" << endl;
    cout << "| 3 - Remover dado existente                                           |" << endl;
    cout << "| 4 - Buscar filme                                                     |" << endl;
    cout << "| 5 - Mostrar todos os filmes na tela                                  |" << endl;
    cout << "| 6 - Sair                                                             |" << endl;
    cout << "★══════════════════════════════════════════════════════════════════════★" << endl;
}

void menuFilmes(Filmes f){
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
