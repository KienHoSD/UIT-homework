#include <iostream>
#ifndef DIEM_H
#define DIEM_H

class Diem{
    private:
        double x,y;
    public:
        Diem(double x=0, double y=0);
        friend std::istream& operator >> (std::istream& is, Diem &u);
        friend std::ostream& operator << (std::ostream& os, Diem u);
        double kc(Diem u);
        double dientich(Diem u, Diem v);
        double chuvi(Diem u, Diem v);
};

#endif // DIEM_H
