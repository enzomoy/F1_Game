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
} db_config;

MYSQL *dbConnect(db_config *config);
int addPlayer(MYSQL* conn, const char* pilot, int score);

#endif //F1_GAME_MYSQL_H
