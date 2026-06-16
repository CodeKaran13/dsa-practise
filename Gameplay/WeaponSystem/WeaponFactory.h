//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_WEAPONFACTORY_H
#define DSA_PRATISE_WEAPONFACTORY_H
#include <memory>

class Weapon;

enum class WeaponType
{
    Pistol,
    Shotgun,
    RocketLauncher
};

class WeaponFactory
{
public:
    static std::unique_ptr<Weapon> CreateWeapon(WeaponType wt);
};


#endif //DSA_PRATISE_WEAPONFACTORY_H
