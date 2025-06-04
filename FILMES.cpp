#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Filme {
    int id;
    string nome;
    string diretor;
    int ano;
    string sinopse;
};

void moldura(const Filme& f) {
    cout << "+------------------------------------------------------------+" << endl;
    cout << "| Filme: " << f.nome << endl;
    cout << "| Diretor: " << f.diretor << endl;
    cout << "| Ano do Oscar: " << f.ano << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "| Sinopse:                                                   |" << endl;

    int largura = 58;
    for (size_t i = 0; i < f.sinopse.length(); i += largura) {
        cout << "| " << f.sinopse.substr(i, largura);
        int resto = largura - f.sinopse.substr(i, largura).length();
        for (int j = 0; j < resto; j++) cout << " ";
        cout << " |" << endl;
    }

    cout << "+------------------------------------------------------------+" << endl << endl;
}

int carregarFilmes(const string& nome_arquivo, Filme filmes[], int max_filmes) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return 0;
    }

    string linha;
    getline(arquivo, linha); // pular cabeçalho

    int count = 0;
    while (getline(arquivo, linha) && count < max_filmes) {
        stringstream ss(linha);
        string item;

        getline(ss, item, ','); filmes[count].id = stoi(item);
        getline(ss, filmes[count].nome, ',');
        getline(ss, filmes[count].diretor, ',');
        getline(ss, item, ','); filmes[count].ano = stoi(item);
        getline(ss, filmes[count].sinopse);

        count++;
    }
    arquivo.close();
    return count;
}

int main() {
    const int MAX_FILMES = 15;
    Filme filmes[MAX_FILMES];
    int total = carregarFilmes("filmes.csv", filmes, MAX_FILMES);

    int escolha = 1;
    while (escolha != 0) {
        cout << "==== MENU DE FILMES VENCEDORES DO OSCAR ====" << endl;
        cout << "Escolha um numero (0 para sair):" << endl;
        for (int i = 0; i < total; i++) {
            cout << filmes[i].id << ". " << filmes[i].nome << endl;
        }
        cout << "0. Sair" << endl;
        cout << "Opcao: ";
        cin >> escolha;
        cout << endl;

        switch (escolha) {
            case 0:
                cout << "Encerrando o programa. Até logo!" << endl;
                continue;

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15: {
                int i = escolha - 1; // índice do array
                if (i >= 0 && i < total) {
                    moldura(filmes[i]);
                } else {
                    cout << "Opção inválida. Tente novamente." << endl << endl;
                }
                continue;
            }

            default:
                cout << "Opção inválida. Tente novamente." << endl << endl;
                continue;
        }
    }

    return 0;
}
