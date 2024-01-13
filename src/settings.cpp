#include "../include/settings.h"
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>

Settings::Settings(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    QCheckBox *checkBox = createCheckBox("Fullscreen");
    layout->addWidget(checkBox);

    Xlen = new QLineEdit(this);
    layout->addWidget(Xlen);

    Ylen = new QLineEdit(this);
    layout->addWidget(Ylen);

    bool isChecked = isCheckBoxChecked();

    apply = createButton("Appliquer", this);
    apply->setProperty("class", "Appliquer");

    QPushButton *backButtonSettings = createButton("Back", this);
    backButtonSettings->setProperty("class", "backButtonSettings");
    layout->addWidget(backButtonSettings);

    connect(backButtonSettings, &QPushButton::clicked, this, &Settings::buttonBackClick);

}

////////////////////////////////////////////////////////////////////////////
QPushButton* Settings::createButton(const QString &text, QWidget *parent) {
    QPushButton *button = new QPushButton(text, parent);
    return button;
}

QCheckBox* Settings::createCheckBox(const QString &labelText) {
    QCheckBox *checkBox = new QCheckBox(labelText);
    return checkBox;
}

bool Settings::isCheckBoxChecked() const {
    QCheckBox *checkBox = findChild<QCheckBox*>();
    if (checkBox) {
        return checkBox->isChecked();
    }
    return false;
}

QString Settings::getXlen() const {
    return Xlen->text();
}

QString Settings::getYlen() const {
    return Ylen->text();
}

void Settings::buttonBackClick() {
    emit backClicked();
}
