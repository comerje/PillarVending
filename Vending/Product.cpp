
#include "Product.h"

Product::Product(eProducts product, int price, int quantity)
:m_id(product),
 m_price(price),
 m_quantity(quantity)
{
}

Product::Product(const Product& product)
:m_id(product.m_id),
 m_price(product.m_price),
 m_quantity(product.m_quantity)
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

Product& Product::operator=(const Product& rhs)
{
	if(this == &rhs)
		return *this;

	// code goes here

	return *this;
}

