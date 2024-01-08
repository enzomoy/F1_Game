#ifndef F1_PROJECT_PILOTS_FUNCTIONS_H
#define F1_PROJECT_PILOTS_FUNCTIONS_H

#include "start.h"
#include "mysql.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **getAllPilots();
void freePilots(char** pilots);
int selectPilot(int pilot);
int addScore(int playerId, int addedScore);

#endif //F1_PROJECT_PILOTS_FUNCTIONS_H