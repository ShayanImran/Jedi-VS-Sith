#include "Characters.h"
#include "Cell.h"

    Characters::Characters(float vitality, int damage, int mvmntSpeed, int attRange, int specRange)
    {
        health = vitality;
        damageGiven = damage;
        movementSpeed = mvmntSpeed;
        attackRange = attRange;
        specialRange =  specRange;
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
    void Characters::moveTo(Cell from, Cell to)
    {
        Cell temp;

        temp.setOffset(from.getOffset());
        temp.setImage(from.getImage());

        from.setOffset(to.getOffset());
        from.setImage(to.getImage());

        to.setOffset(temp.getOffset());
        to.setImage(temp.getImage());
    }
*/
    void Characters::doDamage(Characters attacker, Characters hostile)
    {
        hostile.setHealth(hostile.getHealth() - attacker.getDamage());
    }
