//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_PLAYER_H
#define DSA_PRATISE_PLAYER_H
#include <string>


enum class Cell;

class Player
{
private:
    std::string name;
    Cell symbol;

public:
    Player(const std::string& n, Cell s);
    const std::string& GetName() const;
    Cell GetSymbol() const;
};


#endif //DSA_PRATISE_PLAYER_H
