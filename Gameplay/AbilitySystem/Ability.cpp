//
// Created by Karan Nandkar on 01/06/26.
//

#include "Ability.h"

Ability::Ability(int maxC, float coolD)
    : maxCharges(maxC),
      currentCharges(maxCharges),
      cooldown(coolD),
      rechargeTimer(0.0f)
{}

void Ability::Update(float deltaTime)
{
    if (currentCharges >= maxCharges)
        return;

    rechargeTimer += deltaTime;
    if (rechargeTimer >= cooldown)
    {
        rechargeTimer -= cooldown;
        currentCharges++;
    }
}

bool Ability::CanCast() const
{
    return currentCharges > 0;
}

bool Ability::Cast()
{
    if (!CanCast())
    {
        return false;
    }

    currentCharges--;

    return true;
}

int Ability::GetCharges() const
{
    return currentCharges;
}
