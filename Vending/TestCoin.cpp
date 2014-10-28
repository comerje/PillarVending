
#include "TestCoin.h"
#include "VendingMachine.h"

eTestResult TestCoin::TestInsertValidCoin()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Nickel);

	std::string result = vm.Display();
	
	return (result == "$0.05" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestCoin::TestInsertInvalidCoin()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Penny);

	bool result = vm.CoinReturn.empty();
	return (!result ? eTestResult::Passed : eTestResult::Failed);
}

