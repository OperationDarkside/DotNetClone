#include "TimeSpan.h"

namespace dnc{

	TimeSpan::TimeSpan(){}

	TimeSpan::TimeSpan(long long _microseconds){
		this->dur = std::chrono::microseconds(_microseconds);
	}

	TimeSpan::TimeSpan(unsigned int _hours, unsigned int _minutes, unsigned int _seconds){
		this->dur += std::chrono::hours(_hours);
		this->dur += std::chrono::minutes(_minutes);
		this->dur += std::chrono::seconds(_seconds);
	}

	TimeSpan::TimeSpan(unsigned int _days, unsigned int _hours, unsigned int _minutes, unsigned int _seconds){
		this->dur += std::chrono::hours(_days * 24);
		this->dur += std::chrono::hours(_hours);
		this->dur += std::chrono::minutes(_minutes);
		this->dur += std::chrono::seconds(_seconds);
	}

	TimeSpan::TimeSpan(unsigned int _days, unsigned int _hours, unsigned int _minutes, unsigned int _seconds, unsigned int _milliseconds){
		this->dur += std::chrono::hours(_days * 24);
		this->dur += std::chrono::hours(_hours);
		this->dur += std::chrono::minutes(_minutes);
		this->dur += std::chrono::seconds(_seconds);
		this->dur += std::chrono::milliseconds(_milliseconds);
	}


	TimeSpan::~TimeSpan(){}

	TimeSpan * TimeSpan::add(TimeSpan * span){
		TimeSpan* res;
		std::chrono::system_clock::duration dur;
		std::chrono::microseconds ms;

		dur = this->dur + span->dur;
		ms = std::chrono::duration_cast<std::chrono::microseconds>(dur);

		res = new TimeSpan(ms.count());

		return res;
	}

	int TimeSpan::compareTo(TimeSpan * span){
		if(this->dur < span->dur){
			return -1;
		} else if(this->dur == span->dur){
			return 0;
		} else{
			return 1;
		}
	}

	TimeSpan * TimeSpan::negate(){
		TimeSpan* tmp;
		std::chrono::microseconds ms;

		ms = std::chrono::duration_cast<std::chrono::microseconds>(this->dur * -1);

		tmp = new TimeSpan(ms.count());

		return tmp;
	}

	TimeSpan * TimeSpan::subtract(TimeSpan * span){
		TimeSpan* res;
		std::chrono::system_clock::duration dur;
		std::chrono::microseconds ms;

		dur = this->dur - span->dur;
		ms = std::chrono::duration_cast<std::chrono::microseconds>(dur);

		res = new TimeSpan(ms.count());

		return res;
	}

	std::string TimeSpan::toString(){
		std::chrono::system_clock::duration tmp;
		std::string* res;

		tmp = this->dur;

		days d = std::chrono::duration_cast<days>(tmp);
		tmp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tmp);
		tmp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tmp);
		tmp -= m;
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(tmp);
		tmp -= s;
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(tmp);

		res = new std::string();
		*res += std::to_string(d.count());
		*res += " days, ";
		*res += std::to_string(h.count());
		*res += ":";
		*res += std::to_string(m.count());
		*res += ":";
		*res += std::to_string(s.count());
		*res += ":";
		*res += std::to_string(ms.count());

		return *res;
	}

	std::string TimeSpan::getTypeString(){
		return std::string("TimeSpan");
	}

	long long TimeSpan::totalMicroseconds(){
		std::chrono::microseconds microsec = std::chrono::duration_cast<std::chrono::microseconds> (this->dur);

		return microsec.count();
	}

	long TimeSpan::Days(){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);

		return d.count();
	}

	void TimeSpan::Days(long _days){
		days d_new(_days);
		days d_orig = std::chrono::duration_cast<days>(this->dur);

		this->dur -= d_orig;
		this->dur += d_new;
	}

	long TimeSpan::Hours(){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);

		return h.count();
	}

	void TimeSpan::Hours(long _hours){
		std::chrono::hours h_new(_hours);
		std::chrono::hours h_orig = std::chrono::duration_cast<std::chrono::hours>(this->dur);

		this->dur -= h_orig;
		this->dur += h_new;
	}

	long TimeSpan::Minutes(){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tp);

		return m.count();
	}

	void TimeSpan::Minutes(long min){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tp);
		tp -= m;

		std::chrono::minutes m_new(min);
		tp += m_new;
		tp += h;
		tp += d;

		this->dur = tp;
	}

	long TimeSpan::Seconds(){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tp);
		tp -= m;
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(tp);

		return s.count();
	}

	void TimeSpan::Seconds(long sec){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tp);
		tp -= m;
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(tp);
		tp -= s;

		std::chrono::seconds s_new(sec);
		tp += s_new;
		tp += m;
		tp += h;
		tp += d;

		this->dur = tp;
	}

	long TimeSpan::Milliseconds(){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tp);
		tp -= m;
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(tp);
		tp -= s;
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp);

		return ms.count();
	}

	void TimeSpan::Milliseconds(long ms){
		std::chrono::system_clock::duration tp = this->dur;
		days d = std::chrono::duration_cast<days>(tp);
		tp -= d;
		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tp);
		tp -= h;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(tp);
		tp -= m;
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(tp);
		tp -= s;
		std::chrono::milliseconds ms_old = std::chrono::duration_cast<std::chrono::milliseconds>(tp);
		tp -= ms_old;

		std::chrono::milliseconds ms_new(ms);
		tp += ms_new;
		tp += s;
		tp += m;
		tp += h;
		tp += d;

		this->dur = tp;
	}

	long long TimeSpan::Ticks(){
		return std::chrono::duration_cast<std::chrono::microseconds>(this->dur).count();
	}

	void TimeSpan::Ticks(long long ticks){
		this->dur = std::chrono::microseconds(ticks);
	}
}