#include "../include/pilots_fonctions.h"

char **getAllPilots() {
    char **pilots = (char **)malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++) {
        pilots[i] = (char *)malloc(18 * sizeof(char));
    }

    strcpy(pilots[0], "Lewis Hamilton");
    strcpy(pilots[1], "Valtteri Bottas");
    strcpy(pilots[2], "Max Verstappen");
    strcpy(pilots[3], "Sergio Perez");
    strcpy(pilots[4], "Lando Norris");
    strcpy(pilots[5], "Daniel Ricciardo");
    strcpy(pilots[6], "Charles Leclerc");
    strcpy(pilots[7], "Carlos Sainz");
    strcpy(pilots[8], "Pierre Gasly");
    strcpy(pilots[9], "Yuki Tsunoda");
    strcpy(pilots[10], "Fernando Alonso");
    strcpy(pilots[11], "Esteban Ocon");
    strcpy(pilots[12], "Sebastian Vettel");
    strcpy(pilots[13], "Lance Stroll");
    strcpy(pilots[14], "Kimi Raikkonen");
    strcpy(pilots[15], "Antonio Giovinazzi");
    strcpy(pilots[16], "Mick Schumacher");
    strcpy(pilots[17], "Nikita Mazepin");
    strcpy(pilots[18], "George Russell");
    strcpy(pilots[19], "Nicholas Latifi");

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

    char ***pilots = getAllDriversInfo();
    printf("Vous avez selectionne le pilote %s\n", pilots[pilot][1]);

    if (addPlayer(pilots[pilot][1], 0) == 1) {
        return 1;
    }

    freeDriversInfo(pilots);
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
    }

    int lastScore = score;

    score += addedScore;

    printf("Le score du joueur %d est de %d (anciennement %d)\n", playerId, score, lastScore);

    if (setScore(playerId, score) == 1) {
        return 1;
    }

    return 0;
}
