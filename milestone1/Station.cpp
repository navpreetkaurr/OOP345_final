// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 19 March, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include"Station.h"
#include"Utilities.h"
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
int Station::id_generator = 0;
size_t Station::m_widthField = 0u;
Station::Station()
{
	m_description = "";
	m_description = "";
	m_name = "";
	m_quantity = 0u;
	m_serialNumber = 0u;
}
Station::Station(std::string str)
{
	id_generator++;
	m_id = id_generator;
	Utilities utils;
	try {
		size_t next_pos = 0;
		bool check = true;
		m_name = utils.extractToken(str, next_pos, check);
		m_serialNumber = std::stoi(utils.extractToken(str, next_pos, check));
		m_quantity = std::stoi(utils.extractToken(str, next_pos, check));
		if (m_widthField < utils.getFieldWidth()) {
			m_widthField = utils.getFieldWidth();
		}
		m_description = utils.extractToken(str, next_pos, check);
	}
	catch (char* msg) {
		std::cout << msg;
		exit(1);
	}
}
const std::string& Station::getItemName() const
{
	return m_name;
}
unsigned int Station::getNextSerialNumber()
{
	return m_serialNumber++;
}
unsigned int Station::getQuantity() const
{
	return m_quantity;
}
void Station::updateQuantity()
{
	if (m_quantity > 0) {
		m_quantity--;
	}
	else if (m_quantity == 0) {
		m_quantity = 0;
	}
}
void Station::display(std::ostream& os, bool full) const
{
	os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "] Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << getItemName();
	os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ');

	//if a full display is wanted then add Quantity and description to ostream 
	full ? os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity <<
		" Description: " << m_description << std::endl : os << std::endl << std::setfill('0');

}
