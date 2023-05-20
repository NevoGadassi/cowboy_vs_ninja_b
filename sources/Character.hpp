

#ifndef CHARACTER_H
#define CHARACTER_H
#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;


namespace ariel {
    class Character {
    private:
        string name;
        Point location;
        int hitp;
        bool alive;
        bool inteam;

    public:
        
        Character (const  string name, Point location, int points) :
            name(name), location(location), hitp(points), alive(true), inteam(false) {}

        virtual ~Character() = default;
        void setAlive (bool alive);
        void setLocation (Point x);
        void setHitPoints (int hit);
        void addtoteam();
        bool isAlive () const;
        double distance (Character* someone) const;
        void hit (int num);
        string getName () const;
        Point getLocation () const;
        int getHitPoints () const;
        bool getInTeam ();
        
        virtual string print () const {
            string output="";
            output=this->name+ "HP "+to_string(this->hitp)+", place: "+this->location.toString();
            return output;
        };
    };
}

#endif 