/**
 * @file main.cpp
 * @authors Kendall Martinez Carvajal (kendallmc@estudiantec.cr) && Jose Umana Rivera
 * @brief Este codigo contiene las llamadas para mostrar la interfaz grafica del proyecto
 *
 * @version 1.0
 *
 * @copyright Copyright (c) 2021
 */
#include "rent_car.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Rent_Car_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Rent_Car w;
    w.show();
    return a.exec();
}
