// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 19 March, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include<string>
class Utilities {
	size_t m_widthField;
	static char m_delimiter;
public:
	Utilities();
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string&, size_t&, bool&);
	static void setDelimiter(char);
	static char getDelimiter();
};
#endif