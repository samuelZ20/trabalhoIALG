#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//ETAPA1 - Cada filme vai conter essas informações, permitindo que eu crie um vetor de filmes
struct Filme{

    int id;
    string nome;
    string diretor;
    int ano;
    string sinopse;

    bool removido; //serve para marcar quando um registro foi removido, sem precisar apagar de verdade do vetor, tipo inves de tirar o filme do vetor, eu façõ : filme[3].removido=true;
};

//ETAPA2 - Criando um vetor dinamico com uma quantidade inicial de 40 filmes, caso exceda aumenta em 5 ou 10, controla quantos filmes estao cadastrados
//Função para redimensionamento
void redimensionar (Filme*& filmes, int& capacidade, int aumento){
    int novaCapacidade = capacidade+aumento;
    Filme* novoVetor = new Filme[novaCapacidade];

    for(int i=0; i<capacidade; i++){
        novoVetor[i] = filmes[i];
    }

    delete[] filmes;
    filmes = novoVetor;
    capacidade = novaCapacidade;
}

//ETAPA3 - Leitura do arquivo CSV e jogar as informacoes no vetor dinamico
void importarCSV (Filme*& filmes, int& tamanho, int& capacidade, const string& nomeArquivo){
    ifstream arquivo (nomeArquivo);
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    string linha;
    getline (arquivo, linha);

    while(getline(arquivo, linha)){
        if(tamanho == capacidade){
            redimensionar(filmes, capacidade, 10);
        }

        stringstream ss(linha);
        string campo;

        getline(ss, campo, ',');
        filmes[tamanho].id = stoi(campo);

        getline(ss, filmes[tamanho].nome, ',');

        getline(ss, filmes[tamanho].diretor, ',');

        getline(ss,campo, ',' );
        filmes[tamanho].ano = stoi(campo);

        getline(ss,campo, ' " ');
        getline (ss, filmes[tamanho].sinopse, '"');

        filmes[tamanho].removido = false;
        tamanho++;
    }
    arquivo.close();
    cout << "Concluiu a importação! Filmes carregados: " << tamanho << endl;
}















int main (){
   
}
