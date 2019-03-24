#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main()
{
	int a, b;
	cin >> a >> b;
	int temp = gcd(a, b);
	int lcd = (a*b) / temp;
	cout << temp << '\n';
	cout << lcd << '\n';
	return 0;
}