#ifndef F1_PROJECT_PILOTS_FUNCTIONS_H
#define F1_PROJECT_PILOTS_FUNCTIONS_H

#include "start.h"
#include "mysql.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char **getAllPilots();
int selectPilot(int pilot);
int addScore(int playerId, int addedScore);
Pilots getDriverData(int id);
int initAllDrivers(Pilots pilots[]);
extern int driverSelected;
void savePilot(int id);
int getPilot();
char **getAllPilots();

#endif //F1_PROJECT_PILOTS_FUNCTIONS_H