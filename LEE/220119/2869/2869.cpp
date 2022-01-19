#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    scanf("%d %d %d", &a, &b, &c);
    int result = (c - a) / (a - b);
    if (((c - a) % (b - a)) != 0)
        result += 2;
    else
        result += 1;
    printf("%d", result);
    return 0;
}