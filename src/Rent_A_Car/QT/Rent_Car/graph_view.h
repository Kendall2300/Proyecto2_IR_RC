#ifndef GRAPH_VIEW_H
#define GRAPH_VIEW_H

#include <QDialog>

namespace Ui {
class graph_view;
}

class graph_view : public QDialog
{
    Q_OBJECT

public:
    explicit graph_view(QWidget *parent = nullptr);
    ~graph_view();

private:
    Ui::graph_view *ui;
};

#endif // GRAPH_VIEW_H
