#include "UkladRownanLiniowych.hh"
#include <cmath>



/* Metody Getter i Setter */

const Wektor & UkladRownanL:: getwektor() const{                     

  return B ;
}



const Macierz & UkladRownanL :: getmacierz() const{               

  return A;
}



void UkladRownanL :: setwektor(const Wektor & im){                  

  this->B=im;
}



void UkladRownanL :: setmacierz( const Macierz & im){            

  this->A=im;
}

/* Metody */

Wektor UkladRownanL :: oblicz() const {


  Macierz P(this->A);
  double i=0;                                                                                                                                                                Wektor rozw;                                        //Oblicza uklad rownan, zwaraca wektor
  Wektor W(this->B);
  
  


  for(int x=0;x<ROZMIAR-1;x++){                                                                                                                                                   for(int y=x+1;y<ROZMIAR;y++){
      
      if(std::abs(P[x][x])> eps){
	i=P[y][x]/P[x][x];

	P[y]=P[y]-(P[x]*i);
	W[y]=W[y]-(W[x]*i);
       
      }

      else{

	for(int z=x+1;z<ROZMIAR;z++){
	  if(std::abs(P[z][x])> eps){
	    P = P.Zmienwiersze(x,z);
	    std::swap(W[x],W[z]);            //Jesli zmieniamy wiersze w macierzy to skladowe wektora takze trzeba zamienic miejscami   
	    z=ROZMIAR;
	  }
	  else {
	    std::cerr << "Brak zmiennej x" << x+1 <<std::endl;            //Blad jesli cala koloumna jest rowna 0
	    exit(1);
	}
      }
    }
    }
  }
  for (int a = ROZMIAR-1; a > -eps; a--){
    if(std::abs(P[a][a])<eps){

      std::cerr << "Blad dzielenie przez 0 !" << std::endl;     //Blad jesli dzielimy przez  0 
      exit(1);
    }
    rozw[a]=(W[a]+(-1)*(P[a]*rozw))/P[a][a];    
    
  }
  return rozw;
}
 

Wektor UkladRownanL:: wekbledu() const{                 //metoda wylicza wktor bledu zwraca wektor  


  return this->A*this->oblicz()-this->B;


}


double UkladRownanL :: dlugoscwek() const{       //metoda wylicza dlugosc wektora bledu zrwaca wartosc typu double 


  return this->wekbledu().dlugosc();
}


/* Przeciazenia operatorow in/out*/


std::istream & operator >> (std::istream & strm, UkladRownanL & UK){

  Macierz X;
  Wektor Y;
                                          //Przeeciazaenie in pobiera od uzytkownika najpierw macierz potem wektor 
                                         
  strm>> X;
  strm>> Y;
  UK.setmacierz(X);
  UK.setwektor(Y);
  
  return strm;
}



std::ostream & operator << ( std::ostream & strm,  const UkladRownanL & UK){                     


  strm<<"Macierz A^T : \n"<< UK.getmacierz().transpozycja();
  strm<<"Wektor wyrazow wolnych: " << UK.getwektor();
  strm<<"Rozwiazanie x = (x1, x2, x3): " << UK.oblicz();                        //Przeciazenie out wypisuje na ekran macierz transponowana, wektor wyrazow wolnych 
  strm<<"Wektor bledu: Ax-b = "<<UK.wekbledu();                                //wektor bledu oraz dlugosc wektora 
  strm<<"Dlugosc wektora bledu: ||Ax-b|| = "<<UK.dlugoscwek();

    return strm;
}
  
