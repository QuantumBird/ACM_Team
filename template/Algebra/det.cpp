#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const int maxr = 20;
const int maxc = 20;

struct Mat{
    ll m[maxr][maxc];
    int rows, cols;
    Mat(int r, int c):
        rows(r), cols(c){};
    Mat(){}
    ll * operator[](int i){
        return m[i];
    }
};
istream & operator>>(istream & in, Mat & a){
    in>>a.rows>>a.cols;
    for(int i = 0; i < a.rows; i ++)
        for(int j = 0; j < a.cols; j ++)
            cin>>a[i][j];
    return in;
}
ostream & operator<<(ostream & out, Mat a){
    for(int i = 0; i < a.rows; i ++){
        out<<a[i][0];
        for(int j = 1; j < a.cols; j ++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    return out;
}
ll det(Mat & a){
    if(a.rows != a.cols)
        return LLONG_MAX;
    if(a.rows == 2)
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    ll tmp = 0;
    int size = a.rows;
    for(int i = 0; i < size; i ++){
        Mat t;
        t.rows = t.cols = size - 1;
        for(int p = 0; p < size - 1; p ++){
            for(int q = 0; q < size - 1; q ++){
                if(q < i)
                    t[p][q] = a[p + 1][q];
                else
                    t[p][q] = a[p + 1][q + 1];
            }
        }
        if(i & 1 == 0)
            tmp += a[0][i]*det(t);
        else if(i & 1)
            tmp -= a[0][i]*det(t);
    }
    return tmp;
}


int main(){
    Mat a;
    cin>>a;
    cout<<det(a);
    return 0;
}

