#include "DateTime.h"
#include "Convert.h"
#include "date.h"

/*
Many thanks to Howard Hinnant, who published his great algorithm to get the days since epoche and back.
Link to the paper: http://howardhinnant.github.io/date_algorithms.html
Link to github: https://github.com/HowardHinnant/date
*/

namespace dnc{

	DateTime::DateTime(){}
	DateTime::DateTime(long long ms){
		std::chrono::microseconds dur(ms);
		std::chrono::time_point<std::chrono::system_clock> dt(dur);
		this->tp = dt;
	}

	DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day){
		year -= month <= 2;
		const int era_t = (year >= 0 ? year : year - 399) / 400;
		const unsigned yoe_t = static_cast<unsigned>(year - era_t * 400);      // [0, 399]
		const unsigned doy_t = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;  // [0, 365]
		const unsigned doe_t = yoe_t * 365 + yoe_t / 4 - yoe_t / 100 + doy_t;         // [0, 146096]
		int days_since_epoch = era_t * 146097 + static_cast<int>(doe_t) - 719468;

		this->tp += days(days_since_epoch);
	}


	DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second){
		year -= month <= 2;
		const int era_t = (year >= 0 ? year : year - 399) / 400;
		const unsigned yoe_t = static_cast<unsigned>(year - era_t * 400);      // [0, 399]
		const unsigned doy_t = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;  // [0, 365]
		const unsigned doe_t = yoe_t * 365 + yoe_t / 4 - yoe_t / 100 + doy_t;         // [0, 146096]
		int days_since_epoch = era_t * 146097 + static_cast<int>(doe_t) - 719468;

		this->tp += days(days_since_epoch);
		this->tp += std::chrono::hours(hour);
		this->tp += std::chrono::minutes(minute);
		this->tp += std::chrono::seconds(second);
	}

	DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond){
		year -= month <= 2;
		const int era_t = (year >= 0 ? year : year - 399) / 400;
		const unsigned yoe_t = static_cast<unsigned>(year - era_t * 400);      // [0, 399]
		const unsigned doy_t = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;  // [0, 365]
		const unsigned doe_t = yoe_t * 365 + yoe_t / 4 - yoe_t / 100 + doy_t;         // [0, 146096]
		int days_since_epoch = era_t * 146097 + static_cast<int>(doe_t) - 719468;

		this->tp += days(days_since_epoch);
		this->tp += std::chrono::hours(hour);
		this->tp += std::chrono::minutes(minute);
		this->tp += std::chrono::seconds(second);
		this->tp += std::chrono::milliseconds(millisecond);
	}

	DateTime::DateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second, unsigned int millisecond, unsigned int microsecond){
		year -= month <= 2;
		const int era_t = (year >= 0 ? year : year - 399) / 400;
		const unsigned yoe_t = static_cast<unsigned>(year - era_t * 400);      // [0, 399]
		const unsigned doy_t = (153 * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;  // [0, 365]
		const unsigned doe_t = yoe_t * 365 + yoe_t / 4 - yoe_t / 100 + doy_t;         // [0, 146096]
		int days_since_epoch = era_t * 146097 + static_cast<int>(doe_t) - 719468;

		this->tp += days(days_since_epoch);
		this->tp += std::chrono::hours(hour);
		this->tp += std::chrono::minutes(minute);
		this->tp += std::chrono::seconds(second);
		this->tp += std::chrono::milliseconds(millisecond);
		this->tp += std::chrono::microseconds(microsecond);
	}

	DateTime::~DateTime(){}

	DateTime& DateTime::add(TimeSpan * span){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + std::chrono::microseconds(span->totalMicroseconds());

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addDays(long long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + days(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addHours(long long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + std::chrono::hours(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addMicroseconds(long long ms){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + std::chrono::microseconds(ms);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addMilliseconds(long long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + std::chrono::milliseconds(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addMinutes(long long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + std::chrono::minutes(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addMonths(long long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + months(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addSeconds(long long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + std::chrono::seconds(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
	}

	DateTime& DateTime::addTicks(long long ms){
		return this->addMicroseconds(ms);
	}

	DateTime& DateTime::addYears(long value){
		std::chrono::time_point<std::chrono::system_clock> tp_new;

		tp_new = this->tp + years(value);

		return DateTime(std::chrono::duration_cast<std::chrono::microseconds>(tp_new.time_since_epoch()).count());
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

		res = new TimeSpan(std::chrono::duration_cast<std::chrono::microseconds>(this->tp - value->tp).count());

		return *res;
	}

	DateTime DateTime::substract(TimeSpan * value){
		DateTime * res;

		std::chrono::microseconds dur(value->totalMicroseconds());

		std::chrono::time_point<std::chrono::system_clock> tmp = this->tp - dur;

		res = new DateTime(tmp.time_since_epoch().count());

		return *res;
	}

	String DateTime::toLongDateString(){
		//time_t tt;
		//tm* tm1;
		//years ys;
		//months mons;
		days ds;
		std::chrono::milliseconds ms;
		std::chrono::time_point<std::chrono::system_clock> tp_temp;
		// time_point<system_clock> tp_wd;
		String res;


		tp_temp = this->tp;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp_temp.time_since_epoch());




		/*int year_t = 2017;
		int month_t = 2;
		int day_t = 28;

		year_t -= month_t <= 2;
		const int era_t = (year_t >= 0 ? year_t : year_t - 399) / 400;
		const unsigned yoe_t = static_cast<unsigned>(year_t - era_t * 400);      // [0, 399]
		const unsigned doy_t = (153 * (month_t + (month_t > 2 ? -3 : 9)) + 2) / 5 + day_t - 1;  // [0, 365]
		const unsigned doe_t = yoe_t * 365 + yoe_t / 4 - yoe_t / 100 + doy_t;         // [0, 146096]
		int days_since_epoch = era_t * 146097 + static_cast<int>(doe_t) - 719468;*/
		int z = 0;
		int era = 0;
		int doe = 0;
		int yoe = 0;
		int y = 0;
		int doy = 0;
		int mp = 0;
		int d = 0;
		int m = 0;
		int year_final = 0;

		z = std::chrono::duration_cast<days>(ms).count() + 719468;
		era = (z >= 0 ? z : z - 146096) / 146097;
		doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
		yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;  // [0, 399]
		y = static_cast<days::rep>(yoe) + era * 400;
		doy = doe - (365 * yoe + yoe / 4 - yoe / 100);                // [0, 365]
		mp = (5 * doy + 2) / 153;                                   // [0, 11]
		d = doy - (153 * mp + 2) / 5 + 1;                             // [1, 31]
		m = mp < 10 ? mp + 3 : mp - 9;                              // [1, 12]
		year_final = y + (m <= 2);
		//return year_month_day{date::year{y + (m <= 2)}, date::month(m), date::day(d)};


		/*ys = duration_cast<years>(ms);
		ms -= ys;
		mons = duration_cast<months>(ms);
		ms -= mons;
		ds = duration_cast<days>(ms);

		if(ys > years(1970)){
			tp_wd = tp_temp - years(1970);
		} else{
			tp_wd = tp_temp;
		}

		tt = system_clock::to_time_t(tp_wd);
		tm1 = localtime(&tt);*/
		int wd = 0;

		if(z >= -4){
			wd = (z + 3) % 7;
		} else{
			wd = (z + 5) % 7 + 6;
		}

		//int wd = static_cast<unsigned>(z >= -4 ? (z + 4) % 7 : (z + 5) % 7 + 6);

		res += this->getWeekdayName(wd);
		res += ", ";
		res += this->getMonthName(m - 1);
		res += " ";
		res += Convert::toString(d).padLeft(2, '0');
		res += ", ";
		res += Convert::toString(year_final).padLeft(4, '0');

		return res;
	}

	String DateTime::toLongTimeString(){
		years ys;
		months mons;
		days ds;
		std::chrono::hours hs;
		std::chrono::minutes mins;
		std::chrono::seconds ss;
		std::chrono::milliseconds ms;
		std::chrono::time_point<std::chrono::system_clock> tp_temp;
		String res;

		tp_temp = this->tp;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp_temp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ms);
		ms -= ys;
		mons = std::chrono::duration_cast<months>(ms);
		ms -= mons;
		ds = std::chrono::duration_cast<days>(ms);
		ms -= ds;
		hs = std::chrono::duration_cast<std::chrono::hours>(ms);
		ms -= hs;
		mins = std::chrono::duration_cast<std::chrono::minutes>(ms);
		ms -= mins;
		ss = std::chrono::duration_cast<std::chrono::seconds>(ms);
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
		std::chrono::hours hs;
		std::chrono::minutes mins;
		std::chrono::seconds ss;
		std::chrono::milliseconds ms;
		std::chrono::time_point<std::chrono::system_clock> tp_temp;
		String res;

		tp_temp = this->tp;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp_temp.time_since_epoch());




		int z = 0;
		int era = 0;
		int doe = 0;
		int yoe = 0;
		int y = 0;
		int doy = 0;
		int mp = 0;
		int d = 0;
		int m = 0;
		int year_final = 0;

		z = std::chrono::duration_cast<days>(ms).count() + 719468;
		era = (z >= 0 ? z : z - 146096) / 146097;
		doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
		yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;  // [0, 399]
		y = static_cast<days::rep>(yoe) + era * 400;
		doy = doe - (365 * yoe + yoe / 4 - yoe / 100);                // [0, 365]
		mp = (5 * doy + 2) / 153;                                   // [0, 11]
		d = doy - (153 * mp + 2) / 5 + 1;                             // [1, 31]
		m = mp < 10 ? mp + 3 : mp - 9;                              // [1, 12]
		year_final = y + (m <= 2);





		ys = std::chrono::duration_cast<years>(ms);
		ms -= ys;
		mons = std::chrono::duration_cast<months>(ms);
		ms -= mons;
		ds = std::chrono::duration_cast<days>(ms);
		ms -= ds;
		hs = std::chrono::duration_cast<std::chrono::hours>(ms);
		ms -= hs;
		mins = std::chrono::duration_cast<std::chrono::minutes>(ms);
		ms -= mins;
		ss = std::chrono::duration_cast<std::chrono::seconds>(ms);
		ms -= ss;

		res += Convert::toString(year_final).padLeft(4, '0');
		res += "-";
		res += Convert::toString(m).padLeft(2, '0');
		res += "-";
		res += Convert::toString(d).padLeft(2, '0');
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

	std::string DateTime::ToString(){
		return toUtcString().GetStringValue();
	}

	std::string DateTime::GetTypeString(){
		return std::string("DateTime");
	}

	DateTime DateTime::Date(){
		years ys;
		months mons;
		days ds;
		std::chrono::time_point<std::chrono::system_clock> tp_temp;
		DateTime res;

		tp_temp = this->tp;
		ds = std::chrono::duration_cast<days>(tp_temp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ds);
		ds -= ys;
		mons = std::chrono::duration_cast<months>(ds);
		ds -= mons;

		res = DateTime(ys.count(), mons.count(), ds.count());

		return res;
	}

	void DateTime::Date(DateTime & date){
		std::chrono::system_clock::time_point tmp = this->tp;
		std::chrono::system_clock::time_point tmp_new = date.tp;

		years y = std::chrono::duration_cast<years>(tmp.time_since_epoch());
		tmp -= y;
		months m = std::chrono::duration_cast<months>(tmp.time_since_epoch());
		tmp -= m;
		days d = std::chrono::duration_cast<days>(tmp.time_since_epoch());
		tmp -= d;

		years y_new = std::chrono::duration_cast<years>(tmp_new.time_since_epoch());
		tmp_new -= y_new;
		months m_new = std::chrono::duration_cast<months>(tmp_new.time_since_epoch());
		tmp_new -= m_new;
		days d_new = std::chrono::duration_cast<days>(tmp_new.time_since_epoch());

		tmp += y_new;
		tmp += m_new;
		tmp += d_new;

		this->tp = tmp;
	}

	unsigned short DateTime::Day(){
		days ds;
		std::chrono::milliseconds ms;
		std::chrono::time_point<std::chrono::system_clock> tp_temp;


		tp_temp = this->tp;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp_temp.time_since_epoch());

		int z = 0;
		int era = 0;
		int doe = 0;
		int yoe = 0;
		int y = 0;
		int doy = 0;
		int mp = 0;
		int d = 0;
		int m = 0;
		int year_final = 0;

		z = std::chrono::duration_cast<days>(ms).count() + 719468;
		era = (z >= 0 ? z : z - 146096) / 146097;
		doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
		yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;  // [0, 399]
		y = static_cast<days::rep>(yoe) + era * 400;
		doy = doe - (365 * yoe + yoe / 4 - yoe / 100);                // [0, 365]
		mp = (5 * doy + 2) / 153;                                   // [0, 11]
		d = doy - (153 * mp + 2) / 5 + 1;                             // [1, 31]
		m = mp < 10 ? mp + 3 : mp - 9;                              // [1, 12]
		year_final = y + (m <= 2);

		return d;
	}

	void DateTime::Day(unsigned short day){
		std::chrono::system_clock::time_point tmp = this->tp;

		days d = std::chrono::duration_cast<days>(tmp.time_since_epoch());
		tmp -= d;

		days d_new(day);

		tmp += d_new;

		this->tp = tmp;
	}

	unsigned short DateTime::DayOfWeek(){
		time_t tt;
		tm tm;

		tt = std::chrono::system_clock::to_time_t(std::chrono::time_point_cast<std::chrono::microseconds>(this->tp));
		tm = *localtime(&tt);

		return tm.tm_wday;
	}

	void DateTime::DayOfWeek(unsigned short dow){
		time_t tt;
		tm tm;

		tt = std::chrono::system_clock::to_time_t(std::chrono::time_point_cast<std::chrono::microseconds>(this->tp));
		tm = *localtime(&tt);

		tm.tm_wday = dow;

		// still work to do, to keep microseconds

		this->tp = std::chrono::system_clock::from_time_t(mktime(&tm));
	}

	unsigned short DateTime::DayOfYear(){
		time_t tt;
		tm tm;

		tt = std::chrono::system_clock::to_time_t(std::chrono::time_point_cast<std::chrono::microseconds>(this->tp));
		tm = *localtime(&tt);

		return tm.tm_yday;
	}

	void DateTime::DayOfYear(unsigned short doy){
		time_t tt;
		tm tm;

		tt = std::chrono::system_clock::to_time_t(std::chrono::time_point_cast<std::chrono::microseconds>(this->tp));
		tm = *localtime(&tt);

		tm.tm_yday = doy;

		// still work to do, to keep microseconds

		this->tp = std::chrono::system_clock::from_time_t(mktime(&tm));
	}

	unsigned short DateTime::Hour(){
		unsigned short res = 0;
		years ys;
		months mons;
		days ds;
		std::chrono::hours hs;
		std::chrono::seconds ss;

		ss = std::chrono::duration_cast<std::chrono::seconds>(this->tp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ss);
		ss -= ys;
		mons = std::chrono::duration_cast<months>(ss);
		ss -= mons;
		ds = std::chrono::duration_cast<days>(ss);
		ss -= ds;
		hs = std::chrono::duration_cast<std::chrono::hours>(ss);

		res = hs.count();

		return res;
	}

	void DateTime::Hour(unsigned short _hours){
		std::chrono::system_clock::time_point tmp = this->tp;

		std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(tmp.time_since_epoch());
		tmp -= h;

		std::chrono::hours h_new(_hours);

		tmp += h_new;

		this->tp = tmp;
	}

	unsigned int DateTime::Millisecond(){
		unsigned int res = 0;
		years ys;
		months mons;
		days ds;
		std::chrono::hours hs;
		std::chrono::minutes mins;
		std::chrono::seconds ss;
		std::chrono::milliseconds ms;

		ms = std::chrono::duration_cast<std::chrono::milliseconds>(this->tp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ms);
		ms -= ys;
		mons = std::chrono::duration_cast<months>(ms);
		ms -= mons;
		ds = std::chrono::duration_cast<days>(ms);
		ms -= ds;
		hs = std::chrono::duration_cast<std::chrono::hours>(ms);
		ms -= hs;
		mins = std::chrono::duration_cast<std::chrono::minutes>(ms);
		ms -= mins;
		ss = std::chrono::duration_cast<std::chrono::seconds>(ms);
		ms -= ss;

		res = ms.count();

		return res;
	}

	void DateTime::Millisecond(unsigned int ms){
		std::chrono::system_clock::time_point tmp = this->tp;

		std::chrono::milliseconds ms_old = std::chrono::duration_cast<std::chrono::milliseconds>(tmp.time_since_epoch());
		tmp -= ms_old;

		std::chrono::milliseconds ms_new(ms);

		tmp += ms_new;

		this->tp = tmp;
	}

	unsigned short DateTime::Minute(){
		unsigned short res = 0;
		years ys;
		months mons;
		days ds;
		std::chrono::hours hs;
		std::chrono::minutes mins;
		std::chrono::seconds ss;

		ss = std::chrono::duration_cast<std::chrono::seconds>(this->tp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ss);
		ss -= ys;
		mons = std::chrono::duration_cast<months>(ss);
		ss -= mons;
		ds = std::chrono::duration_cast<days>(ss);
		ss -= ds;
		hs = std::chrono::duration_cast<std::chrono::hours>(ss);
		ss -= hs;
		mins = std::chrono::duration_cast<std::chrono::minutes>(ss);

		res = mins.count();

		return res;
	}

	void DateTime::Minute(unsigned short min){
		std::chrono::system_clock::time_point tmp = this->tp;

		std::chrono::minutes min_old = std::chrono::duration_cast<std::chrono::minutes>(tmp.time_since_epoch());
		tmp -= min_old;

		std::chrono::minutes min_new(min);

		tmp += min_new;

		this->tp = tmp;
	}

	unsigned short DateTime::Month(){
		unsigned short res = 0;
		years ys;
		months mons;
		std::chrono::seconds ss;

		ss = std::chrono::duration_cast<std::chrono::seconds>(this->tp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ss);
		ss -= ys;
		mons = std::chrono::duration_cast<months>(ss);

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
		std::chrono::hours hs;
		std::chrono::minutes mins;
		std::chrono::seconds ss;

		ss = std::chrono::duration_cast<std::chrono::seconds>(this->tp.time_since_epoch());

		ys = std::chrono::duration_cast<years>(ss);
		ss -= ys;
		mons = std::chrono::duration_cast<months>(ss);
		ss -= mons;
		ds = std::chrono::duration_cast<days>(ss);
		ss -= ds;
		hs = std::chrono::duration_cast<std::chrono::hours>(ss);
		ss -= hs;
		mins = std::chrono::duration_cast<std::chrono::minutes>(ss);
		ss -= mins;

		res = ss.count();

		return res;
	}

	void DateTime::Second(unsigned short sec){
		setTime<std::chrono::seconds>(sec);
	}

	long long DateTime::Ticks(){
		return std::chrono::nanoseconds(this->tp.time_since_epoch()).count();
	}

	void DateTime::Ticks(long long micsec){
		setTime<std::chrono::microseconds>(micsec);
	}

	unsigned short DateTime::Year(){
		unsigned short res = 0;

		res = std::chrono::duration_cast<years>(this->tp.time_since_epoch()).count();

		return res;
	}

	void DateTime::Year(unsigned short year){
		setTime<years>(year);
	}

	template<typename T>
	void DateTime::setTime(long long nr){
		std::chrono::system_clock::time_point tmp = this->tp;

		T nr_old = std::chrono::duration_cast<T>(tmp.time_since_epoch());
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
}