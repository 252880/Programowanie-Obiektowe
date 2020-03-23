#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <cstdlib>
#include<iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
public:
  float   re;    /*! Pole repezentuje czesc rzeczywista. */
  float   im;    /*! Pole repezentuje czesc urojona. */

  friend std::istream & operator >> (std::istream & strm, LZespolona &Z1);
  friend std::ostream & operator << (std::ostream & strm, const LZespolona &wynik);
  friend bool operator ==(LZespolona & w1, LZespolona & w2);  
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona utworz(float re, float im);

#endif
