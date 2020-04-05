#ifndef MACIERZ_HH
#define MACIERZ_HH

#include"Wektor.hh"
#include "rozmiar.h"
#include <iostream>
 


class Macierz {

  Wektor tab[ROZMIAR];

public:

 Macierz();
 Macierz(Wektor a1, Wektor a2, Wektor a3);
 Macierz( const Wektor *W2);  

  const Wektor & operator[] (int index) const;
  Wektor & operator[] (int index);


  const Macierz  transpozycja() const;

     Wektor operator * (const Wektor &W3)const;
     Macierz operator * (const Macierz & W3)const;
     Macierz operator + (const Macierz  &W3)const;
     Macierz operator - (const Macierz  &W3)const;
     Macierz operator * (double l)const;


  const Macierz Zmienkolumny(int x,int y) const;
  const Macierz Zmienwiersze(int x, int y) const;

  double wyznacznikGauss() const;

     

};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &strm, Macierz &M);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &strm, const Macierz &M);


#endif
