#include <iostream>
using namespace std;
class B1
{
    protected:
    virtual int test() {};

};
class P1:public B1
{
    public:
    int* zmienna;
    P1():zmienna(new int [1]){}
    virtual int test() {return 1;}
    void set_zmienna(int a) {zmienna[1]=a;}
    void wypisz(){cout <<  zmienna[1];}
     friend ostream& wypisz_p1(ostream& out, P1 klasa);
    int& operator[] (int pos)
    {
        if(pos>1) {cerr << "Blad!"; return zmienna[1];}
        return zmienna[pos];
    }
    P1& operator=(const P1& obiekt)
    {
        zmienna=new int [1];
        zmienna[1]=obiekt.zmienna[1];
    }
};
/*
class P2: public B1
{
    P1 zmienna;
public:
    P2(){zmienna.set_zmienna(2); zmienna.wypisz();}
    virtual int test() {return 1;}
};
*/
ostream& operator<< (ostream& out,P1 klasa)
{
    out << klasa[1];
    return out;
}

int main()
{




    return 0;
}
