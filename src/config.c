/*
 * Fichier : config.c
 * Description: Fichier source de config.h
 */

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


    fclose(file);
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
    FILE *file = fopen("../config.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier config.txt\n");
        return 1;
    }

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;

        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (key != NULL && value != NULL) {
            if (strcmp(key, "fullscreen") == 0) {
                if (strcmp(value, "true") == 0) {
                    config->fullscreen = 1;
                } else if (strcmp(value, "false") == 0) {
                    config->fullscreen = 0;
                } else {
                    fprintf(stderr, "Erreur : La valeur de fullscreen n'est pas valide.\n");
                    fclose(file);
                    return 1;
                }
            } else if (strcmp(key, "width") == 0) {
                char *endptr;
                long int width = strtol(value, &endptr, 10);

                if (*endptr != '\0' || width < 0 || width > INT_MAX) {
                    fprintf(stderr, "Erreur : La valeur de width n'est pas un entier valide.\n");
                    fclose(file);
                    return 1;
                }

                config->width = (int)width;
            } else if (strcmp(key, "height") == 0) {
                char *endptr;
                long int height = strtol(value, &endptr, 10);

                if (*endptr != '\0' || height < 0 || height > INT_MAX) {
                    fprintf(stderr, "Erreur : La valeur de height n'est pas un entier valide.\n");
                    fclose(file);
                    return 1;
                }

                config->height = (int)height;
            } else {
                fprintf(stderr, "Clé inconnue dans le fichier de configuration : %s\n", key);
            }
        }
    }

    fclose(file);
    return 0;
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
        fprintf(stderr, "Erreur lors de la conversion de la chaine de caractère en bool\n");
        return -1;
    }
}

int editConfig(Config *config, int fullscreen, int width, int height) {

    /*
     * Permet de modifier les paramètres de la structure Config
     * Retourne 0 si la modification s'est bien déroulée
     * Retourne 1 si la modification a échouée
     */

    if (fullscreen != -1) {
        config->fullscreen = fullscreen;
    } else {
        fprintf(stderr, "Erreur lors de la modification du paramètre fullscreen\n");
        return 1;
    }

    if (width != -1) {
        config->width = width;
    } else {
        fprintf(stderr, "Erreur lors de la modification du paramètre width\n");
        return 1;
    }

    if (height != -1) {
        config->height = height;
    } else {
        fprintf(stderr, "Erreur lors de la modification du paramètre height\n");
        return 1;
    }

    if (fillConfigWithStruct(config) == 1) {
        fprintf(stderr, "Erreur lors de la modification du fichier de configuration\n");
        return 1;
    }

    return 0;
}

int fillConfigWithStruct(Config *config) {

        /*
        * Permet de remplir le fichier de configuration avec les paramètres de la structure Config
        * Retourne 0 si la modification s'est bien déroulée
        * Retourne 1 si la modification a échouée
        */

        if (deleteConfig() == 1) {
            fprintf(stderr, "Erreur lors de la suppression du fichier de configuration\n");
            return 1;
        }

        FILE *file = fopen("../config.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier config.txt\n");
            return 1;
        }

        if (fprintf(file, "fullscreen=%s\n", config->fullscreen ? "true" : "false") < 0) {
            perror("Erreur lors de l'écriture dans le fichier de configuration");
            fclose(file);
            return 1;
        }

        if (fprintf(file, "width=%d\n", config->width) < 0) {
            perror("Erreur lors de l'écriture dans le fichier de configuration");
            fclose(file);
            return 1;
        }

        if (fprintf(file, "height=%d\n", config->height) < 0) {
            perror("Erreur lors de l'écriture dans le fichier de configuration");
            fclose(file);
            return 1;
        }

        fclose(file);
        return 0;
}

int deleteConfig() {

    /*
     * Permet de supprimer le fichier de configuration
     * Retourne 0 si la suppression s'est bien déroulée
     * Retourne 1 si la suppression a échouée
     */

    if (remove("../config.txt") == 0) {
        return 0;
    } else {
        return 1;
    }
}