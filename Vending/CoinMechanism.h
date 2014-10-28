
#ifndef COINMECHANISM_H__
#define COINMECHANISM_H__

#include <list>
#include "Coin.h"

class CoinMechanism
{
public:
	CoinMechanism();
	~CoinMechanism();

	void InsertCoin(eCoin coin);
	int Total();
	void Transfer(std::list<eCoin>& transferTo);
	void Clear();

private:
	std::list<eCoin> m_coins;
};

#endif
