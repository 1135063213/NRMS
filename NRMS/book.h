#pragma once
#include <string>
using namespace std;

class Book
{
public:
	int m_id;
	string m_book_name;
	string m_authorID;
	double m_price;
	string m_publishDate;
};

int addBook();
void queryBook();
void queryAllBook();