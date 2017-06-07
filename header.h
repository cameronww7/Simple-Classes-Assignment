/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Simple Classes Assignment
 * Class         : CS 301
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

#include "Book.h"
#include "Date.h"

using namespace std;

const int ARRAY_SIZE = 10;

Book CheckOutBook(Date currentDate);

void CheckinBook(Book arrayBooks[ARRAY_SIZE],
			     int  currentSize,
			     Date currentDate);

void PrintAllCheckedOut(Book arrayBooks[ARRAY_SIZE]);

char menuPrompt(const string MENU_PROMPT);

int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int    IN_MIN,			// IN & OUT		- minimum option
		 	 	const int    IN_MAX);			// IN & OUT		- maximum option

void PrintToFile(Book arrayBooks[ARRAY_SIZE],
				 int  currentSize);
void ReadFromFile(Book arrayBooks[ARRAY_SIZE],
				 int  &currentSize);


#endif /* HEADER_H_ */
