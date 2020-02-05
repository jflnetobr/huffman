# Projeto da disciplina de Estrutura de Dados :game_die: (2019.2) - Engenharia de Computação - UFAL 
* **[_Site da disciplina_](https://sites.google.com/a/ic.ufal.br/comp208/)**

* **_Professor:_ [_Márcio Ribeiro_](http://www.ic.ufal.br/marcio)**
* **_Alunos:_ [_José Ferreira Leite Neto_](https://github.com/jflnetobr), [_Bruno Lemos de Lima_](https://github.com/CaosMen) e [_João Pedro Cajueiro Marcolino_](https://github.com/Jpcajueiro)**
### O projeto se divide em 4 módulos, sendo obrigatório o uso de **Git**.
  1. Seminário de um algoritmo ou estrutura de dados não vista em sala. Escolha do grupo: **TRIE**;
  2. Implementação do _algoritmo de Huffman_;
  3. Contagem e plotagem de comparações de duas estruturas vistas no curso. Escolha do grupo: **Árvore desbalanceada vs AVL**;
  4. Escrever Casos de Testes Unitários para TODAS as Estrutura de Dados do Huffman;

# Seminário sobre Trie

 * Todo o conteúdo referente ao seminário encontra-se no repositório, mas também encontra-se hospedado no [Google Docs](https://docs.google.com/presentation/d/1ffBPVS1kxG33w4uyE_Oiwzd09zx97oix8gzMljBUXXs/edit#slide=id.p1)
 
 
# Codificação de Huffman
* Programa em **linguagem C** para compressão e descompressão de arquivos, baseado no método da _Codificação de Huffman_

## Configurações iniciais
* Abra o **CMD** e encaminhe-se até o diretório onde se encontra o projeto.
    * `$ cd .../.../huffman/2 - Huffman/`
    
* Digite o seguinte comando:
    * `$ make`
    
* **O programa será compilado e estará pronto para uso.**

## Execução do programa
* **Opções de comandos**:
    * `-c caminho do arquivo` para comprimir.
    * `-d caminho do arquivo` para descomprimir.
    * `-o caminho do arquivo` após o -c ou -d, para escolher o local onde vai ser salvo o arquivo. (Opcional)
    * `-h` para informações.

* **Exemplo de comandos:**
  * **Geral:**
    * `$ ./huffman -opção caminho do arquivo opção caminho do arquivo`
   * **Informações:**
     * `$ ./huffman -h`
     


Compressão | Arquivo de saída |  Descompressão | Arquivo de saída
------------ | -------------  | -------------- | ---------------- 
`$ ./huffman -c original.ṕng` | `original.png.huff` |  `$ ./huffman -d original.png.huff` |  `original.png`
`$ ./huffman -c original.png -o compressed.huff` | `compressed.huff` |  `./huffman -d compressed.huff -o descompressed.png` | `descompressed.png`


# Comparação das Estruturas
* :punch:  **BST vs AVL**  :punch:

## Links úteis:
* [Matplotlib](https://matplotlib.org/)
* [NumPy](https://numpy.org/)
* [Instalação Alternativa das bibliotecas Matplotlib e Numpy](https://youtu.be/ClOlSlDpCm4)
## Configurações para testes

* Clone o [repositório](https://github.com/jflnetobr/huffman) para uma pasta local do seu computador.

* Instale o [Python](https://www.python.org/downloads/).
    * __Lembre-se de marcar a opção:__
    * - [x] `Add Python 3.X to PATH`

* Para a instalação das bibliotecas, digite o seguinte comando:
    * **`$ pip install numpy matplotlib`**
    
* Abra o **CMD** e encaminhe-se até o diretório onde se encontra o projeto.
    * PS: `Lembre-se de escolher um tipo de comparação (encaminhando-se até a pasta), por número ou por tamanho.`
    * **`$ cd .../.../huffman/3 - Comparação Estruturas/`**
    
* Para rodar os testes, e em seguida plotar o resultado, digite o seguinte comando:
   * **`$ bash ./compare_plot.sh`**
 
 
 # Testes Unitários para as Estrutura de Dados do Huffman

## Configurações iniciais
* **A biblioteca CUnit deve ser instalada, para isso, digite o seguinte comando:**
    * **`$ sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev`**
* Abra o **CMD** e encaminhe-se até o diretório onde se encontra o projeto.
    * **`$ cd .../.../huffman/4 - Testes/`**
    
* Digite o seguinte comando para compilar o programa:
    * **`$ make`**
* E por último, para executar os testes:
    * **`$ ./test`**

