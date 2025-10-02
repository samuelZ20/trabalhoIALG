🎬 Gerenciador de Catálogo de Filmes em C++
📖 Sobre o Projeto
Este projeto é um sistema de gerenciamento de catálogo de filmes desenvolvido em C++, que roda diretamente no terminal. Ele permite ao usuário cadastrar, buscar, remover, listar e gerenciar informações sobre filmes, utilizando um arquivo .csv para persistência de dados.

O programa foi construído com foco em estruturas de dados e algoritmos, implementando funcionalidades como ordenação com QuickSort, busca com Busca Binária e gerenciamento de memória com alocação dinâmica de arrays.

✨ Funcionalidades Principais
Cadastrar Filmes: Adiciona novos filmes ao catálogo com informações como ID, nome, diretor, ano e sinopse. O sistema impede o cadastro de IDs duplicados.

Importar e Exportar Dados:

Importar: Carrega uma lista de filmes a partir de um arquivo filmes.csv.

Exportar: Salva o estado atual do catálogo (filmes cadastrados e não removidos) em um arquivo filmes.csv.

Remover Filmes: Realiza a remoção lógica (soft delete) de filmes, marcando-os como removidos sem apagá-los fisicamente do arquivo, podendo buscar o filme a ser removido por ID ou por nome.

Busca Otimizada: Permite buscar filmes por ID ou por nome utilizando o algoritmo de Busca Binária, garantindo alta performance.

Listagem Flexível: Exibe todos os filmes do catálogo na tela, com as seguintes opções de ordenação:

Por ID (crescente)

Por Nome (ordem alfabética)

Em ordem aleatória

🔧 Tecnologias e Algoritmos
Linguagem: C++

Estrutura de Dados: Array dinâmico com realocação de memória.

Algoritmos de Ordenação: QuickSort para ordenar os filmes por ID ou por nome.

Algoritmos de Busca: Busca Binária para encontrar filmes de forma eficiente.

Manipulação de Arquivos: fstream para leitura e escrita de dados em formato .csv.

📁 Formato do Arquivo filmes.csv
Para a funcionalidade de importação, o programa espera um arquivo chamado filmes.csv no mesmo diretório do executável. O arquivo deve seguir o seguinte formato, com um cabeçalho na primeira linha:

Cabeçalho:
identificador,nome,diretor,ano,sinopse

Exemplo de linha:
123,"O Poderoso Chefão","Francis Ford Coppola",1972,"Uma família mafiosa luta para estabelecer sua supremacia nos Estados Unidos depois da Segunda Guerra Mundial."

🚀 Como Compilar e Executar
Pré-requisitos
Para compilar e executar o projeto, você precisa de um compilador C++, como o g++.

Passo a Passo
Clone o repositório:

Bash

git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio
Compile o código:
Abra o terminal na pasta do projeto e execute o seguinte comando para compilar o arquivo main.cpp (ou o nome que você deu ao seu arquivo):

Bash

g++ main.cpp -o catalogo_filmes
Execute o programa:
Após a compilação, um arquivo executável chamado catalogo_filmes será criado. Execute-o com o comando:

Bash

./catalogo_filmes
Siga as instruções do menu que aparecerá no terminal para interagir com o sistema.

🏛️ Estrutura do Código
O código está contido em um único arquivo e é estruturado da seguinte forma:

struct Filmes: Define a estrutura de dados principal para armazenar as informações de cada filme.

Funções de Menu (menuPrincipal, menuFilmes): Responsáveis por exibir a interface de texto para o usuário.

Gerenciamento de Memória (aumentarTamanho): Função para expandir o array dinâmico quando necessário.

Manipulação de CSV (importarCSV, exportarCSV): Funções para ler e escrever os dados no arquivo.

Algoritmos de Ordenação (ordenarId, ordenarNome): Implementação do QuickSort para os campos ID e nome.

Algoritmos de Busca (buscaBinariaporID, buscaBinariaporNome): Implementação da Busca Binária.

Funções de CRUD (registrarFilme, removerFilme, mostrarTodosFilmes): Funções que implementam as operações principais do sistema.

main(): Função principal que controla o fluxo do programa, o loop de eventos e as chamadas para as outras funções.

