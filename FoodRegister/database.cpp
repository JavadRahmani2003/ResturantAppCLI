#include "database.h"

void CreateTable(sqlite3* db, std::string OrderTable)
{
    string checkSQLiteTable = "SELECT name FROM sqlite_master WHERE type='table' AND name='FoodReg';";
    sqlite3_stmt* stmt;
    // Check if the table exists
    if (sqlite3_prepare_v2(db, checkSQLiteTable.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) != SQLITE_ROW)
        {
            string sql_cmd = "CREATE TABLE FoodReg (FoodName TEXT (50) NOT NULL, FoodPrice NUMERIC (10) NOT NULL);";
            char* errorMSG;
            if (sqlite3_exec(db, sql_cmd.c_str(), nullptr, 0, &errorMSG) != SQLITE_OK)
            {
                cout << "Error Creating table! " << errorMSG << endl;
                sqlite3_free(errorMSG);
            }
            else
            {
                cout << "FoodReg Table Created successfully." << endl;
            }
        }
        else
        {
            cout << "Looks like there is something: " << sqlite3_errmsg(db) << endl;
        }
        sqlite3_finalize(stmt); // Finalize the prepared statement
    }
}

void InsertIntoDb(sqlite3* db, const string FoodName, const int FoodPrice)
{
    string sql_cmd = "INSERT INTO FoodReg (FoodName, FoodPrice) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql_cmd.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, FoodName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, FoodPrice);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            cout << "Error Inserting User: " << sqlite3_errmsg(db) << endl;
        }
        else
        {
            cout << "Inserting " << FoodName << " And " << FoodPrice << " user success!" << endl;
        }
    }
    else
    {
        cout << "Error Preparing statement: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt); // Finalize the prepared statement
}

void ShowMenu(sqlite3* db)
{
    string sql_cmd = "SELECT * FROM FoodReg;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql_cmd.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            const string FoodName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)); // Index 0 for FoodName
            int FoodPrice = sqlite3_column_int(stmt, 1); // Index 1 for FoodPrice
            cout << "FoodName: " << FoodName << "\t" << "FoodPrice: " << FoodPrice << endl;
        }
    }
    else
    {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt); // Finalize the prepared statement
}

void DeleteFrmDb(sqlite3* db, const string FoodName)
{
    string sql_cmd = "DELETE FROM FoodReg WHERE FoodName = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql_cmd.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, FoodName.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            cout << "Error Deleting User! " << sqlite3_errmsg(db) << endl;
        }
        else
        {
            cout << "Deleting " << FoodName << " has been successfully completed." << endl;
        }
    }
    else
    {
        cout << "Error preparing statement! Code: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt); // Finalize the prepared statement
}
