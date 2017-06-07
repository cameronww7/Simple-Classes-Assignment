/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Simple Classes Assignment
 * Class         : CS 301
 ************************************************************************/


#ifndef DATE_H_
#define DATE_H_

using namespace std;

class Date
{
   friend ostream &operator<<( ostream &, const Date & );

public:
   	   Date(int m = 1, int d = 1, int y = 1900); // constructor, note the
   	   	   	   	   	   	   	   	   	   	   	   	 //    default values
	   void    setDate( int, int, int );		// set the date
	   void    PrintDate(ostream &output);
	   bool    leapYear() const;    		// is this a leap year?
	   bool    endOfMonth() const; 		// is this end of month?
		int    getMonth() const;
		int    getDay() const;
		int    getYear() const;
	 string    getMonthString() const;

	   bool operator== (Date other) const;
	   bool operator<(Date other) const;
 const Date &operator+=(int); 			// add days, modify object

private:
   int month;
   int day;
   int year;

   static const int days[];         // array of days per month
   static const string monthName[]; // array of month names
   void helpIncrement();            // utility function
};



#endif /* DATE_H_ */
