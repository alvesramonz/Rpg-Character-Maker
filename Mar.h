/*
    Aqui presente neste será toda parte do código responsavel por orquestrar a "execução"
    Aqui presente será uma 'classe'(função) executora
*/
#ifndef MAR_H_
#define MAR_H_ 

#include <iostream>
#include <fstream>
#include "Ficha.h"
#include "Cabecalhos.h"
#define MAX_FICHAS 10

using namespace std;

class Rpg_System
{
    private:
    string Campaign_name;
    string Character_name;
    int Opcao;
    int Numero_de_fichas;
    bool Program_status;
    int Result;
    Ficha *Fichas_[MAX_FICHAS];
    Cabecalhos *Cabecalho_[1];

    public:
    Rpg_System();
    ~Rpg_System();
    void Executable();
    int Choose_option();
    void Add_ficha(Ficha *Fichas);

    int Campaign_verification();
    void Create_campaign(string Campaign_name_);

    int Character_name_verification(string Campaign_name_,string Character_name_);

};

#endif