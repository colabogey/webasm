#include <basicMath.h>

int basicMath::add(int a, int b)
{
    return (a + b);
}

int basicMath::subtract(int a, int b)
{
    return (a - b);
}

int basicMath::multiply(int a, int b)
{
    return (a * b);
}

int basicMath::divide(int a, int b)
{
    return (b == 0 ? 0 : a/b);
}
