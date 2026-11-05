#include <iostream>
#include "VectorLib.h"
using namespace std;

int main() {
    double t;
    Vector vect1, vect2;
    cin >> vect1.X >> vect1.Y >> vect1.Z >> vect2.X >> vect2.Y >> vect2.Z >> t;
    DoubleVectors field(vect1,vect2);
    cout << " X * Y = "  << field.SkallrnoeProizvedenie(vect1,vect2) << endl;
    cout << " X + Y = "  << (field.vectorSum(vect1,vect2))<< endl;
    cout << " X * t = "  << (field.MultiplyVector(vect1,t))<< endl;
    cout << " Y * t = "  << (field.MultiplyVector(vect2,t))<< endl;
    cout << " length(X) = " << field.VectorLength(vect1) << endl;
    cout << " length(Y) = " << field.VectorLength(vect2) << endl;
    cout << " X x Y = "  << (field.VectorMultiplier(vect1,vect2))<< endl;
}
