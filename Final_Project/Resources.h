#pragma once


class Resources
{
public:
	Resources();
	Resources(unsigned fuel, unsigned money);

	unsigned setFuel(unsigned newFuel) { fuel = newFuel; return fuel; }
	unsigned getFuel() const { return fuel; }
	unsigned setMoney(unsigned newMoney) { money = newMoney; return money; }
	unsigned getMoney() const { return money; }

	Resources operator+(const Resources& other) const {
		return Resources(fuel + other.fuel, money + other.money);
	}

	Resources& operator+=(const Resources& other) {
		fuel += other.fuel;
		money += other.money;
		return *this;
	}

private:
	unsigned fuel;
	unsigned money;
};