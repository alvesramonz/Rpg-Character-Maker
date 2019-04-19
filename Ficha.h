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
};

#endif