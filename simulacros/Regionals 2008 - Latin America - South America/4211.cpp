#include <iostream>
#include <vector>
#include <algorithm>


#define forn(i,n) for(int (i) = 0; (i) < (int)(n); i++ )
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)


typedef long long tint;
using namespace std;

const tint maxGrado = 70;

struct Polinomio
{
	tint coeff[maxGrado];
	Polinomio()
	{
		forn(i,maxGrado)
			coeff[i] = 0;
	}
};

Polinomio operator + (Polinomio p1, Polinomio p2)
{
	Polinomio p;
	forn(i,maxGrado)
		p.coeff[i] = p1.coeff[i] + p2.coeff[i];
	return p;
}

Polinomio operator - (Polinomio p1, Polinomio p2)
{
	Polinomio p;
	forn(i,maxGrado)
		p.coeff[i] = p1.coeff[i] - p2.coeff[i];
	return p;
}

Polinomio operator * (Polinomio p1, Polinomio p2)
{
	Polinomio p;
	forn(i,maxGrado)
	forn(j,maxGrado)
    if (i + j < maxGrado)
		p.coeff[i+j] += p1.coeff[i]*p2.coeff[j];
	return p;
		
}

Polinomio toPoly (string s)
{
	Polinomio p;
	tint r = s.size();
	forn(i,r)
		p.coeff[r-i-1] = (tint) (s[i]-'0');
	return p;
}

bool evaluar (Polinomio p, tint x)
{
    // Gronchada que hago yo de mirar modulo muchos numeros para evitar el overflow.
	vector<tint> modulos = {32151,135477,32153,321579,32415,235763118,1000000007};
	bool tutti = true;
	for(auto m : modulos)
	{
		tint k = 1;
		tint ans = 0;
		forn(i,maxGrado)
		{
			ans = (((ans + p.coeff[i]*k) % m )+ m) % m;
			k = (((k*x) % m) + m) % m;
		}
		tutti &= (ans == 0);
	}
	return tutti;
	// Posta determinista corta y eficiente que me dijo Agus.
    /*
    tint q = 0;
    forn(i, maxGrado)
    {
        q += p.coeff[i];
        if (q % x != 0) return false;
        q /= x;
    }
    return q == 0;
    */
}

vector<string> split (string s, char x)
{
	tint anterior = 0, r = s.size();
	vector<string> termino;
	forn(i,r)
	{
		if (s[i] == x)
		{
			termino.push_back(s.substr(anterior, i - anterior));
			anterior = i+1;
		}
	}
	termino.push_back(s.substr(anterior, r - anterior));
	return termino;
}

Polinomio parsing (string s)
{
	vector<string> terminoSuma = split(s,'+');
	Polinomio ans;
	for (auto termino : terminoSuma)
	{
		vector<string> polis = split(termino,'*');
		Polinomio p = toPoly(polis[0]);
		forsn(i,1,polis.size())
			p = p * toPoly(polis[i]);
		ans = ans + p;
	}
	return ans;
}

tint pisoRaiz (tint x)
{
	x = abs(x);
	tint k = 0;
	while (k*k <= x)
		k++;
	return k-1;
}

int main()
{
	
	#ifdef ACMTUYO
		if (!freopen("entrada.in", "r", stdin))
			return 1;
	#endif
	string s;
	while (cin >> s && s != "=")
	{
		tint maxi = -1;
		forn(i,s.size())
			if (s[i] != '=' && s[i] != '*' && s[i] != '+')
				maxi = max(maxi,(tint)(s[i]-'0'));
		vector<string> lado = split(s,'=');
		Polinomio p = parsing(lado[0]) - parsing(lado[1]);
		tint terminoIndependiente = 0;
		forn(i,maxGrado)
			if( p.coeff[i] != 0)
			{
				terminoIndependiente = p.coeff[i];
				break;
			}
		vector<tint> ans;
		tint cotaDivisor = pisoRaiz(terminoIndependiente);
		forsn(b,1,cotaDivisor+1)
			if ( (terminoIndependiente % b) == 0 )
			{
                if (evaluar(p,b))
                    ans.push_back(b);
				tint newb = abs(terminoIndependiente/b);
				if ( b != newb && evaluar(p,newb))
					ans.push_back(newb);
			}
        sort(ans.begin(),ans.end());
		bool imprimi = false;
        forn(i,ans.size())
            if(ans[i] >= max((tint)2,maxi+1))
            {
                if(imprimi)
                    cout << " ";
                cout << ans[i];
                imprimi = true;
            }
		if (!imprimi && terminoIndependiente == 0)
			cout << max((tint) 2,maxi + 1) << "+";
		else if (!imprimi)
			cout << "*";
	
        cout << endl;
	}
	
	return 0;
}
