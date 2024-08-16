/**
 * @file cell.hpp
 * @brief Declaração da classe Cell para representar as células do tabuleiro.
 * 
 * Este arquivo define a classe `Cell` que representa uma célula individual em um tabuleiro de jogo.
 * A classe fornece funcionalidades para gerenciar o estado de uma célula, como o valor armazenado e
 * o estado de seleção.
 */
#ifndef CELL_H
#define CELL_H

/**
 * @class Cell
 * @brief Representa uma célula individual em um tabuleiro de jogo.
 * 
 * A classe `Cell` é usada para representar uma célula em um tabuleiro. Ela armazena o valor da célula
 * e um estado booleano que indica se a célula foi selecionada ou não.
 */
class Cell {
private:

    /** 
     * @brief Valor armazenado na célula.
     * 
     * Este valor pode representar diferentes estados ou informações dependendo do jogo.
     */
    int _value;

    /** 
     * @brief Indica se a célula foi selecionada ou não.
     * 
     * Esse estado pode ser usado para verificar se a célula foi jogada ou manipulada de alguma forma.
     */
    bool _wasSelected;

public:

    /**
     * @brief Construtor padrão da classe Cell.
     * 
     * Inicializa a célula com valores padrão. Normalmente, o valor é 0 e o estado de seleção é false.
     */
    Cell();

    /**
     * @brief Obtém o valor armazenado na célula.
     * 
     * @return O valor armazenado na célula.
     */
    int getValue();

    /**
     * @brief Define o valor da célula.
     * 
     * @param value O novo valor a ser armazenado na célula.
     */
    void setValue(int value);

    /**
     * @brief Verifica se a célula foi selecionada.
     * 
     * @return Retorna true se a célula foi selecionada, caso contrário retorna false.
     */
    bool getSelected();
    
    /**
     * @brief Define o estado de seleção da célula.
     * 
     * @param wasSelected O novo estado de seleção da célula. Deve ser true se a célula foi selecionada,
     *        ou false se não foi.
     */
    void setSelected(bool wasSelected);
};

#endif //CELL_H