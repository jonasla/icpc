#include <iostream>
#include <cmath>
#include <algorithm>

#define forn(i,n) for(int i=0;i<(int)(n); i++)


using namespace std;

typedef long double ldouble;

struct Complejo
{
	ldouble real,imag;
	Complejo(ldouble rr, ldouble ii) {real = rr; imag = ii;}
	Complejo() {real = 0.0; imag = 0.0;}
	Complejo operator + (Complejo c) {return Complejo(real + c.real, imag + c.imag);}
	Complejo operator - (Complejo c) {return Complejo(real - c.real, imag - c.imag);}
	Complejo operator * (Complejo c) {return Complejo(real*c.real - imag*c.imag, real*c.imag + imag*c.real);}
};

const int maxN = 1 << 19;
Complejo aa[maxN];
Complejo bb[maxN];
Complejo cc[maxN];
Complejo dd[maxN];
Complejo ee[maxN];
ldouble pi = acos(-1);

void fftAux (Complejo *a, Complejo *b, int paso)
{
	if (paso < maxN)
	{
		int tam = maxN/paso;
		fftAux(a,b, 2*paso);
		fftAux(a+paso,b+tam/2, 2*paso);
		ldouble arg = -2*pi/ldouble(tam);
		Complejo wn = Complejo(cos(arg),sin(arg)), w = Complejo(1,0);
		forn(k,tam/2)
		{
			Complejo a0 = b[k], a1 = b[k + tam/2];
			b[k] 	   = a1 + w*a0;
			b[k+tam/2] = a1 - w*a0;
			w = w*wn;
		}
	}
	else
		b[0] = a[0];
}
	
void fft (Complejo *a,Complejo *b)
{
	fftAux(a,b,1);
}

void ifft(Complejo *a, Complejo *b)
{
	ldouble nn = ldouble(maxN);
	reverse(a,a+maxN);
	forn(i,maxN)
		a[i].imag = -a[i].imag;
	fft(a,b);
	forn(i,maxN)
		{b[i].real = b[i].real/nn; b[i].imag = -b[i].imag/nn;}
	reverse(b,b+maxN);
}

void multfft(Complejo *a, Complejo *b, Complejo *c)
{
	fft(a,dd);
	fft(b,ee);
	forn(i,maxN)
		dd[i] = dd[i]*ee[i];
	ifft(dd,c);
	Complejo aux = c[maxN-1];
	forn(i,maxN-1)
		c[i] = c[i+1];
	c[maxN-1] = aux;
	
}


int main()
{
	aa[1] = Complejo(1,0);
	aa[3] = Complejo(1,0);
	aa[5] = Complejo(1,0);
	bb[1] = Complejo(1,0);
	bb[0] = Complejo(1,0);
	multfft(aa,bb,cc);
	//forn(i,maxN)
	//	cout << i << ": " << cc[i].real << " +  i * " << cc[i].imag << endl;
	forn(i,500)
	{
		if (i % 25 == 0)
			cout << endl;
		printf("%.2Lf ",cc[i].real);
	}
	return 0;
}
