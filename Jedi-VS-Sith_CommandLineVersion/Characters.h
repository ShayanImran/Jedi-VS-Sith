#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED


class Characters
{
    public:

        Characters(char team);
        Characters();
        ~Characters();
        float getHealth();
        float doDamage(int attackerDamage, float hostileHealth);
        float health;
        int getDamage();
        int attackRange;
        int damageGiven;
        int movementSpeed;
        char teamIcon; // J for jedi and S for Sith
        bool isJedi;
        bool isSith;
        bool isCellOpen;
        bool ticked;
        void setHealth(float vitality);


    private:


    protected:

};
#endif // CHARACTERS_H_INCLUDED
