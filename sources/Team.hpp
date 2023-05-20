
#ifndef TEAM_H
#define TEAM_H
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
namespace ariel {
    
  class Team
    {
    protected:
        std::vector<Character *> fighters;
        Character *leader;
        int maxfighters = 10;
        int Size;



    public:
        Team(Character *leader);
        ~Team();
         void add(Character *member);
        virtual void attack(Team *other);
        int stillAlive();
        Character* getLeader(){return leader;}
        virtual void print() const ;
        static Character* closetvictim (Character* leader,Team* enemy);
        std:: vector<Character *>  getfighters(){
            return this->fighters;
        }
        
    };
};
#endif 