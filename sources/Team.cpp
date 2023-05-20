#include "Team.hpp"
using namespace std;
using namespace ariel;

Team::Team(Character *leader)
{
    if (leader == nullptr)
    {
        throw invalid_argument("Leader cant be null");
    }
    if (!leader->isAlive())
    {
        throw invalid_argument("Leader cant be null ");
    }
    if (leader->getInTeam())
    {
        throw runtime_error("Leader in a team");
    }
    this->fighters.push_back(leader);
    this->leader = leader;
    this->Size = 1;
    this->leader->addtoteam();
}

Team::~Team()
{
    for (Character *fighter : this->fighters)
    {
        delete fighter;
    }
}

void Team::add(Character *member)
{
    if (member == nullptr)
    {
        throw std::invalid_argument("fighter cant ne null");
    }

    if (!member->isAlive())
    {
        throw std::runtime_error("fighter cant be deed");
    }

    if (member->getInTeam())
    {
        throw std::runtime_error("fighter is already in  team");
    }

    if (this->fighters.size() == this->maxfighters)
    {
        throw std::runtime_error("The team is full");
    }

    member->addtoteam();
    this->fighters.push_back(member);
}

void Team::attack(Team *enemy)
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
    // first cowboy attack
    Character *victim = closetvictim(this->leader,enemy);

    for (Character *fighter : this->fighters)
    {
        if (victim == nullptr)
        {
            break;
        }
        Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
        if (cowboy != nullptr)
        {
            if (cowboy->isAlive())
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(victim);
                    if (!victim->isAlive())
                    {
                        victim = closetvictim(this->leader,enemy);
                    }
                }
                else
                {
                    
                    cowboy->reload();
                }
            }
        }
    }
    // now ninja attack
    victim = closetvictim(this->leader,enemy);

    for (Character *fighter : this->fighters)
    {
        if (victim == nullptr)
        {
            break;
        }
        Ninja *ninja = dynamic_cast<Ninja *>(fighter);
        if (ninja != nullptr)
        {
            if (ninja->isAlive())
            {
                if (ninja->getLocation().distance(victim->getLocation()) <= 1)
                {
                    ninja->slash(victim);
                    if (!victim->isAlive())
                    {
                        victim = closetvictim(this->leader,enemy);
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

Character *Team ::closetvictim(Character *leader,Team *enemy) 
{
    Character *victim = nullptr;
    double dist = -1;
    for (Character *fighter : enemy->getfighters())
    {
        if (fighter->isAlive())
        {
            if (leader->distance(fighter) < dist || dist == -1)
            {
                dist = leader->distance(fighter) ;
                victim = fighter;
            }
        }
    }
    return victim;
}

int Team::stillAlive()
{
    int alive = 0;
    for (Character *fighter : this->fighters)
    {
        if (fighter->isAlive())
        {
            alive++;
        }
    }
    return alive;
}

void Team::print() const
{
    for (Character *fighter : this->fighters)
    {
        if (dynamic_cast<Cowboy *>(fighter) != nullptr)
        {
            std::cout << fighter->print() << std::endl;
        }
    }

    for (Character *fighter : this->fighters)
    {
        if (dynamic_cast<Ninja *>(fighter) != nullptr)
        {
            std::cout << fighter->print()<< std::endl;
        }
    }
}