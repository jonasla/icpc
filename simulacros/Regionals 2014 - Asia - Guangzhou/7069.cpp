#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long tint;

struct Candy
{
	tint sweetness, sourness;
	Candy(tint sw, tint so)
	{
		sweetness = sw;
		sourness = so;
	}
};

bool operator < (Candy c1, Candy c2)
{
	return make_pair(c1.sweetness, c1.sourness) < make_pair(c2.sweetness, c2.sourness);
}


int main()
{
	tint n;
	cin >> n;
	while (n != 0)
	{
		map<Candy,tint> indice;
		vector<Candy> boxIterable;
		vector<bool> estaAdentro;
		for (tint i = 0; i < n; i++)
		{
			tint t,x,y;
			cin >> t >> x >> y;
			if (t == 1)
			{
				indice[Candy(x,y)] = boxIterable.size();
				boxIterable.push_back(Candy(x,y));
				estaAdentro.push_back(true);
			}
			else if (t == 0)
			{
				tint maxi = -3000000000000000000;
				tint m = boxIterable.size();
				for (tint j = 0; j < m; j++)
					if (estaAdentro[j])
						maxi = max(maxi, boxIterable[j].sweetness * x + boxIterable[j].sourness * y);
				cout << maxi << endl;
			}
			else
				estaAdentro[indice[Candy(x,y)]] = false;
				
				
		}
		cin >> n;
	}
	return 0;
	
}
