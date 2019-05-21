
#include <iostream>
#include <fstream>
#include <string>
#include "Personagem.h"
#include "Mar.h"
#include "Cabecalho.h"

using namespace std; 

/**/
    char *ConvertStrToCharP(string text)
    {
    char* converted = new char [text.length()+1];
    strcpy (converted, text.c_str());
    return converted;
    }

//Construtor
    Personagem::Personagem(string Campaign_name_, string Dungeon_master_){}

//Destrutor
    Personagem::~Personagem(){}
//Getters
    //Formações
        string Personagem::getFormationI()
        {
            return FormationI;
        }
        string Personagem::getFormationII()
        {
            return FormationII;
        }
    //Atributos
        int Personagem::getVigor()
        {
            return Vigor;
        }
        int Personagem::getFinesse()
        {
            return Finesse;
        }
        int Personagem::getArgucia()
        {
            return Argucia;
        }
        int Personagem::getDeterminacao()
        {
            return Determinacao;
        }
        int Personagem::getPanache()
        {
            return Panache;
        }
//Setters  
    //Formações
        void Personagem::setFormationI(string FormationI_)
        {
            FormationI = FormationI_;
        }
        void Personagem::setFormationII(string FormationII_)
        {
            FormationII = FormationII_;
        }
    //Atributos
        void Personagem::setVigor(int Vigor_)
        {
            Vigor = Vigor_;
        }
        void Personagem::setFinesse(int Finesse_)
        {
            Finesse = Finesse_;
        }
        void Personagem::setArgucia(int Argucia_)
        {
            Argucia = Argucia_;
        }
        void Personagem::setDeterminacao(int Determinacao_)
        {
            Determinacao = Determinacao_;
        }
        void Personagem::setPanache(int Panache_)
        {
            Panache = Panache_;
        }  
