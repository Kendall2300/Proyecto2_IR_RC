//Include libraries
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QLabel>
#include "TestGenetico.h"
#include <QGridLayout>
#include <QFileDialog>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//Defining variables
int frows, fcols;
int ppn, plen;
int mrate = 2;
int c_index;
bool found = false;
uchar **best;
uchar ***dataa, ***ndata;
int *mpool;
bool sWhite = true;
bool eWhite = true;
int srow, scol, erow, ecol;
string readFile;

//Struct with methods for Genetic Algorithm
struct Species
{
public:
    int fit;
    int _rw, _cl;
    int index;

    //Defines the proc fitness
    void setFit(int refI)
    {
        int ref = refI - 7;
        int cnt = 0;
        for (int i = 0; i < _rw; i++)
        {
            for (int j = 0; j < _cl; j++)
            {
                if (dataa[index][i][j] == best[ref][j])
                    cnt++;
            }
        }
        fit = 1000 * cnt / (_rw * _cl);
        fit = (fit * fit) / 1000;
    }

    //Places random colors per pixels
    void allocate(int rw, int cl)
    {
        _rw = rw;
        _cl = cl;
        index = c_index;
        for (int i = 0; i < _rw; i++)
            if(i > srow && i < erow){
                for (int j = 0; j < _cl; j++) {
                    if (j > scol && j < ecol) {
                        dataa[c_index][i][j] = rand() % 256;
                    }
                    else {
                        dataa[c_index][i][j] = best[i][j];
                    }
                }
            }
            else{
                for (int j = 0; j < _cl; j++) {
                    dataa[c_index][i][j] = best[i][j];
                }
            }
        c_index++;
    }

    //Duplicates the Mat
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

    //Depending on the fitness it randomizes the color of certain pixel
    void mutate()
    {
        for (int i = 0; i < _rw; i++)
        {
            if (i > srow && i < erow){
                for (int j = 0; j < _cl; j++)
                {
                    if(j > scol && j < ecol){
                        if (rand() % 100 < mrate)
                            ndata[index][i][j] = rand() % 256;
                    }
                }
            }
        }
    }
};

//Values certain pixels with the reference pixels
void breed(int place, Species a, Species b, int refI)
{
    int ref = refI - 7;
    for (int i = 0; i < frows; i++)
    {
        for (int j = 0; j < fcols; j++)
        {
            if ((dataa[a.index][i][j] == best[ref][j]) || (dataa[b.index][i][j] == best[ref][j]))
            {
                if (rand() % 10 == 0)
                    ndata[place][i][j] = best[ref][j];
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

//Return fitness
bool sortRule(Species a, Species b)
{
    return a.fit > b.fit;
}

//Main function of Genetic Algorithm
int TestGenetic(){
    srand(time(NULL));


    Mat target, proc;
    target = imread(readFile, 0);
    namedWindow("Display Image", WINDOW_AUTOSIZE);

    proc = target;

    frows = target.rows;
    fcols = target.cols;
    Species *ppl;

    cout << fcols << "  x  " << frows << "  pixeles" << endl;

    //  Get white
    Mat OutImg4;
    inRange(target, Scalar(240, 240, 240), Scalar(255, 255, 255) , OutImg4);

    int wrows = OutImg4.rows;
    int wcols = OutImg4.cols;


    for (int i = 0; i < wrows; i++)
    {
        for (int j = 0; j < wcols; j++)
        {
            if(sWhite){
                if(OutImg4.at<uchar>(i,j) == 255){
                    srow = i;
                    scol = j;
                    cout << srow << " & " << scol << endl;
                    sWhite = false;
                }
            }
        }
    }

    for (int i = wrows-1; i > 0; i--)
    {
        for (int j = wcols-1; j > 0; j--)
        {
            if(eWhite){
                if(OutImg4.at<uchar>(i,j) == 255){
                    erow = i;
                    ecol = j;
                    cout << erow << " & " << ecol << endl;
                    eWhite = false;
                }
            }
        }
    }
//    End get white

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
//    std::cin >> ppn;
    ppn = 80;
    mpool = new int[ppn * (ppn + 1) / 2];

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
    for (int i = 0; i < ppn; i++)
    {
        ppl[i].allocate(frows, fcols);
        ppl[i].setFit(srow);
    }
    while (!found)
    {
        for (int i = 0; i < ppn; i++)
        {
            ppl[i].setFit(srow);
            if (ppl[i].fit > 990)
                found = true;
        }
        std::sort(ppl, ppl + ppn, sortRule);
        std::cout << ppl[0].fit << '\n';
        ppl[0].copyImg(proc);
        imshow("Display Image", proc);
        waitKey(5);

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
            breed(i, ppl[mpool[a]], ppl[mpool[b]], srow);
        }
        for (int i = 0; i < ppn; i++)
            ppl[i].mutate();
        swap(dataa, ndata);
    }
    delete dataa;
    delete ndata;
    return 0;
}
//Defining the Main Window appearance
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

//Loading image file from main directory
void PlusMinus::OnPlus() {

    QString filename= QFileDialog::getOpenFileName(this, tr("Chose"), "", tr("Images(*.png *.jpg *.jpeg *.gif)"));
    readFile = filename.toStdString();
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
//Execute TestGenetic() for interface
 void PlusMinus::genetic(){
    TestGenetic();
}

//Execute main Window of QT
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    PlusMinus window;

    window.resize(600, 600);
    window.setWindowTitle("Image Recovery");
    window.show();

    return app.exec();
}
