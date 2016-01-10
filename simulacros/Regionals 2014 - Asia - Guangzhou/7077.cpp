#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <cstdio>
using namespace std;
typedef long long tint;

double maxi = 0.0;

void backTracking (vector<bool> &usados, vector<double> &lado, int cantNoUsados, double areaTotal)
{
	if(cantNoUsados >= 3){
		int n = usados.size();
		for(tint i = 0; i < n; i++)
		{
			if(!usados[i]){
				for(tint j = i+1; j < n; j++)
				{
					if(!usados[j]){
						for(tint k = j+1; k < n; k++)
						{
							if(!usados[k]){
								if (lado[i] <= lado[j] + lado[k] && lado[j] <= lado[i] + lado[k] && lado[k] <= lado[i] + lado[j])
								{
									usados[i] = true;
									usados[j] = true;
									usados[k] = true;
									
									double s = (lado[i] + lado[j] + lado[k])/2.0;
									double area = sqrt(s*(s-lado[i])*(s-lado[j])*(s-lado[k]));
																		
									// compar max
									if(areaTotal + area > maxi){
										maxi = areaTotal + area;
									}
									
									backTracking(usados, lado, cantNoUsados-3, areaTotal+area);
									
									usados[i] = false;
									usados[j] = false;
									usados[k] = false;
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
	while (n != 0)
	{
		maxi = 0;
		vector<double> lado (n);
		for(tint i = 0; i < n; i++)
		{
			double l;
			cin >> l;
			lado[i] = l;
		}
		vector<bool> usados (n,false);

		backTracking(usados, lado, n, 0.0);

		printf("%.2f\n",maxi); 
		cin >> n;
	}
	
	return 0;
}
