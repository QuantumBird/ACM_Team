const int maxn = 2e5 + 1;

int a[maxn];
int suma[maxn];
int sumb[maxn];
int n;

inline int lowbit(int x) {
    return x & (- x);
}

void update(int i, int k) {
    int x = i;
    while(i <= n) {
        suma[i] += k;
        sumb[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int getSum(int i) {
    int res = 0, x = i;
    while(i > 0) {
        res += x * suma[i] - sumb[i];
        i -= lowbit(i);
    }
    return res;
}

void updateInit(int arr[], int len) {
    for(int i = 0; i < len; i ++) {
        int diff = (i? arr[i] - arr[i - 1]: arr[i]);
        update(i + 1, diff);
    }
}

inline void updateRange(int l, int r, int k) {
    update(l, k);
    if(r < n)
        update(r + 1, -k);
}

inline int getRangeSum(int l, int r) {
    int ret = getSum(r);
    if(l > 1)
        ret -= getSum(l - 1);
    return ret;
}

