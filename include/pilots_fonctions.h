/*
 * Fichier : pilotes_fonctions.h
 * Description: Fichier d'en-tête de pilotes_fonctions.c
 */

#ifndef F1_PROJECT_PILOTS_FUNCTIONS_H
#define F1_PROJECT_PILOTS_FUNCTIONS_H

#include "start.h"
#include "mysql.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DRIVERS_NUMBER 20

typedef struct Pilots {
    char nom[20];
    int courses;
    int victoires;
    int deuxiemes;
    int troisiemes;
    int podiums;
    int poles;
    int laps;
    float points;
} Pilots;

void savePilot(int id);
int getPilot();
Pilots getDriverData(int id);
int initAllDrivers(Pilots pilots[]);




#endif //F1_PROJECT_PILOTS_FUNCTIONS_H