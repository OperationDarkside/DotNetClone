#include <chrono>
#include "String.h"

#pragma once

namespace dnc{

	/**
	Represents a duration of time (c++ chrono duration)
	*/
	class TimeSpan: public Object{
	public:
		/**
		Creates an TimeSpan instance with 0 duration
		*/
		TimeSpan();
		/**
		Creates an TimeSpan instance with the given microseconds

		@param microseconds Duration component
		*/
		TimeSpan(long long microseconds);
		/**
		Creates an TimeSpan instance with the given hours, minutes, seconds

		@param hours Duration component
		@param minutes Duration component
		@param seconds Duration component
		*/
		TimeSpan(unsigned int hours, unsigned int minutes, unsigned int seconds);
		/**
		Creates an TimeSpan instance with the given days, hours, minutes, seconds

		@param days Duration component
		@param hours Duration component
		@param minutes Duration component
		@param seconds Duration component
		*/
		TimeSpan(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds);
		/**
		Creates an TimeSpan instance with the given days, hours, minutes, seconds, milliseconds

		@param days Duration component
		@param hours Duration component
		@param minutes Duration component
		@param seconds Duration component
		@param milliseconds Duration component
		*/
		TimeSpan(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds, unsigned int milliseconds);
		~TimeSpan();

		/**
		Adds the given TimeSpan instance to this instance

		@param span Duration component
		*/
		TimeSpan* add(TimeSpan* span);
		/**
		Compares the TimeSpan span to this instance

		@param span Number >0, ==0 or <0
		*/
		int compareTo(TimeSpan* span);
		/**
		Inverts this TimeSpan instance (+ to - and vice versa)

		@return This instance
		*/
		TimeSpan* negate();
		/**
		Sutracts the TimeSpan span from this TimeSpan instance

		@param span TimeSpan to subtract
		@return This instance
		*/
		TimeSpan* subtract(TimeSpan* span);
		/**
		Returns a c++ string representation of this instance "dd hh:mm:ss:sss"

		@return The c++ string duration representation
		*/
		std::string toString();
		std::string getTypeString();
		/**
		Returns duration of this instance in microseconds

		@return Microseconds duration
		*/
		long long totalMicroseconds();


		/**
		Returns the day component of this duration

		@return Day component
		*/
		long Days();
		/**
		Sets the day component of this duration

		@param days Day component
		*/
		void Days(long days);
		/**
		Returns the hour component of this duration

		@return Hour component
		*/
		long Hours();
		/**
		Sets the hour component of this duration

		@param hours Hour component
		*/
		void Hours(long hours);
		/**
		Returns the minute component of this duration

		@return Minute component
		*/
		long Minutes();
		/**
		Sets the minute component of this duration

		@param minutes Minute component
		*/
		void Minutes(long min);
		/**
		Returns the second component of this duration

		@return Second component
		*/
		long Seconds();
		/**
		Sets the second component of this duration

		@param sec Second component
		*/
		void Seconds(long sec);
		/**
		Returns the millisecond component of this duration

		@return Millisecond component
		*/
		long Milliseconds();
		/**
		Sets the millisecond component of this duration

		@param ms Milliseconds component
		*/
		void Milliseconds(long ms);
		/**
		Returns the ticks of this duration in microsecond

		@return Microsecond component
		*/
		long long Ticks();
		/**
		Sets the ticks of this duration in microseconds

		@param ticks Microsecond component
		*/
		void Ticks(long long ticks);
	private:
		typedef std::chrono::duration<int, std::ratio_multiply<std::chrono::hours::period, std::ratio<24> >::type> days;

		std::chrono::system_clock::duration dur;
	};
}
