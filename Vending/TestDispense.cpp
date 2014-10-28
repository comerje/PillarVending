
#include "TestDispense.h"
#include "VendingMachine.h"
#include "Coin.h"
#include "Products.h"

eTestResult TestDispense::TestDispenseChipsWithCorrectChange()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Chips);

	std::string result = vm.Display();

	return ("THANK YOU" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestDispenseColaWithCorrectChange()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Cola);

	std::string result = vm.Display();

	return ("THANK YOU" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestDispenseCandyWithCorrectChange()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Dime);
	vm.InsertCoin(eCoin::Nickel);
	vm.Dispense(eProducts::Candy);

	std::string result = vm.Display();

	return ("THANK YOU" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestDispenseShowInsertCoinAfterThankYou()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Chips);
	vm.Display();

	std::string result = vm.Display();

	return ("INSERT COIN" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestShowPriceWhenNoMoneyInserted()
{
	VendingMachine vm;
	vm.Dispense(eProducts::Chips);

	std::string result = vm.Display();

	return ("PRICE $0.50" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestShowInsertCoinAfterShowPriceWhenNoMoneyInserted()
{
	VendingMachine vm;
	vm.Dispense(eProducts::Chips);
	vm.Display();

	std::string result = vm.Display();

	return ("INSERT COIN" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestShowPriceWhenInsufficientMoneyInserted()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Chips);

	std::string result = vm.Display();

	return ("PRICE $0.50" == result ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDispense::TestShowTotalInsertedAfterPriceWithInsufficientFunds()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Chips);
	vm.Display();

	std::string result = vm.Display();

	return ("$0.25" == result ? eTestResult::Passed : eTestResult::Failed);
}
