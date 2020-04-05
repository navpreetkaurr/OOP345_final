// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 April, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include "Workstation.h"
#include "Utilities.h"
#include <vector>

using namespace std;
class LineManager {
	std::vector<Workstation*> m_AssemblyLine;
	std::vector<Workstation*> m_AssemblyLineSorted;
	std::deque<CustomerOrder> m_ToBeFilled;
	std::deque<CustomerOrder> m_Completed;
	size_t m_cntCustomerOrder;
	static size_t count;
public:
	LineManager();
	LineManager(const string& str, vector<Workstation*>& station, vector<CustomerOrder>& order);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};



#endif