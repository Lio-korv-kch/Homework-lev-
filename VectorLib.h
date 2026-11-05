#pragma once
#include <cmath>
#include <ostream>
#include <iostream>
using namespace std;

struct Vector{
double X;
double Y;
double Z;
};

ostream& operator << (ostream& os,const Vector& v){
  os << v.X << " " << v.Y << " " << v.Z;
  return os;
}

class DoubleVectors{
private:
   Vector vect1;
   Vector vect2;
public:
    DoubleVectors(){
    vect1 = {0.0 , 0.0 , 0.0};
    vect2 = {0.0 , 0.0 , 0.0};
    }
    DoubleVectors(Vector vectt1, Vector vectt2){
        vect1.X = vectt1.X;
        vect1.Y = vectt1.Y;
        vect1.Z = vectt1.Z;
        vect2.X = vectt2.X;
        vect2.Y = vectt2.Y;
        vect2.Z = vectt2.Z;
    }
    Vector vectorSum (Vector vect1,Vector vect2){
        Vector vectSum;
        vectSum.X = vect1.X + vect2.X;
        vectSum.Y = vect1.Y + vect2.Y;
        vectSum.Z = vect1.Z + vect2.Z;
        return vectSum;
    }

    Vector MultiplyVector (Vector vect1,double a){
        Vector MultipliedVector;
        MultipliedVector = {vect1.X * a, vect1.Y * a, vect1.Z * a};
        return MultipliedVector;
    }


    double VectorLength (Vector vect1){
        double vectLength = sqrt(pow(vect1.X,2) + pow(vect1.Y,2) + pow(vect1.Z,2));
        return vectLength;
    }

    double SkallrnoeProizvedenie (Vector vect1,Vector vect2){
        return vect1.X * vect2.X + vect1.Y * vect2.Y + vect1.Z * vect2.Z;
    }

    Vector VectorMultiplier (Vector vect1,Vector vect2){
        Vector vectMulti;
        vectMulti.X = vect1.Y * vect2.Z - vect1.Z * vect2.Y;
        vectMulti.Y = vect1.Z * vect2.X - vect1.X * vect2.Z;
        vectMulti.Z = vect1.X * vect2.Y - vect1.Y * vect2.X;
        return vectMulti;
    }
    void get_vector(Vector v){
        cout << v.X << " " << v.Y << " " << v.Z << endl;
    }
};
