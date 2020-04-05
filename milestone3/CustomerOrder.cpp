// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 April, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include"Utilities.h"
#include<vector>
#include<iostream>
#include<iomanip>
size_t CustomerOrder::m_widthField = 0u;
size_t temp = 0u;
CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(const std::string str)
{
	Utilities utils;
	size_t next_pos = 0;
	bool check = false;
	std::vector<Item*> tmpVec;
	m_name = utils.extractToken(str, next_pos, check);
	m_product = utils.extractToken(str, next_pos, check);
	while (check) {
		tmpVec.push_back(new Item(utils.extractToken(str, next_pos, check)));
	}
	if (temp < utils.getFieldWidth()) {
		temp = utils.getFieldWidth();
	}
	m_cntItem = static_cast<unsigned int>(tmpVec.size());
	m_lstItem = new Item * [m_cntItem];
	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = std::move(tmpVec[i]);
	}

}
CustomerOrder::CustomerOrder(CustomerOrder& copy)
{
	throw "ERROR: Cannot make copies.";
}
CustomerOrder::CustomerOrder(CustomerOrder&& move) noexcept {
	*this = std::move(move);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& mv)
{
	if (this != &mv) {
		m_name = mv.m_name;
		m_product = mv.m_product;
		m_cntItem = mv.m_cntItem;
		m_lstItem = mv.m_lstItem;
		m_widthField = mv.m_widthField;

		mv.m_name = "";
		mv.m_product = "";
		mv.m_cntItem = 0;
		mv.m_lstItem = nullptr;
		mv.m_widthField = 0;
	}
	return *this;
	// TODO: insert return statement here
}
CustomerOrder::~CustomerOrder() {
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isItemFilled(std::string str) const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
	}
	return true;
}

bool CustomerOrder::isOrderFilled() const
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false)
			return false;
	}
	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() != 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;

				os << (m_lstItem[i]->m_isFilled ? "    Filled" : "Unfilled") << " "
					<< m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else if (station.getQuantity() == 0) {
				os << " Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}
}
void CustomerOrder::display(std::ostream& os) const {
	m_widthField = temp;
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
		os << std::setfill('0') << "[" << std::right << std::setw(6) << this->m_lstItem[i]->m_serialNumber << "] ";
		os << std::setfill(' ') << std::left << std::setw(this->m_widthField);
		os << this->m_lstItem[i]->m_itemName << " - ";

		this->m_lstItem[i]->m_isFilled ? os << "FILLED" : os << "MISSING";

		os << std::endl;
	}
}
