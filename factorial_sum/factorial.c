#include <stdio.h>

/**
 * 这是一个求阶乘的函数。对于一个给定的整数k，这个函数的返回值就是k的阶乘
 * 比如：
 *  如果k是1，那么factorial(k)的值就是1；
 *  如果k是3，那么factorial(k)的值就是6；
 *  如果k是5，那么factorial(k)的值就是120
 */
int factorial(int k) {
    int ret = 1;
    for (int i = 1; i <= k; i++) {
        ret = ret * i;
    }
    return ret;
}

int factorial_sum(int n) {
    int sum = 0;
    for (int k = 1; k <= n; k++) {
        sum = sum + factorial(k);
    }
    return sum;
}

int main() {
    printf("Please enter a number: ");
    int n;
    scanf("%d", &n);
    int answer = factorial_sum(n);
    printf("Factorial sum from 1! to %d! is %d\n", n, answer);
    return 0;
}
