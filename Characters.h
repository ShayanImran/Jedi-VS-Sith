#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED


class Characters
{
    public:

        Characters(float vitality, int damageGiven, int mvmntSpeed, int attRange, int specRange, char team);
        Characters();
        float getHealth();
        void setHealth(float vitality);
        int getDamage();
        int attackRange;
        char teamIcon; // J for jedi and S for Sith
        bool isJedi;
        bool isSith;
        void moveTo(Characters one, Characters two);
        int xVal;
        int yVal;

    private:

        float health;
        int damageGiven;
        int movementSpeed;
        //int attackRange;
        int specialRange;

    protected:

        void animate(Characters current);

        void doDamage(Characters attacker, Characters hostile);

};
#endif // CHARACTERS_H_INCLUDED
