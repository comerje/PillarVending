
#ifndef COINMECHANISM_H__
#define COINMECHANISM_H__

#include <list>
#include "Coin.h"

class CoinMechanism
{
public:
	CoinMechanism();
	~CoinMechanism();

	void insertCoin(eCoin coin);
	int total();

private:
	std::list<eCoin> m_coins;
};

#endif
