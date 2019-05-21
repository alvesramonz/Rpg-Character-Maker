#ifndef FICHA_H_
#define FICHA_H_ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ficha
{
    private:
        //Informação do personagem
            string Campaign_name;
            string Character_name;
            string Player_name;
            string Nation;
            string Religion;
            int Richness;
        //Perícias
            int Mirar, Atletismo, Briga, Convencer, Empatia, Esconder, Intimidar, Observar = 0;
            int Atuar, Cavalgar, Navegar, Erudicao, Seduzir, Furto, Arte_da_Guerra, Armas = 0;
    public:
            //Getters
                //Informações
                    string getCampaign_name();
                    string getCharacter_name();
                    string getPlayer_name();
                    string getNation();
                    string getReligion();
                    int getRichness();
                //Pericias
                    int getMirar(), getAtletismo(), getBriga(), getConvencer(), getEmpatia(), getEsconder(), getIntimidar(), getObservar();
                    int getAtuar(), getCavalgar(), getNavegar(), getErudicao(), getSeduzir(), getFurto(), getArte_da_Guerra(), getArmas();
            //Setters
                //Informações
                    void setCampaign_name(string Campaign_name_);
                    void setCharacter_name(string Character_name_);
                    void setPlayer_name(string Player_name_);
                    void setNation(string Nation_);
                    void setReligion(string Religion_);
                    void setRichness(int Richness);
                //Pericias
                    void setMirar(int Mirar_), setAtletismo(int Atletismo_), setBriga(int Brigar_), setConvencer(int Convencer_), setEmpatia(int Empatia_), setEsconder	 (int Esconder_), setIntimidar(int Intimidar_), setObservar(int Observar_);
                    void setAtuar(int Atuar_), setCavalgar(int Cavalgar_), setNavegar(int Navegar_), setErudicao(int Erudicao_), setSeduzir(int Seduzir_), setFurto(int Furto_), setArte_da_Guerra(int Arte_da_Guerra_), setArmas(int Armas_);
                //Funções
                    
};

#endif