
#ifndef TESTDISPENSE_H__
#define TESTDISPENSE_H__

#include "TestResult.h"

class TestDispense
{
public:
	eTestResult TestDispenseChipsWithCorrectChange();
	eTestResult TestDispenseColaWithCorrectChange();
	eTestResult TestDispenseCandyWithCorrectChange();
	eTestResult TestDispenseShowInsertCoinAfterThankYou();
	eTestResult TestShowPriceWhenNoMoneyInserted();
	eTestResult TestShowInsertCoinAfterShowPriceWhenNoMoneyInserted();
	eTestResult TestShowPriceWhenInsufficientMoneyInserted();
	eTestResult TestShowTotalInsertedAfterPriceWithInsufficientFunds();
};

#endif
