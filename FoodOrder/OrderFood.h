#pragma once
#include "MainHeader.h"
class OrderFood
{
private:
	struct PeopleOrdersTable
	{
		int OrderId;
		string CustomerName;
		string OrderItems;
		int OrderPrices;
		string OrderDateAndTimes;
	};
	vector<PeopleOrdersTable> Vec_PeopleOrdersTable;
	struct OrderTableTemp
	{
		int OrderCount;
		string OrderItemName;
	};
	vector<OrderTableTemp> Vec_OrderTableTemp;
public:
	int GenereteOrderId();
	string SystemTime();
	void CreateTableForOrderOfCustomers(sqlite3 *db);
	void ListingCustomersOrdersInVector();
	void SetPeopleOrders();
	void CalculatePeopleOrders();
};
