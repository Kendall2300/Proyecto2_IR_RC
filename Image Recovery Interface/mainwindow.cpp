//
// Created by gabriel on 3/11/21.
//
#include "mainwindow.h"
#include <QGridLayout>
#include <QFileDialog>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


PlusMinus::PlusMinus(QWidget *parent)
        : QWidget(parent) {

    auto *addBtn = new QPushButton("Subir Imagen", this);
    auto *closeBtn = new QPushButton("Cerrar", this);
    auto *runBtn = new QPushButton("Correr algoritmo", this);
    lbl = new QLabel("", this);

    auto *grid = new QGridLayout(this);
    grid->addWidget(addBtn, 0, 0);
    grid->addWidget(closeBtn, 2, 0);
    grid->addWidget(runBtn, 1, 0);
    grid->addWidget(lbl, 1, 2);

    setLayout(grid);

    connect(addBtn, &QPushButton::clicked, this, &PlusMinus::OnPlus);
    connect(runBtn, &QPushButton::clicked, this, &PlusMinus::genetic);
    connect(closeBtn, &QPushButton::clicked, this, &QApplication::quit);
}

void PlusMinus::OnPlus() {

    QString filename= QFileDialog::getOpenFileName(this, tr("Chose"), "", tr("Images(*.png *.jpg *.jpeg *.gif)"));
    if (QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool vallid = image.load(filename);
        if (vallid)        {
            image = image.scaledToWidth(lbl->width(), Qt::SmoothTransformation);
            lbl->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            // Error
        }
    }
}



int frows, fcols;
int ppn, plen;
int mrate = 2;
int c_index;
bool found = false;
uchar **best;
uchar ***dataa, ***ndata;
int *mpool;

struct Species
{
public:
    int fit;
    int _rw, _cl;
    int index;

    void setFit(int rw, int cl)
    {
        _rw = rw;

        _cl = cl;

        cout << "si" << endl;
        int cnt = 0;
        cout << "si" << endl;
        for (int i = 0; i < _rw; i++)
        {
            cout << "si" << endl;
            for (int j = 0; j < _cl; j++)
            {
                cout << "si" << endl;
                if (dataa[index][i][j] == best[i][j])
                    cnt++;
                cout << "si" << endl;
            }
        }
        fit = 1000 * cnt / (_rw * _cl);
        fit = (fit * fit) / 1000;
    }

    void allocate(int rw, int cl)
    {

        _rw = rw;

        _cl = cl;

        index = c_index;

        for (int i = 0; i < _rw; i++)

            for (int j = 0; j < _cl; j++)
                dataa[c_index][i][j] = rand() % 256;

        c_index++;
    }

    void copyImg(Mat m)
    {
        for (int i = 0; i < m.rows; i++)
        {
            uchar *lin = m.ptr(i);
            for (int j = 0; j < m.cols; j++)
            {
                lin[j] = (uchar)dataa[index][i][j];
            }
        }
    }

    void mutate()
    {
        for (int i = 0; i < _rw; i++)
        {
            for (int j = 0; j < _cl; j++)
            {
                if (rand() % 100 < mrate)
                    ndata[index][i][j] = rand() % 256;
            }
        }
    }
};

void breed(int place, Species a, Species b)
{
    for (int i = 0; i < frows; i++)
    {
        for (int j = 0; j < fcols; j++)
        {
            if ((dataa[a.index][i][j] == best[i][j]) || (dataa[b.index][i][j] == best[i][j]))
            {
                if (rand() % 10 == 0)
                    ndata[place][i][j] = best[i][j];
                else
                    goto branch;
            }
            else
            {
                branch:
                if (rand() % 2 == 0)
                    ndata[place][i][j] = dataa[a.index][i][j];
                else
                    ndata[place][i][j] = dataa[b.index][i][j];
            }
        }
    }
}

bool sortRule(Species a, Species b)
{
    return a.fit > b.fit;
}

int genetic1()
{
    cout << "si" << endl;
    srand(time(NULL));

    Mat target, proc;
    target = imread("prueba.png", 0);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    cout << "si" << endl;

    proc = target;
    frows = target.rows;
    fcols = target.cols;
    Species *ppl;

    best = new uchar *[frows];
    for (int i = 0; i < frows; i++)
    {
        best[i] = new uchar[fcols];
    }
    for (int i = 0; i < frows; i++)
    {
        uchar *lin = target.ptr(i);
        for (int j = 0; j < fcols; j++)
        {
            best[i][j] = (uchar)lin[j];
        }
    }
    ppn = 80;
    mpool = new int[ppn * (ppn + 1) / 2];
    cout << "si" << endl;
    dataa = new uchar **[ppn + 10];
    for (int i = 0; i < ppn + 10; i++)
    {
        dataa[i] = new uchar *[frows];
        for (int j = 0; j < frows; j++)
            dataa[i][j] = new uchar[fcols];
    }
    ndata = new uchar **[ppn + 10];
    for (int i = 0; i < ppn + 10; i++)
    {
        ndata[i] = new uchar *[frows];
        for (int j = 0; j < frows; j++)
            ndata[i][j] = new uchar[fcols];
    }
    ppl = new Species[ppn];
    cout << "si" << endl;


    for (int i = 0; i < ppn; i++)
    {
        ppl[i].allocate(frows, fcols);
        cout << "si" << endl;
        ppl[i].setFit(frows, fcols);
        cout << "si" << endl;
    }
    while (!found)
    {
        for (int i = 0; i < ppn; i++)
        {
            ppl[i].setFit(frows, fcols);
            if (ppl[i].fit > 807)
                found = true;
        }
        cout << "si" << endl;
        std::sort(ppl, ppl + ppn, sortRule);
        std::cout << ppl[0].fit << '\n';
        ppl[0].copyImg(proc);
        imshow("Display Image", proc);
        waitKey(5);
        cout << "si" << endl;
        if (found)
            break;

        plen = 0;
        //create mating pool
        for (int i = 0; i < ppn; i++)
        {
            for (int j = 0; j < ppn - i; j++)
            {
                mpool[plen] = i;
                plen += 1;
            }
        }
        for (int i = 0; i < ppn; i++)
        {
            int a = rand() % plen, b = rand() % plen;
            breed(i, ppl[mpool[a]], ppl[mpool[b]]);
        }
        for (int i = 0; i < ppn; i++)
            ppl[i].mutate();
        swap(dataa, ndata);
    }
    delete dataa;
    delete ndata;
    return 0;

}


void PlusMinus::genetic(){
    genetic1();
}