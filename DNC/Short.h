#pragma once

#ifndef SHORT_H
#define SHORT_H

#include "String.h"

namespace dnc{

	class Short: public Object{

		friend class Serializable;

	public:
		Short();
		Short(short s);
		~Short();

		std::string ToString() override;
		std::string GetTypeString() override;

		Short operator=(short s);
		operator short();

	private:
		short value;

		void FromString(std::string val) override;
	};
}
#endif // !SHORT_H