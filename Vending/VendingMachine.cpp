
#include "VendingMachine.h"
#include "StringFormatter.h"

VendingMachine::VendingMachine()
	:m_state(eVendingState::Waiting)
{
	m_inventory.insert(std::map<eProducts, Product>::value_type(eProducts::Candy, Product(eProducts::Candy, 65, 1)));
	m_inventory.insert(std::map<eProducts, Product>::value_type(eProducts::Chips, Product(eProducts::Chips, 50, 1)));
	m_inventory.insert(std::map<eProducts, Product>::value_type(eProducts::Cola, Product(eProducts::Cola, 100, 1)));
}

VendingMachine::~VendingMachine()
{
}

void VendingMachine::InsertCoin(eCoin coin)
{
	if(eCoin::Penny == coin)
	{
		CoinReturn.push_back(coin);
		return;
	}

	m_coinMechanism.InsertCoin(coin);
	m_state = ValidCoin;
}

std::string VendingMachine::Display()
{
	switch(m_state)
	{
	case eVendingState::Waiting: return std::string("INSERT COIN");
	case eVendingState::ValidCoin: return StringFormatter::FormatCurrency(m_coinMechanism.Total());
	case eVendingState::InvalidCoin: break;
	case eVendingState::Dispense:
		if(!m_coinMechanism.Total())
			m_state = eVendingState::Waiting;
		else
			m_state = eVendingState::ValidCoin;
		
		return std::string("PRICE " + StringFormatter::FormatCurrency(m_inventory.find(m_product)->second.Price()));
		break;
	case eVendingState::Complete: 
		m_state = eVendingState::Waiting;
		return std::string("THANK YOU");
	case eVendingState::OutOfStock:
		if(!m_coinMechanism.Total())
			m_state = eVendingState::Waiting;
		else
			m_state = eVendingState::ValidCoin;

		return std::string("SOLD OUT");
	}

	return std::string("");
}

void VendingMachine::Dispense(eProducts product)
{
	m_state = eVendingState::Dispense;
	m_product = product;

	Product& tempProduct = m_inventory.find(product)->second;
	if(m_coinMechanism.Total() < tempProduct.Price())
		return;

	if(tempProduct.OutOfStock())
	{
		m_state = eVendingState::OutOfStock;
		return;
	}

	MakeChange();
	tempProduct.Remove(1);
	m_coinMechanism.Clear();
	m_state = eVendingState::Complete;

	/*Product& tempProduct = m_inventory.find(product)->second;
	if(m_coinMechanism.Total() >= tempProduct.Price())
	{
		MakeChange();
		tempProduct.Remove(1);
		m_state = eVendingState::Complete;
	}*/
}

void VendingMachine::ReturnCoins()
{
	m_coinMechanism.Transfer(CoinReturn);
	m_state = eVendingState::Waiting;
}

void VendingMachine::MakeChange()
{
	int toReturn = m_coinMechanism.Total() - m_inventory.find(m_product)->second.Price();
	if(0 == toReturn)
		return;

	int quartersToReturn = toReturn / 25;
	toReturn -= (quartersToReturn*25);
	int dimesToReturn = toReturn / 10;
	toReturn -= (dimesToReturn*10);
	int nickelsToReturn = toReturn / 5;

	for(int i = 0; i < quartersToReturn; ++i)
		CoinReturn.push_back(eCoin::Quarter);

	for(int i = 0; i < dimesToReturn; ++i)
		CoinReturn.push_back(eCoin::Dime);

	for(int i = 0; i < nickelsToReturn; ++i)
		CoinReturn.push_back(eCoin::Nickel);
}
