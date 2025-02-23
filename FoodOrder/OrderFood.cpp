#include "OrderFood.h"

int OrderFood::GenereteOrderId()
{
	random_device rd;
	mt19937 gen(rd);
	uniform_int_distribution<int> dis(100000, 999999);
	return dis(gen);
}

string OrderFood::SystemTime()
{
	return "";
}

void OrderFood::CreateTableForOrderOfCustomers(sqlite3 *db)
{
    string sql_cmd = "CREATE TABLE IF NOT EXISTS orders (\
                orderId          NUMERIC(8)  NOT NULL,\
                orderPerson      TEXT(70)    NOT NULL,\
                orderFoods       TEXT(30)    NOT NULL,\
                priceOrders      NUMERIC(12) NOT NULL,\
                orderDateAndTime TEXT(40)    NOT NULL);";
    char* errorMSG;
    if (sqlite3_exec(db, sql_cmd.c_str(), nullptr, 0, &errorMSG) != SQLITE_OK)
    {
        std::cout << "Error Creating table! " << errorMSG << std::endl;
        sqlite3_free(errorMSG);
    }
    else
    {
        std::cout << "Orders Table Created successfully." << std::endl;
    }
}

void OrderFood::ListingCustomersOrdersInVector()
{
    
}

void OrderFood::SetPeopleOrders()
{
}

void OrderFood::CalculatePeopleOrders()
{
}
