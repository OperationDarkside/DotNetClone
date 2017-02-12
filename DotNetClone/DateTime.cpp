#include "DateTime.h"


DateTime::DateTime()
{
}
DateTime::DateTime(long long ms)
{
	microseconds dur(ms);
	time_point<system_clock> dt(dur);
	this->tp = dt;
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day)
{
	tm temp = { 0 };
	temp.tm_year = year - 1900;
	temp.tm_mon = month - 1;
	temp.tm_mday = day;
	temp.tm_isdst = -1;

	time_t tt = mktime(&temp);

	time_point<system_clock> timep = system_clock::from_time_t(tt);

	this->tp = timep;
}


DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second)
{
	tm* temp = new tm();
	temp->tm_year = year - 1900;
	temp->tm_mon = month;
	temp->tm_mday = day;
	temp->tm_hour = hour;
	temp->tm_min = minute;
	temp->tm_sec = second;

	time_t tt = mktime(temp);

	this->tp = system_clock::from_time_t(tt);

	delete temp;
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond)
{
	tm* temp = new tm();
	temp->tm_year = year - 1900;
	temp->tm_mon = month;
	temp->tm_mday = day;
	temp->tm_hour = hour;
	temp->tm_min = minute;
	temp->tm_sec = second;

	time_t tt = mktime(temp);

	this->tp = system_clock::from_time_t(tt);

	this->tp += milliseconds(millisecond);

	delete temp;
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond, unsigned int microsecond)
{
	tm* temp = new tm();
	temp->tm_year = year - 1900;
	temp->tm_mon = month;
	temp->tm_mday = day;
	temp->tm_hour = hour;
	temp->tm_min = minute;
	temp->tm_sec = second;

	time_t tt = mktime(temp);

	this->tp = system_clock::from_time_t(tt);

	this->tp += milliseconds(millisecond);
	this->tp += microseconds(microsecond);

	delete temp;
}

DateTime::~DateTime()
{
}

DateTime DateTime::add(TimeSpan * span)
{
	this->tp += microseconds(span->totalMicroseconds());

	return *this;
}

DateTime DateTime::addDays(double days)
{
	this->tp += microseconds((long long)(days * 24 * 3600 * 1000000));

	return *this;
}

DateTime DateTime::addHours(double hours)
{
	this->tp += microseconds((long long)(hours * 3600 * 1000000));

	return *this;
}

DateTime DateTime::addMicroseconds(long long ms)
{
	this->tp += microseconds(ms);

	return *this;
}

DateTime DateTime::addMilliseconds(double milliseconds)
{
	this->tp += microseconds((long long)(milliseconds * 1000));

	return *this;
}

DateTime DateTime::addMinutes(double minutes)
{
	this->tp += microseconds((long long)(minutes * 60 * 1000000));

	return *this;
}

DateTime DateTime::addMonths(double months)
{
	this->tp += microseconds((long long)(months * 31 * 24 * 3600 * 1000000));

	return *this;
}

DateTime DateTime::addSeconds(double seconds)
{
	this->tp += microseconds((long long)(seconds * 1000000));

	return *this;
}

DateTime DateTime::addTicks(long long ms)
{
	this->tp += microseconds(ms);

	return *this;
}

DateTime DateTime::addYears(long years)
{
	this->tp += microseconds((long long)(years * 365 * 24 * 3600 * 1000000));

	return *this;
}

int DateTime::compareTo(DateTime * value)
{
	if (this->tp > value->tp) {
		return 1;
	}
	else if (this->tp == value->tp) {
		return 0;
	}
	else {
		return -1;
	}
}

TimeSpan DateTime::substract(DateTime * value)
{
	TimeSpan* res;

	res = new TimeSpan(duration_cast<microseconds>(this->tp - value->tp).count());

	return *res;
}

DateTime DateTime::substract(TimeSpan * value)
{
	DateTime * res;

	microseconds dur(value->totalMicroseconds());

	time_point<system_clock> tmp = this->tp - dur;

	res = new DateTime(tmp.time_since_epoch().count());

	return *res;
}

String DateTime::toLongDateString()
{
	String* res = new String();
	char buf_day[3];
	char buf_year[5];

	time_t tt = system_clock::to_time_t(this->tp);
	tm tm = *localtime(&tt);
	itoa(tm.tm_mday, buf_day, 10);
	itoa(tm.tm_year + 1900, buf_year, 10);

	*res += *this->getWeekdayName(tm.tm_wday);
	*res += " ";
	*res += buf_day;
	*res += ". ";
	*res += *this->getMonthName(tm.tm_mon);
	*res += " ";
	*res += buf_year;

	return res;
}

String DateTime::toLongTimeString()
{
	String* res = new String();
	char buf_hour[3];
	char buf_min[3];
	char buf_sec[3];

	time_t tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm tm = *localtime(&tt);
	itoa(tm.tm_hour, buf_hour, 10);
	itoa(tm.tm_min, buf_min, 10);
	itoa(tm.tm_sec, buf_sec, 10);

	*res += buf_hour;
	*res += ":";
	*res += buf_min;
	*res += ":";
	*res += buf_sec;

	return res;
}

String DateTime::toUtcString()
{
	String* res = new String();
	char buf_day[2];
	char buf_mon[2];
	char buf_year[4];
	char buf_hour[2];
	char buf_min[2];
	char buf_sec[2];

	time_t tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm tm = *localtime(&tt);
	itoa(tm.tm_mday, buf_day, 10);
	itoa(tm.tm_mon, buf_mon, 10);
	itoa(tm.tm_year, buf_year, 10);
	itoa(tm.tm_hour, buf_hour, 10);
	itoa(tm.tm_min, buf_min, 10);
	itoa(tm.tm_sec, buf_sec, 10);

	*res += buf_year;
	*res += "-";
	*res += buf_mon;
	*res += "-";
	*res += buf_day;
	*res += "T";
	*res += buf_hour;
	*res += ":";
	*res += buf_min;
	*res += ":";
	*res += buf_sec;


	return res;
}

