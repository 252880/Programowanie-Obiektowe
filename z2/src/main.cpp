#include <iostream>
#include "BazaTestu.hh"
#include <ctype.h>
#include <complex>
#include<string>
#include <cstdlib>

/*
int main(int argc, char **argv)
{
  const char *c;
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
  int z=0;
  int y=0;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona   Odp;
  LZespolona Wynik;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    z++;
    switch(WyrZ_PytanieTestowe.Op){
    case 0:
      c="+";  
  Wynik=operator +(WyrZ_PytanieTestowe.Arg1,WyrZ_PytanieTestowe.Arg2);
      break;

    case 1:
      c="-";
      Wynik=operator -(WyrZ_PytanieTestowe.Arg1,WyrZ_PytanieTestowe.Arg2);
      break;

    case 2:
      c="*";
      Wynik=operator *(WyrZ_PytanieTestowe.Arg1,WyrZ_PytanieTestowe.Arg2);
      break;

    case 3:
      c="/";
	
      try{ 
      Wynik=operator /(WyrZ_PytanieTestowe.Arg1,WyrZ_PytanieTestowe.Arg2);
      }
      catch (const char* msg) {
	cout << msg;

	cout << endl;
      return 0;
      }
      break;
    }      
    
    
    char a[3];

      cout << WyrZ_PytanieTestowe.zad<<"."<<" "<<"Podaj wynik operacji:";
      cout <<"("<<WyrZ_PytanieTestowe.Arg1.re<<::showpos<<WyrZ_PytanieTestowe.Arg1.im<<::noshowpos;
      cout<<"i"<<")"<<c<<"("<<WyrZ_PytanieTestowe.Arg2.re<<::showpos<<WyrZ_PytanieTestowe.Arg2.im<<::noshowpos<<"i"<<")" << endl;
      cout<<"Twoja odpowiedz:";  
      cin >>a[1]>> Odp.re>>::showpos>>Odp.im>>::noshowpos>>a[0]>>a[2];

      if(cin.fail()){
	cerr<<"Blad! Wprowadzono niepoprawnie liczbe zespolona! Wlacz program ponownie!";
	y++;
	break;
      }
	
 	 if(a[1]=='('&&Wynik.re==Odp.re&&Wynik.im==Odp.im&&a[0]=='i'&&a[2]==')'){
	
	cout<<"Odpowiedz poprawna. \n";
       
	}
      else{
	cerr<<"Blad. Sprobuj jeszcze raz:";
        cin>>a[1]>>Odp.re>>Odp.im>>a[0]>>a[2];
	
       if(a[1]=='('&&Wynik.re==Odp.re&&Wynik.im==Odp.im&&a[0]=='i'&&a[2]==')'){

	cout<<"Odpowiedz poprawna. \n";
	
       }
      else{
	  cerr<<"Blad. Sprobuj jeszcze raz:";
	  cin>>a[1]>>Odp.re>>Odp.im>>a[0]>>a[2];
	
	
       if(a[1]=='('&&Wynik.re==Odp.re&&Wynik.im==Odp.im&&a[0]=='i'&&a[2]==')'){

	cout<<"Odpowiedz poprawna. \n";
}
      else{

        cerr<<"Blad. Prawidlowym wynikeim jest:";
	cout<<'('<<Wynik.re<<::showpos<<Wynik.im<<::noshowpos<<'i'<<')'<<'\n';
	y++;
      }
      }      
      }
  
  }
  
        cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  cout<<"\n"<<"Statystyki:";
  cout<<"\n"<<"Liczba pytan - "<<z;
  cout<<"\n"<<"Liczba prawidlowych odpowiedzi - "<<z-y;
  cout<<"\n"<<"Liczba niepoprawnych odpowiedzi - "<<y<<"\n";
}
*/


int main (){
  LZespolona wynik,w2;
  WyrazenieZesp w1; 

 std::cout<<"Podaj wyrazenie zespolone:"<<"\n";
 std::cin>>w1;  /* Wczytuje wyrazenie zespolone wpisane przez uzytkownika*/
 switch(w1.Op){   /*Sprawdza w zaleznosci od parametru w1.Op jakie dzialanie trzeba wykonac oraz je wykonuje */
 case 0:
   wynik = operator +(w1.Arg1,w1.Arg2);
   break;
 case 1:
   wynik = operator -(w1.Arg1,w1.Arg2);
   break;
 case 2:
   wynik = operator *(w1.Arg1,w1.Arg2);
   break;
 case 3:
   try{
  wynik = operator /(w1.Arg1,w1.Arg2);
   }                                      /* Obsluga wyjatkow w przypadku dzielenia przez 0*/
      catch (const char* msg) {
	std::cout << msg;
      return 0;
      }
   break;
 }

 std::cout<<"Podaj swoj wynik:"<<"\n";
 std::cin>>w2; /*Wczytuje wynik podany przez uzytkownika */
 if(w2.re==wynik.re&&w2.im==wynik.im){ /*Sprawdza podany wynik z wynikiem prawidlowym*/
   std::cout<<"Wynik prawidlowy!!"<<"\n";
 }
 else{                          /*Jesli wyniki sa zgodne wyswietla sie napis "Wynik prawidlowy"
                                 jesli nie wypisuje tekst na strumieniu bledow "Blad!!Prawidlowy wynik" oraz  wypisuje prawidlowy wynik */
   
   std::cerr<<"Blad!! Prawidlowy wynik:"<<"\n";
   std::cout<<wynik<<"\n";
 }
}
