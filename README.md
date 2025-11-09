Desafio: nível aventureiro Tabuleiro Completo e Navios Diagonais

Nesta etapa, você irá aprimorar seu jogo de Batalha Naval adicionando a complexidade de navios posicionados na diagonal. Dê continuidade ao código que você desenvolveu no Desafio do Nível Novato.

O que você vai fazer

Você deve modificar seu programa em C para:

Criar um Tabuleiro 10x10: Declare uma matriz (array bidimensional) de tamanho 10x10 para representar o tabuleiro da Batalha Naval. Inicialize todas as posições com o valor 0, representando água.

Posicionar Quatro Navios: Posicionar quatro navios no tabuleiro.

Dois navios devem estar posicionados horizontalmente ou verticalmente (como no nível anterior).

Os outros dois navios deverão ser posicionados na diagonal. Considere que um navio diagonal ocupa posições onde a linha e a coluna aumentam ou diminuem simultaneamente (ex: tabuleiro[i][i] ou tabuleiro[i][9-i] para um tabuleiro 10x10).

Representar as posições ocupadas pelos navios com o valor 3.

Escolha as coordenadas iniciais.

É válido que as posições dos navios estejam dentro dos limites do tabuleiro e que eles não se sobreponham.

Exibir o Tabuleiro: Utilize loops aninados e o comando printf para exibir o tabuleiro completo no console. A saída deve mostrar a matriz 10x10, com 0s representando água e 3s representando as partes dos navios. Utilize espaços para alinhar a saída e facilitar a visualização do tabuleiro.

Requisitos

O programa deve utilizar uma matriz 10x10 para representar o tabuleiro.

O programa deve permitir o posicionamento de quatro navios, sendo dois na diagonal.

O programa deve validar se as coordenadas e o tamanho dos navios são válidos dentro dos limites do tabuleiro.

O programa deve garantir que os navios não se sobreponham.

O programa deve exibir o tabuleiro completo no console com os navios posicionados corretamente.

Requisitos não

Desempenho: O programa deve ser executado de forma eficiente, sem causar atrasos perceptíveis.

Documentação: O código deve ser bem documentado, com comentários claros explicando a lógica e o propósito de cada parte do programa. Utilize comentários para explicar a função de cada variável, loop e bloco de código.

Legibilidade: O código deve ser escrito de forma clara, organizado e fácil de entender, com nomes de variáveis ​​descritivas e recuo consistente.

Simplificações para o nível intermediário

As convenções e tamanhos dos navios são definidas diretamente no código, sem entrada do usuário.

Os navios têm tamanho fixo igual a 3.

A validação de sobreposição de navios pode ser simplificada, mas deve cobrir os casos diagonais.

Não é necessário implementar a lógica do jogo (ataques, acertos, etc.) neste nível.
