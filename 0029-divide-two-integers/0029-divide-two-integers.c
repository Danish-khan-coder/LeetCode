int divide(int dividend, int divisor) {

    long long a = dividend;
    long long b = divisor;

    int negative = 0;

    if (a < 0) {
        a = -a;
        negative = !negative;
    }

    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    long long quotient = 0;

    while (a >= b) {

        long long temp = b;
        long long multiple = 1;

        // Find the largest multiple of divisor
        // that can be subtracted from dividend
        while ((temp << 1) <= a) {
            temp = temp << 1;
            multiple = multiple << 1;
        }

        a = a - temp;
        quotient = quotient + multiple;
    }

    if (negative)
        quotient = -quotient;

    // Handle overflow
    if (quotient > 2147483647)
        return 2147483647;

    if (quotient < -2147483648LL)
        return -2147483648LL;

    return (int)quotient;
}