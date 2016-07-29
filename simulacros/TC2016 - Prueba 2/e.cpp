#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define forn(i,n) for(long long i=0; i<(long long)n; i++)
#define forsn(i,s,n) for(long long (i)=s; i<(long long)n; i++)

typedef long long tint;

char s[3000050];
char gString[3050];

tint ordinal(char x)
{
	if ((int) x >= 97)
		return x-'a';
	else
		return x-'A'+26;
	
}

tint gg[52];
tint ss[52];

int main()
{
	//forn(i,26)
		//cout << (char)('a'+i) << " " << ordinal('a'+i) << endl;
	//forn(i,26)
		//cout << (char)('A'+i) << " " << ordinal('A'+i) << endl;
		
	tint g,n;
	//cin >> g >> n;
	scanf("%Ld %Ld", &g, &n);
	//string gString,s;
	//cin >> gString >> s;
	scanf("%s %s", gString, s);
	tint ans = 0;
	forn(i,g)
		gg[ordinal(gString[i])]++;		
	//forn(i,60)
	//	cout << gg[i] << " ";
	
	forn(i,n)
	{
		if (i < g)
			ss[ordinal(s[i])]++;
		if (i == g-1)
		{
			bool anda = true;
			forn(j,52)
				anda &= (gg[j] == ss[j]);
			ans += anda;
		}
		if (i >= g)
		{
			//cout << s[i-g] << " " << s[i] << endl;
			ss[ordinal(s[i-g])]--;
			ss[ordinal(s[i])]++;
			bool anda = true;
			forn(j,52)
				anda &= (gg[j] == ss[j]);
			ans += anda;
		}
		
	}
	//cout << ans << endl;
	printf("%Ld\n", ans);
	return 0;
}
