/*
 * Fichier : circuits_fonctions.c
 * Description: Fichier source de circuits_fonctions.h
 */

#include "../include/circuits_fonctions.h"
int CircuitSelected;

// CIRCUIT FUNCTIONS

int initAllCircuits(CircuitData circuits[]) {

    /*
     * Récupère toutes les informations sur tous les circuits et les stocke dans un tableau de CircuitData
     * Retourne 0 si la récupération est réussie
     * Retourne 1 si la récupération est échouée
     */

    MYSQL_RES *result = NULL;

    char *query = (char *)"SELECT * FROM circuits";

    if (mysql_query(globalDbConnection.connection, query) != 0) {
        fprintf(stderr, "Erreur lors de la requête : %s\n", mysql_error(globalDbConnection.connection));
        return 1;
    }

    result = mysql_store_result(globalDbConnection.connection);

    if (result == NULL) {
        fprintf(stderr, "Erreur lors de la récupération des circuits : %s\n", mysql_error(globalDbConnection.connection));
        return 1;
    }

    int i = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL) {
        circuits[i].circuit_id = atoi(row[0]);
        strcpy(circuits[i].nom, row[1]);
        strcpy(circuits[i].pays, row[2]);
        circuits[i].nombre_de_tours = atoi(row[3]);
        circuits[i].longueur_circuit = atof(row[4]);
        circuits[i].longueur_course = atof(row[5]);
        strcpy(circuits[i].type_circuit, row[6]);
        circuits[i].niveau_difficulte = atoi(row[7]);
        circuits[i].usure_pneus = atoi(row[8]);
        circuits[i].virages_gauche = atoi(row[9]);
        circuits[i].virages_droite = atoi(row[10]);
        circuits[i].longueur_ligne_droite = atoi(row[11]);
        circuits[i].zones_drs = atoi(row[12]);
        i++;
    }

    mysql_free_result(result);
    return 0;
}

CircuitData getCircuitData(int id) {
    /*
     * Permet de récupérer les données d'un circuit
     * Retourne le circuit correspondant à l'id
     */

    CircuitData circuits[CIRCUITS_NUMBER];
    initAllCircuits(circuits);

    return circuits[id];

}

void saveCirsuit(int id) {
    CircuitSelected = id;
}

int getCircuit() {
    return CircuitSelected;
}