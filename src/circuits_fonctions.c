//
// Created by enzom on 06/01/2024.
//

#include "../include/circuits_fonctions.h"


// CIRCUIT FUNCTIONS

char ***getAllCircuits() {

    /*
    * Permet de récupérer toutes les informations sur tous les circuits
    * Retourne un tableau de char*** si la récupération est réussie
    * Retourne NULL si la récupération est échouée
    */

    if (globalDbConnection.connection == NULL) {
        return NULL;
    }

    char query[1000];
    snprintf(query, sizeof(query), "SELECT * FROM circuits");

    if (mysql_query(globalDbConnection.connection, query) != 0) {
        fprintf(stderr, "Erreur lors de la requête : %s\n", mysql_error(globalDbConnection.connection));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(globalDbConnection.connection);

    if (result == NULL) {
        fprintf(stderr, "Erreur lors de la récupération des circuits : %s\n", mysql_error(globalDbConnection.connection));
        return NULL;
    }

    int num_fields = mysql_num_fields(result); // nombre de colonnes dans le résultat

    char ***circuits = (char ***)malloc((mysql_num_rows(result) + 1) * sizeof(char **));
    if (circuits == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
        mysql_free_result(result);
        return NULL;
    }

    int i = 0;

    // Parcours des lignes du résultat
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)) != NULL) {
        circuits[i] = (char **)malloc(num_fields * sizeof(char *));
        if (circuits[i] == NULL) {
            fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
            mysql_free_result(result);
            freeCircuits(circuits);
            return NULL;
        }

        for (int j = 0; j < num_fields; j++) {
            circuits[i][j] = strdup(row[j]);
            if (circuits[i][j] == NULL) {
                fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
                mysql_free_result(result);
                freeCircuits(circuits);
                return NULL;
            }
        }
        i++;
    }

    circuits[i] = NULL; // Fin du tableau
    mysql_free_result(result);

    return circuits;
}

char **getCircuitsName() {

    /*
     * Permet de récupérer le nom des circuits
     * Retourne un tableau de char** si la récupération est réussie
     * Retourne NULL si la récupération est échouée
     */

    if (globalDbConnection.connection == NULL) {
        return NULL;
    }

    char query[1000];
    snprintf(query, sizeof(query), "SELECT nom FROM circuits");

    if (mysql_query(globalDbConnection.connection, query) != 0) {
        fprintf(stderr, "Erreur lors de la requête : %s\n", mysql_error(globalDbConnection.connection));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(globalDbConnection.connection);

    if (result == NULL) {
        fprintf(stderr, "Erreur lors de la récupération des circuits : %s\n", mysql_error(globalDbConnection.connection));
        mysql_free_result(result);
        return NULL;
    }

    char **circuits = (char **)malloc((mysql_num_rows(result) + 1) * sizeof(char *));

    if (circuits == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
        mysql_free_result(result);
        return NULL;
    }

    int i = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL) {
        circuits[i] = strdup(row[0]);
        if (circuits[i] == NULL) {
            fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
            mysql_free_result(result);
            freeCircuitsName(circuits);
            return NULL;
        }
        i++;
    }

    circuits[i] = NULL;
    mysql_free_result(result);

    freeCircuitsName(circuits);
    return circuits;

}

// Free functions

void freeCircuitsName(char **circuits) {
    for (int i = 0; circuits[i] != NULL; i++) {
        free(circuits[i]);
    }
    free(circuits);
}

void freeCircuits(char ***circuits) {
    for (int i = 0; circuits[i] != NULL; i++) {
        for (int j = 0; circuits[i][j] != NULL; j++) {
            free(circuits[i][j]);
        }
        free(circuits[i]);
    }
    free(circuits);
}