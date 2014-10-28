
#ifndef TESTDISPLAY_H__
#define TESTDISPLAY_H__

#include "TestResult.h"

class TestDisplay
{
public:
	eTestResult TestDisplayInsertCoinWhenTotalIs0();
	eTestResult TestDisplayWhenTotalIs5Cents();
	eTestResult TestDisplayWhenTotalIs10Cents();
	eTestResult TestDisplayWhenTotalIs15Cents();
	eTestResult TestDisplayWhenTotalIs25Cents();
	eTestResult TestDisplaySoldOutWhenNoInventory();
	eTestResult TestDisplayAmountInsertedAfterSoldOut();
	eTestResult TestDisplayExactChange();
};

#endif
