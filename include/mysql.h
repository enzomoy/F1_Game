/*
 * Fichier : mysql.h
 * Description: Fichier d'en-tête de mysql.c
 */

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
int removePlayer();
int setScore(int id, int score);
int getScore(int id);

// Driver prototypes
char ***getAllDriversInfo();
void freeDriversInfo(char ***drivers);
void freeDriversName(char **drivers);

#endif //F1_GAME_MYSQL_H
