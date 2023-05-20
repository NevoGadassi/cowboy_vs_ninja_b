#include "Team2.hpp"
using namespace std;
using namespace ariel;

void Team2 ::attack(Team *enemy)
{
    if (enemy == nullptr)
    {
        throw std::invalid_argument("enemy cant be null");
    }

    if (enemy->stillAlive() == 0)
    {
        throw std::runtime_error(" attack dead Team");
    }


    if (this->stillAlive() == 0)
    {
        throw std::runtime_error("this team in dead");
    }
    if (enemy == this)
    {
        throw std::runtime_error("enemy and attack team is the same team");
    }
    // new leader
    if (!this->leader->isAlive())
    {
        double dist = 0;
        Character *newLeader = nullptr;
        for (Character *fighter : this->fighters)
        {
            if (fighter->isAlive())
            {
                if (this->leader->distance(fighter) < dist || newLeader == nullptr)
                {
                    dist = this->leader->distance(fighter);
                    newLeader = fighter;
                }
            }
        }
        this->leader = newLeader;
    }
    Character *victim = closetvictim(this->leader, enemy);

    for (Character *fighter : this->fighters)
    {
        if (victim == nullptr)
        {
            break;
        }
        Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
        Ninja *ninja = dynamic_cast<Ninja *>(fighter);
        if (cowboy != nullptr)
        {
            if (cowboy->isAlive())
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(victim);
                    if (!victim->isAlive())
                    {
                        victim = closetvictim(this->leader, enemy);
                    }
                }
                else
                {
                    
                    cowboy->reload();
                }
            }
        }
        if (ninja != nullptr)
        {
            if (ninja->isAlive())
            {
                if (ninja->getLocation().distance(victim->getLocation()) <= 1)
                {
                    ninja->slash(victim);
                    if (!victim->isAlive())
                    {
                        victim = closetvictim(this->leader, enemy);
                    }
                }
                else
                {
                    ninja->move(victim);
                }
            }
        }
    }
}

void Team2 ::print() const
{
    for (Character *fighter : this->fighters)
    {
        std::cout << fighter->print() << std::endl;
    }
}