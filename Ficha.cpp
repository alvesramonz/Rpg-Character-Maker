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