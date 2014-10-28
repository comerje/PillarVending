
#include <iostream>
#include "TestDisplay.h"
#include "TestCoin.h"
#include "TestDispense.h"
#include "TestReturnCoins.h"

void RunTestDisplay()
{
	TestDisplay tests;
	std::cout << "Test Display" << std::endl
		<< (tests.TestDisplayInsertCoinWhenTotalIs0() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestDisplayWhenTotalIs5Cents() == eTestResult::Passed  ? "Passed" : "Failed") << std::endl
		<< (tests.TestDisplayWhenTotalIs10Cents() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestDisplayWhenTotalIs15Cents() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestDisplayWhenTotalIs25Cents() == eTestResult::Passed ? "Passed" : "Failed") << std::endl;
	std::cout << std::endl;
}

void RunTestCoin()
{
	TestCoin tests;
	std::cout << "Test Coins" << std::endl
		<< (tests.TestInsertValidCoin() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestInsertInvalidCoin() == eTestResult::Passed ? "Passed" : "Failed") << std::endl;
	std::cout << std::endl;
}

void RunTestDispense()
{
	TestDispense tests;
	std::cout << "Test Dispense" << std::endl
		<< (tests.TestDispenseChipsWithCorrectChange() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestDispenseColaWithCorrectChange() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestDispenseCandyWithCorrectChange() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestDispenseShowInsertCoinAfterThankYou() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestShowPriceWhenNoMoneyInserted() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestShowInsertCoinAfterShowPriceWhenNoMoneyInserted() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestShowPriceWhenInsufficientMoneyInserted() == eTestResult::Passed ? "Passed" : "Failed") << std::endl
		<< (tests.TestShowTotalInsertedAfterPriceWithInsufficientFunds() == eTestResult::Passed ? "Passed" : "Failed") << std::endl;
	std::cout << std::endl;
}

void RunTestReturnCoins()
{
	TestReturnCoins tests;
	std::cout << "Test Return Coins" << std::endl
		<< (tests.TestReturn3Coins() == eTestResult::Passed ? "Passed" : "Failed") << std::endl;
	std::cout << std::endl;
}

int main(int argc, const char* argv[])
{
	RunTestDisplay();
	RunTestCoin();
	RunTestDispense();
	RunTestReturnCoins();

	std::cin.get();

	return 0;
}
