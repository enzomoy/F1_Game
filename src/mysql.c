//
// Created by enzom on 03/01/2024.
//

#include "../include/mysql.h"

DbConnectionInfo globalDbConnection = {
        .server = "localhost",
        .user = "user",
        .password = "Azerty11",
        .database = "f1_project",
};

int dbConnect(DbConnectionInfo *config) {

    /*
     * Permet la connexion à la base de données
     * Retourne la connection si la connexion est réussie
     * Retourne NULL si la connexion est échouée
     */

    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        return 1;
    }

    if (mysql_real_connect(conn, config->server, config->user,
                           config->password, config->database, 0, NULL, 0) == NULL) {
        mysql_close(conn);
        return 1;
    }

    config->connection = conn;

    return 0;
}

int addPlayer(const char* pilot, int score) {

    /*
     * Permet d'ajouter un joueur à la base de données
     * Retourne 0 si l'ajout est réussi
     * Retourne 1 si l'ajout est échoué
     */

    if (globalDbConnection.connection == NULL) {
        return 1;
    }

    char query[1000];

    time_t t;
    struct tm* tm_info;
    time(&t);
    tm_info = localtime(&t);

    // Formattage de la date du jour en YYYY-MM-DD H-M-S
    char creation_date[20];
    strftime(creation_date, sizeof(creation_date), "%Y-%m-%d %H:%M:%S", tm_info);

    snprintf(query, sizeof(query), "INSERT INTO player (pilot, creation_date, score) VALUES ('%s', '%s', %d)", pilot, creation_date, score);

    if (mysql_query(globalDbConnection.connection, query) != 0) {
        return 1;
    }
    return 0;
}