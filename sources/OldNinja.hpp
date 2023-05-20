
#ifndef OLDNINJA_H
#define OLDNINJA_H
#include "Ninja.hpp"
#include "Character.hpp"
using namespace std;


namespace ariel {
    class OldNinja : public Ninja {

    public:
    
    OldNinja (const std :: string name, Point location) :
         Ninja(name, location, 150, 8) {}


    std :: string print () const override{
        string output = "";
        if (this->isAlive())
        {
            output = "oldNinja - " + this->getName() + ", " + to_string(this->getHitPoints()) + " HP. place: " + this->getLocation().toString()+ " speed:"+ to_string(this->getSpeed()) ;
        }
        else
        {
            output = "oldNinja - " + this->getName()  + ", DEAD";
        }
        return output;
    }
    };
}

#endif 
