/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Simple Classes Assignment
 * Class         : CS 301
 ************************************************************************/

#include "header.h"


/************************************************************************
 *
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int main()
{
	Book arrayBooks[ARRAY_SIZE];
	int currentSize = 0;

	Date currentDate;

	char option;

	cout << " Enter the Date : \n";
	currentDate.setDate(NumberError(" Month : " ,1 ,12),
					    NumberError(" Day   : " ,1 ,32),
					    NumberError(" Year  : " ,0 ,2014));

	ReadFromFile(arrayBooks,
				 currentSize);

	option = menuPrompt("\n Please enter your one letter choice as follows:"
						"\n\t C:  Check out a book"
						"\n\t D:  Check in a book"
						"\n\t T:  Print all books currently checked out"
						"\n\t Q:  Quit this program"
						"\n   Enter Choice : ");

	while(option != 'Q')
	{


		switch(option)
		{
			case 'C' : arrayBooks[currentSize] = CheckOutBook(currentDate);
					   currentSize = currentSize + 1;
					break;
			case 'D' :	if(currentSize != 0)
						{
							CheckinBook(arrayBooks,
									currentSize,
									currentDate);
							currentSize = currentSize - 1;
						}
						else
						{
							cout << "\n\tBooks Are Empty\n";
						}

					break;
			case 'T' :	if(currentSize != 0)
						{
							PrintAllCheckedOut(arrayBooks);
						}
						else
						{
							cout << "\n\t There are no books checked out.\n";
						}

					break;
		}

		option = menuPrompt("\n Please enter your one letter choice as follows:"
								"\n\t C:  Check out a book"
								"\n\t D:  Check in a book"
								"\n\t T:  Print all books currently checked out"
								"\n\t Q:  Quit this program"
								"\n   Enter Choice : ");
	}

	PrintToFile(arrayBooks,
					 currentSize);

	cout << "\n\nThank You, And Have  Wonderful Day\n\n";
	return 0;
}

Book CheckOutBook(Date currentDate)
{
	const int DAYS_TILL_DUE = 14;

	string info;
	Book tempBook;

	string firstName	= "";
	string lastName		= "";
	string title		= "";
	string temp 		= "";
	int    counter 		= 0;
	int    index 		= 0;
	int    nameSize;


	cout << "\n Please enter one line consisting the first and last names of the"
			"\n author followed by the title of the book.\n";

	//Promtps for Name
	getline(cin, info);

	//Gets Size of String
	nameSize = info.length();

	//Begins Word Wraping (finding First,last then Title in the string)
	while(nameSize != counter)
	{
		temp = temp + info[counter];

		if(info[counter] == ' ')
		{

			switch(index)
			{
			case 0 : tempBook.setFirstName(temp);
				break;
			case 1 : tempBook.setLastName(temp);
				break;
			case 2 : tempBook.setTitle(tempBook.getTitle() + temp);
				break;
			}
			if(index < 2)
			{
				index++;
			}
			temp = "";
		}
			counter++;

	}
	tempBook.setTitle(tempBook.getTitle() + temp);
	tempBook.setCheckOutDate(currentDate);
	tempBook.setDueDatePlus(DAYS_TILL_DUE);

	return tempBook;
}

void CheckinBook(Book arrayBooks[ARRAY_SIZE],
			     int  currentSize,
			     Date currentDate)
{
	Book tempBook;
	bool found;
	int  index;

	found = false;
	index = 0;

	tempBook = CheckOutBook(currentDate);

	while(!found && index < ARRAY_SIZE)
	{
		if(tempBook.getFirstName() == arrayBooks[index].getFirstName() &&
		   tempBook.getLastName()  == arrayBooks[index].getLastName()  &&
		   tempBook.getTitle()     == arrayBooks[index].getTitle()        )
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	if(currentDate < tempBook.getDueDate())
	{
		cout << "\n\t This book is overDue.\n";
	}

	arrayBooks[index].setFirstName   (arrayBooks[currentSize].getFirstName()    );
	arrayBooks[index].setLastName    (arrayBooks[currentSize].getLastName()     );
	arrayBooks[index].setTitle       (arrayBooks[currentSize].getTitle()        );
	arrayBooks[index].setCheckOutDate(arrayBooks[currentSize].getCheckOutDate() );
	arrayBooks[index].setDueDate     (arrayBooks[currentSize].getDueDate()      );

}

void PrintAllCheckedOut(Book arrayBooks[ARRAY_SIZE])
{

	cout << left;
	cout << setw(27) << "Author"
		 << setw(30) << "Title"
		 << setw(20) << "Check in Date"
		 << setw(12) << "Due Date";
	cout << right;

	for(int index = 0; index < ARRAY_SIZE; index++)
	{
		if(arrayBooks[index].getFirstName().length() != 0)
		{
			cout << endl;
			arrayBooks[index].PrintBook();
		}
	}
	cout << endl << endl;
}


char menuPrompt(const string MENU_PROMPT)
{

	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	char option;					// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_PROMPT;
		cin.get(option);
		option = toupper(option);

		if (option == 'C' || option == 'D' || option == 'T' || option == 'Q')
		{
			someBool = true;
		}
		else
		{
			cout << "\n * Error *  Please Enter one choice Of C,D,T,Q \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(!someBool);

	return option;

}


/************************************************************************
 *  int NumberError
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX)			// IN & OUT		- maximum option
{
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	int option;						// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a vaild number, if invaild it will
		 *	clear the input then reoutput the menu until and do the
		 *	check's until the user puts in a vaild entry.
		 *****************************************************************/
		if(!(cin >> option))
		{
			cout << "\n**** Please input a NUMBER between " << IN_MIN
				 << " and " << IN_MAX << " ****";
			cin.clear();

			someBool  = true;
			cout << endl << endl;
		}
		else if (option > IN_MAX || option < IN_MIN)
		{
			cout << endl;
			cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			cout << "**** Please input a number between "
				 << IN_MIN << " and " << IN_MAX << " ****\n";
			cout << endl;
			someBool = true;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(someBool);

	return option;
}

