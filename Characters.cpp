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

    void Characters::moveTo(Characters one, Characters two)
    {
        Characters temp;

        temp.xVal = one.xVal;
        temp.yVal = one.yVal;

        one.xVal = two.xVal;
        one.yVal = two.yVal;

        two.xVal = temp.xVal;
        two.xVal = one.xVal;

    }


    void Characters::doDamage(Characters attacker, Characters hostile)
    {
        hostile.setHealth(hostile.getHealth() - attacker.getDamage());
    }
