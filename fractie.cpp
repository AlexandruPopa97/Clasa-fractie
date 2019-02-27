#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
class fractie
{
	private:
		int numarator;
		int numitor;
	public:
		fractie();
		fractie(int, int);
		int get_numarator()const;
		int get_numitor()const;
		fractie get_inv()const;
		friend bool operator ==(const fractie &,const fractie &);
		friend bool operator !=(const fractie &,const fractie &);
		friend fractie operator+(const fractie &,const fractie &);
		friend fractie operator-(const fractie &,const fractie &);
		friend fractie operator*(const fractie &,const fractie &);
		friend fractie operator/(const fractie &,const fractie &);
		fractie& operator+=(const fractie&);
		fractie& operator-=(const fractie&)	;
		fractie& operator*=(const fractie&)	;
		fractie& operator/=(const fractie&);
		friend ostream& operator<<(ostream &,const fractie &);
		//operator<<;		
};

fractie::fractie()
{
	numarator=0;
	numitor=0;
}
fractie::fractie(int numarator1,int numitor1)
{
	numarator=numarator1;
	numitor=numitor1;
}
int fractie::get_numarator()const
{
	return numarator;
}
int fractie::get_numitor()const
{
	return numitor;
}
fractie fractie::get_inv()const
{
	fractie aux,ceva;
	ceva.numarator=numitor;
	ceva.numitor=numarator;
	//numitor=aux;
	return ceva;
}
bool operator==(const fractie &x,const fractie &y)
{
	if((x.numarator/x.numitor)!=(y.numarator/y.numitor))return false;
	//else if(x.numitor!=x.numitor)return false;
	else return true;
}
bool operator!=(const fractie &x,const fractie &y)
{
	if((x.numarator/x.numitor)==(y.numarator/y.numitor))return false;
	else return true;
}
int functie(int a,int b)
{
	int p;
	p=a*b;
	while(a!=b)
	{
		if(a>b)a=a-b;
		else b=b-a;
	}
	//fractie r;
	//r.numitor=p.numitor/a.numitor;
	return p/a;
}
fractie operator+(const fractie &x,const fractie &y)
{
	fractie rezultat;
	int cmm;
	int t,p;
	if(x.numitor==y.numitor)
	{
		rezultat.numarator=x.numarator+y.numarator;
		rezultat.numitor=x.numitor;
		return rezultat;
	}
	else
	{
		cmm=functie(x.numitor,y.numitor);
		t=cmm/y.numitor;
		p=cmm/x.numitor;
		x.numarator=x.numarator*t;
		y.numarator=y.numarator*p;
		rezultat.numitor=cmm;
		rezultat.numarator=x.numarator+y.numarator;
		return rezultat;
	}
	
}
fractie operator-(const fractie &x,const fractie &y)
{
	fractie rezultat;
	int cmm;
	if(x.numitor==y.numitor)
	{
		rezultat.numarator=x.numarator-y.numarator;
		rezultat.numitor=x.numitor;
		return rezultat;
	}
	else
	{
		cmm=functie(x.numitor,y.numitor);
		x.numarator=x.numarator*(cmm/(y.numitor));
		y.numarator=y.numarator*(cmm/(x.numitor));
		rezultat.numitor=cmm;
		rezultat.numarator=x.numarator-y.numarator;
		return rezultat;
	}
}
fractie operator*(const fractie &x,const fractie &y)
{
	fractie rezultat;
	rezultat.numarator=x.numarator*y.numarator;
	rezultat.numitor=x.numitor*y.numitor;
	return rezultat;
}
fractie operator/(const fractie &x,const fractie &y)
{
	fractie rezultat,obiect;
	//obiect.get_inv(y);
	rezultat.numarator=x.numarator*y.numitor;
	rezultat.numitor=x.numitor*y.numarator;
	return rezultat;
}
fractie&operator+=(const fractie &y)
{
	int cmm;
	if(numitor==y.numitor)
	{
		numarator+=y.numarator;
		numitor=y.numitor;
		return *this;
	}
	else
	{
		cmm=functie(numitor,y.numitor);
		//cmm=cmmmc(x.numitor,y.numitor);
		numarator=numarator*(cmm/y.numitor);
		y.numarator=y.numarator*(cmm/numitor);
		numitor=cmm;
		numarator+=y.numarator;
		return *this;
	}
}
fractie& operator-=(const fractie &y)
{
	if(numitor==y.numitor)
	{
		numarator-=y.numarator;
		numitor=y.numitor;
		return *this;
	}
	else
	{
		cmm=functie(numitor,y.numitor);
		//cmm=cmmmc(x.numitor,y.numitor);
		numarator=numarator*(cmm/y.numitor);
		y.numarator=y.numarator*(cmm/numitor);
		numitor=cmm;
		numarator-=y.numarator;
		return *this;
	}
	//numitor
}
fractie& operator*=(const fractie &y)
{
	//fractie rezultat,cmm;
	numarator*=y.numarator;
	numitor*=y.numitor;
	return *this;
}
fractie& operator/=(const fractie &y)
{
	fractie rezultat,obiect;
	//obiect.get_inv();
	numarator=numarator*y.numitor;
	numitor=numitor*y.numarator;
	return *this;
}
ostream& operator<<(ostream &d,const fractie &x)
{
	d<<x.numarator;
	d<<x.numitor;
	return d;
}


int main(int argc, char** argv) 
{
	fractie *v;
	v= new fractie[4];
	v[0]=fractie(2,3);
	v[1]=fractie(4,5);
	v[2]=fractie(6,8);
	v[3]=fractie(1,2);
	return 0;
}