std::string DateTime::toString()
{
	return toUtcString().getStringValue();
}

string DateTime::getTypeString()
{
	return string("DateTime");
}

DateTime DateTime::Date()
{
	time_t tt;
	tm tm;
	DateTime* res;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	res = new DateTime(tm.tm_year, tm.tm_mon, tm.tm_mday);

	return *res;
}

void DateTime::Date(DateTime & date)
{
	system_clock::time_point tmp = this->tp;
	system_clock::time_point tmp_new = date.tp;

	years y = duration_cast<years>(tmp.time_since_epoch());
	tmp -= y;
	months m = duration_cast<months>(tmp.time_since_epoch());
	tmp -= m;
	days d = duration_cast<days>(tmp.time_since_epoch());
	tmp -= d;

	years y_new = duration_cast<years>(tmp_new.time_since_epoch());
	tmp_new -= y_new;
	months m_new = duration_cast<months>(tmp_new.time_since_epoch());
	tmp_new -= m_new;
	days d_new = duration_cast<days>(tmp_new.time_since_epoch());

	tmp += y_new;
	tmp += m_new;
	tmp += d_new;

	this->tp = tmp;
}

unsigned short DateTime::Day()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_mday;
}

void DateTime::Day(unsigned short day)
{
	system_clock::time_point tmp = this->tp;

	days d = duration_cast<days>(tmp.time_since_epoch());
	tmp -= d;

	days d_new(day);

	tmp += d_new;

	this->tp = tmp;
}

unsigned short DateTime::DayOfWeek()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_wday;
}

void DateTime::DayOfWeek(unsigned short dow)
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	tm.tm_wday = dow;

	// still work to do, to keep microseconds

	this->tp = system_clock::from_time_t( mktime(&tm));
}

unsigned short DateTime::DayOfYear()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_yday;
}

void DateTime::DayOfYear(unsigned short doy)
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	tm.tm_yday = doy;

	// still work to do, to keep microseconds

	this->tp = system_clock::from_time_t(mktime(&tm));
}

unsigned short DateTime::Hour()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_mday;
}

void DateTime::Hour(unsigned short _hours)
{
	system_clock::time_point tmp = this->tp;

	hours h = duration_cast<hours>(tmp.time_since_epoch());
	tmp -= h;

	hours h_new(_hours);

	tmp += h_new;

	this->tp = tmp;
}

long long DateTime::Millisecond()
{
	time_point<system_clock, milliseconds> tmp = time_point_cast<milliseconds>(this->tp);
	return tmp.time_since_epoch().count();
}

void DateTime::Millisecond(long long ms)
{
	system_clock::time_point tmp = this->tp;

	milliseconds ms_old = duration_cast<milliseconds>(tmp.time_since_epoch());
	tmp -= ms_old;

	milliseconds ms_new(ms);

	tmp += ms_new;

	this->tp = tmp;
}

unsigned short DateTime::Minute()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_min;
}

void DateTime::Minute(unsigned short min)
{
	system_clock::time_point tmp = this->tp;

	minutes min_old = duration_cast<minutes>(tmp.time_since_epoch());
	tmp -= min_old;

	minutes min_new(min);

	tmp += min_new;

	this->tp = tmp;
}

unsigned short DateTime::Month()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_mon;
}

void DateTime::Month(unsigned short mon)
{
	setTime<months>(mon);
}

unsigned short DateTime::Second()
{
	std::time_t tt;
	std::tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_sec;
}

void DateTime::Second(unsigned short sec)
{
	setTime<seconds>(sec);
}

long long DateTime::Ticks()
{
	return nanoseconds(this->tp.time_since_epoch()).count();
}

void DateTime::Ticks(long long micsec)
{
	setTime<microseconds>(micsec);
}

unsigned short DateTime::Year()
{
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(this->tp);
	tm = *localtime(&tt);

	return tm.tm_year + 1900;
}

void DateTime::Year(unsigned short year)
{
	setTime<years>(year);
}

template<typename T>
void DateTime::setTime(long long nr) {
	system_clock::time_point tmp = this->tp;
	
	T nr_old = duration_cast<T>(tmp.time_since_epoch());
	tmp -= nr_old;

	T nr_new(nr - 1970);
	// still work to do, to keep correct date
	tmp += nr_new;

	this->tp = tmp;
}

String * DateTime::getWeekdayName(short wd_nr)
{
	char* wd;

	switch (wd_nr)
	{
	case 0:
		wd = "Sunday";
		break;
	case 1:
		wd = "Monday";
		break;
	case 2:
		wd = "Tuesday";
		break;
	case 3:
		wd = "Wednesday";
		break;
	case 4:
		wd = "Thursday";
		break;
	case 5:
		wd = "Friday";
		break;
	case 6:
		wd = "Saturday";
		break;
	}

	return new String(wd);
}

String * DateTime::getMonthName(short mon_nr)
{
	char* mon;

	switch (mon_nr)
	{
	case 0:
		mon = "January";
		break;
	case 1:
		mon = "February";
		break;
	case 2:
		mon = "March";
		break;
	case 3:
		mon = "April";
		break;
	case 4:
		mon = "May";
		break;
	case 5:
		mon = "June";
		break;
	case 6:
		mon = "July";
		break;
	case 7:
		mon = "August";
		break;
	case 8:
		mon = "September";
		break;
	case 9:
		mon = "October";
		break;
	case 10:
		mon = "November";
		break;
	case 11:
		mon = "December";
		break;
	}

	return new String(mon);
}
