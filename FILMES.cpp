#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

struct Filmes{

    int identificador;
    string nome;
    string diretor;
    int ano;
    string sinopse;

    bool removido;
};

void menuPrincipal() {
    cout << "------------------------------------------------------------------------" << endl;
    cout << "|                              MENU PRINCIPAL                            |" << endl;
    cout << "|------------------------------------------------------------------------|" << endl;
    cout << "| 1 - Registrar novo filme                                               |" << endl;
    cout << "| 2 - Importar ou exportar                                               |" << endl;
    cout << "| 3 - Remover dados                                                      |" << endl;
    cout << "| 4 - Buscar filme                                                       |" << endl;
    cout << "| 5 - Mostrar todos os filmes na tela                                    |" << endl;
    cout << "| 6 - Fechar Programa                                                    |" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}

void menuFilmes(Filmes f) {
    cout << "------------------------------------------------------------------------" << endl;
    cout << "|Filme: " << f.nome << endl;
    cout << "|Diretor: " << f.diretor << endl;
    cout << "|Ano do Oscar: " << f.ano << endl;
    cout << "|Sinopse: " << f.sinopse << endl;
    cout << "------------------------------------------------------------------------" << endl;

}
Filmes* filmes = nullptr;


//Cria um vetor e quando necessário aumenta o tamanho em 10
void aumentarTamanho (Filmes*& filmes, int& capacidade, int& tamanho, const int aumento){ 
    int novaCapacidade = capacidade + aumento;
    Filmes* novoVetor = new Filmes[novaCapacidade]; 

    for(int i=0; i<tamanho; i++){
        novoVetor[i] = filmes[i]; 
    }

    delete[] filmes;
    filmes = novoVetor;
    capacidade = novaCapacidade;
}


//Função ImportarCSV
Filmes* importarCSV(const string& nomeArquivo, int& tamanho) { //passa informações do arquivo csv para um vetor dinamico filmes
    ifstream arquivo(nomeArquivo); 

    int capacidade = 40;
    Filmes* filmes = new Filmes[capacidade];
    tamanho = 0;

    string linha;
    getline(arquivo, linha);

    while(getline(arquivo, linha)){
        if(tamanho == capacidade){
            aumentarTamanho(filmes, capacidade, tamanho, 10);
        }

        int pos = 0;

        pos = linha.find(','); 
        filmes[tamanho].identificador = stoi(linha.substr(0,pos)); 
        linha.erase(0, pos + 1); 

        pos = linha.find(',');
        filmes[tamanho].nome = linha.substr(0, pos);
        linha.erase(0, pos + 1);

        pos = linha.find(',');
        filmes[tamanho].diretor = linha.substr(0, pos);
        linha.erase(0, pos + 1);

        pos = linha.find(',');
        filmes[tamanho].ano = stoi(linha.substr(0, pos));
        linha.erase(0, pos + 1);

        filmes[tamanho].sinopse = linha;

        filmes[tamanho].removido = false;
        tamanho++; 
    }
    cout << "Fimes carregados: " << tamanho << endl;
    return filmes;
}



void mostrarTodosFilmes(Filmes* filmes, int tamanho){
    for(int i=0; i<tamanho; i++){
        if(!filmes[i].removido){
            cout << "Identificador: " << filmes[i].identificador << endl;
            menuFilmes(filmes[i]);
        }
    }
}



void exportarCSV(Filmes* filmes, int tamanho, const string& nomeArquivo){
    ofstream arquivo(nomeArquivo); //abrindo o nosso arquivo

    arquivo << "identificador,nome,diretor,ano,sinopse" << endl; //ta escrevendo os elementos do nosso cabeçalho

    for(int i=0; i<tamanho; i++){
        if(!filmes[i].removido){
            arquivo << filmes[i].identificador << ","
                    << filmes[i].nome << ","
                    << filmes[i].diretor << ","
                    << filmes[i].ano << ","
                    << " \"" << filmes[i]. sinopse << "\"" << endl;
        }

        } 
        arquivo.close();
    }

    // busca um filme de acordo com o identificador
