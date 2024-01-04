//
// Created by enzom on 03/01/2024.
//

#include "../include/mysql.h"

DbConnectionInfo globalDbConnection = {
        .server = (char *)"localhost",
        .user = (char *)"user",
        .password = (char *)"Azerty11",
        .database = (char *)"f1_project",
        .connection = NULL
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

int removePlayer(int id) {

        /*
        * Permet de supprimer un joueur de la base de données
        * Retourne 0 si la suppression est réussie
        * Retourne 1 si la suppression est échouée
        */

        if (globalDbConnection.connection == NULL) {
            return 1;
        }

        char query[1000];

        snprintf(query, sizeof(query), "DELETE FROM player WHERE id = %d", id);

        if (mysql_query(globalDbConnection.connection, query) != 0) {
            return 1;
        }
        return 0;
}

int updatePlayerScore(int id, int score) {

        /*
        * Permet de mettre à jour le score d'un joueur
        * Retourne 0 si la mise à jour est réussie
        * Retourne 1 si la mise à jour est échouée
        */

        if (globalDbConnection.connection == NULL) {
            return 1;
        }

        char query[1000];

        snprintf(query, sizeof(query), "UPDATE player SET score = %d WHERE id = %d", score, id);

        if (mysql_query(globalDbConnection.connection, query) != 0) {
            return 1;
        }
        return 0;
}

int getScore(int id) {

            /*
            * Permet de récupérer le score d'un joueur
            * Retourne le score si la récupération est réussie
            * Retourne -1 si la récupération est échouée
            */

            if (globalDbConnection.connection == NULL) {
                return -1;
            }

            char query[1000];

            snprintf(query, sizeof(query), "SELECT score FROM player WHERE id = %d", id);

            if (mysql_query(globalDbConnection.connection, query) != 0) {
                return -1;
            }

            MYSQL_RES *result = mysql_store_result(globalDbConnection.connection);
            if (result == NULL) {
                return -1;
            }

            MYSQL_ROW row = mysql_fetch_row(result);
            if (row == NULL) {
                return -1;
            }

            int score = atoi(row[0]);

            mysql_free_result(result);

            return score;
}