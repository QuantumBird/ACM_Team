const int maxn = 2e5 + 1;

int a[maxn];    // original array
int c[maxn];    // binary index tree difference affay
int n;          // the length of range (1 ~ n, include 1 and n)

// c[i] = A[i] - A[i - 1]

// same as BIT_PCPQ
inline int lowbit(int x) {
    return x & (- x);
}

void update(int i, int k) {
    while(i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

int getSum(int i) {
    int ret = 0;
    while(i > 0) {
        ret += c[i];
        i -= lowbit(i);
    }
    return ret;
}

// func updateInit: init the c[i] from arr[]
// notice: arr[]' s start from 0 (arr[]: 0 ~ n - 1)
void updateInit(int arr[], int len) {
    memset(c, 0, sizeof(c));
    for(int i = 0; i < len; i ++) {
        int diff = (i? a[i] - a[i - 1]: a[i]);
        update(i + 1, diff);
    }
}

// func updateRange: add k to the range from l to r
inline void updateRange(int l, int r, int k) {
    update(l, k);
    update(r + 1, -k);
}

// use func getNum to get number in position i
#define getNum getSum


