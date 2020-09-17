/* 问题描述：如上所示，由正整数1，2，3……组成了一颗特殊满二叉树。我们已知这个二叉树的最后一个结点是n。现在的问题是，结点m所在的子树中一共包括多少个结点。     比如，n = 12，m = 3那么上图中的结点13，14，15以及后面的结点都是不存在的，结点m所在子树中包括的结点有3，6，7，12，因此结点m的所在子树中共有4个结点。
 *
 * 输入描述：输入数据包括多行，每行给出一组测试数据，包括两个整数m，n (1 <= m <= n <= 1000000000)。
 *
 * 输出描述：对于每一组测试数据，输出一行，该行包含一个整数，给出结点m所在子树中包括的结点的数目。
 */

#include <iostream>
#include <cmath>

using namespace std;

int fix(int n) {
    int fl = 0;
    while (n > 1) {
        n /= 2;
        fl++;
    }
    
    return fl;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        int fm = fix(m), fn = fix(n);
        int left = m << (fn-fm), dur = pow(2, fn-fm);
        int sum = 0, line = 1;
        for (int i = 1; i <= fn-fm; i++) {
            sum += line;
            line *= 2;
        }
        if (n >= left+dur) sum += dur;
        else if (n >= left) sum += n-left+1;
        printf("%d\n", sum);
    }
    
    return 0;
}
