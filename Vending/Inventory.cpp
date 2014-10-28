#include "Inventory.h"


Inventory::Inventory()
{
	m_inventory.insert(std::map<eProducts, Product>::value_type(eProducts::Candy, Product(eProducts::Candy, 65, 1)));
	m_inventory.insert(std::map<eProducts, Product>::value_type(eProducts::Chips, Product(eProducts::Chips, 50, 1)));
	m_inventory.insert(std::map<eProducts, Product>::value_type(eProducts::Cola, Product(eProducts::Cola, 100, 1)));
}


Inventory::~Inventory()
{
}

int Inventory::GetPrice(eProducts product) const
{
	return m_inventory.find(product)->second.Price();
}

Product& Inventory::GetProduct(eProducts product)
{
	return m_inventory.find(product)->second;
}

Inventory::Inventory(const Inventory& inventory)
{
}

Inventory& Inventory::operator=(const Inventory& rhs)
{
	if(this == &rhs)
		return *this;

	// code goes here

	return *this;
}

