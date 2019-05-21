#ifndef MAR_H_
#define MAR_H_ 

#include <iostream>
#include <fstream>
#include <cstring>
#include "Personagem.h"
#include "Villain.h"
#include "Cabecalho.h"

#define MAX_PERSO 10 /*Número Máximo de Fichas*/
#define MAX_VILLA 15 /*Número Máximo de Personagens*/

using namespace std;

class Mar_system 
{
    private:
    //Informação do mestre
        string Dungeon_master;
    //Informações do personagem
        string Campaign_name;
        string Character_name;
        string Player_name;
    //
        int Opcao; /*Opção digitada pelo usuário*/
        int Numero_de_viloes; /*Atual numero de viloes no programa*/
        int Numero_de_fichas; /*Atual numero de personagens no programa*/
        int Result; /*Variavel auxiliar de verificação no Executable*/
        bool Program_status; /*Caso verdadeiro o programa roda, caso não ele fecha*/
        Personagem *Fichas_[MAX_PERSO]; /*Classe Ficha possuindo no máximo dez objetos*/
        Villain *Villain_[MAX_VILLA];
        Cabecalho *Cabecalho_[1]; /*Classe Cabecalho possuindo apenas um objeto necessário*/

    public:
    //Construtor
        Mar_system();
    //Destrutor
        ~Mar_system();
    //Getters
    //Setters
    //Funções
    int Campaign_verification1_0();
    int Campaign_verification2_1();
    int Campaign_verification2_2(string Campaign_name_);
    int Character_name_verification(string Campaign_name_,string Character_name_);
    int Choose_option();
    void Create_campaign(string Campaign_name_);
    void Add_ficha(Personagem *Fichas_);
    void Add_Villain(Villain *Villain_);
    void Executable();
};

#endif