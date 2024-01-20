//
// Created by enzom on 03/01/2024.
//

#ifndef F1_GAME_MYSQL_H
#define F1_GAME_MYSQL_H

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>

typedef struct {
    char *server;
    char *user;
    char *password;
    char *database;
    MYSQL *connection;
} DbConnectionInfo;

extern DbConnectionInfo globalDbConnection;

// Player prototypes
int dbConnect(DbConnectionInfo *config);
int addPlayer(const char* pilot, int score);
int removePlayer(int id);
int setScore(int id, int score);
int getScore(int id);
char* getLastPilot();


// Driver prototypes
char ***getAllDriversInfo();
void freeDriversInfo(char ***drivers);
char **getAllDriversName();
void freeDriversName(char **drivers);

#endif //F1_GAME_MYSQL_H
