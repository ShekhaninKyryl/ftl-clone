#include "Fight.h"


Fight::Fight(Ship* player, EnemyShip* enemy) : player(player), enemy(enemy)
{
}

FightState Fight::update(float deltaTime)
{
    if (player == nullptr || enemy == nullptr) return FightState::Idle;
    // Простий радіус зіткнення
            std::cout << "Battle with the enemy!" << std::endl;

            std::string logStr;
            player->takeDamage(enemy->getDamage(), logStr);  // Гравець отримує ушкодження
            logs.push_back(logStr);

            enemy->takeDamage(player->getDamage(), logStr);  // Ворог отримує ушкодження
            logs.push_back(logStr);

            

            // Перевірка, чи ворог або гравець не загинув
            if (enemy->getHealth() <= 0) {
                std::cout << "The enemy is destroyed!" << std::endl;
                logs.push_back("The enemy is destroyed!");


                player->lootResources(enemy->grabLoot(), logStr);
                logs.push_back(logStr);
                return FightState::Win;
            }
            if (player->getHealth() <= 0) {
                std::cout << "The player is dead!" << std::endl;
                logs.push_back("The player is dead!");

                return FightState::Lose;
            }

            return FightState::Idle;
}
