#ifndef MENU_H
#define MENU_H

#include <QDialog>

class QPushButton;

class Menu : public QDialog {
Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    void createPage(const QString &nomFenetre, int largeur, int hauteur);
    void ShowMenu();

private:
    void createBoutonExit();
    void createBoutonStart();
    void createBoutonSettings();
};

#endif // MENU_H
