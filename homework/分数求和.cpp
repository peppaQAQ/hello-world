#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
	{
        return a;
    }
    int r = a % b;
    return gcd(b, r);
} 
class Fraction {
public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        simplify(); 
    }

    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        if (frac.numerator == 0)
		{ 
            os << 0;
        }
		else if (frac.denominator == 1)
		{ 
            os << frac.numerator;
        }
		else
		{ 
            int g = gcd(abs(frac.numerator), abs(frac.denominator));
            int new_num = frac.numerator / g;
            int new_denom = frac.denominator / g;
            if (new_denom < 0) { 
                new_num = -new_num;
                new_denom = -new_denom;
            }
            os << new_num << '/' << new_denom;
        }
        return os;
    }

private:
    int numerator;       // ·Ö×Ó
    int denominator;     // ·ÖÄ¸

    void simplify() {
        if (numerator == 0)
		{
            denominator = 1;
            return;
        }
        
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }
};

int main()
{
    int n;
    cin >> n;

    Fraction sum(0); 
    for (int i = 0; i < n; ++i)
	{
        int numerator, denominator;
        char slash;
        cin >> numerator >> slash >> denominator;
        if (denominator == 0)
		{ 
            cout << "error" << endl;
            return 0;
        }
        Fraction frac(numerator, denominator);   
        sum = sum + frac;  
    }
    cout << sum << endl;

    return 0;
}
