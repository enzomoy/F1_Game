#include "../include/pilots_fonctions.h"
#include "../include/start.h"

int driverSelected;

char **getAllPilots() {
    char **pilots = (char **)malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++) {
        pilots[i] = (char *)malloc(18 * sizeof(char));
    }

    strcpy(pilots[0], "Max Verstappen");
    strcpy(pilots[1], "Lewis Hamilton");
    strcpy(pilots[2], "Valtteri Bottas");
    strcpy(pilots[3], "Sergio Perez");
    strcpy(pilots[4], "Daniel Ricciardo");
    strcpy(pilots[5], "Esteban Ocon");
    strcpy(pilots[6], "Carlos Sainz");
    strcpy(pilots[7], "Lando Norris");
    strcpy(pilots[8], "Charles Leclerc");
    strcpy(pilots[9], "Pierre Gasly");
    strcpy(pilots[10], "Fernando Alonso");
    strcpy(pilots[11], "Sebastian Vettel");
    strcpy(pilots[12], "Lance Stroll");
    strcpy(pilots[13], "Yuki Tsunoda");
    strcpy(pilots[14], "George Russell");
    strcpy(pilots[15], "Nicholas Latifi");
    strcpy(pilots[16], "Antonio Giovinazzi");
    strcpy(pilots[17], "Nikita Mazepin");
    strcpy(pilots[18], "Mick Schumacher");
    strcpy(pilots[19], "Kimi Raikkonen");

    return pilots;
}

char **getAllDriversName() {

    /*
     * Permet de récupérer tous le nom des pilotes
     * Retourne un tableau de char* contenant tous les pilotes
     */

    char ***drivers = getAllDriversInfo();

    char **driversName = (char **)malloc(sizeof(char*) * 20);
    for (int i = 0; i < 20; i++) {
        driversName[i] = (char *)malloc(sizeof(char) * 50);
        strcpy(driversName[i], drivers[i][1]);
    }

    freeDriversName(driversName);
    freeDriversInfo(drivers);

    printf("%s\n", driversName[0]);

    return driversName;
}


int selectPilot(int pilot) {

    /*
     * Permet de sélectionner un pilote
     * Retourne 0 si la sélection est réussie
     * Retourne 1 si la sélection est échouée
     */

    char **pilots = getAllPilots();

    if (addPlayer(pilots[pilot], 0) == 1) {
        return 1;
    }

    freeDriversName(pilots);
    return 0;
}

int addScore(int playerId, int addedScore) {
    /*
     * Permet de mettre à jour le score d'un joueur
     * Retourne 0 si la mise à jour est réussie
     * Retourne 1 si la mise à jour est échouée
     * Retourne 2 si le joueur n'existe pas
     */

    // Récupération du score actuel du joueur
    int score = getScore(playerId);
    switch (score) {
        case -1:
            return 1;
        case -2:
            return 2;
        default:
            break;
    }

    int lastScore = score;

    score += addedScore;

    printf("Le score du joueur %d est de %d (anciennement %d)\n", playerId, score, lastScore);

    if (setScore(playerId, score) == 1) {
        return 1;
    }

    return 0;
}

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
     * Retourne 0 si la récupération est réussie
     * Retourne 1 si la récupération est échouée
     */

    Pilots pilotes[20];
    initAllDrivers(pilotes);

    return pilotes[id];
}

void savePilot(int id) {
    driverSelected = id;
}

int getPilot() {
    return driverSelected;
}