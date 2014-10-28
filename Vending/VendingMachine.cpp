
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
	if(!IsCoinValid(coin))
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
	case eVendingState::Waiting: 
		if(CanMakeChange())
			return std::string("INSERT COIN");
		else
			return std::string("EXACT CHANGE");
		break;
	case eVendingState::ValidCoin: return StringFormatter::FormatCurrency(m_coinMechanism.Total());
	case eVendingState::Dispense:
		if(!IsMoneyInMachine())
			m_state = eVendingState::Waiting;
		else
			m_state = eVendingState::ValidCoin;
		
		return std::string("PRICE " + StringFormatter::FormatCurrency(m_inventory.GetPrice(m_product)));
		break;
	case eVendingState::Complete: 
		m_state = eVendingState::Waiting;
		return std::string("THANK YOU");
	case eVendingState::OutOfStock:
		if(!IsMoneyInMachine())
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

	Product& tempProduct = m_inventory.GetProduct(product);
	if(NeedMoreMoneyInserted(m_coinMechanism.Total(), tempProduct.Price()))
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
}

void VendingMachine::ReturnCoins()
{
	m_coinMechanism.Transfer(CoinReturn);
	m_state = eVendingState::Waiting;
}

void VendingMachine::MakeChange()
{
	int toReturn = m_coinMechanism.Total() - m_inventory.GetPrice(m_product);
	if(0 == toReturn)
		return;

	m_coinMechanism.Clear();

	int quartersToReturn = toReturn / 25;
	if(m_coinMechanism[eCoin::Quarter] >= quartersToReturn)
		toReturn -= (quartersToReturn*25);

	int dimesToReturn = toReturn / 10;
	if(m_coinMechanism[eCoin::Dime] >= dimesToReturn)
		toReturn -= (dimesToReturn*10);
	
	int nickelsToReturn = toReturn / 5;

	ReturnCoin(eCoin::Quarter, quartersToReturn);
	ReturnCoin(eCoin::Dime, dimesToReturn);
	ReturnCoin(eCoin::Nickel, nickelsToReturn);
}

bool VendingMachine::CanMakeChange()
{
	if(m_coinMechanism[eCoin::Nickel] == 0)
		return false;

	if(m_coinMechanism[eCoin::Quarter] == 0)
		return (m_coinMechanism[eCoin::Dime] >= 5);

	return (m_coinMechanism[eCoin::Dime] >= 2);
}

void VendingMachine::ReturnCoin(eCoin type, int quantityToReturn)
{
	for(int i = 0; i < quantityToReturn; ++i)
	{
		--(m_coinMechanism[type]);
		CoinReturn.push_back(type);
	}
}

VendingMachine::VendingMachine(const VendingMachine& vm)
{
}

VendingMachine& VendingMachine::operator=(const VendingMachine& rhs)
{
	if(this == &rhs)
		return *this;

	// code goes here

	return *this;
}
