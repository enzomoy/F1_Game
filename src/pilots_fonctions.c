#include "../include/pilots_fonctions.h"

int initAllDrivers(Pilots pilots[]) {

    /*
     * Récupère les données de tous les pilotes dans la base de données et les stocke dans un tableau de Pilots
     * Retourne 0 si la récupération est réussie
     * Retourne 1 si la récupération est échouée
     */

    MYSQL_RES *result = NULL;

    char *query = (char *)"SELECT * FROM drivers";

    if (mysql_query(globalDbConnection.connection, query)) {
        printf("Erreur lors de la récupération des pilotes\n");
        return 1;
    }

    result = mysql_store_result(globalDbConnection.connection);

    if (result == NULL) {
        printf("Erreur lors de la récupération des pilotes\n");
        return 1;
    }

    MYSQL_ROW row;
    int i = 0;

    while ((row = mysql_fetch_row(result))) {
        strcpy(pilots[i].nom, row[1]);
        pilots[i].courses = atoi(row[2]);
        pilots[i].victoires = atoi(row[3]);
        pilots[i].deuxiemes = atoi(row[4]);
        pilots[i].troisiemes = atoi(row[5]);
        pilots[i].podiums = atoi(row[6]);
        pilots[i].poles = atoi(row[7]);
        pilots[i].laps = atoi(row[8]);
        pilots[i].points = atof(row[9]);
        i++;
    }

    mysql_free_result(result);
    return 0;
}


Pilots getDriverData(int id) {

    /*
     * Permet de récupérer les données d'un pilote
     * Retourne le pilote correspondant à l'id
     */

    Pilots pilotes[20];
    initAllDrivers(pilotes);

    return pilotes[id];
}