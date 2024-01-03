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

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Menu menu;

    menu.show();

    return a.exec();
}
