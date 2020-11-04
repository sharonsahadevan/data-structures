#include <stdio.h>

int fsum(int n)
{
    int sum;
    if (n == 0)
        return 1;
    return sum = fsum(n-1) * n;
}

int main()
{
    int sum; 
    sum = fsum(5);
    printf("%d",sum);


}