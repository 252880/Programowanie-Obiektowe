#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


class Wektor {

  double tab[ROZMIAR];

public:

  Wektor ();


  Wektor(double x, double y, double z);
  Wektor(double * tab);

 Wektor operator + (const  Wektor & W1) const;
 Wektor  operator - (const Wektor & W1)const;
 double operator * (const Wektor & W1)const;
 Wektor  operator * (double li)const;

double dlugosc() const;

const double & operator [] (int index) const;
 double & operator [] (int index);

  
};

  std::istream& operator >> (std::istream &strm, Wektor &W1);
  std::ostream& operator << (std::ostream &strm, const Wektor &W1); 

#endif
