#include "TimeSpan.h"



TimeSpan::TimeSpan()
{
}

TimeSpan::TimeSpan(long long _microseconds)
{
	this->dur = microseconds(_microseconds);
}

TimeSpan::TimeSpan(unsigned int _hours, unsigned int _minutes, unsigned int _seconds)
{
	this->dur += hours(_hours);
	this->dur += minutes(_minutes);
	this->dur += seconds(_seconds);
}

TimeSpan::TimeSpan(unsigned int _days, unsigned int _hours, unsigned int _minutes, unsigned int _seconds)
{
	this->dur += hours(_days * 24);
	this->dur += hours(_hours);
	this->dur += minutes(_minutes);
	this->dur += seconds(_seconds);
}

TimeSpan::TimeSpan(unsigned int _days, unsigned int _hours, unsigned int _minutes, unsigned int _seconds, unsigned int _milliseconds)
{
	this->dur += hours(_days * 24);
	this->dur += hours(_hours);
	this->dur += minutes(_minutes);
	this->dur += seconds(_seconds);
	this->dur += milliseconds(_milliseconds);
}


TimeSpan::~TimeSpan()
{
}

TimeSpan * TimeSpan::add(TimeSpan * span)
{
	TimeSpan* res;
	system_clock::duration dur;
	microseconds ms;

	dur = this->dur + span->dur;
	ms = duration_cast<microseconds>(dur);

	res = new TimeSpan(ms.count());

	return res;
}

int TimeSpan::compareTo(TimeSpan * span)
{
	if (this->dur < span->dur) {
		return -1;
	}
	else if (this->dur == span->dur) {
		return 0;
	}
	else {
		return 1;
	}
}

TimeSpan * TimeSpan::negate()
{
	TimeSpan* tmp;
	microseconds ms;

	ms = duration_cast<microseconds>(this->dur * -1);

	tmp = new TimeSpan(ms.count());

	return tmp;
}

TimeSpan * TimeSpan::subtract(TimeSpan * span)
{
	TimeSpan* res;
	system_clock::duration dur;
	microseconds ms;

	dur = this->dur - span->dur;
	ms = duration_cast<microseconds>(dur);

	res = new TimeSpan(ms.count());

	return res;
}

std::string TimeSpan::toString()
{
	system_clock::duration tmp;
	string* res;

	tmp = this->dur;

	days d = duration_cast<days>(tmp);
	tmp -= d;
	hours h = duration_cast<hours>(tmp);
	tmp -= h;
	minutes m = duration_cast<minutes>(tmp);
	tmp -= m;
	seconds s = duration_cast<seconds>(tmp);
	tmp -= s;
	milliseconds ms = duration_cast<milliseconds>(tmp);

	res = new string();
	*res += to_string(d.count());
	*res += " days, ";
	*res += to_string(h.count());
	*res += ":";
	*res += to_string(m.count());
	*res += ":";
	*res += to_string(s.count());
	*res += ":";
	*res += to_string(ms.count());

	return *res;
}

string TimeSpan::getTypeString()
{
	return string("TimeSpan");
}

long long TimeSpan::totalMicroseconds()
{
	microseconds microsec = duration_cast<microseconds> (this->dur);

	return microsec.count();
}

long TimeSpan::Days()
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);

	return d.count();
}

void TimeSpan::Days(long _days)
{
	days d_new(_days);
	days d_orig = duration_cast<days>(this->dur);

	this->dur -= d_orig;
	this->dur += d_new;
}

long TimeSpan::Hours()
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);

	return h.count();
}

void TimeSpan::Hours(long _hours)
{
	hours h_new(_hours);
	hours h_orig = duration_cast<hours>(this->dur);

	this->dur -= h_orig;
	this->dur += h_new;
}

long TimeSpan::Minutes()
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);
	tp -= h;
	minutes m = duration_cast<minutes>(tp);

	return m.count();
}

void TimeSpan::Minutes(long min)
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);
	tp -= h;
	minutes m = duration_cast<minutes>(tp);
	tp -= m;

	minutes m_new(min);
	tp += m_new;
	tp += h;
	tp += d;

	this->dur = tp;
}

long TimeSpan::Seconds()
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);
	tp -= h;
	minutes m = duration_cast<minutes>(tp);
	tp -= m;
	seconds s = duration_cast<seconds>(tp);

	return s.count();
}

void TimeSpan::Seconds(long sec)
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);
	tp -= h;
	minutes m = duration_cast<minutes>(tp);
	tp -= m;
	seconds s = duration_cast<seconds>(tp);
	tp -= s;

	seconds s_new(sec);
	tp += s_new;
	tp += m;
	tp += h;
	tp += d;

	this->dur = tp;
}

long TimeSpan::Milliseconds()
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);
	tp -= h;
	minutes m = duration_cast<minutes>(tp);
	tp -= m;
	seconds s = duration_cast<seconds>(tp);
	tp -= s;
	milliseconds ms = duration_cast<milliseconds>(tp);

	return ms.count();
}

void TimeSpan::Milliseconds(long ms)
{
	system_clock::duration tp = this->dur;
	days d = duration_cast<days>(tp);
	tp -= d;
	hours h = duration_cast<hours>(tp);
	tp -= h;
	minutes m = duration_cast<minutes>(tp);
	tp -= m;
	seconds s = duration_cast<seconds>(tp);
	tp -= s;
	milliseconds ms_old = duration_cast<milliseconds>(tp);
	tp -= ms_old;

	milliseconds ms_new(ms);
	tp += ms_new;
	tp += s;
	tp += m;
	tp += h;
	tp += d;

	this->dur = tp;
}

long long TimeSpan::Ticks()
{
	return duration_cast<microseconds>(this->dur).count();
}

void TimeSpan::Ticks(long long ticks)
{
	this->dur = microseconds(ticks);
}
