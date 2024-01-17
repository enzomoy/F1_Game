//
// Created by enzom on 29/12/2023.
//

#include "../include/config.h"

Config globalConfig;

int createConfig() {

    /*
     * Permet la création du fichier de configuration s'il n'existe pas
     * Retourne 0 si le fichier a été créé ou s'il existe déjà
     * Retourne 1 si le fichier n'a pas pu être créé
     * Retourne 2 si les lignes par défaut n'ont pas pu être ajoutées
     */

    char *filename = (char *)"../config.txt";

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        file = fopen(filename, "w");
        if (file == NULL) {
            return 1;
        }

        if (addBaseConfig(filename) == 1) {
            return 2;
        }
    }


    return 0;
}

int addBaseConfig(char *filename) {

    /*
     * Ajoute les lignes par défaut dans le fichier de configuration
     * Retourne 0 si aucune erreur n'est survenue
     * Retourne 1 si le fichier n'a pas pu être ouvert
     * Retourne 2 si l'écriture dans le fichier a échoué
     */

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        return 1;
    }

    if (fprintf(file, "fullscreen=false\n") < 0) {
        perror("Erreur lors de l'écriture dans le fichier de configuration");
        fclose(file);
        return 2;
    }

    if (fprintf(file, "width=800\n") < 0) {
        perror("Erreur lors de l'écriture dans le fichier de configuration");
        fclose(file);
        return 2;
    }

    if (fprintf(file, "height=600\n") < 0) {
        perror("Erreur lors de l'écriture dans le fichier de configuration");
        fclose(file);
        return 2;
    }

    fclose(file);
    return 0;
}

int readConfiguration(Config *config) {

    /*
     * Permet de lire le fichier de configuration et le stocker dans la structure Config
     * Retourne 0 si la lecture s'est bien déroulée
     * Retourne 1 si le fichier n'a pas pu être ouvert
     */

    FILE *file = fopen("../config.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier config.txt\n");
        return 1;  // Indiquer une erreur
    }

    char line[100];  // Vous pouvez ajuster la taille en fonction de vos besoins

    while (fgets(line, sizeof(line), file) != NULL) {
        // Supprimer le caractère de saut de ligne à la fin de la ligne
        line[strcspn(line, "\n")] = 0;

        // Utiliser strtok pour diviser la ligne en clé et valeur
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (key != NULL && value != NULL) {
            if (strcmp(key, "fullscreen") == 0) {
                config->fullscreen = strToBool(value);
            } else if (strcmp(key, "width") == 0) {
                config->width = atoi(value);
            } else if (strcmp(key, "height") == 0) {
                config->height = atoi(value);
            } else {
                fprintf(stderr, "Clé inconnue dans le fichier de configuration : %s\n", key);
            }
        }
    }

    fclose(file);
    return 0;  // Indiquer le succès
}

int strToBool(char *str) {

    /*
     * Convertit une chaine de caractère en booléen
     * Retourne 1 si la chaine de caractère est égale à "true"
     * Retourne 0 si la chaine de caractère est égale à "false"
     * Retourne -1 si la chaine de caractère n'est pas égale à "true" ou "false"
     */

    if (strcmp(str, "true") == 0) {
        return 1;
    } else if (strcmp(str, "false") == 0) {
        return 0;
    } else {
        fprintf(stderr, "Erreur lors de la conversion de la chaine de caractère en booléen\n");
        return -1;
    }
}
