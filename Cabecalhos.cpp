/*
    Cabeçalhos:
    -Apresentação -> (Presentation)
    -Escolher Sistema -> (Choose_system)
    -Opção 7o Mar (2a Edição) -> (Sea_menu)
    -Cabeçalho de exposição de todas as profissões já com suas respectivas pericias e vantagens -> (Professions)

    Ps.: Interessante acrescentar aqui nesse número de versão sempre que atualizado ou commitado por nós. 
    Ps.: V0.5
*/

#include <iostream>
using namespace std;

void Presentation()
{
    cout << "      ___________________________________________________ "  << endl;
    cout << "     |                                                   |" << endl;
    cout << "     |Seja bem vindo ao gerenciador de fichas de rpg V1.0|" << endl;
    cout << "     |                                                   |" << endl;
    cout << "     |Neste programa será possível a criação de fichas e |" << endl; 
    cout << "     |gerenciamentos de campanhas. O nosso objetivo é aju|" << endl;
    cout << "     |dar o mestre e toda sua mesa a se organizarem da me|" << endl;
    cout << "     |lhor e mais simplista forma para que toda diversão |" << endl;
    cout << "     |seja totalmente garantida. Na versão atual temos su|" << endl;
    cout << "     |porte para o sistema de 'Tormenta Rpg' e '7o Mar 2a|" << endl;
    cout << "     |edição'. Então aproveite! De jogador para jogador! |" << endl;
    cout << "     |___________________________________________________|" << endl;
}

void Choose_system()
{
    cout << "      ___________________________________________________ " << endl;
    cout << "     |                                                   |" << endl; 
    cout << "     |       Para prosseguir escolha seu sistema:        |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |       > Tormenta (Rpg)                            |" << endl; 
    cout << "     |       > 7o Mar (2a Edição)                        |" << endl; 
    cout << "     |                                                   |" << endl;
    cout << "     |       > Sair                                      |" << endl;
    cout << "     |___________________________________________________|" << endl; 
}

void Sea_menu()
{
    cout << "      ___________________________________________________ " << endl;
    cout << "     |                                                   |" << endl;  
    cout << "     |       Sistema: 7o Mar (Segunda Edição)            |" << endl;  
    cout << "     |                                                   |" << endl;  
    cout << "     |       > Adicionar campanha (Mestre)               |" << endl;  
    cout << "     |       > Criação de ficha                          |" << endl;  
    cout << "     |       > Criação de Vilão/Monstro (Mestre)         |" << endl;  
    cout << "     |       > Apagar ficha                              |" << endl;  
    cout << "     |       > Listar fichas                             |" << endl;  
    cout << "     |       > Listar fichas p/Jogador                   |" << endl; 
    cout << "     |       > Listar fichas p/Campanha                  |" << endl;
    cout << "     |       > Listar fichas do mestre (Mestre)          |" << endl;
    cout << "     |       > Buscar ficha                              |" << endl;
    cout << "     |       > Voltar para escolha de sistema            |" << endl; 
    cout << "     |       > Opções                                    |" << endl;
    cout << "     |       > Limpar tela                               |" << endl;
    cout << "     |       > Ajuda                                     |" << endl; 
    cout << "     |       > Sair                                      |" << endl;
    cout << "     |___________________________________________________|" << endl;
}

void Professions()
{
    cout << "      ___________________________________________________ " << endl;
    cout << "     |                                                   |" << endl;  
    cout << "     |       Sistema: 7o Mar (Segunda Edição)            |" << endl;  
    cout << "     |                                                   |" << endl;  
    cout << "     |       > FORMAÇÕES BÁSICAS                         |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |       > ATOR                                      |" << endl; 
    cout << "     |       > ARISTOCRATA                               |" << endl; 
    cout << "     |       > ARQUEÓLOGO                                |" << endl; 
    cout << "     |       > ARTÍFICE                                  |" << endl; 
    cout << "     |       > ARTISTA                                   |" << endl; 
    cout << "     |       > ASSASSINO                                 |" << endl; 
    cout << "     |       > CAÇADOR                                   |" << endl; 
    cout << "     |       > CONTRAMESTRE                              |" << endl; 
    cout << "     |       > CAPITÃO DO MAR                            |" << endl; 
    cout << "     |       > CRIADO                                    |" << endl; 
    cout << "     |       > CRIMINOSO                                 |" << endl; 
    cout << "     |       > DIVISÃO DE CAVALARIA                      |" << endl; 
    cout << "     |       > DOCENTE                                   |" << endl; 
    cout << "     |       > DUELISTA                                  |" << endl; 
    cout << "     |       > ENGENHEIRO                                |" << endl; 
    cout << "     |       > ESPIÃO                                    |" << endl;  
    cout << "     |       > ESTUDIOSO                                 |" << endl; 
    cout << "     |       > EXPLORADOR                                |" << endl; 
    cout << "     |       > MARINHEIRO                                |" << endl; 
    cout << "     |       > MÉDICO                                    |" << endl; 
    cout << "     |       > MERCADOR                                  |" << endl; 
    cout << "     |       > MERCENÁRIO                                |" << endl; 
    cout << "     |       > OFICIAL DO EXÉRCITO                       |" << endl; 
    cout << "     |       > OFICIAL DA MARINHA                        |" << endl; 
    cout << "     |       > ÓRFÃO                                     |" << endl; 
    cout << "     |       > PALACIANO                                 |" << endl; 
    cout << "     |       > PIRATA                                    |" << endl; 
    cout << "     |       > PUGILISTA                                 |" << endl; 
    cout << "     |       > RAMEIRA                                   |" << endl; 
    cout << "     |       > ROCEIRO                                   |" << endl; 
    cout << "     |       > SACERDOTE                                 |" << endl; 
    cout << "     |       > SOLDADO                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |       > FORMAÇÕES DAS ILHAS DO GLAMOUR            |" << endl; 
    cout << "     |       > FORMAÇÕES DE AVALON                       |" << endl;  
    cout << "     |       > FORMAÇÕES DE INISHMORE                    |" << endl; 
    cout << "     |       > FORMAÇÕES DAS TERRAS ALTAS                |" << endl; 
    cout << "     |       > FORMAÇÕES DE CASTILHA                     |" << endl; 
    cout << "     |       > FORMAÇÕES DE EISEN                        |" << endl; 
    cout << "     |       > FORMAÇÕES DE MONTAIGNE                    |" << endl; 
    cout << "     |       > FORMAÇÕES DA SAMÁRCIA                     |" << endl; 
    cout << "     |       > FORMAÇÕES DE USSURA                       |" << endl; 
    cout << "     |       > FORMAÇÕES DE VESTENMENNAVENJAR            |" << endl; 
    cout << "     |       > FORMAÇÕES DE VODACCE                      |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |___________________________________________________|" << endl;
}

void Advantages()
{
    cout << "      ___________________________________________________ " << endl;
    cout << "     |                                                   |" << endl;  
    cout << "     |       Sistema: 7o Mar (Segunda Edição)            |" << endl;  
    cout << "     |                                                   |" << endl; 
    cout << "     |       > VANTAGENS                                 |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |       > VANTAGENS DE 1 PONTO                      |" << endl; 
    cout << "     |                                                   |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |       >                                           |" << endl; 
    cout << "     |___________________________________________________|" << endl;
}

