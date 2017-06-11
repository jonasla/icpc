#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis1(1, 25);
uniform_real_distribution<long double> dis2(26, 50);

int main()
{
	
	cout <<  dis1(gen) << "\n";
	cout <<  fixed << showpoint << setprecision(16) << dis2(gen) << "\n";
	return 0;
}

