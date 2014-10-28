
#ifndef TESTCOIN_H__
#define TESTCOIN_H__

#include "Coin.h"
#include "TestResult.h"

class TestCoin
{
public:
	eTestResult TestInsertValidCoin();
	eTestResult TestInsertInvalidCoin();
};

#endif
