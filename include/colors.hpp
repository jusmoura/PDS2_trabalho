/**
 * @file colors.hpp
 * @brief Declaração de constantes para cores e estilos de texto para alterar a saída no terminal.
 *
 * Este arquivo define uma série de constantes para representar cores e estilos de texto que podem
 * ser usados para colorir e formatar a saída do terminal. As cores são definidas usando códigos
 * ANSI e são aplicadas para estilizar os jogos de tabuleiro.
 */
#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

 /*Cores*/
const std::string GRAY_COLOR = "\033[30m";   // Cor cinza
const std::string RED_COLOR = "\033[31m";    // Cor vermelha
const std::string GREEN_COLOR = "\033[32m";  // Cor verde
const std::string YELLOW_COLOR = "\033[33m"; // Cor amarela
const std::string BLUE_COLOR = "\033[34m";   // Cor azul
const std::string PURPLE_COLOR = "\033[35m"; // Cor roxo
const std::string CYAN_COLOR = "\033[36m";   // Cor ciano
const std::string WHITE_COLOR = "\033[37m";  // Cor branco

/*Estilos*/
const std::string MAIN_TITLE_STYLE = "\033[34;1m"; // Cor azul em negrito
const std::string WINNER_STYLE = "\033[32;1m";     // Cor verde em negrito
const std::string BOLD = "\033[;1m";               // Cor padrão em negrito
const std::string RED_BOLD = "\033[31;1m";         // Cor vermelha em negrito
const std::string YELLOW_BOLD = "\033[33;1m";      // Cor amarela em negrito

/*RESET_ALL*/
const std::string RESET_ALL = "\033[;10m";

#endif //COLORS_HPP