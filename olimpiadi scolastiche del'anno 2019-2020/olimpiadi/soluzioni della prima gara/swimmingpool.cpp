// for each position, considers the longest distance between itself and first/last;
// returns the minimum of all this distances
// O(N)

#include <stdio.h>
#include <assert.h>
#include <algorithm>
// constraints
#define MAXN 10000

// input data
int N, i;
int P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));

    int res = P[N-1] - P[0];
    for (i=1; i<N; i++)
        res = std::min(res, std::max(P[i] - P[0], P[N-1] - P[i]));

    printf("%d\n", res); // print the result
    return 0;
}
