//
// Created by Karan Nandkar on 01/06/26.
//

#include "Player.h"
#include "Weapon.h"

Player::Player() = default;

Player::~Player() = default;

void Player::EquipWeapon(std::unique_ptr<Weapon> weapon)
{
    currentWeapon = std::move(weapon);
}

void Player::FireWeapon()
{
    if (currentWeapon)
    {
        currentWeapon->Fire();
    }
}
