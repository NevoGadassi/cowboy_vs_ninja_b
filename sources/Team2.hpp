#ifndef TEAM2_H
#define TEAM2_H
#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {

    public:
        Team2 (Character* leader) : Team(leader) {}
        void attack (Team *) override;
        void print() const override;
    };
}

#endif 
