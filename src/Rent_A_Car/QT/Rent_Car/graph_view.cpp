#include "graph_view.h"
#include "ui_graph_view.h"

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
