//
// Created by enzom on 06/01/2024.
//

#ifndef F1_GAME_CIRCUITS_FONCTIONS_H
#define F1_GAME_CIRCUITS_FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"

#define CIRCUITS_NUMBER 20

typedef struct CircuitData {
    int circuit_id;
    char nom[255];
    char pays[255];
    int nombre_de_tours;
    double longueur_circuit;
    double longueur_course;
    char type_circuit[50];
    int niveau_difficulte;
    int usure_pneus;
    int virages_gauche;
    int virages_droite;
    int longueur_ligne_droite;
    int zones_drs;
} CircuitData;

// Circuit prototypes
int initAllCircuits(CircuitData circuits[]);
CircuitData getCircuitData(int id);

#endif //F1_GAME_CIRCUITS_FONCTIONS_H
