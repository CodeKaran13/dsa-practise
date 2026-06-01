//
// Created by Karan Nandkar on 01/06/26.
//

#include "Player.h"

Player::Player(const std::string& n, Cell s)
    : name(n), symbol(s) {}

const std::string& Player::GetName() const
{
    return name;
}

Cell Player::GetSymbol() const
{
    return symbol;
}
