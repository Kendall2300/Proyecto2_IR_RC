#include "graph_view.h"
#include "ui_graph_view.h"
#include <Grafo.h>
#include <iostream>

graph_view::graph_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph_view)
{
    ui->setupUi(this);
}

graph_view::~graph_view()
{
    delete ui;
}

void graph_view::on_label_listad_adyacencia_linkActivated(const QString &link)
{

}