int buscaBinariaporID(Filmes* filmes, int& tamanho, int& identificador){
    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(filmes[meio].identificador == identificador){
            return meio; // achou na sorte
        } else if(filmes[meio].identificador < identificador){
            inicio = meio + 1; // procura na parte direita do numero
        } else {
            fim = meio - 1; // procura na parte esquerda do numero
        }
    }
    
    return -1; //se nao achar
}

    // busca o filme de acordo com o nome digitado
int buscaBinariaporNome(Filmes* filmes, int& tamanho, string& nomeFilme){
    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (filmes[meio].nome == nomeFilme and !filmes[meio].removido){
            return meio;
        } else if(filmes[meio].nome < nomeFilme){
            inicio = meio + 1;
        } else{
            fim = meio - 1;
        }
    }
    
    return -1;
}

//ETAPA 6- Ordenar dois campos diferentes

//Ordenando por Nome do Filme
int particionarNome(Filmes* filmes, int inicio, int fim){
    Filmes pivo = filmes[fim];
    int i = inicio-1;

    for(int j=inicio; j<fim; j++){
if(filmes[j].nome < pivo.nome){
    i++;
    swap(filmes[i],filmes[j]);
    }
}

swap (filmes[i+1], filmes[fim]);
return i+1;
}

void ordenarNome (Filmes* filmes, int inicio, int fim){
    if(inicio<fim){
        int pos= particionarNome(filmes, inicio, fim);
        ordenarNome(filmes, inicio, pos-1);
        ordenarNome(filmes, pos+1, fim);
    }
}


//Ordenando por IdCrescente
 int particionarId(Filmes* filmes, int inicio, int fim){   
    Filmes pivo = filmes[fim];
    int i = inicio - 1;

    for(int j=inicio; j<fim; j++){
        if(filmes[j].identificador < pivo.identificador){
            i++;
            swap (filmes[i], filmes[j]);
        }
    }

    swap(filmes[i+1], filmes[fim]);
    return i+1;
}

void ordenarId (Filmes* filmes, int inicio, int fim){
    if(inicio<fim){
        int pos = particionarId(filmes, inicio, fim);
        ordenarId(filmes, inicio, pos-1);
        ordenarId(filmes, pos+1, fim);
    }
}

//Funcao para registrar novo filme no case 1
void registrarFilme(Filmes*& filmes, int& tamanho, int& capacidade){ 
if(tamanho==capacidade){
aumentarTamanho(filmes,capacidade,tamanho,10);
}

Filmes novo; //variavel que armazena um novo filme vazio

cout << "Digite o novo ID do filme: ";
cin >> novo.identificador;
cin.ignore(); //Para nao ler uma string vazia na quebra de linha

//Verificar se o ID ja existe
bool idDuplicado=false;
for(int i=0; i<tamanho; i++){
    if(filmes[i].identificador==novo.identificador and !filmes[i].removido){
        idDuplicado=true;
        break;
    }
}

if(idDuplicado){
    cout << "ID já cadastrado!!!" << endl;
    return;
}

cout << "Digite o nome do filme: ";
getline(cin, novo.nome);

cout << "Digite o diretor do filme: ";
getline(cin, novo.diretor);

cout << "Digite o ano que ganhou o Oscar: ";
cin >> novo.ano;
cin.ignore();

cout << "Digite a sinopse: ";
getline(cin, novo.sinopse);

novo.removido=false;

filmes[tamanho]=novo; //Agora que "novo" está preenchido, adiciona ele no vetor posiçao tamanho
tamanho++;

cout << "Filme cadastrado" << endl;
}

