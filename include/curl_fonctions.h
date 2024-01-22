/*
 * Fichier : curl_fonctions.h
 * Description: Fichier d'en-tête de curl_fonctions.c
 */

#ifndef F1_GAME_CURL_FONCTIONS_H
#define F1_GAME_CURL_FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl/curl.h>

int perform_request(const char *url);


#endif //F1_GAME_CURL_FONCTIONS_H
