#include "LZespolona.hh"
#include<string>
#include<iostream>
#include<cmath>

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
} 



/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *   Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re*Skl2.re)-(Skl1.im*Skl2.im);
  Wynik.im = (Skl1.re*Skl2.im)+(Skl1.im*Skl2.re);
  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  if(Skl2.re+Skl2.im==0){
    throw "Blad!! Dzielnik jest zerem!!\n";
  }

  else{
  Wynik.re = (Skl1.re*Skl2.re+Skl1.im*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  Wynik.im = (Skl2.re*Skl1.im-Skl1.re*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  return Wynik; 
  }
}

/*Tworzy liczbe zespolona */
LZespolona utworz(float re, float im){
  
  LZespolona liczba;

  liczba.re=re;
  liczba.im=im;

  return liczba;
}
/* Przeciazenie operatora >> dla  kalsy LZeolona oraz sprawdznie
czy  wprowadzone dane sa zgodne z przyjeta forma zapisywania
liczy zespolonej tzn.(x+yi). Bledny zapis skutkuje zatrzymaniem
sie programu i wypisaniem tekstu na strumieniu bledow "Blednie
wpisana liczba zaspolona!!"
*/
std::istream & operator >> (std::istream & strm, LZespolona &Z1){
  char znak,znak3,znak4;
  strm>>znak>>Z1.re>>Z1.im>>znak3>>znak4;
  if(znak!='('){
    strm.setstate(std::ios::failbit);
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
  return strm;                                                                                                                                                              }

/*Przeciazenie operatora << dla klasy Lzespolona*/
std::ostream & operator << (std::ostream & strm, const LZespolona & wynik) {
  strm<<'(';
  strm<<wynik.re;
  strm<<std::showpos<<wynik.im<<std::noshowpos;
  strm<<'i';
  strm<<')';
  return strm;
}
/* Przeciazenie operatora == dla dwoch parametrow klasy LZespolona */
bool operator ==(LZespolona & w1, LZespolona & w2){

  if( w1.re==w2.re&&w1.im==w2.im){
    std::cout<<"Wynik poprawny!!"<<"\n";
    return true;
  }
  else{                                                                  /* Sprawdzamy czy parametry sa sobie rowne. */
    std::cerr<<"Blad!! Sproboj ponownie:"<<"\n";                        /*  Jesli nie to zostaje wypisany odpowiedni tekst na strumieniu bledow  */
    std::cin>>w2;                                                      /*   Uzytkownik ma 3 szanse na wprowadzenie poprawnej odpowiedzi*/
    if( w1.re==w2.re&&w1.im==w2.im){                                  
    std::cout<<"Wynik poprawny!!"<<"\n";
    return true;
    }
    else{
      std::cerr<<"Blad!! Sproboj ponownie:"<<"\n";
      std::cin>>w2;
      if ( w1.re==w2.re&&w1.im==w2.im){
    std::cout<<"Wynik poprawny!!"<<"\n";
    return true;
      }
    else{
    std::cerr<<"Bald!! Poprawnym wynikiem jest:"<<"\n";
    return false;
}
      }
  }
} 
 
