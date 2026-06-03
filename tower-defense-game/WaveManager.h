//
// Created by Karan Nandkar on 03/06/26.
//

#ifndef DSA_PRATISE_WAVEMANAGER_H
#define DSA_PRATISE_WAVEMANAGER_H
#include "Enemy.h"
#include "Path.h"

namespace TowerDefense
{
    class WaveManager
    {
    private:
        const Path* path;

        int enemiesToSpawn;
        int spawnedEnemies;

        float spawnInterval;
        float spawnTimer;

        bool waveActive;

    public:
        WaveManager(const Path* path);

        void StartWave(int enemyCount);
        void Update(float deltaTime, std::vector<std::unique_ptr<Enemy>>& enemies);

        bool IsWaveActive() const;
    };
} // TowerDefense

#endif //DSA_PRATISE_WAVEMANAGER_H
