#pragma once

#include <stdio.h>
#include "mysql.h"
#include <string>
#include <iostream>
#include "book.h"
using namespace std;



void mysql_connect();
void mysql_create_books();
int mysql_insert_books(Book book);
void mysql_query_books();
void mysql_query_books(int id);