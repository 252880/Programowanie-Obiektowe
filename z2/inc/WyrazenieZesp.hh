#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include <cstdlib>
#include<iostream>

#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
public:
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

friend std::istream & operator >> (std::istream & strm, WyrazenieZesp & wyraz);
};
 std::istream & operator >> (std::istream & strm, LZespolona &Z1);
 std::ostream & operator << (std::ostream & strm, const LZespolona &wynik);



/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


#endif
