#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>
using namespace std;

class numere_complexe
{
    double real,imaginar;
    public:
    friend class v_complex;
    friend istream& operator>>(istream &in, numere_complexe &ob);
    friend ostream & operator <<(ostream &out,const numere_complexe &ob);
    numere_complexe operator+(const numere_complexe &ob);
    numere_complexe operator*(const numere_complexe &ob);
    double get_modul();
};
class v_complex
{
    int dim;
    numere_complexe *vector;
    double *vector_modul;
    public:
    v_complex();
    friend istream &operator>>(istream &in,v_complex &ob);
    friend ostream &operator<<(ostream &out,const v_complex &ob);
    void set_modul( v_complex &ob);
    void sort(v_complex &ob);
    numere_complexe suma();
    numere_complexe operator*(const v_complex &ob1);
    int verif(const v_complex &ob1);
    v_complex(const v_complex &ob);
    ~v_complex();
    
    v_complex operator=(const v_complex & ob);
};
#endif // COMPLEX_H_INCLUDED
