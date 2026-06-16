#include <iostream>
#include <thread>
#include <vector>

#include "Gameplay/WeaponSystem/Player.h"
#include "Gameplay/WeaponSystem/Weapon.h"
#include "Gameplay/WeaponSystem/WeaponFactory.h"
#include "Gameplay/Vector.h"
#include "RAII/ThreadSafeQueue.h"

std::vector<int> TwoSum(const std::vector<int>& nums, int target);

bool IsValid(const std::string& s);

bool IsValidOptimized(const std::string& s);

void Move(const Vector2 start, const Vector2 end, const float duration, float deltaTime)
{
    float elapsedTime = 0.0f;

    while (elapsedTime < duration)
    {
        elapsedTime += deltaTime;
        float alpha = elapsedTime / duration;
        Vector2 position = Vector2::Lerp(start, end, alpha);

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

    ThreadSafeQueue<std::string> queue;

    std::thread producer([&queue]()
    {
        queue.Push("Load Assets");
        queue.Push("Parse Config");
        queue.Push("Build NavMesh");
    });

    std::thread consumer([&queue]()
    {
        for (int i = 0; i < 3; i++)
        {
            std::string job = queue.WaitAndPop();
            std::cout << "Consumed Job: " << job << "\n";
        }
    });

    producer.join();
    consumer.join();

    return 0;
}
