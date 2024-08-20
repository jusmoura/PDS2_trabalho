# Pixel Patterns

O **Pixel Patterns** é um sistema projetado para gerenciar jogadores e jogar jogos de tabuleiro, como Reversi, Lig4, Jogo da Velha, Campo Minado e Damas. O sistema oferece uma interface amigável e colorida para facilitar a navegação e a interação.
O link para acessar o repositório é https://github.com/jusmoura/PDS2_trabalho

## Funcionalidades

### Menu Principal

O menu principal permite acessar as seguintes opções:

- **Gerenciar Jogadores**: Adicionar, remover e listar jogadores.
- **Jogar!**: Selecionar e jogar um dos jogos disponíveis.
- **Sair do Programa**: Encerrar a execução do sistema.

### Gerenciar Jogadores

Nesta seção, você pode:

- **Criar Jogador**: Adicionar um novo jogador com um nome e apelido único.
- **Remover Jogador**: Excluir um jogador existente pelo apelido.
- **Listar Jogadores**: Exibir uma lista de jogadores ordenada por nome ou apelido.

#### Criar Jogador

1. Selecione "Criar Jogador" no menu de gerenciamento.
2. Digite o nome do jogador.
3. Digite o apelido do jogador. O apelido deve ser único.

**Exemplos de Saída:**

- Sucesso: `Jogador <nickname> criado com sucesso`
- Erro: `Jogador com apelido <nickname> ja cadastrado! Tente novamente!`

#### Remover Jogador

1. Selecione "Remover Jogador" no menu de gerenciamento.
2. Digite o apelido do jogador a ser removido.

**Exemplos de Saída:**

- Sucesso: `Jogador <nickname> removido com sucesso.`
- Erro: `Jogador com apelido <nickname> nao encontrado! Tente novamente!`

#### Listar Jogadores

1. Selecione "Listar Jogadores" no menu de gerenciamento.
2. Escolha ordenar por nome ou apelido.

**Formato da Lista:**

Nome: Daniela, Apelido: Dani

Nome: Júlia, Apelido: jusmoura

Nome: Pedro Henrique, Apelido: Piter

Nome: Vanessa, Apelido: Nessa

### Jogar!

Permite iniciar uma nova partida de um dos seguintes jogos:

- **Reversi**
- **Lig4**
- **Jogo da Velha**
- **Campo Minado**
- **Damas**

Para cada jogo, o sistema solicitará o login dos jogadores e, em alguns casos, a seleção de jogadores adicionais, caso o jogo não seja individual, mas em dupla, como no Reversi e no Damas.

**Exemplos de Mensagens Durante o Jogo:**

- **Bem-vindo(a), `<Nickname>`!**
- **Iniciando o jogo `<Nome do Jogo>`...**
- **Encerrando `<Nome do Jogo>`...**

### Encerrar o Programa

Permite sair do sistema e liberar os recursos.

## Tratamento de Exceções e Entradas Inválidas

Todos os tratamentos de possíveis erros, em todo o projeto, ocorrem por meio de if's e switch cases; todos os trys, catchs e throws presentes nos jogos e interface são utilizados, exclusivamente, para auxiliar no fluxo entre menus (voltar e sair) e na "desistência" do usuário durante os jogos, fazendo-o retornar na pilha stack de execução. Dessa forma, o usuário possui controle total de seu caminho entre os menus durante a utilização do sistema. 

## Entradas e Saídas

### Entradas

- **Criar Jogador**: Apelido do jogador.
- **Remover Jogador**: Apelido do jogador.
- **Listar Jogadores**: Ordenação por nome ou apelido.
- **Selecionar Jogo**: Índice do jogo desejado (Reversi(0), Lig4(1), Jogo da velha(2), Campo minado(3), Damas(4))

### Saídas

- **Sucesso**: Mensagens de confirmação para criação, remoção de jogadores e início de jogos.
- **Erros**: Mensagens de erro para dados incorretos ou jogadores não encontrados.

# Jogos

# CheckersGame

A classe `CheckersGame` gerencia o jogo de Damas (Checkers) com um tabuleiro 8x8 e permite que dois jogadores joguem uma partida.

## Visão geral

- **Inicialização do Jogo**: Configura o tabuleiro com peças dos jogadores nos lugares iniciais.
- **Movimentos**: Permite que os jogadores façam movimentos simples e capturas de peças adversárias.
- **Gerenciamento de Jogo**: Alterna entre os jogadores, atualiza o tabuleiro após cada jogada e verifica se há um vencedor.
- **Condições de Vitória**: Determina o vencedor com base no número de peças restantes.

## Como Funciona

