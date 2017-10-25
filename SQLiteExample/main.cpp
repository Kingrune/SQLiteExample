#include "sqlite3.h"

#include <string>
#include <iostream>

sqlite3* db;

const std::string DB_FILENAME = "exampledb.db";

/**
 * OpenSQLiteDB
 * Attempts to open a SQLite db from the provided
 * filename
 * @Param filename - the name of the sqlite db
 * @return bool - TRUE if successful, FALSE otherwise
 */
bool OpenSQLiteDB(const std::string& filename)
{
	int result = sqlite3_open(filename.c_str(), &db);

	if (result)
	{
		printf("Failed to open sqlite db: %s\n", sqlite3_errmsg(db));
		return false;
	}

	printf("Successfully opened the sqlite database!\n");
	return true;
}

/**
 * CloseSQLiteDB
 * Closes the sqlite db
 */
void CloseSQLiteDB()
{
	printf("Closing SQLite db...\n");
	sqlite3_close(db);
}

/**
 * RunSQLiteExample
 * The example to run
 */
void RunSQLiteExample()
{
	std::string sql;

	// TODO: Create sql code here

	// TODO: Execute sql code here

	// TODO: Check for errors
}

/**
 * main
 */
int main()
{
	if (!OpenSQLiteDB(DB_FILENAME))
	{
		return 1;
	}

	RunSQLiteExample();

	CloseSQLiteDB();

	int breakpoint = 0;

	return 0;
}