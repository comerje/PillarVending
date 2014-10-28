
#ifndef COINMECHANISM_H__
#define COINMECHANISM_H__

#include <list>
#include <map>
#include "Coin.h"

class CoinMechanism
{
public:
	CoinMechanism();
	~CoinMechanism();

	void InsertCoin(eCoin coin);
	int Total() const;
	void Transfer(std::list<eCoin>& transferTo);
	void Clear();
	int& operator[](eCoin coinType);

private:
	// don't want these being used
	CoinMechanism(const CoinMechanism& cm);
	CoinMechanism& operator=(const CoinMechanism& rhs);

	std::list<eCoin> m_coins;
	std::map<eCoin, int> m_coinInventory;
};

#endif
