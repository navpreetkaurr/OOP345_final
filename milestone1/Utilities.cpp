// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 19 March, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
#include<string>
#include<iostream>
Utilities::Utilities()
{
	m_widthField = 0u;
}
void Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string token;
	int index;
	more = false;
	index = str.find(m_delimiter, next_pos + 1);
	if (next_pos == 0) {
		token = str.substr(next_pos, index - next_pos);
	}
	else {
		if (next_pos < str.length()) {
			token = str.substr(next_pos + 1, index - next_pos - 1);
		}
	}
	next_pos = index;
	if (!token.empty()) {
		more = true;
		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}
	}
	else {
		throw "No data between delimiters";
	}
	return token;
}
void Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}
char Utilities::m_delimiter = ' ';
char Utilities::getDelimiter()
{
	return m_delimiter;
}

