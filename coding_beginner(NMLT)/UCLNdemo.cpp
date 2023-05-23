
#include <iostream>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << gcd(m, n);
	return 0;
}
