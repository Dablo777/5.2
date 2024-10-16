// Лабораторна робота № 5.2
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double S(const double x, const double eps, int& n, double& s);
double A(const double x, const int n);
int main()
{
	double xp, xk, x, dx, eps, s = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-------------------------------------------------------" << endl;
	cout << "|" << setw(8) << "x" << " |"
		<< setw(11) << "ln((x + 1) / (x - 1))" << " |"
		<< setw(11) << "S" << " |"
		<< setw(6) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		S(x, eps, n, s);
		cout << "|" << setw(8) << setprecision(2) << x << " |"
			<< setw(21) << setprecision(5) << log((x + 1) / (x - 1)) << " |"
			<< setw(11) << setprecision(5) << s << " |"
			<< setw(6) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------------" << endl;
	return 0;
}
double S(const double x, const double eps, int& n, double& s)
{
	n = 1; // вираз залежить від умови завдання варіанту
	double a;
	s = 0;
	do {
		a = A(x, n);
		s += a;
		n += 2;
	} 
	while (abs(a) >= eps);
	s *= 2;
	return s;
}
double A(const double x, const int n)
{
	double a = 1 / n * (pow(x, n)); // вираз залежить від умови завдання варіанту
	return a;
}