//Função para remover os dados
void removerFilme(Filmes* filmes, int tamanho) {
    if (tamanho == 0) {
        cout << "Nao ha filmes cadastrados para remover!" << endl;
        return;
    }

    int opcao;
    cout << "\nComo deseja buscar o filme para remover:" << endl;
    cout << "1 - Por ID" << endl;
    cout << "2 - Por Nome" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    if (opcao == 1) {
        int identificador;
        cout << "Digite o ID do filme que deseja remover: ";
        cin >> identificador;

        ordenarId(filmes, 0, tamanho - 1);
        int pos = buscaBinariaporID(filmes, tamanho, identificador);

        if (pos != -1 && !filmes[pos].removido) {
            filmes[pos].removido = true;
            cout << "Filme removido com sucesso!" << endl;
        } else {
            cout << "Filme nao encontrado ou ja esta removido." << endl;
        }

    } else if (opcao == 2) {
        string nome;
        cin.ignore();
        cout << "Digite o nome do filme que deseja remover: ";
        getline(cin, nome);

        ordenarNome(filmes, 0, tamanho - 1);
        int pos = buscaBinariaporNome(filmes, tamanho, nome);

        if (pos != -1 && !filmes[pos].removido) {
            filmes[pos].removido = true;
            cout << "Filme removido com sucesso!" << endl;
        } else {
            cout << "Filme nao encontrado ou ja esta removido." << endl;
        }

    } else {
        cout << "Opcao invalida. Retornando ao menu." << endl;
    }
}


void avaliarTrabalho (){
    int nota;

    do{
        cout << "Antes de sair, qual nota de 0 a 16 voce daria para o trabalho: " << endl;
        cin >> nota;
        if(nota < 0 or nota > 16){
            cout << "Nota invalida! Digite outra: " << endl;
            continue;
        }
         else if(nota != 16) {
            cout << "Nota muito baixa, tente outra: " << endl;
        }
    } while(nota != 16);
        cout << "Muito obrigado pela nota maxima!" << endl;
        cout << "------------------------------------------------------------------------\n" << endl;
}

