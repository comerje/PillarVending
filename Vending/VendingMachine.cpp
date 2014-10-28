
#include "VendingMachine.h"
#include "StringFormatter.h"

VendingMachine::VendingMachine()
	:m_state(eVendingState::Waiting)
{
	m_productPriceMap.insert(std::map<eProducts, int>::value_type(eProducts::Candy, 65));
	m_productPriceMap.insert(std::map<eProducts, int>::value_type(eProducts::Chips, 50));
	m_productPriceMap.insert(std::map<eProducts, int>::value_type(eProducts::Cola, 100));
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
		
		return std::string("PRICE " + StringFormatter::FormatCurrency(m_productPriceMap[m_product]));
		break;
	case eVendingState::Complete: 
		m_state = eVendingState::Waiting;
		return std::string("THANK YOU");
	}

	return std::string("");
}

void VendingMachine::Dispense(eProducts product)
{
	m_state = eVendingState::Dispense;
	m_product = product;

	if(m_coinMechanism.Total() >= m_productPriceMap[product])
	{
		MakeChange();
		m_state = eVendingState::Complete;
	}
}

void VendingMachine::ReturnCoins()
{
	m_coinMechanism.Transfer(CoinReturn);
	m_state = eVendingState::Waiting;
}

void VendingMachine::MakeChange()
{
	int toReturn = m_coinMechanism.Total() - m_productPriceMap[m_product];
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
