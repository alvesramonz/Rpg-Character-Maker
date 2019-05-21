#ifndef VILLAIN_H_
#define VILLAIN_H_ 

#include <iostream>
#include <fstream>
#include <cstring>
#include "Ficha.h"

class Villain:public Ficha
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
            int Villainy;
            int Power;
            int Rank;
        //Perícias
            int Mirar, Atletismo, Briga, Convencer, Empatia, Esconder, Intimidar, Observar = 0;
            int Atuar, Cavalgar, Navegar, Erudicao, Seduzir, Furto, Arte_da_Guerra, Armas = 0;
        //Vantagens [Opcional]
        //Arcana [Opcional]
    public:
        //Construtor
            Villain(string Campaign_name_, string Dungeon_master_);
        //Destrutor
            ~Villain();
        //Getters
            //Atributos
            int getVillainy();
            int getPower();
            int getRank();
        //Setters
            //Atributos
            void setVillainy(int Villainy_);
            void setPower(int Power_);
            void setRank(int Rank_);
        //Funções
            void Expertise(int Pontos_);
            void Create_character(string Player_name_, string Character_name_);
            int Expertise_calc(string Expertise_, int Pontos_);
};

#endif