#include "SmartTeam.hpp"
using namespace ariel;

// The attack in this smartteam make the cowboys attack on the less hp character to take him down together
// and then continue like this character by character
// at the same time each ninja checks who is the character closest to her and do a slash or a move

void SmartTeam ::attack(Team *enemy)
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

    Character *victim;
    for (Character *fighter : this->fighters)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
        if (cowboy != nullptr)
        {

            if (cowboy->isAlive())
            {
                victim = lesshp(enemy);
                if (victim == nullptr)
                {
                    break;
                }
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(victim);
                }
                else
                {

                    cowboy->reload();
                }
            }
            else
            {
                Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                if (ninja != nullptr)
                {
                    if (ninja->isAlive())
                    {
                        victim = closetoninja(ninja, enemy);
                        if (victim == nullptr)
                        {
                            break;
                        }
                        if (ninja->getLocation().distance(victim->getLocation()) <= 1)
                        {
                            ninja->slash(victim);
                        }
                        else
                        {
                            ninja->move(victim);
                        }
                    }
                }
            }
        }
    }
}

Character *SmartTeam::lesshp(Team *enemy)
{
    int minhp = 200;
    Character *victim = nullptr;
    for (Character *fighter : enemy->getfighters())
    {
        if (fighter->isAlive())
        {
            if (fighter->getHitPoints() < minhp && fighter->getHitPoints() != 0)
            {
                minhp = fighter->getHitPoints();
                victim = fighter;
            }
        }
    }
    return victim;
}
Character *SmartTeam::closetoninja(Character *attack, Team *defend)
{
    int distance = 0;
    Character *victim = nullptr;
    Point attackplace = attack->getLocation();

    for (Character *fighter : defend->getfighters())
    {
        if (fighter->isAlive())
        {
            if (attackplace.distance(fighter->getLocation()) <= distance || victim == nullptr)
            {
                distance = attackplace.distance(fighter->getLocation());
                victim = fighter;
            }
        }
    }
    return victim;
}


