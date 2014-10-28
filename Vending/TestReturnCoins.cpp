
#include "TestReturnCoins.h"
#include "VendingMachine.h"
#include "Coin.h"
#include "Products.h"

eTestResult TestReturnCoins::TestReturn3Coins()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Nickel);
	vm.Dispense(eProducts::Candy);
	
	int result = vm.CoinReturn.size();

	return (3 == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestReturnCoins::TestInsert6QuartersAndReturnThem()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.ReturnCoins();

	int result = vm.CoinReturn.size();

	return (6 == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestReturnCoins::TestDisplayInsertCoinsAfterReturning()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.ReturnCoins();
	vm.CoinReturn.size();

	std::string result = vm.Display();

	return ("INSERT COIN" == result ? eTestResult::Passed : eTestResult::Failed);
}