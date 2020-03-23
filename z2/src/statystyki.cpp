#include"statystyki.hh"
#include<iostream>
#include<cstdlib>
/* Przeciazenie operatora << dla klasy statystyki*/
std::ostream & operator << (std::ostream & strm, statystyki &s){
  int z;
  z=s.calosc-s.zle;
  return strm<<"Ilosc pytan:"<<"\n"<<s.calosc<<"\n"<<"Ilosc zlych opwowiedzi:"<<"\n"<<s.zle<<"\n"<<"Ilosc dobrych odpowiedzi:"<<"\n"<<z<<"\n";
}
