
#include "Ninja.hpp"
using namespace std;
using namespace ariel;

void Ninja ::slash(Character *someone) const
{
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
        throw runtime_error("Dead Ninja ");
        }
        if (this->distance(someone)<=1) {
            someone->hit(40);
        }
}

void Ninja ::move(Character *enemy)
{
    if (enemy == nullptr)
    {
        throw invalid_argument("Enemy cant be null");
    }
    if (!this->isAlive())
    {
        throw "Character is dead";
    }
    else{
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
    }
}

int Ninja ::getSpeed() const { return this->speed; }
string Ninja ::print() const
{
       string output = "";
        if (this->isAlive())
        {
            output = "Ninja - " + this->getName() + ", " + to_string(this->getHitPoints()) + " HP. place: " + this->getLocation().toString()+ " speed:"+ to_string(this->speed) ;
        }
        else
        {
            output = "Ninja - " + this->getName()  + ", DEAD";
        }
        return output;
}