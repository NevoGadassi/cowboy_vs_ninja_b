#include <exception>
#include <iostream>
#include "Cowboy.hpp"
using namespace std;
using namespace ariel;

int Cowboy :: getBullets () const { return this->bullets; }
bool Cowboy :: hasboolets () const {
    return (this->bullets > 0);
}

void Cowboy :: shoot (Character* someone) {
        if(!someone->isAlive())
        {
            throw runtime_error("enemy is dead");
        }
        if(someone == nullptr)
        {
            throw invalid_argument("enemy cant be null");
        }
        if(someone == this)
        {
            throw runtime_error("cant shoot himself");
        }
        if (!isAlive()) {
        throw runtime_error("Dead cowboy ");
        }
        if (this->bullets > 0) {
        someone->hit(10);
        this->bullets--;
        }


}

void Cowboy :: reload () {
    if(!this->isAlive())
        {
            throw runtime_error("Cowboy is dead");
        }
        this->bullets = 6;
}

string Cowboy :: print () const {
    string output = "";
        if (this->isAlive())
        {
            output = "Cowboy - " + this->getName() + ", " + to_string(this->getHitPoints()) + " HP. place: " + this->getLocation().toString() +" bullets: "+ to_string(this->bullets);
        }
        else
        {
            output = "Cowboy - " + this->getName() + ", DEAD";
        }
        return output;
}

