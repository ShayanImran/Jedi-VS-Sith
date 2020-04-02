#include "Characters.h"
#include "Cell.h"
#include <utility>
    Characters::Characters(float vitality, int damage, int mvmntSpeed, int attRange, int specRange, char team)
    {
        isCellOpen = true;
        health = vitality;
        damageGiven = damage;
        movementSpeed = mvmntSpeed;
        attackRange = attRange;
        specialRange =  specRange;
        teamIcon = team;

        if (teamIcon == 's')
        {
            this->isSith = true;
            this->isJedi = false;
        }
        if (teamIcon == 'j')
        {
            this->isSith = false;
            this->isJedi = true;
        }
    }


    Characters::Characters()
    {


    }

    float Characters::getHealth()
    {
        return health;
    }

    void Characters::setHealth(float vitality)
    {
        health = vitality;
    }

    int Characters::getDamage()
    {
        return damageGiven;
    }

    void Characters::animate(Characters curr)
    {

    }
/*
    void Characters::moveUp(Characters ****gboard)
    {
        std::swap(gboard[0][0][0],gboard[1][0][0]);


    }
*/

    void Characters::doDamage(Characters attacker, Characters hostile)
    {
        hostile.setHealth(hostile.getHealth() - attacker.getDamage());
    }
