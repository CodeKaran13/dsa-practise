//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_PLAYER_H
#define DSA_PRATISE_PLAYER_H
#include <memory>


class Weapon;

class Player
{
public:
    Player();

    ~Player();

private:
    std::unique_ptr<Weapon> currentWeapon;

public:
    void EquipWeapon(std::unique_ptr<Weapon> weapon);

    void FireWeapon();
};


#endif //DSA_PRATISE_PLAYER_H
