//
// Created by enzom on 03/01/2024.
//

#include "../include/mysql.h"

// Connection à la base de données

int dbConnect() {

    /*
     * Permet la connexion à la base de données
     * Retourne 0 si la connexion est réussie
     * Retourne 1 si la connexion est échouée
     */

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = (char *)"localhost";
    char *user = (char *)"user";
    char *password = (char *)"Azerty11";
    char *database = (char *)"f1_project";
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server,
                            user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return 1;
    }
    res = mysql_use_result(conn);

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}