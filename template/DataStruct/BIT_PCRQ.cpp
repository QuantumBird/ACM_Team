const int maxn = 2e5 + 1;

int a[maxn];    // original array
int c[maxn];    // binary index tree array
int n;          // length of the range which will be queried

inline int lowbit(int x) {
    return x & (- x);
}

// add k on position i
void update(int i, int k) {
    while(i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

// get the sum from 1 to i
int getSum(int i) {
    int res = 0;
    while(i > 0) {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

// warning: remember to use 'n' (global variable)
//          do not define yourself 'n' in the func main
//                                  
//                                  2019.08.12 18:45 gjz
