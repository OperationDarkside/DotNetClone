#include "LingerOption.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			LingerOption::LingerOption(){}

			LingerOption::LingerOption(bool enable, int sec):enabled(enable), seconds(sec){}


			LingerOption::~LingerOption(){}

			std::string LingerOption::ToString(){
				return std::string("System.Net.Sockets.LingerOption");
			}

			std::string LingerOption::GetTypeString(){
				return std::string("LingerOption");
			}

			bool LingerOption::Enabled(){
				return this->enabled;
			}

			void LingerOption::Enabled(bool value){
				this->enabled = value;
			}

			int LingerOption::LingerTime(){
				return this->seconds;
			}

			void LingerOption::LingerTime(int sec){
				this->seconds = sec;
			}

		}
	}
}