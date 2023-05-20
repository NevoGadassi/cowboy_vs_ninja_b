
#ifndef NINJA_H
#define NINJA_H
#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    private:
        int speed;

    public:
        Ninja (const  std :: string name, Point location, const int points, int speed) :
            Character(name, location, points), speed(speed) {}
         int getSpeed () const;
        void slash (Character * someone) const;
        void move (Character *someone );
   

         std :: string print () const override;

    };
}

#endif 