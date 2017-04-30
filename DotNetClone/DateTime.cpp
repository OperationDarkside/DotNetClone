#include "DateTime.h"
#include "Convert.h"


DateTime::DateTime(){}
DateTime::DateTime(long long ms){
	microseconds dur(ms);
	time_point<system_clock> dt(dur);
	this->tp = dt;
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day){
	this->tp += years(year);
	this->tp += months(month);
	this->tp += days(day);
}


DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second){
	this->tp += years(year);
	this->tp += months(month);
	this->tp += days(day);
	this->tp += hours(hour);
	this->tp += minutes(minute);
	this->tp += seconds(second);
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond){
	this->tp += years(year);
	this->tp += months(month);
	this->tp += days(day);
	this->tp += hours(hour);
	this->tp += minutes(minute);
	this->tp += seconds(second);
	this->tp += milliseconds(millisecond);
}

DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond, unsigned int microsecond){
	this->tp += years(year);
	this->tp += months(month);
	this->tp += days(day);
	this->tp += hours(hour);
	this->tp += minutes(minute);
	this->tp += seconds(second);
	this->tp += milliseconds(millisecond);
	this->tp += microseconds(microsecond);
}

DateTime::~DateTime(){}

DateTime DateTime::add(TimeSpan * span){
	this->tp += microseconds(span->totalMicroseconds());

	return *this;
}

DateTime DateTime::addDays(long long value){
	this->tp += days(value);

	return *this;
}

DateTime DateTime::addHours(long long value){
	this->tp += hours(value);

	return *this;
}

DateTime DateTime::addMicroseconds(long long ms){
	this->tp += microseconds(ms);

	return *this;
}

DateTime DateTime::addMilliseconds(long long value){
	this->tp += milliseconds(value);

	return *this;
}

DateTime DateTime::addMinutes(long long value){
	this->tp += minutes(value);

	return *this;
}

DateTime DateTime::addMonths(long long value){
	this->tp += months(value);

	return *this;
}

DateTime DateTime::addSeconds(long long value){
	this->tp += seconds(value);

	return *this;
}

DateTime DateTime::addTicks(long long ms){
	this->tp += microseconds(ms);

	return *this;
}

DateTime DateTime::addYears(long value){
	this->tp += years(value);

	return *this;
}

int DateTime::compareTo(DateTime * value){
	if(this->tp > value->tp){
		return 1;
	} else if(this->tp == value->tp){
		return 0;
	} else{
		return -1;
	}
}

TimeSpan DateTime::substract(DateTime * value){
	TimeSpan* res;

	res = new TimeSpan(duration_cast<microseconds>(this->tp - value->tp).count());

	return *res;
}

DateTime DateTime::substract(TimeSpan * value){
	DateTime * res;

	microseconds dur(value->totalMicroseconds());

	time_point<system_clock> tmp = this->tp - dur;

	res = new DateTime(tmp.time_since_epoch().count());

	return *res;
}

String DateTime::toLongDateString(){
	time_t tt;
	tm* tm;
	years ys;
	months mons;
	days ds;
	milliseconds ms;
	time_point<system_clock> tp_temp;
	time_point<system_clock> tp_wd;
	String res;

	tp_temp = this->tp;
	ms = duration_cast<milliseconds>(tp_temp.time_since_epoch());

	ys = duration_cast<years>(ms);
	ms -= ys;
	mons = duration_cast<months>(ms);
	ms -= mons;
	ds = duration_cast<days>(ms);

	if(ys > years(1900)){
		tp_wd = tp_temp - years(1900);
	} else{
		tp_wd = tp_temp;
	}

	tt = system_clock::to_time_t(tp_wd);
	tm = localtime(&tt);

	res += this->getWeekdayName(tm->tm_wday);
	res += ", ";
	res += this->getMonthName(mons.count());
	res += " ";
	res += Convert::toString(ds.count()).padLeft(2, '0');
	res += ", ";
	res += Convert::toString(ys.count()).padLeft(4, '0');

	return res;
}

