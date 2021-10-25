//
// Created by dlurena24 on 24/10/21.
//

#include "Species.h"
#include <opencv2/core/hal/interface.h>
#include <cstdlib>


uchar **best;
uchar ***data, ***ndata;
int mrate = 2;
int c_index;

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

    void allocate(int rw, int cl)
    {
        _rw = rw;
        _cl = cl;
        index = c_index;
        for (int i = 0; i < _rw; i++)
            for (int j = 0; j < _cl; j++)
                data[c_index][i][j] = rand() % 256;
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
            for (int j = 0; j < _cl; j++)
            {
                if (rand() % 100 < mrate)
                    ndata[index][i][j] = rand() % 256;
            }
        }
    }
};
