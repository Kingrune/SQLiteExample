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
 * AddHighScore
 * Adds a high score to the database
 * @param score - the score to add
 */
void AddHighScore(int id, int score)
{
	// TODO: 
}

/**
 * GetHighScores
 * Retrieves the high scores from
 * the database
 */
void GetHighScores()
{
	// TODO:
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
	// TODO:
}

/**
 * DeleteHighScore
 * Deletes a highscore with the provided id
 * @param id - the id of the highscore to delete
 */
void DeleteHighScore(int id)
{
	// TODO:
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