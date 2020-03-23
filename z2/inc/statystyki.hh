#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH
#include<iostream>
#include<cstdlib>


class statystyki{
public:
  int zle;
  int calosc;
  friend std::ostream & operator << (std::ostream & strm, statystyki & s);
  
};




#endif
