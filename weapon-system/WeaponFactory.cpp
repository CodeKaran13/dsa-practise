//
// Created by Karan Nandkar on 01/06/26.
//

#include "WeaponFactory.h"
#include "Pistol.h"
#include "RocketLauncher.h"
#include "Shotgun.h"
#include "Weapon.h"


std::unique_ptr<Weapon> WeaponFactory::CreateWeapon(WeaponType wt)
{
    switch (wt)
    {
    case WeaponType::Pistol:
        return std::make_unique<Pistol>();

    case WeaponType::Shotgun:
        return std::make_unique<Shotgun>();

    case WeaponType::RocketLauncher:
        return std::make_unique<RocketLauncher>();

    default:
        return nullptr;
    }
}
