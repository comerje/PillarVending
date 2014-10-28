
#include <iostream>
#include "TestDisplay.h"
#include "TestCoin.h"

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

int main(int argc, const char* argv[])
{
	RunTestDisplay();
	RunTestCoin();

	std::cin.get();

	return 0;
}
