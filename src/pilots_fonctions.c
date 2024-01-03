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