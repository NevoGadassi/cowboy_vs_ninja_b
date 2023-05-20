
#include "Character.hpp"
using namespace std;
using namespace ariel;


void Character :: setLocation (Point location) 
{ this->location = location; }
void Character :: setHitPoints (int points)
 { this->hitp = points; }
void Character :: setAlive (bool isalive)
 { this->alive = isalive; }
 void Character ::addtoteam()
 { this->inteam = true; }
bool Character :: isAlive () const 
{ return this->alive; }
double Character :: distance (Character* other) const {
    return location.distance(other -> getLocation());
}

void Character :: hit (int amount) {
    if (amount < 0) {
            throw std::invalid_argument ("Damage cant be negative");
        }

        if (!isAlive()) {
            throw std::runtime_error("allready dead");
        }

        if (amount < this->hitp) {
           this->hitp=this->hitp-amount;
        } else {
             this->hitp = 0;
             this->setAlive(false);
        }

}

string Character :: getName () const 
{ return this->name; }
Point Character :: getLocation () const 
{ return this->location; }
int Character :: getHitPoints () const
 { return this->hitp; }
bool Character :: getInTeam () 
{ return this->inteam; }





