#include <gtest/gtest.h>
#include <sailcu/hello.h>

TEST(SAILCU_HELLO, PRINT_SUM)
{
    sail::printHello();
}

TEST(SAILCU_HELLO, PRINT_SUM_DIRECT)
{
    int a[N], b[N], c[N];
    for (auto i = 0; i < N; i++) {
        a[i] = -i;
        b[i] = i * i;
    }
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < N; j++) {
            a[i] = a[i] + j;
            b[i] = b[i] + j * j;
        }
        c[i] = a[i] + b[i];
    }
    for (auto i = 0; i < N; i++) {
        // printf("%d + %d = %d \n", a[i], b[i], c[i]);
    }
}