#include "sqlite3.h"

#include <string>
#include <iostream>

sqlite3* db;

const std::string DB_FILENAME = "exampledb.db";

const int MAX_SQL_LENGTH = 200;

/**
 * CheckSQLiteErrors
 * Checks for SQLite errors
 * @param result - the result to check
 * @return int - 0 if all good, 1 if error
 */
int CheckSQLiteErrors(int result)
{
	if (result)
	{
		printf("SQLite error: %s\n", sqlite3_errmsg(db));
		return 1;
	}

	return 0;
}

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
	if (CheckSQLiteErrors(result) == 1)
	{
		printf("Failed to open the sqlite database!\n");
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
* SQLiteCallback
* Called from the sqlite3_exec method
*/
int SQLiteCallback(void *v, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

/**
 * ExecuteSQLite
 * Executes a sqlite query with the provided info
 * Handles the errors
 * @param sql - the sql to execute
 */
void ExecuteSQLite(char* sql)
{
	char* errMsg = 0;
	int result = sqlite3_exec(db, sql, SQLiteCallback, 0, &errMsg);
	CheckSQLiteErrors(result);
	if (result != 0)
	{
		printf(errMsg);
		printf("\n");
		return;
	}
}

/**
 * AddHighScore
 * Adds a high score to the database
 * @param score - the score to add
 */
void AddHighScore(int id, int score)
{
	char* errMsg = 0;
	char sql[MAX_SQL_LENGTH];
	sprintf_s(sql, "INSERT INTO highscores (highscore_id, score) VALUES (%d, %d);", id, score);
	ExecuteSQLite(sql);
	printf("Inserted id(%d) score(%d) into the db\n", id, score);
}

/**
 * GetHighScores
 * Retrieves the high scores from
 * the database
 */
void GetHighScores()
{
	char* errMsg = 0;
	char sql[MAX_SQL_LENGTH];
	sprintf_s(sql, "SELECT * FROM highscores;");
	ExecuteSQLite(sql);
}

/**
 * SetHighScore
 * Sets the high score of the provided 
 * id to the new score
 * @param id - the id of the highscore
 * @param score - the new score
 */
void SetHighScore(int id, int score)
{
	char* errMsg = 0;
	char sql[MAX_SQL_LENGTH];
	sprintf_s(sql, "UPDATE highscores SET score = %d WHERE highscore_id = %d;", score, id);
	ExecuteSQLite(sql);
	printf("Updated id(%d) to score(%d)\n", id, score);
}

/**
 * DeleteHighScore
 * Deletes a highscore with the provided id
 * @param id - the id of the highscore to delete
 */
void DeleteHighScore(int id)
{
	char* errMsg = 0;
	char sql[MAX_SQL_LENGTH];
	sprintf_s(sql, "DELETE FROM highscores WHERE highscore_id = %d;", id);
	ExecuteSQLite(sql);
	printf("Deleted all entries from highscores with id(%d).\n", id);
}

/**
 * RunSQLiteExample
 * The example to run
 * CRUD
 * C - Create		INSERT
 * R - Read			SELECT
 * U - Update		UPDATE
 * D - Delete		DELETE
 * Using the highscores table:
 * Create a high score, read high score, 
 * update high score, and delete high score
 */
void RunSQLiteExample()
{
	std::string sql;

	AddHighScore(2, 10);
	system("pause");

	GetHighScores();
	system("pause");

	SetHighScore(2, 15);
	system("pause");

	DeleteHighScore(2);
	system("pause");
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