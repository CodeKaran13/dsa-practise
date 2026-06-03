//
// Created by Karan Nandkar on 02/06/26.
//

#include "Enemy.h"

namespace TowerDefense
{
    Enemy::Enemy(float health, float speed, const Path* path)
        : health(health),
          speed(speed),
          path(path),
          currentWaypointIndex(0),
          reachedEnd(false)
    {
        if (path && path->GetWaypointCount() > 0)
        {
            position = path->GetWaypoint(0);
            currentWaypointIndex = 1;
        }
    }

    void Enemy::Update(float deltaTime)
    {
        if (IsDead() || reachedEnd || !path)
            return;

        if (currentWaypointIndex > path->GetWaypointCount())
        {
            reachedEnd = true;
            return;
        }

        Vector2 target = path->GetWaypoint(currentWaypointIndex);
        Vector2 direction = target - position;

        float distanceToTarget = direction.Length();
        float moveDistance = speed * deltaTime;

        if (moveDistance >= distanceToTarget)
        {
            position = target;
            currentWaypointIndex++;

            if (currentWaypointIndex >= path->GetWaypointCount())
            {
                reachedEnd = true;
            }
        }
        else
        {
            position = position + direction.Normalized() * moveDistance;
        }
    }

    void Enemy::TakeDamage(float damage)
    {
        health -= damage;
    }

    bool Enemy::IsDead() const
    {
        return health <= 0.0f;
    }

    bool Enemy::HasReachedEnd() const
    {
        return reachedEnd;
    }

    const Vector2& Enemy::GetPosition() const
    {
        return position;
    }
} // TowerDefense
