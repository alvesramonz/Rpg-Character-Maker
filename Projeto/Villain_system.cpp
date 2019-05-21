#include <iostream>
#include <fstream>
#include <cstring>
#include "Villain.h"

using namespace std;

/**/
    char *ConvertStrToCharV(string text)
    {
    char* converted = new char [text.length()+1];
    strcpy (converted, text.c_str());
    return converted;
    }

//Construtor
    Villain::Villain(string Campaign_name_, string Dungeon_master_){}

//Destrutor
    Villain::~Villain(){}

//Getters
    //Atributos
        int Villain::getVillainy()
        {
            return Villainy;
        }
        int Villain::getPower()
        {
            return Power;
        }
        int Villain::getRank()
        {
            return Rank;
        }
//Setters
    //Atributos
        void Villain::setVillainy(int Villainy_)
        {
            Villainy = Villainy_;
        }
        void Villain::setPower(int Power_)
        {
            Power = Power_;
        }
        void Villain::setRank(int Rank_)
        {
            Rank = Rank_;
        }
//Funções

    /**/
    void Villain::Create_character(string Player_name_,string Character_name_) 
    {
        ofstream File;
        char* Conversor = ConvertStrToCharV(Character_name_);
        File.open(strcat(Conversor, ".txt"), ios::app);
        setPlayer_name(Player_name_);
        setCharacter_name(Character_name_);
        
        //Informações do Personagem
            cout << "A partir de agora será feito o registro das informações do seu Vilão, fique atento!" << endl;
            cout << "\n\nDigite a religião ddo seu Vilão (caso não tenha digite Ateu, mas religião é muito importante): ";
            getline(cin, Religion);
            setReligion(Religion);
            system("clear");
            cout << "Digite quanto é a riqueza do Vilão (riqueza em vilões não é tão relevante): ";
            cin >> Richness;
            setRichness(Richness);
            system("clear");
          //Atributos
              cout << "Começamos agora a parte dos atributos, mas antes...";
              cout << " No sistema de 7o Mar está disponíveis 'DEZ' nações, sendo estas:\n" << endl;
              /*Tabela de nações e seus bônus*/
              cout << "-Avalon -> +1 Panache OU +1 Determinação \n-Inishmore -> +1 Panache OU +1 Argúcia \n-As Terras Altas -> +1 Vigor OU +1 Finesse \n-Castilha -> +1 Finesse ou +1 Argúcia \n-Eisen -> +1 Vigor OU +1 Determinação \n-Montaigne -> +1 Finesse OU +1 Panache \n-Sarmácia -> +1 Vigor OU +1 Panache \n-Ussura -> +1 Determinação OU +1 Argúcia \n-Vesten -> +1 Vigor OU +1 Argúcia \n-Vodacce -> +1 Finesse OU +1 Determinação " << endl;
              cout << "Digite a nação de seu personagem (Primeira letra maiuscula): ";
              cin.ignore();              
              getline(cin, Nation);
              setNation(Nation);
              cout << "\n\nTodo vilão se sustenta em dois pilares, sua FORÇA e sua INFLUÊNCIA. ";
              cout << "Força é seu atributo física referente a seu vigor, sua constituição. Influência seria seu poder social, por exeplo." << endl;
              cout << "Sabendo disso agora digite a FORÇA de seu Vilão: ";
              cin >> Power;
              setPower(Power);
              cout << "Sabendo disso agora digite a INFLUÊNCIA de seu Vilão: ";
              cin >> Villainy;
              setVillainy(Villainy);
              system("clear");
          //Perícias
              cout << "Começaremos agora a parte das perícias.Agora você como mestre escolherá quantos pontos deseja gastar [Ex: 10,15,20,25]: ";
              int Pontos_;
              cin >> Pontos_;  
              cin.ignore();
              cout << "\nEsses " << Pontos_ << " pontos serão gastos para aumentar ou comprar novas perícias, não é permitido deixar pontos sobrando.\n" << endl;
              Expertise(Pontos_);
          //Vantagens
          //Impressão da ficha
                if(File.is_open())
                    {
                        File << "_________________________________________________________________________" << endl;
                        File << "------------INFORMAÇÕES DO PERSONAGEM:" << endl;
                        File << "JOGADOR:" <<getPlayer_name()<< endl; 
                        File << "PERSONAGEM:" <<getCharacter_name() << endl;      
                        File << "NAÇÃO:" <<getNation() << endl;                
                        File << "RELIGIÃO:" <<getReligion()<< endl;                                                        
                        File << "RIQUEZA:" <<getRichness()<< endl;         
                        File << "_________________________________________________________________________" << endl; 
                        File << "----ATRIBUTOS:--|-------------PERÍCIAS:----------------|11111111111111|" << endl; 
                        File << "                |-MIRAR:"<<getMirar()<<"            -ATUAR:"<<getAtuar()<<"          |11---------111|" << endl; 
                        File << "                |-ATLETISMO:"<<getAtletismo()<<"        -CAVALGAR:"<<getCavalgar()<<"       |11---------111|" << endl; 
                        File << "-FORÇA:"<<getPower()<<"        |-BRIGA:"<<getBriga()<<"            -NAVEGAR:"<<getNavegar()<<"        |----------1111|" << endl; 
                        File << "-INFLUENCIA:"<<getVillainy()<<"   |-CONVENCER:"<<getConvencer()<<"        -ERUDIÇÃO:"<<getErudicao()<<"       |--------111111|" << endl; 
                        File << "                |-EMPATIA:"<<getEmpatia()<<"          -SEDUZIR:"<<getSeduzir()<<"        |------11111---|" << endl; 
                        File << "                |-ESCONDER:"<<getEsconder()<<"         -FURTO:"<<getFurto()<<"          |-----1111-----|" << endl; 
                        File << "                |-INTIMIDAR:"<<getIntimidar()<<"        -ARTE DA GUERRA:"<<getArte_da_Guerra()<<" |-----111------|" << endl; 
                        File << "                |-OBSERVAR:"<<getObservar()<<"         -ARMAS:"<<getArmas()<<"          |-----111------|" << endl; 
                        File << "________________|______________________________________|-----111------|" << endl;  
                        }
    }

    /**/
    void Villain::Expertise(int Pontos_)
    {
        string Expertise_;

        do
        {   
            setMirar(Mirar), setAtletismo(Atletismo), setBriga(Briga), setConvencer(Convencer), setEmpatia(Empatia), setEsconder(Esconder), setIntimidar(Intimidar), setObservar(Observar);
            setAtuar(Atuar), setCavalgar(Cavalgar), setNavegar(Navegar), setErudicao(Erudicao), setSeduzir(Seduzir), setFurto(Furto), setArte_da_Guerra(Arte_da_Guerra), setArmas(Armas);

            cout << "\n\n\t\tVoce possui > " << Pontos_ << " < pontos para gastar em perícias." << endl;
            cout << "A seguir haverá a tabela da suas atuais perícias advindas de suas formações e perícias já aumentadas.";
            cout << "Para aumenta-las (pericias) verifique se o custo delas está de acordo com seus pontos restante: Custo = Nível Atual + 1" << endl;       
            //Tabela de perícias                
                cout << "\n\n|-MIRAR:       " << getMirar() <<"\t\t"<< "-ATUAR:           " << getAtuar() << "|" << endl;
                cout << "|-ATLETISMO:   " << getAtletismo() <<"\t\t"<< "-CAVALGAR:        " << getCavalgar() << "|" << endl;
                cout << "|-BRIGA:       " << getBriga() <<"\t\t"<< "-NAVEGAR:         " << getNavegar() << "|" << endl;
                cout << "|-CONVENCER:   " << getConvencer() <<"\t\t"<< "-ERUDIÇÃO:        " << getErudicao() << "|" << endl;
                cout << "|-EMPATIA:     " << getEmpatia() <<"\t\t"<< "-SEDUZIR:         " << getSeduzir() << "|" << endl;
                cout << "|-ESCONDER:    " << getEsconder() <<"\t\t"<< "-FURTO:           " << getFurto() << "|" << endl;
                cout << "|-INTIMIDAR:   " << getIntimidar() <<"\t\t"<< "-ARTE DA GUERRA:  " << getArte_da_Guerra() << "|" << endl;
                cout << "|-OBSERVAR:    " << getObservar() <<"\t\t"<< "-ARMAS:           " << getArmas() << "|" << endl;                
            //Fim da tabela
            
            cout << "Escolha sua perícia para aumentar: ";
            getline(cin,Expertise_);
            Pontos_ =Expertise_calc(Expertise_, Pontos_);
        } while (Pontos_ > 0);
    }

    /**/
    int Villain::Expertise_calc(string Expertise_, int Pontos_)
    {
        int Pontos_final = 0;

        if(Expertise_ == "Mirar")
        {
            if((Pontos_ - Mirar) > 0)
            {
                Mirar++;
                Pontos_final = Pontos_ - Mirar; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Atletismo")
        {
            if((Pontos_ - Atletismo) > 0)
            {
                Atletismo++;
                Pontos_final = Pontos_ - Atletismo; 
                return Pontos_final;

            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Briga")
        {
            if((Pontos_ - Briga) > 0)
            {
                Briga++;
                Pontos_final = Pontos_ - Briga; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Convencer")
        {
                    if((Pontos_ - Convencer) > 0)
            {
                Convencer++;
                Pontos_final = Pontos_ - Convencer; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Empatia")
        {
            if((Pontos_ - Empatia) > 0)
            {
                Empatia++;
                Pontos_final = Pontos_ - Empatia; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Esconder")
        {
            if((Pontos_ - Esconder) > 0)
            {
                Esconder++;
                Pontos_final = Pontos_ - Esconder; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Intimidar")
        {
            if((Pontos_ - Intimidar) > 0)
            {
                Intimidar++;
                Pontos_final = Pontos_ - Intimidar; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }
        }else if (Expertise_ == "Observar")
        {
            if((Pontos_ - Observar) > 0)
            {
                Observar++;
                Pontos_final = Pontos_ - Observar; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }    
        }else if (Expertise_ == "Atuar")
        {
            if((Pontos_ - Atuar) > 0)
            {
                Atuar++;
                Pontos_final = Pontos_ - Atuar; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }      
        }else if (Expertise_ == "Cavalgar")
        {
            if((Pontos_ - Cavalgar) > 0)
            {
                Cavalgar++;
                Pontos_final = Pontos_ - Cavalgar; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }            
        }else if (Expertise_ == "Navegar")
        {
            if((Pontos_ - Navegar) > 0)
            {
                Navegar++;
                Pontos_final = Pontos_ - Navegar; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }            
        }else if (Expertise_ == "Erudição")
        {
            if((Pontos_ - Erudicao) > 0)
            {
                Erudicao++;
                Pontos_final = Pontos_ - Erudicao; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }           
        }else if (Expertise_ == "Seduzir")
        {
            if((Pontos_ - Seduzir) > 0)
            {
                Seduzir++;
                Pontos_final = Pontos_ - Seduzir; 
                return Pontos_final;            return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }            
        }else if (Expertise_ == "Furto")
        {
            if((Pontos_ - Furto) > 0)
            {
                Furto++;
                Pontos_final = Pontos_ - Furto; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }            
        }else if (Expertise_ == "Arte da guerra")
        {
            if((Pontos_ - Arte_da_Guerra) > 0)
            {
                Arte_da_Guerra++;
                Pontos_final = Pontos_ - Arte_da_Guerra; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }            
        }else if (Expertise_ == "Armas")
        {
            if((Pontos_ - Armas) > 0)
            {
                Armas++;
                Pontos_final = Pontos_ - Armas; 
                return Pontos_final;
            }else
            {
                cout << "Não é possivel aumentar essa perícia!! Pontos insuficientes!!" << endl;
            }            
        }else
        {
            cout << "Nome da perícia digitada está incorreto." << endl;
        } 
            return Pontos_final;
    }