
#ifndef INVENTORY_H__
#define INVENTORY_H__

#include "Products.h"
#include "Product.h"
#include <map>

class Inventory
{
public:
	Inventory();
	~Inventory();

	int GetPrice(eProducts product) const;
	Product& GetProduct(eProducts product);

private:
	Inventory(const Inventory& inventory);
	Inventory& operator=(const Inventory& rhs);

	std::map<eProducts, Product> m_inventory;
};

#endif
