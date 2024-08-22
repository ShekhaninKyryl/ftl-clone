#pragma once


class Resources
{
public:
	Resources();

	unsigned setFuel(unsigned newFuel) { fuel = newFuel; return fuel; }
	unsigned getFuel() const { return fuel; }
	unsigned setMoney(unsigned newMoney) { money = newMoney; return money; }
	unsigned getMoney() const { return money; }

private:
	unsigned fuel;
	unsigned money;
};