/*
    Aqui presente neste será toda parte do código responsavel por orquestrar a "execução"
    Aqui presente será uma 'classe'(função) executora
*/

#include <iostream>
#include <fstream>
#include "Ficha.h"
#include "Cabecalhos.h"
#include "Mar.h"

using namespace std;

/*      Função que converter string para char[]
    O motivo desta função é par aabertura de aquivos .txt por meio do strcat
*/
char *ConvertStrToCharSystem(string text)
{
char* converted = new char [text.length()+1];
strcpy (converted, text.c_str());
return converted;
}

//Construtor
Rpg_System::Rpg_System()
{
      Numero_de_fichas = 0;
      Program_status = true; //Responsável pelo sistema on ou off
}

//Destrutor
Rpg_System::~Rpg_System(){}

//Executável, responsável pro rodar cada caso
void Rpg_System::Executable()
{
    /*
        While(1) = Enquanto verdadeiro, sendo, sempre. 
        Ps: Feito para ser mantido em loop mesmo.
    */
    while(Program_status)
    {
        int Opcao = Choose_option();
        switch (Opcao)
    //[1]Adicionar uma nova campanha
        {
            case 1:
            Result = Campaign_verification(); 
            /*Possivelmente caso aqui der erro é porque precise de um objeto para acessar essa função X->Verification() a  não ser que essa função seja de Rpg_system */
            if (Result >=0)
            {
                cout << "Digite novamente o nome da nova campanha: " << endl;
                getline(cin,Campaign_name);
                Create_campaign(Campaign_name);
                cout << "Esperando novo comando do usuário..." << endl;
                cout << "      Seu comando: ";
            }
        break;
    //[2]Criação de Ficha
        case 2: 
            cout << "Digite o nome da sua campanha: " << endl;
            cin.ignore();
            getline(cin,Campaign_name);
            /*Essa campanha não existe = Campaign_verification se for 1 ou 0 pode continuar*/
            cout << "Digite o nome de seu personagem: " << endl;
            getline(cin,Character_name);
            Result = Character_name_verification(Campaign_name,Character_name);
            /*Possivelmente caso aqui der erro é porque precise de um objeto para acessar essa função X->Verification() a  não ser que essa função seja de Rpg_system */
            if (Result >=0)
            {
                Add_ficha(new Ficha(Character_name,Campaign_name));
                Fichas_[Numero_de_fichas]->Create_character(Character_name); //PAREI AQUI
            }
                cout << "Esperando novo comando do usuário..." << endl;
                cout << "      Seu comando: ";
        break;
    //[3]Limpar tela não precisa de um "case"
    //[4]Opções
        case 6:
            Cabecalho_[1]->Sea_menu();
        break;
    //[5]Sair
        case 7:
            Program_status=false;
            cout << "Esperamos você em uma próxima vez!" << endl;
        break;
        }
    }
}

/*  Escolha da opção do usuário:
Responsável por receber a opção digitada do usuário e aplicar a alguma função, confira os casos em
void Rpg_System::Executable(){}, pois deste ponto o próximo é essa função
*/
int Rpg_System::Choose_option()
{
        //Necessidade do 'do' em questão
    do{
        int Usuario_comando;
        cin >> Usuario_comando;

        //Criar nova campanha
        if(Usuario_comando == 1)
        {
            Opcao = 1;
        }
        //Criação de uma nova ficha
        else if(Usuario_comando == 2 )
        {
            Opcao = 2;
        }
        //Limpar a tela
        else if(Usuario_comando == 12 )
        {
            system("clear");
            Cabecalho_[1]->Sea_menu();
            Opcao = 0;
        }
        //Sair do programa
        else if(Usuario_comando == 0 )
        {
            Opcao = 7;
        }
        //Opções
        else if(Usuario_comando == 11 )
        {
            Opcao = 6;
        }
    }while(Opcao == 0);  
    return Opcao;
}

/*  Adicionar ficha ao sistema:
Adicionando ficha ao sistema, em resumo aqui é só registrado o número crescente de fichas, ou seja, vai se acumulando o número
de fichas no sistema com um limite de 10 fichas, não mais que isso. 
*/
void Rpg_System::Add_ficha(Ficha *Fichas)
{
    if ( Numero_de_fichas < MAX_FICHAS)
    {
        Fichas_[Numero_de_fichas++] = Fichas;  
    } 
    else
    {
            cerr << "Nosso sistema não suporta mais ficha no momento, volte mais tarde!" << endl;
    }
}

/*      Campaign_verification()
    Verifica se o nome da campanha esta disponível para uso
        Variaveis utilizadas:
        -string Campaign_name
        -<arquivo> FileR - R de leitura, File do arquvio
        -string Line 
        -Verificador - É a saída da função para usar posteriormente em outras situações

        Ps.: Campaign_verification ainda é void, mas posteriormente irá se tornar um int com retorno
*/
int Rpg_System::Campaign_verification()
{
    cin.ignore();
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
                cout << "Seu comando: "; 
                //Interessante ter um retorno de inteiro para a saída da função
                Verificador = -1;
                return Verificador;
            }
        }
            if(Verificador >= 0)
            {
                cout << "Nome da campanha disponível para uso." << endl;
                //Interessante ter um retorno de inteiro para a saída da função
                Verificador = 0;
                return Verificador;

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
                Verificador = 0;
    }
                return Verificador;
}

/*      Create_campaign()
    Criação de um arquivo com todas as campanhas de UM sistema utilizando "ios::app" para incluir sempre
    as campanhas e não as sobrescrever
        Variaveis utilizadas:
        -string Campaign_name 
        -<arquivo> File - nesse caso sendo escrito
*/
void Rpg_System::Create_campaign(string Campaign_name_)
{    
    ofstream File,FileN; //FileN de New

    File.open("CampanhasMar.txt", ios::app);
    /*  Conversor de String para Char* (char[])
        string String_convertida = Campaign_name_;
        int String_tamanho = String_convertida.length();
        char Char_convertida[String_tamanho + 1];
        strcpy(Char_convertida, String_convertida.c_str());
    */
    char* Conversor = ConvertStrToCharSystem(Campaign_name_);
    FileN.open(strcat(Conversor,".txt"));
    /*Criação de um arquivo "NomeDaCampanha.txt" 
    para a campanha em específica.*/

    if (File.is_open())
    {
        File << Campaign_name_ << endl;
        //Possivel modificação futura para utilização do strtok
        File.close();
        FileN.close();
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
int Rpg_System::Character_name_verification(string Campaign_name_,string Character_name_)
{
    ifstream FileR;
    string Line;
    int Verificador = 0;

    char* Conversor = ConvertStrToCharSystem(Campaign_name_);
    FileR.open(strcat(Conversor, ".txt")); //Nome do arquivo da campanha que terá todos os personagens
    if(FileR.is_open())
    {
        while(getline(FileR, Line))
        {
            if(Character_name_ == Line)
            {
                cout << "Nome de personagem já existe! Tente novamente." << endl;
                //Interessante ter um retorno de inteiro para a saída da função
                Verificador = -1;
            }
        }
            FileR.close();
            if(Verificador >= 0)
            {
                cout << "Nome de personagem disponível para uso." << endl;
                ofstream File;
                File.open(strcat(Conversor, ".txt"), ios::app);
                if (File.is_open())
                {
                    File << Character_name_ << endl;
                    File.close();
                }else
                {
                    cout << "Arquivo indisponível! Tente novamente." << endl;
                }
                //Interessante ter um retorno de inteiro para a saída da função
            }
    }
                return Verificador;
}