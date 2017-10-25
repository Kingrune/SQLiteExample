#include "sqlite3.h"

#include <string>
#include <iostream>

sqlite3* db;

const std::string DB_FILENAME = "exampledb.db";

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

void CloseSQLiteDB()
{
	printf("Closing SQLite db...\n");
	sqlite3_close(db);
}

void RunSQLiteExample()
{
	int breakpoint = 0;
}

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