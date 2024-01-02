#include <iostream>
#include <curl/curl/curl.h>
#include <mysql/mysql.h>
#include <QApplication>
#include "../include/menu.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

int main(int argc , char * argv[]) {
    QApplication a(argc, argv);
    Menu menu;


    menu.createPage("F1 manager", 400, 600);

    menu.exec();
    return a.exec();

    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "Erreur cURL : %s\n", curl_easy_strerror(res));
        } else {
            std::cout << "cURL a fonctionné. Réponse :\n" << response << std::endl;
        }

        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Impossible d'initialiser cURL." << std::endl;
    }

    MYSQL* mysql = mysql_init(NULL);

    if (mysql) {
        const char* host = "localhost";
        const char* user = "user";
        const char* password = "pass";
        const char* database = "f1";

        if (mysql_real_connect(mysql, host, user, password, database, 0, NULL, 0)) {
            std::cout << "Connexion MySQL réussie." << std::endl;
            mysql_close(mysql);
        } else {
            std::cerr << "Erreur de connexion MySQL : " << mysql_error(mysql) << std::endl;
        }
    } else {
        std::cerr << "Impossible d'initialiser MySQL." << std::endl;
    }

    return 0;
}
