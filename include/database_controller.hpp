/**
 * @file database_controller.hpp
 * @brief Declaração da classe DatabaseController para gerenciar operações de leitura e escrita de arquivos.
 * 
 * Este arquivo define a classe `DatabaseController`, responsável por gerenciar a leitura e escrita de dados
 * relacionados aos jogadores a partir e para um arquivo. A classe interage com a classe `PlayerController`
 * para carregar e salvar informações dos jogadores.
 */
#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include "player_controller.hpp"

#include <iostream>
#include <fstream>
#include <string>

class PlayerController;
/**
 * @class DatabaseController
 * @brief Gerencia a leitura e escrita de dados de jogadores em arquivos.
 * 
 * A classe `DatabaseController` é responsável por carregar e salvar informações sobre jogadores a partir
 * e para arquivos. Ela utiliza os métodos de leitura e escrita para interagir com a classe `PlayerController`.
 */
class DatabaseController {
private:

    /** 
     * @brief Caminho para o arquivo de dados.
     * 
     * Armazena o caminho do arquivo usado para ler e escrever dados dos jogadores.
     */
    string _filePath;

    /** 
     * @brief Fluxo de entrada para leitura de arquivos.
     * 
     * Usado para ler dados do arquivo especificado por `_filePath`.
     */
    ifstream _inputFile;

    /** 
     * @brief Fluxo de saída para escrita de arquivos.
     * 
     * Usado para escrever dados no arquivo especificado por `_filePath`.
     */
    ofstream _outputFile;

public:
    /**
     * @brief Construtor da classe DatabaseController.
     * 
     * Inicializa uma instância de `DatabaseController`. O caminho do arquivo deve ser definido
     * antes da leitura ou escrita.
     */
    DatabaseController();

    /**
     * @brief Lê os dados dos jogadores a partir de um arquivo e atualiza o PlayerController.
     * 
     * Este método abre o arquivo especificado por `_filePath` para leitura e carrega as informações
     * dos jogadores no `PlayerController`.
     * 
     * @param playerController Ponteiro para o `PlayerController` que será atualizado com os dados lidos.
     */
    void readFile(PlayerController* playerController);
    
    /**
     * @brief Escreve os dados dos jogadores em um arquivo.
     * 
     * Este método abre o arquivo especificado por `_filePath` para escrita e salva as informações
     * dos jogadores a partir do `PlayerController`.
     * 
     * @param playerController Ponteiro para o `PlayerController` que fornece os dados a serem salvos.
     */
    void writeFile(PlayerController* playerController);
};

#endif //DATABASE_CONTROLLER_H