#pragma once
#include "TimeSpan.h"
#include "String.h"
#include <ctime>
#include <chrono>



using namespace std;
using namespace std::chrono;
/**
Represents a point in time in microseconds since epoche
*/
class DateTime : public Object
{
public:
	/**
	Creates an empty DateTime instance with the standart time point
	*/
	DateTime();
	/**
	Creates an empty DateTime instance with the given microseconds

	@param microseconds Number of microseconds since epoche
	*/
	DateTime(long long microseconds);
	/**
	Creates an empty DateTime instance with the given date

	@param year Number of years since 0 AD
	@param month Number of months
	@param day Number of days
	*/
	DateTime(unsigned int year, unsigned int month, unsigned int day);
	/**
	Creates an empty DateTime instance with the given date and time

	@param year Number of years since 0 AD
	@param month Number of months
	@param day Number of days
	@param hour Number of hours
	@param minute Number of minutes
	@param second Number of seconds
	*/
	DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second);
	/**
	Creates an empty DateTime instance with the given date and time

	@param year Number of years since 0 AD
	@param month Number of months
	@param day Number of days
	@param hour Number of hours
	@param minute Number of minutes
	@param second Number of seconds
	@param millisecond Number of milliseconds
	*/
	DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond);
	/**
	Creates an empty DateTime instance with the given date and time

	@param year Number of years since 0 AD
	@param month Number of months
	@param day Number of days
	@param hour Number of hours
	@param minute Number of minutes
	@param second Number of seconds
	@param millisecond Number of milliseconds
	@param microsecond Number of microseconds
	*/
	DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond, unsigned int microsecond);
	~DateTime();

	/**
	Adds the given TimeSpan to this instance's timepoint

	@param span TimeSpan to be added
	@return This instance with the added TimeSpan
	*/
	DateTime add(TimeSpan* span);
	/**
	Adds the given days to this instance's timepoint

	@param days Number of days to be added
	@return This instance with the added days
	*/
	DateTime addDays(long long days);
	/**
	Adds the given hours to this instance's timepoint

	@param hours Number of hours to be added
	@return This instance with the added hours
	*/
	DateTime addHours(long long hours);
	/**
	Adds the given microsedonds to this instance's timepoint

	@param microseconds Number of microseconds to be added
	@return This instance with the added microseconds
	*/
	DateTime addMicroseconds(long long microseconds);
	/**
	Adds the given milliseconds to this instance's timepoint

	@param milliseconds Number of milliseconds to be added
	@return This instance with the added milliseconds
	*/
	DateTime addMilliseconds(long long milliseconds);
	/**
	Adds the given minutes to this instance's timepoint

	@param minutes Number of minutes to be added
	@return This instance with the added minutes
	*/
	DateTime addMinutes(long long minutes);
	/**
	Adds the given months to this instance's timepoint

	@param months Number of months to be added
	@return This instance with the added months
	*/
	DateTime addMonths(long long months);
	/**
	Adds the given seconds to this instance's timepoint

	@param seconds Number of seconds to be added
	@return This instance with the added seconds
	*/
	DateTime addSeconds(long long seconds);
	/**
	Adds the given ticks to this instance's timepoint (might change)

	@param microseconds Number of microseconds to be added
	@return This instance with the added microseconds
	*/
	DateTime addTicks(long long microseconds);
	/**
	Adds the given years to this instance's timepoint

	@param years Number of years to be added
	@return This instance with the added years
	*/
	DateTime addYears(long years);
	/**
	Compares the given DateTime instance with this instance

	@param value DateTime instance to be compared to
	@return Number > 0, 0 or < 0
	*/
	int compareTo(DateTime* value);
	/**
	Returns the TimeSpan between this instance and the given Datetime instance

	@param value DateTime instance to be subtracted
	@return TimeSpan between the two DateTime instances
	*/
	TimeSpan substract(DateTime* value);
	/**
	Returns the DateTime that results in the subtraction between this instance and the given Timespan instance 

	@param value TimeSpan to subtract
	@return DateTime instance after the TimeSpan was subtracted
	*/
	DateTime substract(TimeSpan* value);
	/**
	Returns this DateTime instance's date component as a String with the Format "Weekday day. Monthname year"

	@return String containing the time
	*/
	String toLongDateString();
	/**
	Returns this DateTime instance's time component as a String with the Format "hours:minutes:seconds"

	@return String containing the time
	*/
	String toLongTimeString();
	/**
	Returns this DateTime instance's date and time component as a String with the Format "year-month-dayThours:minutes:seconds"

	@return String containing both date and time
	*/
	String toUtcString();
	/**
	Returns this instance value as UTC formated string

	@return String containing both date and time
	*/
	string toString();
	string getTypeString();

	/**
	Returns the current date component of this instance

	@return DateTime current date without time
	*/
	DateTime Date();
	/**
	Sets the date component of this instance

	@param date DateTime instance with the date to set
	*/
	void Date(DateTime& date);
	/**
	Returns the current day of month of this instance

	@return Day component
	*/
	unsigned short Day();
	/**
	Sets the day component of this instance

	@param day Day component to set
	*/
	void Day(unsigned short day);
	/**
	Returns the current day of week [0 - 6] of this instance

	@return Day of week component
	*/
	unsigned short DayOfWeek();
	/**
	Sets the day of week component of this instance

	@param dow Day of week component to set
	*/
	void DayOfWeek(unsigned short dow);
	/**
	Returns the current day of year since 1.1. [0 - 365] of this instance

	@return Day of year component
	*/
	unsigned short DayOfYear();
	/**
	Sets the day of year component of this instance

	@param doy Day of year component to set
	*/
	void DayOfYear(unsigned short doy);
	/**
	Returns the current hours of this instance

	@return Hour component
	*/
	unsigned short Hour();
	/**
	Sets the hour component of this instance

	@param hours Hour component to set
	*/
	void Hour(unsigned short hours);
	/**
	Returns the current milliseconds of this instance

	@return Milliseconds component
	*/
	unsigned int Millisecond();
	/**
	Sets the millisecond component of this instance

	@param ms Millisecond component to set
	*/
	void Millisecond(unsigned int ms);
	/**
	Returns the current minutes of this instance

	@return Minutes component
	*/
	unsigned short Minute();
	/**
	Sets the minute component of this instance

	@param min Minute component to set
	*/
	void Minute(unsigned short min);
	/**
	Returns the current month of this instance

	@return Month component
	*/
	unsigned short Month();
	/**
	Sets the month component of this instance

	@param mon Month component to set
	*/
	void Month(unsigned short mon);
	/**
	Returns the current seconds of this instance

	@return Second component
	*/
	unsigned short Second();
	/**
	Sets the second component of this instance

	@param sec Second component to set
	*/
	void Second(unsigned short sec);
	/**
	Returns this instance in ticks (microseconds)

	@return Microseconds component
	*/
	long long Ticks();
	/**
	Sets the ticks (in microseconds) of this instance

	@param microseconds Microsecond component to set
	*/
	void Ticks(long long microseconds);
	/**
	Returns the current year of this instance

	@return Year component
	*/
	unsigned short Year();
	/**
	Sets the year component of this instance

	@param year Year component to set
	*/
	void Year(unsigned short year);
private:
	time_point<system_clock> tp;

	
	String getWeekdayName(short wd_nr);
	String getMonthName(short mon_nr);
	template<typename T>
	void setTime(long long nr);
	
	typedef duration<int, ratio_multiply<hours::period, ratio<24> >::type> days;
	typedef duration<int, ratio_multiply<hours::period, ratio<24 * 30> >::type> months;
	typedef duration<int, ratio_multiply<hours::period, ratio<24 * 365> >::type> years;
	//typedef tuple<years, months, days> ymd;

	tuple<years, months, days> from_days(days ds);
};