1. **Início do Jogo**: O tabuleiro é configurado com peças dos jogadores.
2. **Jogadas**: Jogadores alternam turnos para fazer movimentos ou capturas, sendo a primeira entrada a peça a ser movida e a segunda qual é o destino dela.
3. **Atualização**: O tabuleiro é atualizado com as novas posições das peças após cada movimento.
4. **Verificação de Vitória**: O jogo continua até que um jogador vença, com base na quantidade de peças restantes.
5. **Regras**: O jogo segue as regras das damas americanas. Para peças simples não há captura de peça 'para trás'; As damas movimentam-se apenas uma casa em qualquer direção.

## Especificações

- **play()**: A função play inicia o jogo de damas. Faz a chamada da função setDefaults, que inicializa o tabuleiro com as posições das peças do jogo de damas. Em seguida recebe os dois jogadores e chama printBoard, para imprimir o tabuleiro. O jogo funciona dentro de um loop para a leitura das jogadas, alternando entre os dois jogadores. Dentro do loop, há um if chamando a função readMove, que lê as jogadas. Dentro desse if, verifica-se se a jogada é um movimento simples ou um movimento de captura de peça. Após uma jogada válida, atualiza-se o tabuleiro e é checado se alguma peça se tornou 'Dama'. Então, verifica-se se há algum vencedor, chamando a função winner que checa se algum dos jogadores está sem peças restantes. Caso haja um vencedor, imprime a mensagem de vitória e encerra o jogo.


# Lig4

A classe `Lig4` implementa o jogo  Lig4. Este é um jogo de tabuleiro onde os jogadores se alternam para que peças caiam verticalmente, e o objetivo é formar uma linha de quatro peças consecutivas horizontalmente, verticalmente ou diagonalmente.

## Visão geral

- **Inicialização do Jogo**: Configura um tabuleiro 6x7 vazio e define o jogador inicial.
- **Movimentos**: Permite que os jogadores coloquem peças nas colunas do tabuleiro. As peças caem para a posição mais baixa disponível na coluna.
- **Alternância de Jogadores**: Alterna entre os jogadores após cada movimento.
- **Verificação de Vitória**: Verifica se o jogador atual conseguiu alinhar quatro peças consecutivas em qualquer direção (horizontal, vertical ou diagonal).
- **Empate**: Verifica se o tabuleiro está cheio e não há vencedor, resultando em empate.

## Como Funciona

1. **Início do Jogo**: O tabuleiro é inicializado vazio, e o jogador X começa.
2. **Jogadas**: Cada jogador escolhe uma coluna para colocar sua peça, que cai para a posição mais baixa disponível.
3. **Alternância de Turnos**: Após cada jogada, o sistema alterna o jogador atual.
4. **Verificação de Vitória e Empate**:
   - **Vitória**: O jogo verifica se há uma linha de quatro peças consecutivas do mesmo jogador.
   - **Empate**: O jogo verifica se o tabuleiro está cheio e não há vencedor.
5. **Final do Jogo**: O jogo termina quando um jogador vence ou o tabuleiro está cheio, resultando em empate.

## Especificações
1. **play()**: inicia o jogo Lig4 com um tabuleiro 6x7 vazio e recebe 2 jogadores como parâmetro. Um jogo funciona dentro de um while loop que lê a entrada [coluna] e preenche a linha disponível. O loop é interrompido quando há um vencedor ou todas as casas foram preenchidas;
2. **makeMove()**: chama a função validateMove() da classe Board e verifica se a jogada é válida. Em seguida itera pelas linhas da coluna escolhida e preenche a primeira linha disponível, “empilhando” as peças. Caso a coluna esteja totalmente preenchida ou a coluna seja incoerente com o tamanho do tabuleiro, retorna uma mensagem de erro;
3. **switchPlayer()**: é chamada após cada jogada e é responsável por trocar a vez dos jogadores X e O;
4. **checkVictory()** : verifica se há um vencedor, ou seja, se um dos jogadores preencheu 3 casas seguidas na diagonal, vertical ou horizontal.
5. **checkTie()**: verifica se o jogo empatou, isto é, todas as casas foram preenchidas mas não há vencedor;
6. **printBoard()**: sobreescreve o método da classe Board. Imprime o tabuleiro 6x7.


# Minesweeper (Campo Minado)

A classe `Minesweeper` gerencia o jogo Campo Minado em um tabuleiro 8x8, onde o objetivo é revelar todas as células sem explosões de bombas.

## Visão Geral

