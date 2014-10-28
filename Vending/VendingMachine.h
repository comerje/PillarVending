
#ifndef VENDINGMACHINE_H__
#define VENDINGMACHINE_H__

#include "Coin.h"
#include "VendingState.h"
#include "CoinMechanism.h"
#include <string>
#include <list>

class VendingMachine
{
public:
	VendingMachine();
	~VendingMachine();

	void InsertCoin(eCoin coin);
	std::string Display();

	std::list<eCoin> CoinReturn;

private:
	eVendingState m_state;
	CoinMechanism m_coinMechanism;
};

#endif
