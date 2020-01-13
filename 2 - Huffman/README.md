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
