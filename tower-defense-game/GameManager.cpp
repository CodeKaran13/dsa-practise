//
// Created by Karan Nandkar on 03/06/26.
//

#include "GameManager.h"

#include <iostream>

namespace TowerDefense
{
    GameManager::GameManager()
        : playerLives(10),
          gameOver(false)
    {}

    void GameManager::Start()
    {
        CreatePath();
        CreateTowers();

        waveManager = std::make_unique<WaveManager>(&path);
        waveManager->StartWave(5);

        std::cout << "Tower Defense Started\n";
    }

    void GameManager::Update(float deltaTime)
    {
        if (gameOver)
        {
            return;
        }

        waveManager->Update(deltaTime, enemies);

        UpdateEnemies(deltaTime);
        UpdateTowers(deltaTime);
        UpdateProjectiles(deltaTime);

        RemoveDeadObjects();

        if (playerLives <= 0)
        {
            gameOver = true;
            std::cout << "Game Over!\n";
        }
    }

    void GameManager::CreatePath()
    {
        path.AddWaypoint(Vector2(0.0f, 0.0f));
        path.AddWaypoint(Vector2(100.0f, 0.0f));
        path.AddWaypoint(Vector2(100.0f, 100.0f));
        path.AddWaypoint(Vector2(200.0f, 100.0f));
    }

    void GameManager::CreateTowers()
    {
        towers.push_back(std::make_unique<Tower>(
            Vector2(50.0f, 20.0f),
            80.0f,
            1.0f,
            25.0f,
            100.0f
        ));

        towers.push_back(std::make_unique<Tower>(
            Vector2(120.0f, 80.0f),
            80.0f,
            1.5f,
            40.0f,
            80.0f
        ));
    }

    void GameManager::UpdateEnemies(float deltaTime)
    {
        for (auto& enemy : enemies)
        {
            enemy->Update(deltaTime);
            if (enemy->HasReachedEnd())
            {
                playerLives--;
                std::cout << "Enemy reached base. Lives: " << playerLives << "\n";
            }
        }
    }

    void GameManager::UpdateTowers(float deltaTime)
    {
        for (auto& tower : towers)
        {
            tower->Update(deltaTime, enemies, projectiles);
        }
    }

    void GameManager::UpdateProjectiles(float deltaTime)
    {
        for (auto& projectile : projectiles)
        {
            projectile->Update(deltaTime);
        }
    }

    void GameManager::RemoveDeadObjects()
    {
        enemies.erase(
            std::remove_if(
                enemies.begin(),
                enemies.end(),
                [](const std::unique_ptr<Enemy>& enemy)
                {
                    return enemy->IsDead() || enemy->HasReachedEnd();
                }),
            enemies.end()
        );

        projectiles.erase(
            std::remove_if(
                projectiles.begin(),
                projectiles.end(),
                [](const std::unique_ptr<Projectile>& projectile)
                {
                    return !projectile->IsActive();
                }),
            projectiles.end()
        );
    }
} // TowerDefense
