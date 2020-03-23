#include <iostream>
#include"statystyki.hh"
#include "BazaTestu.hh"
#include <ctype.h>
#include <complex>
#include<string>
#include <cstdlib>




using namespace std;
int main(int argc, char **argv)
{
WyrazenieZesp   Pt;
  LZespolona   Odp;
  LZespolona Wynik;
  statystyki x;
  x.calosc=0;
  x.zle=0;
    
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }
   
  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
  }  
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  
  while (PobierzNastpnePytanie(&BazaT,&Pt)) {           /* Pobranie pytania z bazy*/

    x.calosc++;                                      /*licznik pytan */
   
    std::cout<<"Podaj wynik operacji:"<<"\n";                    
    std::cout<<Pt<<" "<<"Twoja odpowiedz:"<<"\n";                  /* Wyswietlenie pytania na ekranie*/
    std::cin>>Odp;                                  /*Pobranie odpowiedzi od uzytkowanika */
    Wynik=operacja(Pt);                             /* Wywolanie funkcji operacja i przypisanie wyniku do zmiennej Wynik*/                      
    if(( Wynik==Odp)==false){                       /* Sprawdzamy czy podany wynik jest prawidlowy jesli na ekranie pojawi sie poprawny wynik  */
      std::cout<<Wynik<<"\n";
      x.zle++;                                      /*licznik zlych odpowiedzi */
    }
  }   	
   
         cout << endl;
  cout << " Koniec testu" << endl;
  std::cout<<"Statystyki:"<<"\n";                   /*Wyswitlenie statystyki*/
  std::cout<<x;   
}


