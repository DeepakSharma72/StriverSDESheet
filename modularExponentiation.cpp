#include <bits/stdc++.h> 
using namespace std;
int modularExponentiation(int x, int n, int m) {
    if(n == 0)
    {
        return (1%m);
    }
    if(n == 1)
    {
        return (x%m);
    }
	long long int val = modularExponentiation(x,n/2,m)%m;
    val = (val*val)%m;
    if(n%2)
    {
        val = (x*val)%m;
    }
    return val;
}