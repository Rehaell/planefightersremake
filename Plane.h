#include <string>


class Plane {
private:
    std::string name;
    int maxSpeed;
    int maxMissiles;
    int maxGunRounds;
    float maxArmor;    

public:
    //Constructor
    Plane(std::string name, int maxSpeed, int maxMissiles, int maxGunRounds, float maxArmor);

};