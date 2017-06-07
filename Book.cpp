/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Simple Classes Assignment
 * Class         : CS 301
 ************************************************************************/

#include "Book.h"

//Book::Book()
//{
//	firstName = "";
//	lastName  = "";
//	title     = "";
//	checkOut.setDate(0,0,0);
//	due.setDate(0,0,0);
//}


Book::Book (string inFirstName,
		    string inLastName,
		    string inTitle,
		    Date inCheckOut,
		    Date inDue)
{
	firstName = inFirstName;
	lastName  = inLastName;
	title     = inTitle;
	checkOut  = inCheckOut;
	due       = inDue;
}

Book::~Book()
{

}

Book & Book::setCheckOutDate (Date inCheckOut)
{
	 checkOut = inCheckOut;

	 return (*this);
}

Book & Book::setDueDate      (Date inDueDate)
{
	due = inDueDate;

	return (*this);
}


Book & Book::setDueDatePlus     (int daysTillDue)
{
	due += daysTillDue;

	return (*this);
}


Book & Book::setFirstName    (string inFirstName)
{
	 firstName = inFirstName;

	 return (*this);
}

Book & Book::setLastName     (string inLastName)
{
	lastName = inLastName;

	return (*this);
}

Book & Book::setTitle        (string inTitle)
{
	title = inTitle;

	return (*this);
}

string Book::getFirstName()
{
	return firstName;
}

string Book::getLastName()
{
	return lastName;
}

string Book::getTitle()
{
	return title;
}

Date Book::getCheckOutDate()
{
	return checkOut;
}

Date Book::getDueDate()
{
	return due;
}



void Book::PrintBook()
{
	cout << left;
	cout << setw(27) << firstName + ", " + lastName;
	cout << setw(30) << title;
	cout << checkOut;
	cout << "     ";
	cout << due;
	cout << right;

}

int Book::getCMonth ( ) const
{
	return checkOut.getMonth();
}
int Book::getCDay ( ) const
{
	return checkOut.getDay();
}
int Book::getCYear ( ) const
{
	return checkOut.getYear();
}
int Book::getDMonth ( ) const
{
	return due.getMonth();
}
int Book::getDDay ( ) const
{
	return due.getDay();
}
int Book::getDYear ( ) const
{
	return due.getYear();
}




