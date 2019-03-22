#include <iostream>
#include <math.h>
#include <cstdlib>
#include "complex.h"
using namespace std;

istream &operator>>(istream &in,numere_complexe &ob)
{

    in>>ob.real>>ob.imaginar;
    return in;

}
ostream &operator<<(ostream &out,const numere_complexe &ob)
{

    out<<ob.real<<" "<<ob.imaginar<<"i"<<endl;
    return out;

}
numere_complexe numere_complexe::operator=(const numere_complexe &ob)
{
    
    real=ob.real;
    imaginar=ob.imaginar;
    return *this;
    
}
numere_complexe numere_complexe::operator+(const numere_complexe &ob)
{

    this->real=this->real+ob.real;
    this->imaginar=this->imaginar+ob.imaginar;
    return *this;

}
numere_complexe numere_complexe::operator*(const numere_complexe &ob)
{

    this->real=(this->real)*ob.real-(ob.imaginar)*(this->imaginar);
    this->imaginar=(this->real)*ob.imaginar+(this->imaginar)*ob.real;
    return *this;

}
double numere_complexe::get_modul()
{

    double modul;
    modul=(double)sqrt(pow(real,2)+pow(imaginar,2));
    return modul;
}
v_complex::v_complex()
{
    this->dim=0;
    this->vector=NULL;
    this->vector_modul=NULL;
}
v_complex::v_complex(const v_complex & ob)//constr copiere
{

    this->dim=ob.dim;
    vector=new numere_complexe[ob.dim];
    for(int i = 0 ; i < dim ; i++)
    {
        vector[i]=ob.vector[i];
    }
    vector_modul=new double[ob.dim];
     for(int i = 0 ; i < dim ; i++)
    {
        vector_modul[i]=ob.vector_modul[i];
    }
    return *this;

}
v_complex::v_complex(const v_complex & ob)//constr copiere
{
  if(this!=&ob){
    this->dim=ob.dim;
    vector=new numere_complexe[ob.dim];
    for(int i = 0 ; i < dim ; i++)
    {
        vector[i]=ob.vector[i];
    }
    vector_modul=new double[ob.dim];
     for(int i = 0 ; i < dim ; i++)
    {
        vector_modul[i]=ob.vector_modul[i];
    }
        }
  

}

v_complex v_complex::operator=(const v_complex &ob)
{
    if(this!=&ob)
    {
        if(vector!=NULL) 
        {
            delete[]vector;
            delete[]vector_modul;
        }
        this->dim=ob.dim;
    vector=new numere_complexe[ob.dim];
    for(int i = 0 ; i < dim ; i++)
    {
        vector[i]=ob.vector[i];
    }
    vector_modul=new double[ob.dim];
     for(int i = 0 ; i < dim ; i++)
    {
        vector_modul[i]=ob.vector_modul[i];
    }
        
    }
    return *this;
}
v_complex::~v_complex()
{
  if(dim!=0)
   {
   delete[] this->vector;
   delete[] this->vector_modul;
   }
}
istream &operator>>(istream &in,v_complex &ob)
{

  in>>ob.dim;
  ob.vector = new numere_complexe[ob.dim];
  int i;
  for(i = 0 ; i < ob.dim ; i++)
  {
      in>>(ob.vector[i]);
  }
return in;

}
ostream &operator<<(ostream &out,const v_complex &ob)
{

    int i;
    for(i = 0 ; i < ob.dim ;i++)
    {
        out<<ob.vector[i];
    }
    return out;

}
void v_complex::set_modul(v_complex &ob)
{

  ob.vector_modul=new double[ob.dim];
    int i;
    for(i = 0 ; i < ob.dim ; i++)
    {

        ob.vector_modul[i]=ob.vector[i].get_modul();

    }
}
void v_complex::sort(v_complex &ob)
{

    for(int i = 0 ; i < ob.dim; i++)
    {
        for(int j = i+1 ; j < ob.dim ;j++)
        {
            if(ob.vector_modul[i]>ob.vector_modul[j])
            {
                swap(ob.vector[i],ob.vector[j]);
                swap(ob.vector_modul[i],ob.vector_modul[j]);

            }
        }
    }

}
numere_complexe v_complex::suma()
{

    numere_complexe op;
    op=vector[0];
    for(int i = 1 ; i < dim ;i++)
      op+vector[i];

    return op;

}
numere_complexe v_complex::operator*(const v_complex &ob1)
{

    numere_complexe op;
    op=vector[0]*ob1.vector[0];
    for(int i = 1; i < ob1.dim ;i++)
        op+(ob1.vector[i]*vector[i]);
    return op;
}
int v_complex::verif(const v_complex &ob1)
{
    if(dim!=ob1.dim) return -1;
    return 1;
}
int main()
{
   int cerinta;
   numere_complexe ob1,ob2;
   v_complex op1,op2,op3;
   cin>>cerinta;
   if(cerinta==1)
   {

    cout<<"numar complex 1:\n";
    cin>>ob1;
    cout<<"Modulul este "<<ob1.get_modul();
    cout<<"\nnumar complex 2:\n";
    cin>>ob2;
    cout<<"suma "<<ob1+ob2<<"\n";
    cout<<"produs"<<ob1*ob2<<"\n";

   }
   else{

     cout<<"vector complex 1\n";
     cin>>op1;
     op1.set_modul(op1);
     op1.sort(op1);
     cout<<"vector sortat "<<op1<<"\n";
     cout<<"suma "<<op1.suma()<<"\n";
     cout<<"vector complex 2\n";
     cin>>op2;
     if(op1.verif(op2)<0) cout<<"nu au aceleasi dimensiuni";
     else cout<<op1*op2;
       }
}
