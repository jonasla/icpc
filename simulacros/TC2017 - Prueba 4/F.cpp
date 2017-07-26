#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <tuple>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long tint;
typedef long double ldouble;

#define forn(i,n) for (tint i = 0; i < tint (n); i++)

map<char,pair<tint,tint> >  movi = {{'N',{0,1}},{'E',{1,0}},{'S',{0,-1}},{'W',{-1,0}}}; 
vector<char> iMovi = {'N','E','S','W'};
map<char,tint> id = {{'N',0},{'E',1},{'S',2},{'W',3}};


struct Respuesta
{
	tint l,b,e,d;
	Respuesta (tint ll, tint bb, tint ee, tint dd)
	{
		l = ll;
		b = bb;
		e = ee;
		d = dd;
	}
};

bool operator < (Respuesta r1, Respuesta r2)
{
	return make_tuple(r1.l,r1.b,r2.e,r1.d) < make_tuple(r2.l,r2.b,r1.e,r2.d);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	tint casos;
	cin >> casos;
	forn(caso,casos)
	{
		if (caso)
			cout << "\n";
		tint n;
		cin >> n;
		map<tint,vector<pair<tint,tint> > > x; // las y de los que tienen las mismas x
		map<tint,vector<pair<tint,tint> > > y; // las x de los que tienen las mismas y
		tint xx = 0, yy = 0;
		vector<tint> puedo (n+1,15);
		x[xx].push_back({yy,0});
		y[yy].push_back({xx,0});
		forn(i,n)
		{
			char m;
			cin >> m;
			puedo[i] -= (1 << id[m]);
			puedo[i+1] -= (1 << ((2+id[m]) % 4)); 
			xx += movi[m].first;
			yy += movi[m].second;
			x[xx].push_back({yy,i+1});
			y[yy].push_back({xx,i+1});
		}
		
		Respuesta ans = Respuesta(1e15,1e15,1e15,3);
		for (auto &s : x)
		{
			tint r = s.second.size();
			sort(s.second.begin(),s.second.end());
			forn(i,r-1)
			{
				tint ll = abs(s.second[i+1].first-s.second[i].first);
				tint bb = s.second[i].second;
				tint ee = s.second[i+1].second;
				if (bb < ee && (puedo[bb] & 1) && (puedo[ee] & 4))
					ans = min(ans,Respuesta(ll,bb,ee,0));
				else if (ee < bb && (puedo[ee] & 4) && (puedo[bb] & 1))
					ans = min(ans,Respuesta(ll,ee,bb,2));
			}
		}
		
		for (auto &s : y)
		{
			
			tint r = s.second.size();
			sort(s.second.begin(),s.second.end());
			forn(i,r-1)
			{
				tint ll = abs(s.second[i+1].first-s.second[i].first);
				tint bb = s.second[i].second;
				tint ee = s.second[i+1].second;
				if (bb < ee && (puedo[bb] & 2) && (puedo[ee] & 8))
					ans = min(ans,Respuesta(ll,bb,ee,1));
				else if (ee < bb && (puedo[ee] & 8) && (puedo[bb] & 2))
					ans = min(ans,Respuesta(ll,ee,bb,3));
			}
		}
		cout << ans.l << " " << ans.b << " " << ans.e << " " << iMovi[ans.d] << "\n";
		  
		
	}
	
	
	return 0;
}
