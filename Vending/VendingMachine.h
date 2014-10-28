
#ifndef VENDINGMACHINE_H__
#define VENDINGMACHINE_H__

#include "Coin.h"
#include "VendingState.h"
#include "CoinMechanism.h"
#include "Products.h"
#include "Product.h"
#include <string>
#include <list>
#include <map>

class VendingMachine
{
public:
	VendingMachine();
	~VendingMachine();

	void InsertCoin(eCoin coin);
	std::string Display();
	void Dispense(eProducts product);
	void ReturnCoins();

	std::list<eCoin> CoinReturn;

private:
	void MakeChange();
	eVendingState m_state;
	CoinMechanism m_coinMechanism;
	eProducts m_product;
	//std::map<eProducts, int> m_productPriceMap;
	std::map<eProducts, Product> m_inventory;
};

#endif