String DateTime::toLongTimeString(){
	years ys;
	months mons;
	days ds;
	hours hs;
	minutes mins;
	seconds ss;
	milliseconds ms;
	time_point<system_clock> tp_temp;
	String res;

	tp_temp = this->tp;
	ms = duration_cast<milliseconds>(tp_temp.time_since_epoch());

	ys = duration_cast<years>(ms);
	ms -= ys;
	mons = duration_cast<months>(ms);
	ms -= mons;
	ds = duration_cast<days>(ms);
	ms -= ds;
	hs = duration_cast<hours>(ms);
	ms -= hs;
	mins = duration_cast<minutes>(ms);
	ms -= mins;
	ss = duration_cast<seconds>(ms);
	ms -= ss;

	res += Convert::toString(hs.count()).padLeft(2, '0');
	res += ":";
	res += Convert::toString(mins.count()).padLeft(2, '0');
	res += ":";
	res += Convert::toString(ss.count()).padLeft(2, '0');
	res += ":";
	res += Convert::toString(ms.count()).padLeft(3, '0');

	return res;
}

String DateTime::toUtcString(){
	years ys;
	months mons;
	days ds;
	hours hs;
	minutes mins;
	seconds ss;
	milliseconds ms;
	time_point<system_clock> tp_temp;
	String res;

	tp_temp = this->tp;
	ms = duration_cast<milliseconds>(tp_temp.time_since_epoch());

	ys = duration_cast<years>(ms);
	ms -= ys;
	mons = duration_cast<months>(ms);
	ms -= mons;
	ds = duration_cast<days>(ms);
	ms -= ds;
	hs = duration_cast<hours>(ms);
	ms -= hs;
	mins = duration_cast<minutes>(ms);
	ms -= mins;
	ss = duration_cast<seconds>(ms);
	ms -= ss;

	res += Convert::toString(ys.count()).padLeft(4, '0');
	res += "-";
	res += Convert::toString(mons.count()).padLeft(2, '0');
	res += "-";
	res += Convert::toString(ds.count()).padLeft(2, '0');
	res += "T";
	res += Convert::toString(hs.count()).padLeft(2, '0');
	res += ":";
	res += Convert::toString(mins.count()).padLeft(2, '0');
	res += ":";
	res += Convert::toString(ss.count()).padLeft(2, '0');
	res += ":";
	res += Convert::toString(ms.count()).padLeft(3, '0');


	return res;
}

std::string DateTime::toString(){
	return toUtcString().getStringValue();
}

string DateTime::getTypeString(){
	return string("DateTime");
}

DateTime DateTime::Date(){
	years ys;
	months mons;
	days ds;
	time_point<system_clock> tp_temp;
	DateTime res;

	tp_temp = this->tp;
	ds = duration_cast<days>(tp_temp.time_since_epoch());

	ys = duration_cast<years>(ds);
	ds -= ys;
	mons = duration_cast<months>(ds);
	ds -= mons;

	res = DateTime(ys.count(), mons.count(), ds.count());

	return res;
}

