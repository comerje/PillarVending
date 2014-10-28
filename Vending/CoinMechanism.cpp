
#include "CoinMechanism.h"


CoinMechanism::CoinMechanism(void)
{
	m_coins.clear();
}


CoinMechanism::~CoinMechanism(void)
{
}

void CoinMechanism::insertCoin(eCoin coin)
{
	m_coins.push_back(coin);
}

int CoinMechanism::total()
{
	int total = 0;
	for(std::list<eCoin>::const_iterator iter = m_coins.begin(); iter != m_coins.end(); ++iter)
		total += *iter;

	return total;
}