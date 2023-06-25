#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define N 40321
int map[N];
//一共有8!=40320中状态，思路来源于https://blog.csdn.net/SourDumplings/article/details/88370626
int fac[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

struct Board {
    int di;        //上一个状态
    int val;       //值
    char str[9];
    void foo();
} m[2 * N], ex;

void Board::foo() {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        int tmp = 0;
        for (int j = i + 1; j < 8; j++) {
            if (this->str[j] < this->str[i]) tmp++;
        }
        num += tmp * fac[7 - i];
    }
    this->val = num;
}

void Init(char s[9]) {
    int rear = 0;
    int tail = 1;
    strcpy(m[0].str, s);
    m[0].foo();
    while (rear < tail) {
        if (map[m[rear].val]) {
            rear++;
            continue;
        }
        map[m[rear].val] = map[m[m[rear].di].val] + 1;
        // 交换行
        for (int i = 0; i < 8; i++)
            m[tail].str[(i + 4) % 8] = m[rear].str[i];
        m[tail].foo();
        if (!map[m[tail].val]) {
            m[tail].di = rear;
            tail++;
        }
        //左移
        for (int i = 0; i < 4; i++)
            m[tail].str[(i + 3) % 4] = m[rear].str[i];
        for (int i = 4; i < 8; i++)
            m[tail].str[(i + 3) % 4 + 4] = m[rear].str[i];
        m[tail].foo();
        if (!map[m[tail].val]) {
            m[tail].di = rear;
            tail++;
        }
        //通过哈希表建立映射(康托展开)，思路来源于https://blog.csdn.net/SourDumplings/article/details/88370626
        // 中心旋转
        strcpy(m[tail].str, m[rear].str);
        m[tail].str[5] = m[rear].str[1];
        m[tail].str[1] = m[rear].str[2];
        m[tail].str[2] = m[rear].str[6];
        m[tail].str[6] = m[rear].str[5];
        m[tail].foo();
        if (!map[m[tail].val]) {
            m[tail].di = rear;
            tail++;
        }
        rear++;
    }
}

int main() {
    Init("12348765");
    int T;
    scanf("%d", &T);
    while (T--) {
        int tmp;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &tmp);
            ex.str[i] = tmp + '0';
        }
        for (int i = 4; i < 8; i++) {
            scanf("%d", &tmp);
            ex.str[(8 - i) + 3] = tmp + '0';
        }
        ex.foo();
        printf("%d\n", map[ex.val] - 1);
    }
    return 0;
}