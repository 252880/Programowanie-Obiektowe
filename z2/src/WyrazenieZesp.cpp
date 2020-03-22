#include "WyrazenieZesp.hh"
#include <iostream>
#include <cstdlib>

/* Przeciazenie operatora >> dla  kalsy LZeolona oraz sprawdznie 
czy  wprowadzone dane sa zgodne z przyjeta forma zapisywania
liczy zespolonej tzn.(x+yi). Bledny zapis skutkuje zatrzymaniem
sie programu i wypisaniem tekstu na strumieniu bledow "Blednie
wpisana liczba zaspolona!!" 
 */  
std::istream & operator >> (std::istream & strm, LZespolona &Z1){
  char znak,znak1,znak3,znak4;
  strm>>znak>>Z1.re>>znak1>>Z1.im>>znak3>>znak4;
  if(znak!='('){
    strm.setstate(std::ios::failbit);
  }
  if(znak1=='-'){
    Z1.im=(-Z1.im);
  }
  if(znak3!='i'){
    strm.setstate(std::ios::failbit);
  }
  if(znak4!=')'){
    strm.setstate(std::ios::failbit);
  }

  if(strm.rdstate()==std::ios::failbit){
    std::cerr<<"Blednie wpisana liczba zespolona!!"<<"\n";
    exit(0);   
  }
  return strm; 
}
/*Przeciazenie operatora >> dla klasy WyrazenieZesp  */


std::istream & operator >> (std::istream & strm, WyrazenieZesp & wyraz) {
  char znak;
  strm >> wyraz.Arg1;
  strm >> znak;
  strm >> wyraz.Arg2;
  switch (znak) {
  case'+':wyraz.Op = Op_Dodaj;
    break;
  case'-':wyraz.Op = Op_Odejmij;
    break;
  case'*':wyraz.Op = Op_Mnoz;
    break;
  case'/':wyraz.Op = Op_Dziel;
    break;
  }
  return strm;
}
/*Przeciazenie operatora << dla klasy Lzespolona*/
std::ostream & operator << (std::ostream & strm, const LZespolona & wynik) {
  strm<<'(';
  strm<<wynik.re;
  strm<<std::showpos<<wynik.im<<std::noshowpos;
  strm<<'i';
  strm<<')';
  return strm;  
}
