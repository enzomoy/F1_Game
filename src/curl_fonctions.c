//
// Created by enzom on 22/01/2024.
//

#include "../include/curl_fonctions.h"

int perform_request(const char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "Error: curl_easy_init() failed\n");
        exit(EXIT_FAILURE);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl);
    return 0;
}