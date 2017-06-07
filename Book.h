/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Simple Classes Assignment
 * Class         : CS 301
 ************************************************************************/

#ifndef BOOK_H_
#define BOOK_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>
#include "Date.h"

using namespace std;

const Date DEFAULT_DATE;

class Book
{
public:
	Book(string = "", string = "", string = "" , Date = DEFAULT_DATE, Date = DEFAULT_DATE);

//	Book (string inFirstName,
//		  string inLastName,
//		  string inTitle,
//		  Date 	 inCheckOut,
//		  Date 	 inDue); // Put in default values
	~Book();
	Book & 	setFirstName    (string inFirstName);
	Book & 	setLastName     (string inLastName);
	Book & 	setTitle        (string inTitle);
	Book & 	setCheckOutDate (Date inCheckOut);
	Book & 	setDueDate      (Date inDueDate);
	Book &  setDueDatePlus  (int daysTillDue);
	string 	getFirstName();
	string 	getLastName();
	string 	getTitle();
	Date 	getCheckOutDate();
	Date 	getDueDate();
	void PrintBook();
	int getCMonth ( ) const;
	int getCDay   ( ) const;
	int getCYear  ( ) const;
	int getDMonth ( ) const;
	int getDDay   ( ) const;
	int getDYear  ( ) const;

private:
	string firstName;
	string lastName;
	string title;
	Date   checkOut;
	Date   due;

};

#endif /* BOOK_H_ */
