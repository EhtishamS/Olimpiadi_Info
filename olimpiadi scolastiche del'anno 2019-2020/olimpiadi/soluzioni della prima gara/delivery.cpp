// in the i-th day, the delivery time w.r.t. the beginning is T[i] + i;
// with that prevision update the minimum if it makes sense and increase a counter

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 10000

// input data
int N, i;
int T[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));

    int minchanged = 0;
    int min = T[0];
    for (i=1; i<N; i++) {
	int time = T[i] + i;
	if (time < min) {
	    min = time;
	    minchanged++;
	}
    }

    printf("%d %d\n", min, minchanged); // print the result
    return 0;
}
