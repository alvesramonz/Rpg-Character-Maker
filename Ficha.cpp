/*  Funções da classe "Ficha":
    -Adicionar Campanha -> (Create_campaign)
        i.Verificação do nome da campanha -> (Campaign_verification)
    -Criar Ficha -> (Create_character)
        i.Verificação do nome da ficha -> (Character_name_verification)
    
    Ps.: Ficha.h é exclusivamente para 7o Mar, por enquanto até resolver a questão de herança.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "Ficha.h"

using namespace std;

/*      Campaign_verification()
    Verifica se o nome da campanha esta disponível para uso
        Variaveis utilizadas:
        -string Campaign_name
        -<arquivo> FileR - R de leitura, File do arquvio
        -string Line 
        -Verificador - É a saída da função para usar posteriormente em outras situações

        Ps.: Campaign_verification ainda é void, mas posteriormente irá se tornar um int com retorno
*/
void Ficha::Campaign_verification()
{
    cout << "Digite o nome de sua campanha de 7o Mar: " << endl;
    getline(cin, Campaign_name);

    ifstream FileR;
    string Line;
    int Verificador = 0;

    FileR.open("CampanhasMar.txt"); //Nome do arquivo que irá armazenas as campanhas de 7o Mar
    if(FileR.is_open())
    {
        while(getline(FileR, Line))
        {
            if(Campaign_name == Line)
            {
                cout << "Nome de campanha existente! Tente novamente." << endl;
                //Interessante ter um retorno de inteiro para a saída da função
                //Verificador = -1;
            }
        }
            if(Verificador >= 0)
            {
                cout << "Nome da campanha disponível para uso." << endl;
                //Interessante ter um retorno de inteiro para a saída da função
                //Verificador = 0;
            }
            FileR.close();
    }else 
    /*  Nesse caso do 'else' o arquivo ainda não vai estar aberto porque o mesmo não existe, sendo assim esse caso
        sempre vai ser a primeira opção de campanha, ou seja, a primeira campanha registrada.

        Outra alternativa é que como abrirá lá em cima um arquivo de mesmo nome esse Else seja atoa...
    */
    {
                cout << "Nome da campanha disponível para uso." << endl;
                //Interessante ter um retorno de inteiro para a saída da função
                //Verificador = 0;
    }
                //Interessante ter um retorno de inteiro para a saída da função (Verificador)
                //Return Verificador;
}

/*      Create_campaign()
    Criação de um arquivo com todas as campanhas de UM sistema utilizando "ios::app" para incluir sempre
    as campanhas e não as sobrescrever
        Variaveis utilizadas:
        -string Campaign_name 
        -<arquivo> File - nesse caso sendo escrito
*/
void Ficha::Create_campaign(string Campaign_name_)
{    
    ofstream File;

    File.open("CampanhasMar.txt", ios::app);
        strcat(Campaign_name_,".txt"); //Criação de um arquivo "NomeDaCampanha.txt" 
                                     //para a campanha em específica.

    if (File.is_open())
    {
        File << Campaign_name_ << endl;
        //Possivel modificação futura para utilização do strtok
        File.close();
    }else
    {
        cout << "Arquivo indisponível! Tente novamente." << endl;
    }
}

/*      Character_name_verification()
    Recebe um nome e o verifica com base na campanha se é possível a utilização do nome,
    pois não é permitido dois nomes iguais numa mesma campanha.
        Variaveis utilizadas:
        -string Campaign_name_
        -string Character_name_
        -string Line
        -int Verificador - É a saída da função para usar posteriormente em outras situações
        -<arquivo> FileR - R de leitura, File do arquvio

        Ps.: Character_name_verification ainda é void, mas posteriormente irá se tornar um int com retorno
*/
void Ficha::Character_name_verification(string Campaign_name_,string Character_name_)
{
    ifstream FileR;
    string Line;
    int Verificador = 0;

    FileR.open(strcat(Campaign_name_, ".txt")); //Nome do arquivo da campanha que terá todos os personagens
    if(FileR.is_open())
    {
        while(getline(FileR, Line))
        {
            if(Character_name_ == Line)
            {
                cout << "Nome de personagem já existe! Tente novamente." << endl;
                //Interessante ter um retorno de inteiro para a saída da função
                //Verificador = -1;
            }
        }
            FileR.close();
            if(Verificador >= 0)
            {
                cout << "Nome de personagem disponível para uso." << endl;
                ofstream File;
                File.open(strcat(Campaign_name_, ".txt"), ios::app);
                if (File.is_open())
                {
                    File << Character_name_ << endl;
                    File.close();
                }else
                {
                    cout << "Arquivo indisponível! Tente novamente." << endl;
                }
                //Interessante ter um retorno de inteiro para a saída da função
                //Verificador = 0;
            }
    }
}