- **Inicialização do Jogo**: Configura um tabuleiro 8x8 e posiciona as bombas aleatoriamente. As células ao redor das bombas são atualizadas para refletir o número de bombas adjacentes.
- **Exibição do Tabuleiro**: Mostra o estado atual do tabuleiro com células selecionadas, bombas e números que indicam a quantidade de bombas adjacentes.
- **Movimentos do Jogador**: Permite ao jogador escolher uma célula para revelar. Se a célula contiver uma bomba, o jogo termina. Se a célula for vazia, revela células adjacentes recursivamente.
- **Verificação de Vitória e Derrota**: Determina se o jogador venceu (revelando todas as células sem bombas) ou perdeu (revelando uma célula com bomba).

## Como Funciona

1. **Inicialização**: O tabuleiro é criado e as posições das bombas são definidas. Cada célula ao redor de uma bomba é atualizada com o número de bombas adjacentes.
2. **Exibição do Tabuleiro**: O método `printBoard` exibe o tabuleiro com cores diferentes para células vazias, números, e bombas.
3. **Jogadas**:
   - **Entrada do Jogador**: O jogador insere uma posição no formato "linha coluna".
   - **Validação e Revelação**: A posição é validada. Se for uma célula vazia, as células adjacentes são reveladas. Se for uma bomba, o jogo termina.
4. **Verificação de Vitória e Derrota**:
   - **Derrota**: Se uma célula com bomba for revelada, o jogo exibe uma mensagem de derrota.
   - **Vitória**: O jogo verifica se todas as células sem bombas foram reveladas, indicando vitória.

## Especificações

- **Construtor**: O contrutor é responsável por instanciar a função setBombsPositions, que aloca bombas em posições aleatórias no tabuleiro.
- **play()**: A função play inicia o campo minado em um loop de jogadas, no qual são solicitados as entradas para realização da escolha de posição a ser revelada. Se o movimento for válido e a posição seleciona estiver vazia (valor 0), é chamada a função checkAndShowAdjacentsCells que, de maneira recursiva, revela todas as células adjacentes àquela jogada. Caso não seja 0, apenas a posição selecionada é revelada. Por fim, é verificado se uma bomba foi selecionada e, em caso positivo, o jogo é encerrado em derrota. Verifica-se, também (caso não tenha ocorrido a derrota), se houve vitória, na situação em que todas as casas, exceto bombas, foram reveladas.

# Reversi

A classe `ReversiGame` implementa o jogo Reversi, um jogo de estratégia de dois jogadores em um tabuleiro 8x8. O objetivo é ter a maioria das peças na cor do jogador ao final do jogo, invertendo as peças do adversário durante as jogadas.

## Visão Geral

- **Inicialização do Tabuleiro**: Configura o tabuleiro com peças iniciais e disponibiliza as posições para jogadas.
- **Realizar Jogada**: Permite que os jogadores façam jogadas e atualizem o estado do tabuleiro.
- **Verificação de Vitória**: Checa se há um vencedor ou se o jogo terminou empatado.
- **Impressão do Tabuleiro**: Exibe o estado atual do tabuleiro no console.
- **Dicas**: Fornece dicas sobre movimentos válidos e suas pontuações potenciais.
- **Ajuda**: Lista todos os movimentos válidos disponíveis no momento.
- **Acompanhamento de Pontuação**: Atualiza e exibe a pontuação em tempo real durante o jogo.

### Como Funciona

1. **Inicialização do Jogo**:
   - O tabuleiro é inicializado com peças nas posições iniciais no centro do tabuleiro. Cada jogador alterna turnos para fazer jogadas.

2. **Jogadas**:
   - Os jogadores fazem jogadas em posições válidas do tabuleiro. A jogada é validada para garantir que as peças adversárias possam ser invertidas.

3. **Verificação de Vitória**:
   - O jogo verifica se há um vencedor ao final de cada turno, com base no número de peças de cada jogador. Se o tabuleiro estiver cheio ou nenhum jogador puder fazer uma jogada válida, o jogo termina.

4. **Impressão do Tabuleiro**:
   - O estado atual do tabuleiro é exibido no console, mostrando as peças dos jogadores em suas posições.

5. **Dicas**:
   - O sistema pode fornecer dicas sobre movimentos válidos e suas pontuações potenciais para ajudar o jogador a escolher a melhor jogada, são fornecidas 5 dicas por jogador durante a partida.

6. **Ajuda**:
   - O sistema pode listar todos os movimentos válidos disponíveis no momento para o jogador, facilitando a visualização das opções.

7. **Acompanhamento de Pontuação**:
   - A pontuação é atualizada e exibida em tempo real durante o jogo, refletindo o número de peças de cada jogador no tabuleiro.

# TicTacToe

A classe `TicTacToe` implementa o clássico jogo da velha, um jogo de estratégia simples para dois jogadores. O objetivo é alinhar três peças em uma linha, seja horizontal, vertical ou diagonal, antes que o adversário o faça.

