
#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include "Ninja.hpp"
using namespace std;


namespace ariel {
    class YoungNinja : public Ninja {

    public:
        // Constructors.
        YoungNinja (const std :: string name, Point location) :
                Ninja(name, location, 100, 14) {}
        std :: string print () const override{
        string output = "";
        if (this->isAlive())
        {
            output = "youngNinja - " + this->getName() + ", " + to_string(this->getHitPoints()) + " HP. place: " + this->getLocation().toString()+ " speed:"+ to_string(this->getSpeed()) ;
        }
        else
        {
            output = "youngNinja - " + this->getName()  + ", DEAD";
        }
        return output;
    }
    };
}

#endif