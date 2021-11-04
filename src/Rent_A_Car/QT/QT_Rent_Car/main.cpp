#include "rent_car.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QT_Rent_Car_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Rent_Car w;
    w.show();*/

    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout<<"Ingrese el numero de ciudades (maximo 15): "<<Qt::endl;

    QString number_city=qin.readLine();

    qout<<"Se ingreso: "<< number_city <<"\n";

    qout.flush();
    return a.exec();
}