void DateTime::Date(DateTime & date){
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

unsigned short DateTime::Day(){
	unsigned short res = 0;
	years ys;
	months mons;
	days ds;
	seconds ss;

	ss = duration_cast<seconds>(this->tp.time_since_epoch());

	ys = duration_cast<years>(ss);
	ss -= ys;
	mons = duration_cast<months>(ss);
	ss -= mons;
	ds = duration_cast<days>(ss);

	res = ds.count();

	return res;
}

void DateTime::Day(unsigned short day){
	system_clock::time_point tmp = this->tp;

	days d = duration_cast<days>(tmp.time_since_epoch());
	tmp -= d;

	days d_new(day);

	tmp += d_new;

	this->tp = tmp;
}

unsigned short DateTime::DayOfWeek(){
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_wday;
}

void DateTime::DayOfWeek(unsigned short dow){
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	tm.tm_wday = dow;

	// still work to do, to keep microseconds

	this->tp = system_clock::from_time_t(mktime(&tm));
}

unsigned short DateTime::DayOfYear(){
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	return tm.tm_yday;
}

void DateTime::DayOfYear(unsigned short doy){
	time_t tt;
	tm tm;

	tt = system_clock::to_time_t(time_point_cast<microseconds>(this->tp));
	tm = *localtime(&tt);

	tm.tm_yday = doy;

	// still work to do, to keep microseconds

	this->tp = system_clock::from_time_t(mktime(&tm));
}

unsigned short DateTime::Hour(){
	unsigned short res = 0;
	years ys;
	months mons;
	days ds;
	hours hs;
	seconds ss;

	ss = duration_cast<seconds>(this->tp.time_since_epoch());

	ys = duration_cast<years>(ss);
	ss -= ys;
	mons = duration_cast<months>(ss);
	ss -= mons;
	ds = duration_cast<days>(ss);
	ss -= ds;
	hs = duration_cast<hours>(ss);

	res = hs.count();

	return res;
}

void DateTime::Hour(unsigned short _hours){
	system_clock::time_point tmp = this->tp;

	hours h = duration_cast<hours>(tmp.time_since_epoch());
	tmp -= h;

	hours h_new(_hours);

	tmp += h_new;

	this->tp = tmp;
}

unsigned int DateTime::Millisecond(){
	unsigned int res = 0;
	years ys;
	months mons;
	days ds;
	hours hs;
	minutes mins;
	seconds ss;
	milliseconds ms;

	ms = duration_cast<milliseconds>(this->tp.time_since_epoch());

	ys = duration_cast<years>(ms);
	ms -= ys;
	mons = duration_cast<months>(ms);
	ms -= mons;
	ds = duration_cast<days>(ms);
	ms -= ds;
	hs = duration_cast<hours>(ms);
	ms -= hs;
	mins = duration_cast<minutes>(ms);
	ms -= mins;
	ss = duration_cast<seconds>(ms);
	ms -= ss;

	res = ms.count();

	return res;
}

void DateTime::Millisecond(unsigned int ms){
	system_clock::time_point tmp = this->tp;

	milliseconds ms_old = duration_cast<milliseconds>(tmp.time_since_epoch());
	tmp -= ms_old;

	milliseconds ms_new(ms);

	tmp += ms_new;

	this->tp = tmp;
}

unsigned short DateTime::Minute(){
	unsigned short res = 0;
	years ys;
	months mons;
	days ds;
	hours hs;
	minutes mins;
	seconds ss;

	ss = duration_cast<seconds>(this->tp.time_since_epoch());

	ys = duration_cast<years>(ss);
	ss -= ys;
	mons = duration_cast<months>(ss);
	ss -= mons;
	ds = duration_cast<days>(ss);
	ss -= ds;
	hs = duration_cast<hours>(ss);
	ss -= hs;
	mins = duration_cast<minutes>(ss);

	res = mins.count();

	return res;
}

void DateTime::Minute(unsigned short min){
	system_clock::time_point tmp = this->tp;

	minutes min_old = duration_cast<minutes>(tmp.time_since_epoch());
	tmp -= min_old;

	minutes min_new(min);

	tmp += min_new;

	this->tp = tmp;
}

unsigned short DateTime::Month(){
	unsigned short res = 0;
	years ys;
	months mons;
	seconds ss;

	ss = duration_cast<seconds>(this->tp.time_since_epoch());

	ys = duration_cast<years>(ss);
	ss -= ys;
	mons = duration_cast<months>(ss);

	res = mons.count();

	return res;
}

void DateTime::Month(unsigned short mon){
	setTime<months>(mon);
}

unsigned short DateTime::Second(){
	unsigned short res = 0;
	years ys;
	months mons;
	days ds;
	hours hs;
	minutes mins;
	seconds ss;

	ss = duration_cast<seconds>(this->tp.time_since_epoch());

	ys = duration_cast<years>(ss);
	ss -= ys;
	mons = duration_cast<months>(ss);
	ss -= mons;
	ds = duration_cast<days>(ss);
	ss -= ds;
	hs = duration_cast<hours>(ss);
	ss -= hs;
	mins = duration_cast<minutes>(ss);
	ss -= mins;

	res = ss.count();

	return res;
}

void DateTime::Second(unsigned short sec){
	setTime<seconds>(sec);
}

long long DateTime::Ticks(){
	return nanoseconds(this->tp.time_since_epoch()).count();
}

void DateTime::Ticks(long long micsec){
	setTime<microseconds>(micsec);
}

unsigned short DateTime::Year(){
	unsigned short res = 0;

	res = duration_cast<years>(this->tp.time_since_epoch()).count();

	return res;
}

void DateTime::Year(unsigned short year){
	setTime<years>(year);
}

template<typename T>
void DateTime::setTime(long long nr){
	system_clock::time_point tmp = this->tp;

	T nr_old = duration_cast<T>(tmp.time_since_epoch());
	tmp -= nr_old;

	T nr_new(nr - 1970);
	// still work to do, to keep correct date
	tmp += nr_new;

	this->tp = tmp;
}

String DateTime::getWeekdayName(short wd_nr){
	char* wd;

	switch(wd_nr){
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

	return String(wd);
}

String DateTime::getMonthName(short mon_nr){
	char* mon;

	switch(mon_nr){
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

	return String(mon);
}
