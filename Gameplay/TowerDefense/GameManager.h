//
// Created by Karan Nandkar on 03/06/26.
//

#ifndef DSA_PRATISE_GAMEMANAGER_H
#define DSA_PRATISE_GAMEMANAGER_H

#include "Enemy.h"
#include "Path.h"
#include "Tower.h"
#include "WaveManager.h"

namespace TowerDefense
{
    class GameManager
    {
    private:
        Path path;
        std::vector<std::unique_ptr<Enemy>> enemies;
        std::vector<std::unique_ptr<Tower>> towers;
        std::vector<std::unique_ptr<Projectile>> projectiles;

        std::unique_ptr<WaveManager> waveManager;

        int playerLives;
        bool gameOver;

    public:
        GameManager();

        void Start();
        void Update(float deltaTime);

    private:
        void CreatePath();
        void CreateTowers();

        void UpdateEnemies(float deltaTime);
        void UpdateTowers(float deltaTime);
        void UpdateProjectiles(float deltaTime);

        void RemoveDeadObjects();
    };
} // TowerDefense

#endif //DSA_PRATISE_GAMEMANAGER_H
