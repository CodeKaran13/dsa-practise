//
// Created by Karan Nandkar on 03/06/26.
//

#ifndef DSA_PRATISE_PROJECTILE_H
#define DSA_PRATISE_PROJECTILE_H

#include "Enemy.h"
#include "../move-a-to-b/Vector.h"

namespace TowerDefense
{
    class Projectile
    {
    private:
        Vector2 position;
        Enemy* target;

        float speed;
        float damage;
        bool active;

    public:
        Projectile(const Vector2& position, Enemy* target, float speed, float damage);

        void Update(float deltaTime);
        bool IsActive() const;
    };
} // TowerDefense

#endif //DSA_PRATISE_PROJECTILE_H
