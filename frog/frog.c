/*
题目：一只青蛙一次能够跳一级台阶或者两级台阶，请问这只青蛙跳上N级台阶一共有多少种跳法？
*/

/*
解：
定义函数f(x)表示青蛙跳上x级台阶的跳法种数，则：
1. f(1) = 1
2. f(2) = 2；一种是连跳两次一级，一种是直接跳一次两级台阶

青蛙要跳上第x级台阶，只有两种方式：
1. 从第 x-1 级台阶再跳一级到达第 x 级；此时青蛙跳上第 x-1 级台阶的种数是 f(x-1)
2. 从第 x-2 级台阶直接跳两级到达第 x 级; 此时青蛙跳上第 x-2 级台阶的种数是 f(x-2)

那么我们有: f(x) = f(x-1) + f(x-2)
*/

#include <stdio.h>

// 递归的解法是：
int frog(int x) {
    if (x == 1) {
        return 1;
    } else if (x == 2) {
        return 2;
    }
    return frog(x - 1) + frog( x - 2);
}

// 我们发现 f(x) = f(x-1) + f(x-2) 其实就是斐波那契数列。那么迭代的解法也比较明显了：
int frog(int x) {
    int a = 1;
    int b = 1;
    int c = 1;

    while (x > 1) {
        c = a + b;
        a = b;
        b = c;

        x--;
    }

    return c;
}

int main() {
    while (1) {
        int x;

        scanf("%d", &x);

        if (x <= 0) {
            break;
        }

        printf("frog(%d): %d\n", x, frog(x));
    }
    return 0;
}