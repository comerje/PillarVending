
#include <string>
#include "TestDisplay.h"
#include "VendingMachine.h"

eTestResult TestDisplay::TestDisplayInsertCoinWhenTotalIs0()
{
	VendingMachine vm;
	
	std::string result = vm.Display();
	
	return (result == "INSERT COIN" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDisplay::TestDisplayWhenTotalIs5Cents()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Nickel);

	std::string result = vm.Display();
	
	return (result == "$0.05" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDisplay::TestDisplayWhenTotalIs10Cents()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Dime);

	std::string result = vm.Display();
	
	return (result == "$0.10" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDisplay::TestDisplayWhenTotalIs15Cents()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Nickel);
	vm.InsertCoin(eCoin::Dime);

	std::string result = vm.Display();
	return (result == "$0.15" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDisplay::TestDisplayWhenTotalIs25Cents()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);

	std::string result = vm.Display();

	return (result == "$0.25" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDisplay::TestDisplaySoldOutWhenNoInventory()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Cola);
	vm.Display();
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Cola);

	std::string result = vm.Display();

	return (result == "SOLD OUT" ? eTestResult::Passed : eTestResult::Failed);
}

eTestResult TestDisplay::TestDisplayAmountInsertedAfterSoldOut()
{
	VendingMachine vm;
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Cola);
	vm.Display();
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.InsertCoin(eCoin::Quarter);
	vm.Dispense(eProducts::Cola);
	vm.Display();

	std::string result = vm.Display();

	return (result == "$1.00" ? eTestResult::Passed : eTestResult::Failed);
}
