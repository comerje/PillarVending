
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