## Visão Geral

- **Inicialização do Tabuleiro**: Configura um tabuleiro 3x3 vazio.
- **Realizar Jogada**: Permite que os jogadores coloquem suas peças em uma posição válida no tabuleiro.
- **Verificação de Vitória**: Checa se há um vencedor ou se o jogo terminou em empate.
- **Impressão do Tabuleiro**: Exibe o estado atual do tabuleiro no console.

### Como Funciona

1. **Inicialização do Jogo**:
   - O tabuleiro é inicializado com 9 células vazias. Cada jogador alterna turnos para colocar suas peças.

2. **Jogadas**:
   - Os jogadores alternam os turnos, colocando suas peças em uma posição não ocupada do tabuleiro. A jogada é validada para garantir que a posição esteja disponível.

3. **Verificação de Vitória**:
   - O jogo verifica se há uma linha de três peças iguais (X ou O) em qualquer direção (horizontal, vertical ou diagonal) após cada jogada. Se sim, o jogo termina com um vencedor. Se todas as posições estiverem preenchidas e não houver um vencedor, o jogo termina em empate.

4. **Impressão do Tabuleiro**:
   - O estado atual do tabuleiro é exibido no console, mostrando as peças dos jogadores (X e O) nas posições correspondentes.
   
## Especificações

1. **play()**: inicia o jogo da velha com um tabuleiro 3x3 vazio e recebe os dois jogadores como parâmetro. O jogo funciona dentro de um while loop que lê a entrada [linha coluna] e preenche a casa do tabuleiro correspondente. O loop é interrompido quando há um vencedor ou todas as casas foram preenchidas;
2. **makeMove()** recebe uma linha e coluna como parâmetro e preenche a casa correspondente se ela estiver vazia ou retorna uma mensagem de erro caso a jogada seja inválida;
3. **validMove()**: recebe uma linha e coluna como parâmetro e verifica se a jogada é válida, ou seja, se a casa escolhida está vazia e dentro do tabuleiro, retornando uma mensagem de erro caso seja inválida;
4. **switchPlayer()**: é chamada após cada jogada e é responsável por trocar a vez dos jogadores X e O;
5. **checkTie()**: verifica se o jogo empatou, isto é, todas as casas foram preenchidas mas não há vencedor;
6. **checkVictory()**: verifica se há um vencedor, ou seja, se um dos jogadores preencheu 3 casas seguidas na diagonal, vertical ou horizontal.  
  

# Compilação e Execução

### No Linux

1. **Navegue até o diretório do projeto**:
   - Abra o terminal.
   - Use o comando `cd` para navegar até o diretório onde o `Makefile` está localizado.

2. **Compile o projeto**:
   - Execute o seguinte comando para compilar o projeto:
     ```bash
     make
     ```

3. **Executar o programa**:
   - Após a compilação, navegue até a pasta `bin`:
     ```bash
     cd bin
     ```
   - Execute o arquivo gerado (`main`):
     ```bash
     ./main
     ```

**Observação**: Certifique-se de que o `make` esteja instalado no seu sistema e que o `Makefile` esteja corretamente configurado para gerar os binários na pasta `bin`.


### No Windows

1. **Navegue até o diretório do projeto**:
   - Abra o terminal ou prompt de comando (cmd).
   - Use o comando `cd` para navegar até o diretório onde o `Makefile` está localizado.

2. **Compile o projeto**:
   - Execute o seguinte comando para compilar o projeto:
     ```bash
     mingw32-make
     ```
   - Isso irá compilar os arquivos e gerar os binários necessários.

3. **Executar o programa**:
   - Após a compilação, navegue até a pasta `bin`:
     ```bash
     cd bin
     ```
   - Execute o arquivo gerado (`main.exe`):
     ```bash
     ./main.exe
     ```

**Observação**: Certifique-se de que o `mingw32-make` esteja instalado e configurado corretamente no seu sistema, e que o `Makefile` esteja corretamente configurado para gerar os binários na pasta `bin`.

# Doxyfile
### Como Abrir a Documentação Gerada pelo Doxygen

Após a geração da documentação com o Doxygen, siga os passos abaixo para visualizar a documentação em HTML:

1. **Navegue até a pasta de documentação**:
   - Acesse a pasta `docs`.

2. **Acesse a subpasta HTML**:
   - Dentro da pasta `docs`, entre na subpasta `html`, onde a documentação HTML gerada pelo Doxygen está localizada.

3. **Abra a documentação**:
   - Execute o comando correspondente ao seu sistema operacional para abrir o arquivo `index.html`:

   **No Linux**:
   ```bash
   xdg-open index.html
   ```
    
   **No Windows**:
   ```bash
    start index.html
    ```
