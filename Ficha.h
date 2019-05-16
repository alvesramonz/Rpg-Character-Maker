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
    /*string Campaign_name;*/
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
    int Mirar, Atletismo, Briga, Convencer, Empatia, Esconder, Intimidar, Observar = 0; //Dúvida, não sei se posso definir valor em ".h"
    int Atuar, Cavalgar, Navegar, Erudicao, Seduzir, Furto, Arte_da_Guerra, Armas = 0;  //Dúvida, não sei se posso definir valor em ".h"
    //Fim das parícias
    public:
    //Construtor
    Ficha(string Character_name_,string Campaign_name_);
    //Destrutor
    //Getters
        //Informações do personagem
    string getCampaign_name();
    string getCharacter_name();
    string getPlayer_name();
    string getConcept();
    string getNation();
    string getReligion();
    string getReputation();
    int getRichness();
        //Atributos
    int getVigor();
    int getFinesse();
    int getArgucia();
    int getDeterminacao();
    int getPanache();
        //Formações
    string getFormationI();
    string getFormationII();    
        //Pericias 
    int getMirar(), getAtletismo(), getBriga(), getConvencer(), getEmpatia(), getEsconder(), getIntimidar(), getObservar();
    int getAtuar(), getCavalgar(), getNavegar(), getErudicao(), getSeduzir(), getFurto(), getArte_da_Guerra(), getArmas();
    //Fim dos Getters
    //Setters
    void setMirar(int Mirar_), setAtletismo(int Atletismo_), setBriga(int Brigar_), setConvencer(int Convencer_), setEmpatia(int Empatia_), setEsconder	 (int Esconder_), setIntimidar(int Intimidar_), setObservar(int Observar_);
    void setAtuar(int Atuar_), setCavalgar(int Cavalgar_), setNavegar(int Navegar_), setErudicao(int Erudicao_), setSeduzir(int Seduzir_), setFurto(int Furto_), setArte_da_Guerra(int Arte_da_Guerra_), setArmas(int Armas_);

    void setVigor(int Vigor_);
    void setFinesse(int Finesse_);
    void setArgucia(int Argucia_);
    void setDeterminacao(int Determinacao_);
    void setPanache(int Panache_);

    void setFormationI(string FormationI_);
    void setFormationII(string FormationII_);

    void setCampaign_name(string Campaign_name_);
    void setCharacter_name(string Character_name_);
    void setPlayer_name(string Player_name_);
    void setConcept(string Concept_);
    void setNation(string Nation_);
    void setReligion(string Religion_);
    void setReputation(string Reputation_);
    void setRichness(int Richness);
	
    //Fim dos Setters
    //Funções diversas
    int Character_name_verification(string Campaign_name_,string Character_name_);
    void Create_character(string Character_name_);

    void Attribute_bonus(string Attribute_);

    void Expertise_from_profession(string Profession_);
    void Expertise();
    int Expertise_calc(string Expertise_, int Pontos_);



};

#endif
