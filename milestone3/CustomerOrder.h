// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 April, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include"Station.h"
#include<string>
struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(const std::string);
	CustomerOrder(CustomerOrder& copy);
	CustomerOrder(CustomerOrder&& move) noexcept;
	CustomerOrder& operator=(CustomerOrder&& mv);
	~CustomerOrder();
	bool isItemFilled(std::string) const;
	bool isOrderFilled() const;
	void fillItem(Station& station, std::ostream&);
	void display(std::ostream&) const;
};

#endif