#include <stdio.h>
#include "common_eml.h"
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i=2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
 
// Driver program to test above function
int main()
{
    int n;
    for (n=1000; n<=1010; n++)
      printf("phi(%d) = %d\n", n, phi(n));
    return 0;
}
