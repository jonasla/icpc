#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef long long tint;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)

struct Pillar
{
	tint x,y;
	Pillar(tint xx, tint yy)
	{
		x = xx;
		y = yy;
	}
};

tint maxi = 0;

bool formanRectangulo(vector<Pillar> p)
{
	tint n =  p.size();
	map<tint, tint> sx;
	map<tint, tint> sy;
	forn(i,n)
	{
		sx[p[i].x]++;
		sy[p[i].y]++;
	}
	bool tutti = true;
	for(auto c : sx)
		tutti &= (c.second == 2);
	for(auto c : sy)
		tutti &= (c.second == 2);
	return tutti;
	
}

tint area(vector<Pillar> p)
{
	tint n = p.size();
	vector<tint> cx (n);
	vector<tint> cy (n);
	forn(i,n)
	{
		cx[i] = p[i].x;
		cy[i] = p[i].y;
	}
	return (*max_element(cx.begin(),cx.end())-*min_element(cx.begin(),cx.end()))*(*max_element(cy.begin(),cy.end())-*min_element(cy.begin(),cy.end()));
}

tint noSolapan(vector<Pillar> p1, vector<Pillar> p2)
{
	tint n = p1.size();
	vector<tint> cx1 (n);
	vector<tint> cy1 (n);
	vector<tint> cx2 (n);
	vector<tint> cy2 (n);
	forn(i,n)
	{
		cx1[i] = p1[i].x;
		cy1[i] = p1[i].y;
		cx2[i] = p2[i].x;
		cy2[i] = p2[i].y;
	}
	tint maxX1 = *max_element(cx1.begin(),cx1.end());
	tint maxX2 = *max_element(cx2.begin(),cx2.end()); 
	tint maxY1 = *max_element(cy1.begin(),cy1.end()); 
	tint maxY2 = *max_element(cy2.begin(),cy2.end());
	tint minX1 = *min_element(cx1.begin(),cx1.end()); 
	tint minX2 = *min_element(cx2.begin(),cx2.end()); 
	tint minY1 = *min_element(cy1.begin(),cy1.end()); 
	tint minY2 = *min_element(cy2.begin(),cy2.end());
	if ((maxX1 < minX2) or (maxX2 < minX1) or (maxY1 < minY2) or (maxY2 < minY1))
		return 1;
	else if ((maxX1 < maxX2 && minX1 > minX2 && maxY1 < maxY2 && minY1 > minY2) or (maxX2 < maxX1 && minX2 > minX1 && maxY2 < maxY1 && minY2 > minY1))
		return 2;
	else
		return 0;
}

void backTracking (vector<bool> &usado, vector<Pillar> &pillar, tint cantidadUsados, tint areaTotal, vector<Pillar> rectanguloViejo)
{
	tint n = pillar.size();
	forn(i,n)
	{
		if (!usado[i])
		{
			forsn(j,i+1,n)
			{
				if (!usado[j])
				{
					forsn(k,j+1,n)
					{
						if (!usado[k])
						{
							forsn(l,k+1,n)
							{
								if (!usado[l])
								{
									vector<Pillar> aux = {pillar[i], pillar[j], pillar[k], pillar[l]};
									if (formanRectangulo(aux))
									{
										usado[i] = true;
										usado[j] = true;
										usado[k] = true;
										usado[l] = true;
										cantidadUsados += 4;
										areaTotal += area(aux);
										
										if (cantidadUsados == 8 && noSolapan(rectanguloViejo,aux) == 1)
											maxi = max(maxi,areaTotal);
										else if (cantidadUsados == 8 && noSolapan(rectanguloViejo,aux) == 2)
											maxi = max(maxi,max(areaTotal - area(aux), area(aux)));
										else if (cantidadUsados == 4)
											backTracking(usado,pillar,cantidadUsados, areaTotal, aux);
										
										areaTotal -= area(aux);
										cantidadUsados -= 4;
										usado[i] = false;
										usado[j] = false;
										usado[k] = false;
										usado[l] = false;
										
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	tint n;
	cin >> n;
	while(n != 0)
	{
		maxi = 0;
		vector<Pillar> pillar (n, Pillar(0,0));
		vector<bool> usado (n,false);
		forn(i,n)
		{
			tint xx,yy;
			cin >> xx >> yy;
			pillar[i] = Pillar(xx,yy);
		}
		
		vector<Pillar> RectanguloViejo;
		backTracking(usado,pillar,0,0,RectanguloViejo);
		
		
		if (maxi != 0)
			cout << maxi << endl;
		else
			cout << "imp" << endl;
		cin >> n;
	}
	
	return 0;
}
