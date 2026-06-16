//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_ABILITY_H
#define DSA_PRATISE_ABILITY_H


class Ability
{
private:
    int maxCharges;

    int currentCharges;

    float cooldown;

    float rechargeTimer;

public:
    Ability(int maxC, float coolD);

    void Update(float deltaTime);

    bool CanCast() const;

    bool Cast();

    int GetCharges() const;
};


#endif //DSA_PRATISE_ABILITY_H
