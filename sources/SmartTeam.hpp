
#ifndef SMARTTEAM_H
#define SMARTTEAM_H
#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {

    public:
        SmartTeam (Character* leader) : Team(leader) {}
        void attack (Team * anotherteam) override;
        static Character* lesshp(Team * enemy );
        static Character* closetoninja(Character * attack ,Team * defend);
       };
}

#endif 
