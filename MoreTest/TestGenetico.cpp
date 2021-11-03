#include "TestGenetico.h"

//#include opencv2/opencv.hpp
//#include time.h
#include <opencv2/opencv.hpp>
//#include algorithm

using namespace cv;
using namespace std;


int frows, fcols;
int ppn, plen;
int mrate = 2;
int c_index;
bool found = false;
uchar **best;
uchar ***data, ***ndata;
int *mpool;

struct Species
{
public:
    int fit;
    int _rw, _cl;
    int index;

    void setFit()
    {
        int cnt = 0;
        for (int i = 0; i < _rw; i++)
        {
            for (int j = 0; j < _cl; j++)
            {
                if (data[index][i][j] == best[i][j])
                    cnt++;
            }
        }
        fit = 1000 * cnt / (_rw * _cl);
        fit = (fit * fit) / 1000;
    }

//    Se modifica
    void allocate(int rw, int cl)
    {
        _rw = rw;
        _cl = cl;
        index = c_index;
        for (int i = 0; i < _rw; i++)
//            for (int j = 0; j < _cl; j++)
//                data[c_index][i][j] = rand() % 256;
            if(i > 50 && i < 75){
                for (int j = 0; j < _cl; j++)
                    data[c_index][i][j] = rand() % 256;
            }
            else{
                for (int j = 0; j < _cl; j++) {
                    data[c_index][i][j] = best[i][j];
                }
            }
        c_index++;
    }

    void copyImg(Mat m)
    {
        for (int i = 0; i < m.rows; i++)
        {
            uchar *lin = m.ptr(i);
            for (int j = 0; j < m.cols; j++)
            {
                lin[j] = (uchar)data[index][i][j];
            }
        }
    }

    void mutate()
    {
        for (int i = 0; i < _rw; i++)
        {
            if (i > 50 && i < 75){
                for (int j = 0; j < _cl; j++)
                {
                    if (rand() % 100 < mrate)
                        ndata[index][i][j] = rand() % 256;
                }
            }
//            for (int j = 0; j < _cl; j++)
//            {
//                if (rand() % 100 < mrate)
//                    ndata[index][i][j] = rand() % 256;
//            }
        }
    }
};

void breed(int place, Species a, Species b)
{
    for (int i = 0; i < frows; i++)
    {
        for (int j = 0; j < fcols; j++)
        {
            if ((data[a.index][i][j] == best[i][j]) || (data[b.index][i][j] == best[i][j]))
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
                    ndata[place][i][j] = data[a.index][i][j];
                else
                    ndata[place][i][j] = data[b.index][i][j];
            }
        }
    }
}

bool sortRule(Species a, Species b)
{
    return a.fit > b.fit;
}

int main(){srand(time(NULL));

    Mat target, proc;
    target = imread("zz.png", 0);
    namedWindow("Display Image", WINDOW_AUTOSIZE);

//    --------------------------------------------------------------
//      Test

//    Mat target, proc;
//    target = imread("zz.png", 1);
//
//    rectangle(target, Point(50,25), Point(100, 75), Scalar(255,0,0));
//
//    namedWindow("Display Image", WINDOW_AUTOSIZE);
//
//    imshow("Display Image", target);
//    waitKey(0);


//      -------------       ----------------        --------------    ------------ Masks
////  BGR
////  Get red
//    Mat OutImg, OutRed;
//    inRange(target, Scalar(0, 0, 95), Scalar(150, 150, 255) , OutImg);
////    bitwise_and(OutImg, target, OutRed);
//
////  Get blue
//    Mat OutImg2;
//    inRange(target, Scalar(100, 0, 0), Scalar(255, 210, 210) , OutImg2);
//
////  Get green
//    Mat OutImg3;
//    inRange(target, Scalar(0, 100, 0), Scalar(100, 255, 100) , OutImg3);
//
////  Get white
//    Mat OutImg4;
//    inRange(target, Scalar(240, 240, 240), Scalar(255, 255, 255) , OutImg4);
//
//    int x1, x2, x3;
//    x1 = countNonZero(OutImg);
//    x2 = countNonZero(OutImg2);
//    x3 = countNonZero(OutImg3);
//
//    if(x1>x2+x3){
//        cout << "Red" << endl;
//    }
//    if(x2>x1+x3){
//        cout << "Blue" << endl;
//    }
//    if(x3>x1+x2){
//        cout << "Green" << endl;
//    }
//
//    cout << x1 << "  " << x2 << "  " << x3;
//
//    namedWindow("Output Image", WINDOW_AUTOSIZE);
//    imshow("Output Image", OutImg3); //Cambia segun el color
//    waitKey(0);

//    --------------------------------------------------------------------- EndTest

    proc = target;

    frows = target.rows;
    fcols = target.cols;
    Species *ppl;

    cout << fcols << "  x  " << frows << "  pixeles" << endl;

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
//        if (i > 50 && i < 75){
//            uchar *lin = target.ptr(i);
//            for (int j = 0; j < fcols; j++)
//            {
//                best[i][j] = (uchar) lin[j];
//            }
//        }
    }
//    std::cin >> ppn;
    ppn = 75;
    mpool = new int[ppn * (ppn + 1) / 2];

    data = new uchar **[ppn + 10];
    for (int i = 0; i < ppn + 10; i++)
    {
        data[i] = new uchar *[frows];
        for (int j = 0; j < frows; j++)
            data[i][j] = new uchar[fcols];
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
        ppl[i].setFit();
    }
    while (!found)
    {
        for (int i = 0; i < ppn; i++)
        {
            ppl[i].setFit();
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
            breed(i, ppl[mpool[a]], ppl[mpool[b]]);
        }
        for (int i = 0; i < ppn; i++)
            ppl[i].mutate();
        swap(data, ndata);
    }
    delete data;
    delete ndata;
    return 0;
}
