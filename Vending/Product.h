
#ifndef PRODUCT_H__
#define PRODUCT_H__

#include "Products.h"

class Product
{
public:
	Product(eProducts product, int price, int quantity);
	Product(const Product& product); // used when populating a std::map
	~Product();
	eProducts Id() const;
	int Price() const;
	int Quantity() const;
	void Remove(int quantity);
	bool OutOfStock() const;
	
private:
	Product& operator=(const Product& rhs);

	eProducts m_id;
	int m_price;
	int m_quantity;
};

#endif