/*      Create_character()
    Recebe um nome de personagem, após ter ocorrido uma verificação no uso do nome na campanha e um nome de jogador.
    Ou seja dentro da campanha não pode haver outro personagem de mesmo nome. Essa etapa é responsável
    pelo armazenamento das informações do personagem, atributos, perícias, vantagens e arcanas do jogador.
    Tudo incluso em um arquivo único "Personagem.txt" já com formatação

    Ps.: Necessitando ainda da inclusão do construtos e possivel mudança dos nomes para os seus respectivos
    setters;
    Ps2.: Suposta e futura necessidade de um indice na entrada da função.
*/
void Ficha::Create_character(string Character_name_) 
{
    ofstream File;
    File.open(strcat(Character_name_, ".txt"), ios::app);

//Informações do Personagem
    cout << "A partir de agora será feito o registro das informações do personagem, fique atento!" << endl;
    cout << "É muito importante que antes de fazer essa etapa o jogador já tenha em mente como será seu personagem." << endl;
    cout << "Digite o nome do jogador: " << endl;
    getline(cin, Player_name);
    //cout << "Digite o nome do personagem: " << endl; Não precisa, pois já se recebe
    cout << "Digite uma frase curta que defina seu personagem, ou seja, seu conceito: " << endl;
    getline(cin, Concept);
    cout << "Digite a religião de seu personagem (caso não tenha digite Ateu, mas religião é muito importante): " << endl;
    getline(cin, Religion);
    cout << "Digite se seu personagem possui reputação, caso não tenha digite 'SEM': " << endl;
    getline(cin, Reputation);
    cout << "Digite quanto é sua riqueza, ou seja, o valor sua perícia mais alta: " << endl;
    cin >> Richness;
        /*
        Ficha_[i]-> setRichness(Richness)
        Ps.: Ficha_[i] é a classe de cada ficha criada de 7o Mar
        */
//Término das informações do personagem

//Atributos
    cout << "Começamos agora a parte dos atributos, mas antes..." << endl;
    cout << "No sistema de 7o Mar está disponíveis 'DEZ' nações, sendo estas:" << endl;
    //Tabela de nações e seus bônus
    cout << "-Avalon -> +1 Panache OU +1 Determinação ()-Inishmore -> +1 Panache OU +1 Argúcia ()-As Terras Altas -> +1 Vigor OU +1 Finesse ()-Castilha -> +1 Finesse ou +1 Argúcia ()-Eisen -> +1 Vigor OU +1 Determinação ()-Montaigne -> +1 Finesse OU +1 Panache ()-Sarmácia -> +1 Vigor OU +1 Panache ()-Ussura -> +1 Determinação OU +1 Argúcia ()-Vesten -> +1 Vigor OU +1 Argúcia ()-Vodacce -> +1 Finesse OU +1 Determinação " << endl;
    cout << "Digite a nação de seu personagem (Primeira letra maiuscula): " << endl;
    getline(cin, Nation);
    cout << "Agora escolhida nação é importante escolher qual dos bônus você deseja acrescentar em seus atributos (Ex.: +1 Panache, digite Panache): " << endl;
    getline(cin, Attribute);
    Attribute_bonus(Attribute);
    cout << "Como regra de sistema agora escolha um atributo para aumentar em um ponto: " << endl;
    getline(cin, Attribute);
    Attribute_bonus(Attribute);
    cout << "Como regra de sistema agora escolha outro atributo ou o mesmo anterior para aumentar em um ponto: " << endl;
    getline(cin, Attribute);
    Attribute_bonus(Attribute);
        /*      Ficha_[i]-> Attribute_bonus(Attribute); 
                Ps.: Possivelmente seja assim
                Ps2.: Inclusão dos setters no fim.
        */
//Fim dos atributos

//Formações
//Fim das formações

//Perícias

//Fim das perícias
//Vantagens

//Fim das vantagens
//Arcana

//Fim da arcana
}