#include <iostream>
#include <fstream>
#include <string>
#include "Ficha.h"

//Getters
    //Informações
        string Ficha::getCampaign_name()
        {
            return Campaign_name;
        }
        string Ficha::getCharacter_name()
        {
            return Character_name;
        }
        string Ficha::getPlayer_name()
        {
            return Player_name;
        }
        string Ficha::getNation()
        {
            return Nation;
        }
        string Ficha::getReligion()
        {
            return Religion;
        }
        int Ficha::getRichness()
        {
            return Richness;
        }
    //Perícias
        int Ficha::getMirar()
        {
            return Mirar;
        }
        int Ficha::getAtletismo()
        {
            return Atletismo;
        }
        int Ficha::getBriga()
        {
            return Briga;
        }
        int Ficha::getConvencer()
        {
            return Convencer;
        }
        int Ficha::getEmpatia()
        {
            return Empatia;
        }
        int Ficha::getEsconder()
        {
            return Esconder;
        }
        int Ficha::getIntimidar()
        {
            return Intimidar;
        }
        int Ficha::getObservar()
        {
            return Observar;
        }
        int Ficha::getAtuar()
        {
            return Atuar;
        }
        int Ficha::getCavalgar()
        {
            return Cavalgar;
        }
        int Ficha::getNavegar()
        {
            return Navegar;
        }
        int Ficha::getErudicao()
        {
            return Erudicao;
        }
        int Ficha::getSeduzir()
        {
            return Seduzir;
        }
        int Ficha::getFurto()
        {
            return Furto;
        }
        int Ficha::getArte_da_Guerra()
        {
            return Arte_da_Guerra;
        }
        int Ficha::getArmas()
        {
            return Armas;
        }
//Setters
    //Informações
        void Ficha::setCampaign_name(string Campaign_name_)
        {
            Campaign_name = Campaign_name_;
        }
        void Ficha::setCharacter_name(string Character_name_)
        {
            Character_name = Character_name_;
        }
        void Ficha::setPlayer_name(string Player_name_)
        {
            Player_name = Player_name_;
        }
        void Ficha::setNation(string Nation_)
        {
            Nation = Nation_;
        }
        void Ficha::setReligion(string Religion_)
        {
            Religion = Religion_;
        }
        void Ficha::setRichness(int Richness_)
        {
            Richness = Richness_;
        }
    //Perícias
        void Ficha::setMirar(int Mirar_)
        {
            Mirar = Mirar_;
        }
        void Ficha::setAtletismo(int Atletismo_)
        {
            Atletismo = Atletismo_;
        }
        void Ficha::setBriga(int Briga_)
        {
            Briga = Briga_;
        }
        void Ficha::setConvencer(int Convencer_)
        {
            Convencer = Convencer_;
        }
        void Ficha::setEmpatia(int Empatia_)
        {
            Empatia = Empatia_;
        }
        void Ficha::setEsconder(int Esconder_)
        {
            Esconder = Esconder_;
        }
        void Ficha::setIntimidar(int Intimidar_)
        {
            Intimidar = Intimidar_;
        }
        void Ficha::setObservar(int Observar_)
        {
            Observar = Observar_;
        }
        void Ficha::setAtuar(int Atuar_)
        {
            Atuar = Atuar_;
        }
        void Ficha::setCavalgar(int Cavalgar_)
        {
            Cavalgar = Cavalgar_;
        }
        void Ficha::setNavegar(int Navegar_)
        {
            Navegar = Navegar_;
        }
        void Ficha::setErudicao(int Erudicao_)
        {
            Erudicao = Erudicao_;
        }
        void Ficha::setSeduzir(int Seduzir_)
        {
            Seduzir = Seduzir_;
        }
        void Ficha::setFurto(int Furto_)
        {
            Furto = Furto_;
        }
        void Ficha::setArte_da_Guerra(int Arte_da_Guerra_)
        {
            Arte_da_Guerra = Arte_da_Guerra_;
        }
        void Ficha::setArmas(int Armas_)
        {
            Armas = Armas_;
        }