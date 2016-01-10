#include <iostream>
#include <deque>

#define forn(i,n) for(int i = 0; i < (int) (n);i++)

using namespace std;



int main()
{
	int n,d;
	cin >> n >> d;
	while (n != 0)
	{
		bool funca = false;
		forn(i,n)
		{
			bool todosUnos = true;
			forn(i,d)
			{
				int aux;
				cin >> aux;
				todosUnos &= (aux == 1);
			}
			funca = funca or todosUnos;
		}
		if (funca)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		
		cin >> n >> d;
	}
	return 0;
}
