//
// Created by Karan Nandkar on 03/06/26.
//

#ifndef DSA_PRATISE_TOWER_H
#define DSA_PRATISE_TOWER_H

#include <vector>
#include "Enemy.h"
#include "Projectile.h"
#include "../Gameplay/Vector.h"
#include <memory>

namespace TowerDefense
{
    class Tower
    {
    private:
        Vector2 position;

        float range;
        float fireRate;
        float fireTimer;

        float projectileSpeed;
        float damage;

    public:
        Tower(const Vector2& position, float range, float fireRate, float projectileSpeed, float damage);
        void Update(float deltaTime, const std::vector<std::unique_ptr<Enemy>>& enemies,
                    std::vector<std::unique_ptr<Projectile>>& projectiles);

    private:
        Enemy* FindTarget(const std::vector<std::unique_ptr<Enemy>>& enemies);
        void Fire(Enemy* target, std::vector<std::unique_ptr<Projectile>>& projectiles);
    };
} // TowerDefense

#endif //DSA_PRATISE_TOWER_H
