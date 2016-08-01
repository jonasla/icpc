#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10000000;

bool is_prime[N];
int prime[N];
int prime_number;
long long number;

int main() {
	while (cin >> number) {
		if (number < 0)
			break;
		memset(is_prime,true,sizeof(is_prime));
		memset(prime,0,sizeof(prime));
		prime_number = 0;
		is_prime[0] = false;
		is_prime[1] = false;

		for (int i = 2; i <= N && i <= (int)sqrt(number); i++) {

			if (is_prime[i]) {
				prime[prime_number] = i;

				while (prime[prime_number] && number % prime[prime_number] == 0) {
					cout << "    " << prime[prime_number] << endl;
					number /= prime[prime_number];
				}

				prime_number++;
			}

			for (int j = 0; j < prime_number && i*prime[j] <= N && i*prime[j] <= (int)sqrt(number); j++) {
				is_prime[i*prime[j]] = false;
				if (prime[j] && i % prime[j] == 0)
					break;
			}
		}
		if (number > 1)
			cout << "    " << number << endl;
		cout << endl;
	}
	return 0;
}
