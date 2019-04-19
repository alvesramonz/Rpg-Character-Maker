/*
    Cabeçalhos:
    -Apresentação -> (Presentation)
    -Escolher Sistema -> (Choose_system)
    -Opção 7o Mar (2a Edição) -> (Sea_menu)
    -Cabeçalho de exposição de todas as profissões já com suas respectivas pericias e vantagens -> (Professions)

    Ps.: Interessante acrescentar aqui nesse número de versão sempre que atualizado ou commitado por nós. 
    Ps.: V0.2
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