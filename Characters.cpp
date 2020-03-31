#include "Characters.h"
#include "Cell.h"

    Characters::Characters(float vitality, int damage, int mvmntSpeed, int attRange, int specRange, char team)
    {
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

    void Characters::moveTo(int currentX, int currentY, int currentZ, int moveToX,int moveToY, int moveToZ)
    {/*
        Characters temp;
        temp.setOffset(from.getOffset());

        from.setOffset(to.getOffset());

        to.setOffset(temp.getOffset());
*/
    }


    void Characters::doDamage(Characters attacker, Characters hostile)
    {
        hostile.setHealth(hostile.getHealth() - attacker.getDamage());
    }
