#include <iostream>
#include "Date.h"

using namespace std;

// Constructor functions
Date::Date()
{
    day = 1;
    month = 1;
    year = 1900;
}

Date::Date(int dd,int mm,int yy)
{
    day = dd;
    month = mm;
    year = yy;
}


// Accessor functions
int Date::get_day()
{
    return day;
}

int Date::get_month()
{
    return month;
}

int Date::get_year()
{
    return year;
}

// Other functions
void Date::print()
{
    cout << day << '/'
    << month << '/'
    << year;
}

void Date::next_day()
{
    int days_in_month;
    day++;
    switch (month)
    {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12: days_in_month = 31;
                 break;
        case 4 :
        case 6 :
        case 9 :
        case 11: days_in_month = 30;
                 break;
        case 2 : if (leap_year())
                    days_in_month = 29;
                 else days_in_month = 28;
                 break;
    }
    if (day > days_in_month)
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

Date Date::week_later(Date date)
// This function returns the date a week
// later than date.
{
    Date temp;
    int days_in_month;
    int day,month,year;
    day = date.get_day();
    month = date.get_month();
    year = date.get_year();
    day += 7;
    switch (month)
    {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12: days_in_month = 31;
                 break;
        case 4 :
        case 6 :
        case 9 :
        case 11: days_in_month = 30;
                 break;
        case 2 : if (leap_year())
                     days_in_month = 29;
                 else days_in_month = 28;
                 break;
    }
    if (day > days_in_month)
    {
        day = day-days_in_month;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    temp = Date(day,month,year);
    return temp;
}



int Date::days_between(Date date)
{
	const int daysInYear [] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	const int daysInLeapYear[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	const int daysInMonth [] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int daysInMonthLeap [] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month = this->get_month();
    int month2 = date.get_month();
    int day = this->get_day();
    int day2 = date.get_day();
    int year = this->get_year();
    int year2 = date.get_year();
    int jdate,jdate2,diff;

	jdate = (this->get_year() - 1900) * 365 + daysInYear[this->get_month()] + this->get_day();
	jdate2 = (date.get_year() - 1900) * 365 + daysInYear[date.get_month()] + date.get_day();

  	diff = abs( jdate - jdate2);
    return diff;
}

int Date::days_since_newyear()
{
    Date d1{1,1,year};
    return this->days_between(d1);
}

// Private function
int Date::leap_year()
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else return 0;
}
