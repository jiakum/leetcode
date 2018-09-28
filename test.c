
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


int main()
{
    int n = 0x800;

    __sync_fetch_and_add(&n, 10);

    printf("hex:0x%x, decimal:%d\n", n, n);
}
