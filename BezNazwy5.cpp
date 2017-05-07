/*
S¹ 3 klasy. klasa B czysto virtualna, klasa P1 podklas¹ B i klasa P2 podklas¹ p1. Klasa P1 posiada zmienn¹ tablicow¹ o rozmiarze 2. Klasa P2 posiada 1 zmienn¹ typu P1
P1 w1;
 const P1 w2("Ala", "Koala");
 P2 w3;
 const P2 w4("Warszawa", "Krakow");
 const P1 w5("******", "+++++++");
 w1=w5;
 w3=w5;
  // wlasciwa definicja tablicy tab

  tab[0] = &w1;
  tab[1] = &w2;
  tab[2] = &w3;
  tab[3] = &w4;

  for (....)
  cout << *tab[i]
  */

#include <iostream>
#include <cstring>
using namespace std;
class B
{

};

class P1 : public B
{
	protected: string * zmienna;
	public:
		P1():zmienna(new string [2])
		{
			zmienna[0]="brak";
			zmienna[1]="brak";
		}
		P1(string a, string b):zmienna(new string [2])
		{
			zmienna[0]=a;
			zmienna[1]=b;
		}
		P1 &operator=(P1 &a)
		{
			return *this;
		}
		const P1 &operator=(const P1 &a)const
		{
			return *this;
		}
		friend ostream&operator<<(ostream &a, const P1 &b);
};
ostream&operator<<(ostream &a, const P1 &b)
{
	a << b.zmienna[0] << " " << b.zmienna[1] << endl;
	return a;
}
class P2 : public P1
{
	public:
		P2():P1(){}
		P2(string a, string b):P1(a,b){}
	const P2 &operator=(const P2 &a)const
		{
			return *this;
		}
	const P2 &operator=(const P1 a)const
		{
			return *this;
		}

	friend ostream&operator<<(ostream &a, const P2 &b);
};
ostream&operator<<(ostream &a, const P2 &b)
{
	a << b.zmienna[0] << " " << b.zmienna[1] << endl;
	return a;
}
int main(){
P1 w1;
 const P1 w2("Ala", "Koala");
 P2 w3;
 const P2 w4("Warszawa", "Krakow");
 const P1 w5("******", "+++++++");
 w1=w5;
 w3=w5;
 const B** tab=new const B* [4];
  tab[0] = &w1;
  tab[1] = &w2;
  tab[2] = &w3;
  tab[3] = &w4;
  for (int i=0; i<4; i++)
  cout << *tab[i];
	return 0;
}
