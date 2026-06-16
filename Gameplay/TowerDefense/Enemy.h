//
// Created by Karan Nandkar on 02/06/26.
//

#ifndef DSA_PRATISE_ENEMY_H
#define DSA_PRATISE_ENEMY_H


#include "Path.h"
#include "../Gameplay/Vector.h"

namespace TowerDefense
{
    class Enemy
    {
    private:
        float health;
        float speed;
        Vector2 position;

        const Path* path;
        int currentWaypointIndex;

        bool reachedEnd;

    public:
        Enemy(float health, float speed, const Path* path);

        void Update(float deltaTime);
        void TakeDamage(float damage);

        bool IsDead() const;
        bool HasReachedEnd() const;

        const Vector2& GetPosition() const;
    };
} // TowerDefense

#endif //DSA_PRATISE_ENEMY_H
