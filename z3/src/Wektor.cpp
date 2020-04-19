#include "Wektor.hh"
#include<iostream>
#include<cmath>
 
/* Konstruktory */


Wektor::Wektor()                           // ustawienie wszystkich skladowych wektora na zera
{

  for(int x=0;x<ROZMIAR;x++)           
    (*this)[x]=0;
}



Wektor::Wektor(double * tab)           // ustawienie odpowiednich skladowych wektora elementami tablicy
{
  
  for(int x=0;x<ROZMIAR;x++)           
    (*this)[x]=tab[x];
}



Wektor::Wektor(double x,double y,double z)          // konstruktor przyjmujacy 3 argumenty typu double
{
  (*this)[0] = x;
  (*this)[1] = y;
  (*this)[2] = z;
}



/* Metody operatorow arytmetycznych */



 Wektor  Wektor :: operator  + (const Wektor & W1) const {               // metoda dodajaca dwa wektory, zwracajaca wektor               
  Wektor W;
  for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]+W1[x];
}
  
  return W;
}



 Wektor  Wektor :: operator - ( const Wektor & W1)const{               // metoda odejmujaca dwa wektory, zwraca wektor
 Wektor W;  
  for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]-W1[x];
}

  return W;
}



double Wektor :: operator * (const Wektor & W1) const{                     // metoda mnozaca dwa wektory, zwraca wektor
  double  i=0;
 
   for(int x=0;x<ROZMIAR;x++){
    
    i+= (*this)[x]*W1[x];
}

  return i;
}



 Wektor  Wektor :: operator * ( double li)const{                      // metoda mozaca wektor z liczba typu double, zwraca wektor
Wektor W;

 for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]*li;
}

  return W;
}



double Wektor :: dlugosc () const{                                     // metoda liczaca dlugosc wektora, zwraca liczbe typu double 
  double i=0;

  for(int x=0;x<ROZMIAR;x++){
    i+=(*this)[x]*(*this)[x];
}
  i=sqrt(i);
  
  return i;
}



/* Metody Getter i Setter */


const double & Wektor :: operator[] (int index)const { 
  if (index < 0 || index >= ROZMIAR){ 
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
}
  else{
    return this->tab[index];
  }
}


double & Wektor :: operator[] (int index) {


  if (index < 0 || index >= ROZMIAR)
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }
  else{
  return this->tab[index];
  }
  }


/*  Przeciazenia in i out */

std::ostream & operator << (std::ostream & strm, const Wektor & W1){    // Przeciazenie out wypisuje na ekran skladowe wektora


  for(int i=0;i<ROZMIAR;i++){
    
    strm<<W1[i]<<" ";
}
  return strm;
}


std::istream & operator >> (std::istream & strm, Wektor & W1){           // Przeciazenie in pobiera od uzytkownika skladowe wektora

  
  for(int i=0;i<ROZMIAR;i++){
    strm>>W1[i];
  }
  return strm;
}
