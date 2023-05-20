
#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H
#include "Ninja.hpp"
using namespace std;

namespace ariel {
    class TrainedNinja : public Ninja {

    public:
        TrainedNinja (const std :: string name, Point location) :
                Ninja(name, location, 120, 12) {}
        std :: string print () const override{
        string output = "";
        if (this->isAlive())
        {
            output = "trainedNinja - " + this->getName() + ", " + to_string(this->getHitPoints()) + " HP. place: " + this->getLocation().toString()+ " speed:"+ to_string(this->getSpeed()) ;
        }
        else
        {
            output = "trainedNinja - " + this->getName()  + ", DEAD";
        }
        return output;
    }
    };
}

#endif 
