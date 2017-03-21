#include "MySqlDataAdapter.h"

MySqlDataAdapter::MySqlDataAdapter(){}

MySqlDataAdapter::MySqlDataAdapter(MySqlCommand & command):cmd(command){

}

MySqlDataAdapter::~MySqlDataAdapter(){}

long MySqlDataAdapter::Fill(DataTable& table){
	long res = 0;

	MySqlDataReader reader = this->cmd.ExecuteReader();;

	reader.FillTable(table);

	return table.Rows().Count();
}
