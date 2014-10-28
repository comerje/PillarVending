
#include "Product.h"

Product::Product(eProducts product, int price, int quantity)
:m_id(product),
 m_price(price),
 m_quantity(quantity)
{
}

Product::~Product()
{
}

eProducts Product::Id() const
{
	return m_id;
}

int Product::Price() const
{
	return m_price;
}

int Product::Quantity() const
{
	return m_quantity;
}

void Product::Remove(int quantity)
{
	m_quantity -= quantity;
}

bool Product::OutOfStock() const
{
	return (m_quantity == 0);
}
