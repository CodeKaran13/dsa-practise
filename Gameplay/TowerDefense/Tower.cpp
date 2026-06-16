//
// Created by Karan Nandkar on 03/06/26.
//

#include "Tower.h"

namespace TowerDefense
{
    Tower::Tower(const Vector2& position, float range, float fireRate, float projectileSpeed, float damage)
        : position(position),
          range(range),
          fireRate(fireRate),
          fireTimer(0.0f),
          projectileSpeed(projectileSpeed),
          damage(damage)
    {}

    void Tower::Update(float deltaTime, const std::vector<std::unique_ptr<Enemy>>& enemies, std::vector<std::unique_ptr<Projectile>>& projectiles)
    {
        fireTimer += deltaTime;
        if (fireTimer < fireRate)
        {
            return;
        }

        // shoot projectile
        Enemy* target = FindTarget(enemies);
        if (target)
        {
            Fire(target, projectiles);
            fireTimer = 0.0f;
        }
    }

    Enemy* Tower::FindTarget(const std::vector<std::unique_ptr<Enemy>>& enemies)
    {
        Enemy* nearestEnemy = nullptr;
        float nearestDistance = range;

        for (auto& enemy : enemies)
        {
            if (!enemy || enemy->IsDead() || enemy->HasReachedEnd())
            {
                continue;
            }

            float distance = Vector2::Distance(position, enemy->GetPosition());
            if (distance <= nearestDistance)
            {
                nearestDistance = distance;
                nearestEnemy = enemy.get();
            }
        }

        return nearestEnemy;
    }

    void Tower::Fire(Enemy* target, std::vector<std::unique_ptr<Projectile>>& projectiles)
    {
        projectiles.push_back(std::make_unique<Projectile>(position, target, projectileSpeed, damage));
    }
} // TowerDefense
