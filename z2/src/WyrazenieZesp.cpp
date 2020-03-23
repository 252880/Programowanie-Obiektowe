#include "WyrazenieZesp.hh"
#include <iostream>
#include <cstdlib>
 

/*Przeciazenie operatora >> dla klasy WyrazenieZesp  */

 
std::istream & operator >> (std::istream & strm, WyrazenieZesp & wyraz){
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
LZespolona operacja( WyrazenieZesp & wyraz){ 
  LZespolona wynik;
  switch(wyraz.Op){   /*Sprawdza w zaleznosci od parametru w1.Op jakie dzialanie trzeba wykonac oraz je wykonuje */
  case 0:
    wynik = operator +(wyraz.Arg1,wyraz.Arg2);
    break;
  case 1:
    wynik = operator -(wyraz.Arg1,wyraz.Arg2);
    break;
  case 2:
    wynik = operator *(wyraz.Arg1,wyraz.Arg2);
    break;
  case 3:
    try{
      wynik = operator /(wyraz.Arg1,wyraz.Arg2);
    }                                      /* Obsluga wyjatkow w przypadku dzielenia przez 0*/
    catch (const char* msg) {
      std::cout << msg;
      exit(0);    
    }                                                                                                                                                                        break;
}
return wynik;
}

/* Przeciazenie operatora << dla klasy WyrazenieZesp */  
std::ostream & operator << (std::ostream & strm, WyrazenieZesp & w1){
  char znak;
  switch(w1.Op){
  case 0: znak='+';
    break;
  case 1: znak='-';
    break;
  case 2: znak='*';
    break;
  case 3: znak='/';
    break;
  }



  return strm<<w1.Arg1<<znak<<w1.Arg2;


}