void PrintToFile(Book arrayBooks[ARRAY_SIZE],
				 int  currentSize)
{
    ofstream oFile;
    oFile.open ("CheckedOutBooks.txt");

    oFile << currentSize << endl;

    for(int index = 0; index < currentSize; index++)
    {
    	oFile << arrayBooks[index].getFirstName() << endl;
		oFile << arrayBooks[index].getLastName()  << endl;
		oFile << arrayBooks[index].getTitle()     << endl;
		//Out files the check out date in 1 19 1990 order
		oFile << arrayBooks[index].getCMonth() << " " <<
				 arrayBooks[index].getCDay()   << " " <<
				 arrayBooks[index].getCYear()  << endl;
		//Out files the due date in 1 19 1990 order
		oFile << arrayBooks[index].getDMonth() << " " <<
				 arrayBooks[index].getDDay()   << " " <<
				 arrayBooks[index].getDYear()  << endl;
    }

    oFile.close();
}

void ReadFromFile(Book arrayBooks[ARRAY_SIZE],
				 int  &currentSize)
{
	string firstNameT;
	string lastNameT;
	string titleT;
	Date   checkOutDateT;
	Date   dueDateT;
	int    tempMon;
	int    tempDay;
	int    tempYr;

    fstream oFile;
    oFile.open("CheckedOutBooks.txt");

    oFile >> currentSize;

    for(int index = 0; index < currentSize; index++)
    {
    	getline(oFile, firstNameT);
		arrayBooks[index].setFirstName(firstNameT);
		getline(oFile, lastNameT);
		arrayBooks[index].setLastName(lastNameT);
		// Reads in the entire Title
		getline(oFile, titleT);
		arrayBooks[index].setTitle(titleT);

		// Temp hold for dates
		oFile >> tempMon;
		oFile >> tempDay;
		oFile >> tempYr;

		// Fill temp Date
		checkOutDateT.setDate(tempMon, tempDay, tempYr);

		//Populates CheckoutDate in Array
		arrayBooks[index].setCheckOutDate(checkOutDateT);

		// Temp hold for dates
		oFile >> tempMon;
		oFile >> tempDay;
		oFile >> tempYr;

		// Fill temp Date
		dueDateT.setDate(tempMon, tempDay, tempYr);

		//Populates CheckoutDate in Array
		arrayBooks[index].setDueDate(dueDateT);

    }
    oFile.close();
}

