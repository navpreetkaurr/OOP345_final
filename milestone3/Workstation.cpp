// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 April, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"
#include<iostream>
using namespace std;

Workstation::Workstation() :m_pNextStation{ nullptr } {}

Workstation::Workstation(const string& str) : Station(str) {
	m_pNextStation = nullptr;
}

void Workstation::runProcess(ostream& os) {
	if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder() {
	bool yes = false;
	if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) && m_pNextStation) {
		yes = true;
		*m_pNextStation += move(m_orders.front());
		m_orders.pop_front();
	}
	return yes;

}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = (Workstation*)& station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool yes = false;
	if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
		yes = true;
		order = move(m_orders.front());
		m_orders.pop_front();
	}
	return yes;
}

void Workstation::display(ostream& os) {
	if (getNextStation()) os << getItemName() << " --> " << getNextStation()->getItemName() << endl;
	else os << getItemName() << " --> " << "END OF LINE" << endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& order) {
	m_orders.push_back(move(order));
	return *this;
}