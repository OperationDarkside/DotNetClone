#include "CsvSerializer.h"


namespace dnc {
	namespace CSV {

		CsvSerializer::CsvSerializer() {}

		CsvSerializer::~CsvSerializer() {}

		std::string CsvSerializer::ToString() {
			return std::string();
		}

		std::string CsvSerializer::GetTypeString() {
			return std::string();
		}

		Data::DataTable CsvSerializer::Deserialize(String& csvString) {
			Data::DataTable table;

			table.Columns().Add(Data::DataColumn());

			return table;
		}
	}
}