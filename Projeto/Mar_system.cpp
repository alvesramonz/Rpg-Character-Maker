

#include <iostream>
#include <fstream>
#include <cstring>
#include "Personagem.h"
#include "Cabecalho.h"
#include "Mar.h"

using namespace std;

/**/
    char *ConvertStrToCharSystem(string text)
    {
    char* converted = new char [text.length()+1];
    strcpy (converted, text.c_str()); /*Esse erro é por causo do <string>, se fosse <cstring> não daria o erro*/
    return converted;
    }

//Construtor
    Mar_system::Mar_system()
    {
        Numero_de_viloes = 0;
        Numero_de_fichas = 0;
        Program_status = true; //Responsável pelo sistema on ou off
    }

//Destrutor
    Mar_system::~Mar_system(){}
//Getters
//Setters
//Funções
    /*Executável do programa, responsável por rodar todas as opções listadas na interface*/
    void Mar_system::Executable()
    {
        while(Program_status)
            {
                int Opcao = Choose_option();
                switch (Opcao)
                    {
                    case 1:
                        Result = Campaign_verification1_0(); 
                        if (Result >=0)
                        {
                            cout << "Digite o nome do mestre da mesa: ";
                            getline(cin, Dungeon_master);
                            Create_campaign(Campaign_name);
                            system("clear");
                        }
                            system("clear");
                            cout << "Esperando novo comando do usuário...\n\n" << endl;
                            Cabecalho_[1]->Sea_menu();
                    break;
                    case 2:
                        Result = Campaign_verification2_1(); 
                        if (Result >=0)
                        {
                            Add_ficha(new Personagem(Campaign_name, Dungeon_master));    
                            cout << "Digite o nome de seu personagem: ";
                            //cin.ignore();
                            getline(cin,Character_name);
                            Result = Character_name_verification(Campaign_name,Character_name);
                            if (Result >=0)
                            {
                                cout << "Digite o seu nome(jogador): ";
                                getline(cin, Player_name);
                                system("clear");
                                Result = Campaign_verification2_2(Campaign_name);
                                Fichas_[Result-1]->Create_character(Player_name, Character_name); 
                            }
                        }
                            system("clear");
                            cout << "Esperando novo comando do usuário...\n\n" << endl;
                            Cabecalho_[1]->Sea_menu();
                    break;
                    case 3:
                        Result = Campaign_verification2_1(); 
                        if (Result >=0)
                        {
                            Add_Villain(new Villain(Campaign_name, Dungeon_master));
                            cout << "Digite o nome de seu Vilão [Ex: Drácula V, Zumbi V, Fulano V]: ";
                            //cin.ignore();
                            getline(cin,Character_name);
                            Result = Character_name_verification(Campaign_name,Character_name);
                            if (Result >=0)
                            {
                                cout << "Digite o seu nome(mestre): ";
                                getline(cin, Player_name);
                                system("clear");
                                Result = Campaign_verification2_2(Campaign_name);
                                Villain_[Result-1]->Create_character(Player_name, Character_name); 
                            }
                        }
                            system("clear");
                            cout << "Esperando novo comando do usuário...\n\n" << endl;
                            Cabecalho_[1]->Sea_menu();
                    break; 
                    }    
            }
    } 

    /**/       
    int Mar_system::Choose_option()
    {
            //Necessidade do 'do' em questão
        do{
            int Usuario_comando;
            cin >> Usuario_comando;

            //Criar nova campanha
            if(Usuario_comando == 1)
            {
                Opcao = 1;
            }else if (Usuario_comando == 2)
            {
                Opcao = 2;
            }else if (Usuario_comando == 3)
            {
                Opcao = 3;
            }
            
        }while(Opcao == 0);  
        return Opcao;
    }

    /**/
    int Mar_system::Campaign_verification1_0()
    {
        cin.ignore();
        cout << "Digite o nome de sua campanha de 7o Mar: ";
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
            sempre vai ser a primeira opção de campanha, ou seja, a primeira campanha registrada.    */
        {
                    cout << "Nome da campanha disponível para uso." << endl;
                    //Interessante ter um retorno de inteiro para a saída da função
                    Verificador = 0;
        }
                    return Verificador;
    }

    /**/
    int Mar_system::Campaign_verification2_1()
    {
        cin.ignore();
        cout << "Digite o nome de sua campanha de 7o Mar: ";
        getline(cin, Campaign_name);

        ifstream FileR;
        string Line;
        int Verificador = -1;

        FileR.open("CampanhasMar.txt"); //Nome do arquivo que irá armazenas as campanhas de 7o Mar
        if(FileR.is_open())
        {
            while(getline(FileR, Line))
            {
                if(Campaign_name == Line)
                {
                    cout << "Nome de campanha verificado..." << endl;
                    //Interessante ter um retorno de inteiro para a saída da função
                    Verificador = 0;
                }            
            }
                if(Verificador >= 0)
                {
                    cout << "Nome da campanha disponível para uso." << endl;
                    //Interessante ter um retorno de inteiro para a saída da função
                    Verificador = 0;
                }else
                {
                    cout << "Nome de campanha inexistente." << endl;
                    cout << "Seu comando: ";
                }          
                FileR.close();
        }
                return Verificador;
    }

    /**/
    int Mar_system::Campaign_verification2_2(string Campaign_name_)
    {

        ifstream FileR;
        string Line;
        int Line_count = 0; /*Esse contador de linhas será essencial para o retorno*/

        FileR.open("CampanhasMar.txt"); //Nome do arquivo que irá armazenas as campanhas de 7o Mar
        if(FileR.is_open())
        {
            while(getline(FileR, Line))
            {
                Line_count++;
                if(Campaign_name_ == Line)
                {
                    break;
                }            
            }        
                FileR.close();
        }
                return Line_count;
    }

    /**/
    int Mar_system::Character_name_verification(string Campaign_name_,string Character_name_)
    {
        fstream File;
        ofstream FileW;
        string Line;
        int Verificador = 0;

        char* Conversor = ConvertStrToCharSystem(Campaign_name_);
        File.open(strcat(Conversor, ".txt"),ios::in); //Nome do arquivo da campanha que terá todos os personagens
        if(File.is_open())
        {
            while(getline(File, Line))
            {
                if(Character_name_ == Line)
                {
                    cout << "Nome de personagem já existe! Tente novamente." << endl;
                    //Interessante ter um retorno de inteiro para a saída da função
                    Verificador = -1;
                }
            }
        }

        if(Verificador >= 0)
                {
                    cout << "Nome de personagem disponível para uso." << endl;
                    FileW.open(Conversor, ios::app);
                    if (FileW.is_open())
                    {
                        FileW << Character_name_ << endl;
                        FileW.close();
                    }else
                    {
                        cout << "Arquivo indisponível! Tente novamente." << endl;
                    }
                }
                    File.close();
                    FileW.close();
                    return Verificador;
    }

    /**/
    void Mar_system::Create_campaign(string Campaign_name_)
    {    
        ofstream File, FileN;

        File.open("CampanhasMar.txt", ios::app);
        char* Conversor = ConvertStrToCharSystem(Campaign_name_);
        FileN.open(strcat(Conversor,".txt"));
        /*Criação de um arquivo "NomeDaCampanha.txt" 
        para a campanha em específica.*/

        if (File.is_open())
        {
            File << Campaign_name_ << endl;
            File.close();
            FileN.close();
        }else
        {
            cout << "Arquivo indisponível! Tente novamente." << endl;
        }
    }

    /**/
    void Mar_system::Add_ficha(Personagem *Fichas)
    {
        if ( Numero_de_fichas < MAX_PERSO)
        {
            Fichas_[Numero_de_fichas++] = Fichas;  
        } 
        else
        {
                cerr << "Nosso sistema não suporta mais ficha no momento, volte mais tarde!" << endl;
        }
    }

    /**/
    void Mar_system::Add_Villain(Villain *Villain)
    {
        if ( Numero_de_viloes < MAX_VILLA)
        {
            Villain_[Numero_de_viloes++] = Villain;  
        } 
        else
        {
                cerr << "Nosso sistema não suporta mais ficha no momento, volte mais tarde!" << endl;
        }
    }