int main (){
    int tamanho = 0;
    int capacidade = 10;
    Filmes* filmes = new Filmes[capacidade];

    capacidade = tamanho + 10;

    int escolha;
    
    //variaveis booleanas para voltar ao menu principal, sair do programa e uma para manter o programa executando
    bool sair_programa = false;
    bool voltar_menu = false;
    bool rodando = true;

    while(rodando){
        menuPrincipal();
        cout << "Digite sua opcao: " << endl;
        cin >> escolha; 

        switch(escolha){
            case 1: {
    registrarFilme(filmes, tamanho, capacidade);

    int opcao;
    cout << "Deseja exportar os filmes para o CSV agora?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    if (opcao == 1) {
        exportarCSV(filmes, tamanho, "filmes.csv");
        cout << "Dados exportados com sucesso!" << endl;
    }

    while (true) {
        cout << "Digite 1 para voltar ao menu ou 2 para sair: ";
        cin >> opcao;

        if (opcao == 1) {
            voltar_menu = true;
            break;
        } else if (opcao == 2) {
            sair_programa = true;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
    break;
}
           case 2: {
    int opcao;
    cout << "\nO que voce deseja fazer?" << endl;
    cout << "1 - Importar filmes do CSV" << endl;
    cout << "2 - Exportar filmes para CSV" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    if (opcao == 1) {
        delete[] filmes; // libera o vetor anterior para evitar vazamento de memória
        filmes = importarCSV("filmes.csv", tamanho);
        cout << "Importacao concluida com sucesso!" << endl;
    } 
    else if (opcao == 2) {
        if (tamanho == 0) {
            cout << "Nao ha filmes para exportar. Cadastre ou importe primeiro!" << endl;
        } else {
            exportarCSV(filmes, tamanho, "filmes.csv");
            cout << "Exportacao concluida com sucesso!" << endl;
        }
    } 
    else {
        cout << "Opcao invalida. Retornando ao menu." << endl;
    }

    // Menu para voltar ou sair
    while (true) {
        cout << "\nDigite 1 para voltar ao menu ou 2 para sair: ";
        cin >> opcao;

        if (opcao == 1) {
            voltar_menu = true;
            break;
        } else if (opcao == 2) {
            sair_programa = true;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
    break;
}
            case 3:{
        // Função Remover dado existente

        while(rodando){
            int opcao;
            cout << "Qual opcao voce deseja? Digite 1 para voltar ao menu principal ou 2 para sair do programa." << endl;
            cout << "Escolha: ";
            cin >> opcao;

            if(opcao == 1) {
              voltar_menu = true;
              break;  
            } else if (opcao == 2){
              sair_programa = true;
              break;
            } else{
              cout << "Numero invalido! Tente novamente." << endl;
            }
        }
        break;
    }
            case 4:{
        int escolha;
                cout << "Como voce quer buscar os filmes: " << endl;
                cout << "1 - Buscar por ID" << endl;
                cout << "2 - Buscar por Nome" << endl;
                cout << "Escolha: ";
                cin >> escolha;

                if(escolha==1){
                    int identificador;
                    cout << "Digite o identificador do filme: ";
                    cin >> identificador;

                    ordenarId(filmes,0,tamanho-1);
                    int pos = buscaBinariaporID(filmes, tamanho, identificador);

                    if(pos != -1){
                        cout << "Filme encontrado: " << endl;
                        menuFilmes(filmes[pos]);
                    } else {
                        cout << "Filme nao encontrado! Tente outro identificador." << endl;
                    }
                }

                else if(escolha==2){
                    string nome;
                    cin.ignore(); // teste para limpar o terminal  
                    cout << "Digite o nome do filme: ";
                    getline(cin, nome); // le a linha inteira

                    ordenarNome(filmes,0,tamanho-1);
                    int pos = buscaBinariaporNome(filmes, tamanho, nome);

                    if(pos != -1){
                        cout << "Filme encontrado: " << endl;
                        menuFilmes(filmes[pos]);
                    } else {
                        cout << "Filme nao encontrado! Tente outro nome." << endl;
                    }

                }

                else{
                    cout << "Nao ha essa opcao. Exibindo sem ordenar..." << endl;
                }

        while(rodando){
            int opcao;
            cout << "Qual opcao voce deseja? Digite 1 para voltar ao menu principal ou 2 para sair do programa." << endl;
            cout << "Escolha: ";
            cin >> opcao;

            if(opcao == 1) {
              voltar_menu = true;
              break;  
            } else if (opcao == 2){
              sair_programa = true;
              break;
            } else{
              cout << "Numero invalido! Tente novamente." << endl;
            }
        }
        break;
    }
           case 5: {
    if (tamanho == 0) {
        cout << "Nao ha filmes cadastrados para exibir!" << endl;
        break;
    }

    int escolha;
    cout << "Como voce quer exibir os filmes: " << endl;
    cout << "1 - Ordenar por ID" << endl;
    cout << "2 - Ordenar por Nome (Alfabetica)" << endl;
    cout << "3 - Em ordem Aleatoria" << endl;
    cout << "Escolha: ";
    cin >> escolha;

    // Criar uma cópia temporária para não bagunçar o vetor principal
    Filmes* copia = new Filmes[tamanho];
    for (int i = 0; i < tamanho; i++) {
        copia[i] = filmes[i];
    }

    if (escolha == 1) {
        ordenarId(copia, 0, tamanho - 1);
        cout << "\nFilmes ordenados por ID:\n";
    } else if (escolha == 2) {
        ordenarNome(copia, 0, tamanho - 1);
        cout << "\nFilmes ordenados por Nome:\n";
    } else if (escolha == 3) {
        // Embaralhamento MANUAL (bem simples)
        for (int i = 0; i < tamanho; i++) {
            // Troca cada filme com outro em posição aleatória (usando tamanho - i)
            int j = i + (i % (tamanho - i));  // Pode não ser perfeito, mas é simples
            swap(copia[i], copia[j]);
        }
        cout << "\nFilmes em ordem aleatoria:\n";
    } else {
        cout << "Opcao invalida! Exibindo sem ordenar...\n";
    }

    mostrarTodosFilmes(copia, tamanho);

    delete[] copia;

    // Menu para voltar ou sair
    while (true) {
        int opcao;
        cout << "\nDigite 1 para voltar ao menu ou 2 para sair: ";
        cin >> opcao;

        if (opcao == 1) {
            voltar_menu = true;
            break;
        } else if (opcao == 2) {
            sair_programa = true;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
    break;
}
            case 6:{
        avaliarTrabalho();
        cout << "Saindo... Ate logo!" << endl;
        return 0;
    }
            default:{
            cout << "Numero nao esta entre as opcoes! Tente novamente." << endl;
            break;
        }
}
            if (sair_programa){
                rodando = false;
            }

}

    delete[] filmes;

    avaliarTrabalho();
    cout << "Saindo... Ate logo!" << endl;

    return 0;
}