#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

int main ()
{
    LL n, k;

    while ( cin >> n >> k ) {
        double digit = 0;

        if ( k > n - k ) {
            for ( LL i = k + 1; i <= n; i++ )
                digit += (log10 (i) - log10 (n - i + 1));
        }
        else {
            for ( LL i = n - k + 1; i <= n; i++ )
                digit += (log10 (i) - log10 (n - i + 1));
        }

        digit = floor (digit) + 1;

        printf ("%0.lf\n", digit);
    }

	return 0;
}

