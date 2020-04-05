// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 April, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include<iostream>
#include "CustomerOrder.h"
using namespace std;

class Workstation : public Station {
	deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;
public:
	Workstation();
	Workstation(const string& str);
	Workstation(Workstation&) = delete;
	Workstation& operator=(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator=(Workstation&&) = delete;
	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os = cout);
	Workstation& operator+=(CustomerOrder&& order);
};



#endif