//Funções

    /**/
    void Personagem::Create_character(string Player_name_,string Character_name_) 
    {
        ofstream File;
        char* Conversor = ConvertStrToCharP(Character_name_);
        File.open(strcat(Conversor, ".txt"), ios::app);
        setPlayer_name(Player_name_);
        setCharacter_name(Character_name_);
        
        //Informações do Personagem
            cout << "A partir de agora será feito o registro das informações do personagem, fique atento!" << endl;
            cout << "\n\nDigite a religião de seu personagem (caso não tenha digite Ateu, mas religião é muito importante): ";
            getline(cin, Religion);
            setReligion(Religion);
            system("clear");
            cout << "Digite quanto é sua riqueza, ou seja, o valor sua perícia mais alta: ";
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
              cout << "Agora escolhida nação é importante escolher qual dos bônus você deseja acrescentar em seus atributos (Ex.: +1 Panache, digite Panache): ";
              string Attribute;
              getline(cin, Attribute);
              Attribute_bonus(Attribute);
              cout << "Como regra de sistema agora escolha um atributo para aumentar em um ponto: ";
              getline(cin, Attribute);
              Attribute_bonus(Attribute);
              cout << "Como regra de sistema agora escolha outro atributo ou o mesmo anterior para aumentar em um ponto: ";
              getline(cin, Attribute);
              Attribute_bonus(Attribute);
              system("clear");
          //Formações
              cout << "Começaremos agora a parte das formações e para iniciarmos colocaremos aqui um lista de profissões e seus respectivos bônus!" << endl;
              /*Professions();*/
              cout << "Agora escolha uma formação: ";
              getline(cin, FormationI);
              setFormationI(FormationI);
              Expertise_from_profession(FormationI);
              //Advantage_from_profession(FormationI);
              cout << "Agora escolha outra formação: ";
              getline(cin, FormationII);
              setFormationII(FormationII);
              Expertise_from_profession(FormationII);
                setMirar(Mirar), setAtletismo(Atletismo), setBriga(Briga), setConvencer(Convencer), setEmpatia(Empatia), setEsconder(Esconder), setIntimidar(Intimidar), setObservar(Observar);
                setAtuar(Atuar), setCavalgar(Cavalgar), setNavegar(Navegar), setErudicao(Erudicao), setSeduzir(Seduzir), setFurto(Furto), setArte_da_Guerra(Arte_da_Guerra), setArmas(Armas);
              //Advantage_from_profession(FormationII);
              system("clear");
          //Perícias
              cout << "Começaremos agora a parte das perícias. Até esse ponto vocês já possui algumas perícias vindas de suas formações, mas agora você possuirá mais 10pnts. para gastar!";
              cout << "Esses 10pnts. serão gastos para aumentar ou comprar novas perícias, não é permitido deixar pontos sobrando.\n" << endl;
              Expertise();
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
        File << "------------FORMAÇÕES:                                                   " << endl; 
        File << getFormationI() << endl;             
        File << getFormationII() << endl;              
        File << "_________________________________________________________________________" << endl; 
        File << "----ATRIBUTOS:--|-------------PERÍCIAS:----------------|11111111111111|" << endl; 
        File << "                |-MIRAR:"<<getMirar()<<"            -ATUAR:"<<getAtuar()<<"          |11---------111|" << endl; 
        File << "                |-ATLETISMO:"<<getAtletismo()<<"        -CAVALGAR:"<<getCavalgar()<<"       |11---------111|" << endl; 
        File << "-VIGOR:"<<getVigor()<<"        |-BRIGA:"<<getBriga()<<"            -NAVEGAR:"<<getNavegar()<<"        |----------1111|" << endl; 
        File << "-FINESSE:"<<getFinesse()<<"      |-CONVENCER:"<<getConvencer()<<"        -ERUDIÇÃO:"<<getErudicao()<<"       |--------111111|" << endl; 
        File << "-ARGÚCIA:"<<getArgucia()<<"      |-EMPATIA:"<<getEmpatia()<<"          -SEDUZIR:"<<getSeduzir()<<"        |------11111---|" << endl; 
        File << "-DETERMINAÇÃO:"<<getDeterminacao()<<" |-ESCONDER:"<<getEsconder()<<"         -FURTO:"<<getFurto()<<"          |-----1111-----|" << endl; 
        File << "-PANACHE:"<<getPanache()<<"      |-INTIMIDAR:"<<getIntimidar()<<"        -ARTE DA GUERRA:"<<getArte_da_Guerra()<<" |-----111------|" << endl; 
        File << "                |-OBSERVAR:"<<getObservar()<<"         -ARMAS:"<<getArmas()<<"          |-----111------|" << endl; 
        File << "________________|______________________________________|-----111------|" << endl;  
        }
    }

    /**/
    void Personagem::Attribute_bonus(string Attribute_)
    {
        if (Attribute_ == "Vigor")
        {
            Vigor++;
        }else if (Attribute_ == "Finesse")
        {
            Finesse++;
        }else if (Attribute_ == "Argúcia")
        {
            Argucia++;
        }else if (Attribute_ == "Determinação")
        {
            Determinacao++;
        }else //Panache
        {
            Panache++;
        }
    }

    /**/
    void Personagem::Expertise_from_profession(string Formation_) 
    {
        if (Formation_ == "Ator")
        {
            Atletismo++;
            Empatia++;
            Atuar++;
            Seduzir++;
            Furto++;
        }else if (Formation_ == "Aristocrata")
        {
            Mirar++;
            Convencer++;
            Empatia++;
            Cavalgar++;
            Erudicao++; 
        }else if (Formation_ == "Arqueologo")
        {
            Atletismo++;
            Convencer++;
            Observar++;
            Erudicao++;
            Furto++;
        }else if (Formation_ == "Artifice")
        {
            Atletismo++;
            Convencer++;
            Observar++;
            Atuar++;
            Erudicao++;
        }else if (Formation_ == "Artista")
        {
            Convencer++;
            Empatia++;
            Atuar++;
            Cavalgar++;
            Seduzir++;
        }else if (Formation_ == "Assassino")
        {
            Atletismo++;
            Empatia++;
            Esconder++;
            Intimidar++;
            Armas++;
        }else if (Formation_ == "Caçador")
        {
            Mirar++;
            Esconder++;
            Intimidar++;
            Observar++;
            Cavalgar++;
        }else if (Formation_ == "Contramestre")
        {
            Mirar++;
            Briga++;
            Esconder++;
            Navegar++;
            Arte_da_Guerra++;
        }else if (Formation_ == "Capitão do Mar")
        {
            Mirar++;
            Convencer++;
            Observar++;
            Navegar++;
            Arte_da_Guerra++;
        }else if (Formation_ == "Criado")
        {
            Esconder++;
            Observar++;
            Cavalgar++;
            Seduzir++;
            Furto++;
        }else if (Formation_ == "Criminoso")
        {
            Atletismo++;
            Empatia++;
            Esconder++;
            Intimidar++;
            Furto++;
        }else if (Formation_ == "Divisão de Cavalaria")
        {
            Intimidar++;
            Observar++;
            Cavalgar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Docente")
        {
            Convencer++;
            Empatia++;
            Atuar++;
            Erudicao++;
            Seduzir++;
        }else if (Formation_ == "Duelista")
        {
            Atletismo++;
            Empatia++;
            Intimidar++;
            Atuar++;
            Armas++;
        }else if (Formation_ == "Engenheiro")
        {
            Mirar++;
            Convencer++;
            Cavalgar++;
            Erudicao++;
            Arte_da_Guerra++;
        }else if (Formation_ == "Espião")
        {
            Empatia++;
            Esconder++;
            Observar++;
            Seduzir++;
            Furto++;
        }else if (Formation_ == "Estudioso")
        {
            Convencer++;
            Empatia++;
            Observar++;
            Atuar++;
            Erudicao++;
        }else if (Formation_ == "Explorador")
        {
            Atletismo++;
            Convencer++;
            Empatia++;
            Cavalgar++;
            Navegar++;
        }else if (Formation_ == "Marinheiro")
        {
            Briga++;
            Observar++;
            Navegar++;
            Seduzir++;
            Armas++;   
        }else if (Formation_ == "Medico")
        {
            Convencer++;
            Empatia++;
            Observar++;
            Cavalgar++;
            Erudicao++;
        }else if (Formation_ == "Mercador")
        {
            Convencer++;
            Empatia++;
            Intimidar++;
            Cavalgar++;
            Seduzir++;
        }else if (Formation_ == "Mercenario")
        {
            Atletismo++;
            Briga++;
            Intimidar++;
            Observar++;
            Armas++;
        }else if (Formation_ == "Oficial do Exercito")
        {
            Mirar++;
            Atletismo++;
            Intimidar++;
            Cavalgar++;
            Arte_da_Guerra++;
        }else if (Formation_ == "Oficial da Marinha")
        {
            Intimidar++;
            Observar++;
            Navegar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Orfão")
        {
            Atletismo++;
            Briga++;
            Empatia++;
            Esconder++;
            Intimidar++;
        }else if (Formation_ == "Palaciano")
        {
            Empatia++;
            Atuar++;
            Cavalgar++;
            Seduzir++;
            Armas++;
        }else if (Formation_ == "Pirata")
        {
            Mirar++;
            Intimidar++;
            Observar++;
            Navegar++;
            Furto++;
        }else if (Formation_ == "Pugilista")
        {
            Atletismo++;
            Briga++;
            Convencer++;
            Empatia++;
            Atuar++;
        }else if (Formation_ == "Rameira")
        {
            Mirar++;
            Atletismo++;
            Empatia++;
            Atuar++;
            Seduzir++;
        }else if (Formation_ == "Roceiro")
        {
            Atletismo++;
            Convencer++;
            Empatia++;
            Atuar++;
            Cavalgar++;
        }else if (Formation_ == "Sacerdote")
        {
            Empatia++;
            Atuar++;
            Cavalgar++;
            Erudicao++;
            Seduzir++;
        }else if (Formation_ == "Soldado")
        {
            Mirar++;
            Intimidar++;
            Observar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Agente da União")
        {
            Mirar++;
            Empatia++;
            Observar++;
            Erudicao++;
            Seduzir++;
        }else if (Formation_ == "Bardo")
        {
            Mirar++;
            Convencer++;
            Empatia++;
            Atuar++;
            Cavalgar++;
        }else if (Formation_ == "Cavaleiro Errante")
        {
            Briga++;
            Intimidar++;
            Cavalgar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Corsario")
        {
            Observar++;
            Navegar++;
            Seduzir++;
            Furto++;
            Armas++;
        }else if (Formation_ == "Puritano")
        {
            Convencer++;
            Empatia++;
            Intimidar++;
            Cavalgar++;
            Erudicao++;
        }else if (Formation_ == "Sabio")
        {
            Atletismo++;
            Convencer++;
            Empatia++;
            Atuar++;
            Armas++;
        }else if (Formation_ == "Poeta Guerreiro")
        {
            Convencer++;
            Observar++;
            Atuar++;
            Cavalgar++;
            Armas++;
        }else if (Formation_ == "Antropologo")
        {
            Atletismo++;
            Convencer++;
            Empatia++;
            Observar++;
            Erudicao++;
        }else if (Formation_ == "Diestro")
        {
            Atletismo++;
            Empatia++;
            Intimidar++;
            Erudicao++;
            Armas++;
        }else if (Formation_ == "Espagirista")
        {
            Empatia++;
            Observar++;
            Erudicao++;
            Seduzir++;
            Furto++;
        }else if (Formation_ == "Mirabilis")//Excessão
        {
            Convencer++;
            Empatia++;
            Atuar++;
            Cavalgar++;
            Erudicao++;
        }else if (Formation_ == "Hexe")
        {
            Atletismo++;
            Intimidar++;
            Observar++;
            Seduzir++;
            Armas++;
        }else if (Formation_ == "Guerreiro")
        {
            Mirar++;
            Atletismo++;
            Cavalgar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Caçador de Demonios")
        {
            Mirar++;
            Atletismo++;
            Briga++;
            Observar++;
            Armas++;
        }else if (Formation_ == "Vitalienbruder" )//Excessão
        {
            Briga++;
            Esconder++;
            Navegar++;
            Furto++;
            Arte_da_Guerra++;
        }else if (Formation_ == "Mousquetaire")
        {
            Mirar++;
            Intimidar++;
            Observar++;
            Cavalgar++;
            Armas++;
        }else if(Formation_ == "Revolutionnaire")
        {
            Esconder++;
            Observar++;
            Cavalgar++;
            Furto++;
            Armas++;
        }else if (Formation_ == "Sorcier de Porte")
        {
            Empatia++;
            Esconder++;
            Cavalgar++;
            Erudicao++;
            Seduzir++;
        }else if (Formation_ == "Hussardo Alado")
        {
            Convencer++;
            Observar++;
            Cavalgar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Emissario")
        {
            Convencer++;
            Empatia++;
            Intimidar++;
            Atuar++;
            Seduzir++;
        }else if (Formation_ == "Tremtis")
        {
            Briga++;
            Empatia++;
            Esconder++;
            Observar++;
            Furto++;
        }else if (Formation_ == "Adivinho")
        {
            Atletismo++;
            Convencer++;
            Erudicao++;
            Armas++;
            Atuar++;
        }else if (Formation_ == "Baleeiro")
        {
            Atletismo++;
            Briga++;
            Navegar++;
            Armas++;
            Observar++;
        }else if (Formation_ == "Condão de Matushka")
        {
            Atletismo++;
            Intimidar++;
            Atuar++;
            Seduzir++;
            Furto++;
        }else if (Formation_ == "Cossaco")
        {
            Briga++;
            Intimidar++;
            Observar++;
            Armas++;
            Cavalgar++;
        }else if (Formation_ == "Progressista")
        {
            Atletismo++;
            Convencer++;
            Empatia++;
            Cavalgar++;
            Seduzir++;
        }else if (Formation_ == "Bearsark")
        {
            Briga++;
            Intimidar++;
            Navegar++;
            Arte_da_Guerra++;
            Armas++;
        }else if (Formation_ == "Escaldo")
        {
            Briga++;
            Intimidar++;
            Atuar++;
            Navegar++;
            Armas++;
        }else if (Formation_ == "Guild Master")
        {
            Convencer++;
            Empatia++;
            Cavalgar++;
            Erudicao++;
            Seduzir++;
        }else if (Formation_ == "Sjorover")
        {
            Briga++;
            Intimidar++;
            Observar++;
            Navegar++;
            Armas++;
        }else if (Formation_ == "Bravo")
        {
            Atletismo++;
            Empatia++;
            Intimidar++;
            Observar++;
            Armas++;
        }else if (Formation_ == "Consigliere")
        {
            Convencer++;
            Empatia++;
            Observar++;
            Cavalgar++;
            Seduzir++;
        }else if (Formation_ == "Esploratore")
        {
            Convencer++;
            Empatia++;
            Intimidar++;
            Navegar++;
            Seduzir++;
        }else if (Formation_ == "Strega del Sortilegio")
        {
            Convencer++;
            Esconder++;
            Atuar++;
            Cavalgar++;
            Seduzir++;
        }else
        {
            cout << "Nome digitado errado, tente novamente..." << endl;
        }
        
    }

    /**/
    void Personagem::Expertise()
    {
        int Pontos = 10;
        string Expertise_;

        do
        {   
            cout << "\n\n\t\tVoce possui > " << Pontos << " < pontos para gastar em perícias." << endl;
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
            Pontos = /*Ficha_[i]->*/Expertise_calc(Expertise_, Pontos);
                setMirar(Mirar), setAtletismo(Atletismo), setBriga(Briga), setConvencer(Convencer), setEmpatia(Empatia), setEsconder(Esconder), setIntimidar(Intimidar), setObservar(Observar);
                setAtuar(Atuar), setCavalgar(Cavalgar), setNavegar(Navegar), setErudicao(Erudicao), setSeduzir(Seduzir), setFurto(Furto), setArte_da_Guerra(Arte_da_Guerra), setArmas(Armas);

            /*      Pontos - Ficha_[i]-> getMirar() 
                Isso é para fazer o cálculo do gasto com base no seu valor atual de pontos para gastar*/
        } while (Pontos > 0);
    }

/**/
    int Personagem::Expertise_calc(string Expertise_, int Pontos_)
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