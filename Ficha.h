/*
    Aqui será disposto tudo que será utilizado no arquivo Ficha.cpp, importante lembrar que essa primeira 
    Ficha.cpp será apenas para o sistema de 7o Mar.

    Ps.: V0.1
*/
#ifndef FICHA_H_
#define FICHA_H_ 

#include <iostream>
#include <cstring>

using namespace std;

class Ficha
{
    private:
    //Informações do personagem
    string Campaign_name;
    string Character_name;
    string Player_name;
    string Concept;
    string Nation;
    string Religion;
    string Reputation;
    int Richness;
    //Fim das informações do personagem
    //Atributo
    string Attribute;
    int Vigor = 2;  //Dúvida, não sei se posso definir valor em ".h"
    int Finesse = 2;    //Dúvida, não sei se posso definir valor em ".h"
    int Argucia = 2;    //Dúvida, não sei se posso definir valor em ".h"
    int Determinacao = 2;   //Dúvida, não sei se posso definir valor em ".h"
    int Panache = 2;    //Dúvida, não sei se posso definir valor em ".h"
    //Fim dos atributos
    //Formações
    string FormationI;
    string FormationII;
    //Fim das formações
    //Perícias
    int Mirar, Atletismo, Briga, Convencer, Empatia, Esconder, Intimidar, Obversar = 0; //Dúvida, não sei se posso definir valor em ".h"
    int Atuar, Cavalgar, Navegar, Erudicao, Seduzir, Furto, Arte_da_Guerra, Armas = 0;  //Dúvida, não sei se posso definir valor em ".h"
    //Fim das parícias
    public:
    //Construtor
    //Destrutor
    //Getters
        //Atributos
    int getVigor();
    int getFinesse();
    int getArgucia();
    int getDeterminacao();
    int getPanache();
        //Pericias 
    int getMirar(), getAtletismo(), getBriga(), getConvencer(), getEmpatia(), getEsconder(), getIntimidar(), getObservar();
    int getAtuar(), getCavalgar(), getNavegar(), getErudicao(), getSeduzir(), getFurto(), getArte_da_Guerra(), getArmas();
    //Fim dos Getters
    //Setters
    //Fim dos Setters
    //Funções diversas
    void Campaign_verification();
    void Create_campaign(string Campaign_name_);
    void Character_name_verification(string Campaign_name_,string Character_name_);
    void Create_character(string Character_name_);

    void Attribute_bonus(string Attribute_);

    void Expertise_from_profession(string Profession_);
    void Expertise();
    int Expertise_calc(string Expertise_, int Pontos_);



};

#endif