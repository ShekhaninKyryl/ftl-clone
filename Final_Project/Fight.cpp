#include <iostream>
#include "Fight.h"
#include "Ship.h"
#include "EnemyShip.h"


Fight::Fight(Ship* player, EnemyShip* enemy) : player(player), enemy(enemy)
{
}

FightState Fight::update(float deltaTime)
{
    if (player == nullptr || enemy == nullptr) return FightState::Idle;
    // ������� ����� ��������
            std::cout << "Battle with the enemy!" << std::endl;
            player->takeDamage(enemy->getDamage());  // ������� ������ ����������
            enemy->takeDamage(player->getDamage());  // ����� ������ ����������

            // ��������, �� ����� ��� ������� �� �������
            if (enemy->getHealth() <= 0) {
                std::cout << "The enemy is destroyed!" << std::endl;
                return FightState::Win;
            }
            if (player->getHealth() <= 0) {
                std::cout << "The player is dead!" << std::endl;
                return FightState::Lose;
            }

            return FightState::Idle;
}
