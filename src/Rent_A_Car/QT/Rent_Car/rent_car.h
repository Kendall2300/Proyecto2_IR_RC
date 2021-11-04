#ifndef RENT_CAR_H
#define RENT_CAR_H

#include <QMainWindow>
#include <graph_view.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Rent_Car; }
QT_END_NAMESPACE

class Rent_Car : public QMainWindow
{
    Q_OBJECT

public:
    Rent_Car(QWidget *parent = nullptr);
    ~Rent_Car();

private slots:
    void on_pushButton_aceptar_Cciudades_clicked();

private:
    Ui::Rent_Car *ui;
    graph_view *Lista_Adyacencia;
};
#endif // RENT_CAR_H
