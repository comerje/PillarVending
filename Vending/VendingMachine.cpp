
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

	m_coinMechanism.insertCoin(coin);
	m_state = ValidCoin;
}

void VendingMachine::Dispense(eProducts product)
{
	m_state = eVendingState::Dispense;
	m_product = product;

	if(m_coinMechanism.total() >= m_productPriceMap[product])
		m_state = eVendingState::Complete;
}

std::string VendingMachine::Display()
{
	switch(m_state)
	{
	case eVendingState::Waiting: return std::string("INSERT COIN");
	case eVendingState::ValidCoin: return StringFormatter::FormatCurrency(m_coinMechanism.total());
	case eVendingState::InvalidCoin: break;
	case eVendingState::Dispense:
		if(!m_coinMechanism.total())
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