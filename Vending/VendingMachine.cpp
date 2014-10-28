
#include "VendingMachine.h"
#include "StringFormatter.h"

VendingMachine::VendingMachine()
:m_state(eVendingState::Waiting)
{
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


std::string VendingMachine::Display()
{
	switch(m_state)
	{
	case Waiting: return std::string("INSERT COIN");
	case ValidCoin: return StringFormatter::FormatCurrency(m_coinMechanism.total());
	case InvalidCoin: break;
	case Dispense: break;
	case Complete:break;
	}

	return std::string("");
}