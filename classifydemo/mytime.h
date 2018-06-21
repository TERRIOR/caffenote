#ifndef MYTIME_H
#define MYTIME_H
#include "Windows.h"
#include <qstring>
#include <qfile>
class mytime
{
public:
    mytime();

    void TimerStart();

    double TimerFinish();
    void OutputToFile(QString fileName);
private:
    LARGE_INTEGER large_integer;
    __int64 IntStart;
    __int64 IntEnd;
    double DobDff;
    double DobMillseconds;

};


#endif // MYTIME_H
