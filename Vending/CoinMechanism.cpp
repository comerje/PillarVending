
#include "CoinMechanism.h"


CoinMechanism::CoinMechanism(void)
{
	m_coinInventory.insert(std::map<eCoin,int>::value_type(eCoin::Dime, 2));
	m_coinInventory.insert(std::map<eCoin,int>::value_type(eCoin::Nickel, 1));
	m_coinInventory.insert(std::map<eCoin,int>::value_type(eCoin::Quarter, 1));
	m_coinInventory.insert(std::map<eCoin,int>::value_type(eCoin::Penny, 0));

	m_coins.clear();
}


CoinMechanism::~CoinMechanism(void)
{
}

void CoinMechanism::InsertCoin(eCoin coin)
{
	m_coins.push_back(coin);
}

int CoinMechanism::Total()
{
	int total = 0;
	for(std::list<eCoin>::const_iterator iter = m_coins.begin(); iter != m_coins.end(); ++iter)
		total += *iter;

	return total;
}

void CoinMechanism::Transfer(std::list<eCoin>& transferTo)
{
	transferTo.insert(transferTo.end(), m_coins.begin(), m_coins.end());
	m_coins.clear();
}

void CoinMechanism::Clear()
{
	for(std::list<eCoin>::const_iterator iter = m_coins.begin(); iter != m_coins.end(); ++iter)
		++(m_coinInventory.find(*iter)->second);

	m_coins.clear();
}

int& CoinMechanism::operator[](eCoin coinType)
{
	return m_coinInventory.find(coinType)->second;
}
