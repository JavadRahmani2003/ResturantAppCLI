#pragma once
#include "AllHeaders.h"
void CreateTable(sqlite3* db, std::string OrderTable);
void InsertIntoDb(sqlite3* db, const string FoodName, const int FoodPrice);
void ShowMenu(sqlite3* db);
void DeleteFrmDb(sqlite3* db, const string FoodName);