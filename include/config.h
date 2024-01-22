/*
 * Fichier : config.h
 * Description: Fichier d'en-tête de config.c
 */

#ifndef F1_PROJECT_CONFIG_H
#define F1_PROJECT_CONFIG_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Config{
    // Fullscreen = 1 - Windowed = 0
    int fullscreen;
    int width;
    int height;
} Config;

extern Config globalConfig;

int createConfig();
int addBaseConfig(char *filename);
int readConfiguration(Config *config);
int strToBool(char *str);
int editConfig(Config *config, int fullscreen, int width, int height);
int deleteConfig();
int fillConfigWithStruct(Config *config);
#endif //F1_PROJECT_CONFIG_H
