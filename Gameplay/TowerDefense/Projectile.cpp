//
// Created by Karan Nandkar on 03/06/26.
//

#include "Projectile.h"

namespace TowerDefense
{
    Projectile::Projectile(const Vector2& position, Enemy* target, float speed, float damage)
        : position(position),
          target(target),
          speed(speed),
          damage(damage),
          active(true)
    {}

    void Projectile::Update(float deltaTime)
    {
        if (!active || !target || target->IsDead())
        {
            active = false;
            return;
        }

        Vector2 direction = target->GetPosition() - position;
        float distanceToTarget = direction.Length();
        float moveDistance = speed * deltaTime;

        if (moveDistance >= distanceToTarget)
        {
            target->TakeDamage(damage);
            active = false;
        }
        else
        {
            position = position + direction.Normalized() * moveDistance;
        }
    }

    bool Projectile::IsActive() const
    {
        return active;
    }
} // TowerDefense
