#include "Characters.h"

#include <utility>
Characters::Characters(char team)
{
    isCellOpen = true;
    teamIcon = team;
    ticked = false;

    if (teamIcon == 's')
    {
        this->isSith = true;
        this->isJedi = false;
        this->health = 9;
        this->damageGiven = 11;
    }
    if (teamIcon == 'j')
    {
        this->isSith = false;
        this->isJedi = true;
        this->health = 11;
        this->damageGiven = 9;
    }

    if (teamIcon == '#')
    {
        this->isSith = true;
        this->isJedi = true;
        this->health = 1000000;
        this->damageGiven = 0;
    }
}

Characters::Characters()
{
}

Characters::~Characters()
{
    if (teamIcon == 's')
    {
    }
    if (teamIcon == 'j')
    {
    }
}

float Characters::getHealth()
{
    return this->health;
}

void Characters::setHealth(float vitality)
{
    this->health = vitality;
}

int Characters::getDamage()
{
    return damageGiven;
}

float Characters::doDamage(int attackerDamage, float hostileHealth)
{

    return hostileHealth - attackerDamage;
}
