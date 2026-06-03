//
// Created by Karan Nandkar on 03/06/26.
//

#include "WaveManager.h"

namespace TowerDefense
{
    WaveManager::WaveManager(const Path* path)
        : path(path),
          enemiesToSpawn(0),
          spawnedEnemies(0),
          spawnInterval(1.0f),
          spawnTimer(0.0f),
          waveActive(false)
    {}

    void WaveManager::StartWave(int enemyCount)
    {
        enemiesToSpawn = enemyCount;
        spawnedEnemies = 0;
        spawnTimer = 0.0f;
        waveActive = true;
    }

    void WaveManager::Update(float deltaTime, std::vector<std::unique_ptr<Enemy>>& enemies)
    {
        if (!waveActive)
        {
            return;
        }

        spawnTimer += deltaTime;
        if (spawnTimer < spawnInterval || spawnedEnemies >= enemiesToSpawn)
        {
            return;
        }

        spawnTimer = 0.0f;
        spawnedEnemies++;
        enemies.push_back(std::make_unique<Enemy>(100.0f, 30.0f, path));

        if (spawnedEnemies >= enemiesToSpawn)
        {
            waveActive = false;
        }
    }

    bool WaveManager::IsWaveActive() const
    {
        return waveActive;
    }
} // TowerDefense
