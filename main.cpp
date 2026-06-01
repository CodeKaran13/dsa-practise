#include <iostream>
#include "weapon-system/Player.h"
#include "weapon-system/Weapon.h"
#include "weapon-system/WeaponFactory.h"
#include "move-a-to-b/Vector.h"

std::vector<int> twoSum(const std::vector<int>& nums, int target);

bool isValid(const std::string& s);

bool isValidOptimized(const std::string& s);

void Move(Vector2 start, Vector2 end, float duration, float deltaTime)
{
    float elapsedTime = 0.0f;

    while (elapsedTime < duration)
    {
        elapsedTime += deltaTime;
        float alpha = elapsedTime / duration;
        Vector2 position = Lerp(start, end, alpha);

        std::cout << "Position: " << position.x << ", " << position.y << "\n";
    }
}

int main()
{
    // std::string s = "()[]{}";
    // std::cout << std::boolalpha << isValidOptimized(s) << std::endl;

    // Player player;
    //
    // player.EquipWeapon(WeaponFactory::CreateWeapon(WeaponType::Pistol));
    // player.FireWeapon();
    //
    // player.EquipWeapon(WeaponFactory::CreateWeapon(WeaponType::Shotgun));
    // player.FireWeapon();
    //
    // player.EquipWeapon(WeaponFactory::CreateWeapon(WeaponType::RocketLauncher));
    // player.FireWeapon();

    Vector2 start{10.0f, 20.0f};
    Vector2 end{110.0f, 70.0f};

    float duration = 5.0f;
    float deltaTime = 0.2f;

    Move(start, end, duration, deltaTime);
}
