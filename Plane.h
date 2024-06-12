// Plane.h
#ifdef PLANE_H
#define PLANE_H

#include <string>


class Plane {
private:
    std::string name;
    int maxSpeed;
    int maxMissiles;
    int maxGunRounds;
    float maxArmor;
    struct speedModifiers
    {
        int x;
        int y;
    };
        

public:


    //Constructor
    Plane(std::string name, int maxSpeed, int maxMissiles, int maxGunRounds, float maxArmor), speedModifiers(speedModifiers);


};

#endif // PLANE_H
