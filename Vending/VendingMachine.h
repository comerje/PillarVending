
#ifndef VENDINGMACHINE_H__
#define VENDINGMACHINE_H__

#include "Coin.h"
#include "VendingState.h"
#include "CoinMechanism.h"
#include "Products.h"
#include "Product.h"
#include "Inventory.h"
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
	bool CanMakeChange();
	void ReturnCoin(eCoin type, int quantityToReturn);

	bool IsCoinValid(eCoin coin) { return !(eCoin::Penny == coin); }
	bool IsMoneyInMachine() { return (m_coinMechanism.Total() != 0); }
	bool NeedMoreMoneyInserted(int totalInserted, int price) { return (totalInserted < price);} 

	VendingMachine(const VendingMachine& vm);
	VendingMachine& operator=(const VendingMachine& rhs);

	eVendingState m_state;
	CoinMechanism m_coinMechanism;
	eProducts m_product;
	Inventory m_inventory;
};

#endif
