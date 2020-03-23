#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED

class Characters
{
public:
    Characters(float vitality, int damageGiven, int mvmntSpeed, int attRange, int specRange);
    float getHealth();
    void setHealth(float vitality);
    int getDamage();
    int attackRange = 0;

private:
    float health;
    int damageGiven;
    int movementSpeed;
    //int attackRange;
    int specialRange;

protected:
    void animate(Characters current);
    // void moveTo(Cell from, Cell to);
    void doDamage(Characters attacker, Characters hostile);
};
#endif // CHARACTERS_H_INCLUDED
