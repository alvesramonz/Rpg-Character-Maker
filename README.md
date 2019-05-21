# Projeto LPI
Programa para criação e armazenamento de fichas e campanhas de RPG.

Integrantes:
Ramon Alves de Lima Oliveira
Hilton Kevin de Carvalho
Raul Miguel de Souto Santos

O Programa:

O programa de gerenciador de fichas de rpg V1.0 é um programa para criar e administrar fichas para jogos de RPG para um jogador da mesa e também para mestre da mesa que tem como base de dados o livro "7o MAR" RPG, UM OFERECIMENTO DE JOHN WICK E NEW ORDER EDITORA.

IMPLEMENTAÇÃO:

Classes:
O programa de gerenciador de fichas tem como classe base principal a "Ficha.h" que foi implementada sem grandes dificuldades, mas CONTE AQUI ALGUMA DIFICULDADE SOBRE.

A Manipulação de Dados:
O grande forte deste programa é a escrita ordenada em um arquivo ".txt". Automatizando o preenchimento de uma ficha com as funções da classe tudo se tornou mais fácil, por exemplo, criando uma ficha de personagem o método

Instruções:

    Compilação:
        Para compilar esse programa basta execultar o comando "make".
    Utilização:
        Execulte o programa digitando no terminal "./Ficheiro"
        Para limpar os arquivos compilados execute o comando "make clean".
        

 ___________________________________________________ 
|                                                   |  
|       Sistema: 7o Mar (Segunda Edição)            |  
|                                                   |  
|       [1] Adicionar campanha (Mestre)             |  
|       [2] Criação de ficha                        |  
|       [3] Criação de Vilão/Monstro (Mestre)       |    
|       [4] Listar fichas criadas                   | 
|       [5] Opções                                  |
|       [6] Limpar tela                             |
|       [0] Sair                                    |
|___________________________________________________|

[1] - Adicionar campanha (Mestre):
    Nessa opção é possível o usuário, seja ele mestre ou não, criar uma nova campanha. Essa nova campanha terá um arquivo ".txt" com seu nome, assim como um outro arquivo de nome "CampanhaMar.txt" que 
    incluirá todas as campanhas criadas.
        COMO USAR - 
        No menu, digite "1" e pressione "enter" para adicionar uma nova campanha. Logo em seguida responda as perguntas personalizadas para a criação da campanha.
[2] - Criação de ficha:
    Na criação de ficha o usuário segue as instruções que o programa dispõe por meio de frases na tela.
    A criação de ficha segue o mais fiel possível plano de criação das fichas do sistema vigente 7th Sea - Second edition, possuindo na V1.0 formações, perícias, atributos e informações básicas como: nome de campanha, nome de personagem, nome do mestre, nome do jogador, nação, religião e riqueza. Ao fim da criação será feito um arquivo ".txt" com o nome do personagem; no arquivo estará presente uma versão virtualizada de uma ficha de RPG do sistema tratado.
        COMO USAR - 
        No menu, digite "2" e pressione "enter" para criar seu personagem. Logo em seguida responda as perguntas personalizadas para a criação da ficha de seu personagem.
[3] - Criação de Vilão/Monstro (Mestre):
    Na criação do Vilão/Monstro segue um plano muito similar a criação de ficha do comando "2", entretando, como certas peculiaridades. A criação de ficha segue o mais fiel possível plano de criação das fichas de vilão do sistema vigente 7th Sea - Second edition, possuindo na V1.0 nome do mestre, nome da campanha, nome do personagem (vilão) e diferentemente da criação normal de ficha, possui ao invés de formações e atributos, poder/força, vilania e rank (periculosidade). Ao fim da criação será feito um arquivo ".txt" com o nome do personagem/vilão; no arquivo estará presente uma versão virtualizada de uma ficha de RPG do sistema tratado.
        COMO USAR - 
        No menu, digite "3" e pressione "enter" para criar um novo monstro/vilão. Logo em seguida responda as perguntas personalizadas para a criação da ficha de seu monstro/vilão.    
[4] - Listar fichas criadas:
    Nessa opção há listagem de todas as fichas. Presente na lista há o número de fichas criadas, assim como respectivamente suas campanhas, nome de jogador e nome de personagem.
        COMO USAR -     
        No menu, digite "4" e pressione "enter" para aparecer logo em sequência a lista de todas as fichas já criadas. 
[5] - Opções:
    Apresentação 
        COMO USAR- 
        No menu, digite "5" e pressione "enter" para visualizar o menu novamente.
[6] - Limpar tela:
    Essa opção limpa o terminal por meio do comando "system("clear")".
        COMO USAR- 
        No menu, digite "6" e pressione "enter" para limpar todo e ecrã.
[0] - Sair:
    Essa opção fecha o terminal por meio do comando "system("exit")".
    COMO USAR- 
    No menu, digite "0" e pressione "enter" para fechar o terminal/sistema.

IMPLEMENTAÇÃO:

Uma das dificuldades sem dúvida foi a passagem de todo elemente textual do livro original para o código, pois foi necessário configurar a disposição dos caracteres, organizando-os no terminal, a passagem fiel textual é importante para manter a essência do criador do sistema.

Sobrecarga de operador de inserção:
A dificuldade foi de conseguir relacionar os ítens públicos da classe mãe com as da classe filha, devido a passagem do arquivo "NomePersonagem.txt" com todas as especificações de uma ficha de RPG, por exemplo: perícias, atributos e informação de personagem findando no código abaixo.

    std::ostream& operator<< (std::ostream &o, Personagem *Ficha)
    {
    o << "Campanha: " << Ficha->getCampaign_name() <<" - Jogador: " << Ficha->getPlayer_name()<<" - Personagem: "<< Ficha->getCharacter_name();
    return o;
    }

Manipulação de arquivo:
A dificuldade maior dentro da manipulação de arquivo foi a confecção de arquivos com o nome do personagem conectado ao fim ".txt". A solução para esse problema foi a criação de uma função que transformace uma string em um vetor de tipos "char", seguida de uma concatenação dessa transformação junto com o término ".txt", findando na função abaixo:

    char *ConvertStrToCharP(string text)
    {
    char* converted = new char [text.length()+1];
    strcpy (converted, text.c_str());
    return converted;
    }
