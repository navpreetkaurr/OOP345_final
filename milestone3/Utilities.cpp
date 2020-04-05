// Name: Navpreet Kaur
// Seneca Student ID: 148332182
// Seneca email: nk79
// Date of completion: 4 April, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include<string>
#include<iostream>
using namespace std;
Utilities::Utilities(){
	m_widthField = 0u;
}
void Utilities::setFieldWidth(size_t newWidth){
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const{
	return m_widthField;
}

string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
	size_t pos = str.find(m_delimiter, next_pos);
	if (pos == next_pos) {
		more = false;
		throw "there are two delimiters with no token";
	}
	else {
		more = (pos != string::npos) ? true : false;
		string tokenExtracted = str.substr(next_pos, pos - next_pos);
		next_pos = pos + 1;
		if (tokenExtracted.size() > m_widthField)
			m_widthField = tokenExtracted.length();
		return tokenExtracted;
	}
}

void Utilities::setDelimiter(char newDelimiter){
	m_delimiter = newDelimiter;
}

char Utilities::m_delimiter = ' ';
char Utilities::getDelimiter(){
	return m_delimiter;
}

