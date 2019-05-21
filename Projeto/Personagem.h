#ifndef PERSONAGEM_H_
#define PERSONAGEM_H_ 

#include <iostream>
#include <fstream>
#include <cstring>
#include "Ficha.h"

using namespace std; 

class Personagem:public Ficha
{

    private:
    //Informação do mestre
        string Dungeon_master;
    //Informação do personagem
        string Campaign_name;
        string Character_name;
        string Player_name;
        string Nation;
        string Religion;
        int Richness;
    //Atributos
        int Vigor = 2;  
        int Finesse = 2;    
        int Argucia = 2;    
        int Determinacao = 2;   
        int Panache = 2;    
    //Formações
        string FormationI;
        string FormationII;
    //Perícias
        int Mirar, Atletismo, Briga, Convencer, Empatia, Esconder, Intimidar, Observar = 0;
        int Atuar, Cavalgar, Navegar, Erudicao, Seduzir, Furto, Arte_da_Guerra, Armas = 0;
    //Vantagens [Opcional]
    //Arcana [Opcional]
    public:
    //Construtor
        Personagem(string Campaign_name_, string Dungeon_master_);
    //Destrutor
        ~Personagem();
        //Getters
            //Formações
                string getFormationI();
                string getFormationII();
        //Getters
            //Atributos
                int getVigor();
                int getFinesse();
                int getArgucia();
                int getDeterminacao();
                int getPanache();
        //Setters
            //Atributos
                void setVigor(int Vigor_);
                void setFinesse(int Finesse_);
                void setArgucia(int Argucia_);
                void setDeterminacao(int Determinacao_);
                void setPanache(int Panache_);
            //Formações
                void setFormationI(string FormationI_);
                void setFormationII(string FormationII_);
        //Funções
            void Attribute_bonus(string Attribute_);
            void Expertise_from_profession(string Profession_);
            void Expertise();
            void Create_character(string Player_name_, string Character_name_, string Campaign_name_);
            int Expertise_calc(string Expertise_, int Pontos_);
            friend std::ostream& operator<< (std::ostream &o, Personagem *Ficha);


};
#endif