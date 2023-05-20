
#ifndef COWBOY_H
#define COWBOY_H
#include "Character.hpp"


namespace ariel {
    class Cowboy : public Character {
    private:
        int bullets;

    public:
        
        Cowboy ( const std :: string name, Point location) :
            Character(name, location, 110), bullets (6) {}

        bool hasboolets () const;
        void shoot (Character* someone);
        void reload ();
        int getBullets () const;
        
        std :: string print () const override;

        
    };
}

#endif 