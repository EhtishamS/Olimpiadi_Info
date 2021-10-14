/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// input data
int N, T, i;

int xor1toN(int n) {
    if ((n & 1) == 0) {
        return xor1toN(n-1) ^ n;
    }
    return ((n+1) >> 1) & 1;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(1 == scanf("%d", &N));

        int all = xor1toN(N);
        int msb = 0;
        while ((1 << msb) <= N)
            msb++;
        int a = (1 << msb) - 1;
        int b = all ^ a;

        printf("%d\n", a + b); // print the result
    }
    return 0;
}
