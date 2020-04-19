#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"



class UkladRownanL{

  Macierz A;
  Wektor B;

public:
 
  Wektor oblicz() const;
  Wektor wekbledu()const;
  double dlugoscwek() const;
  
  UkladRownanL(){};
  UkladRownanL(Macierz AA, Wektor BB): A(AA), B(BB){};

  
  const Macierz & getmacierz() const;
  const Wektor & getwektor() const;


  void setmacierz(const Macierz & im);
  void setwektor(const Wektor & im);

};
  
std::istream& operator >> (std::istream &Strm, UkladRownanL &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm, const UkladRownanL &UklRown);


#endif
