#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
 
using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

int main()
{


  UkladRownanL W;

  cout << endl << " Start programu " << endl << endl;

  
  std::cin >> W;

  std::cout<<W;
  
  cout << endl << "Koniec programu " << endl << endl ;
      }
