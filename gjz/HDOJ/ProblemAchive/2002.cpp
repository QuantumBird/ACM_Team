#include <cstdio>
const double PI = 3.1415927;
int main(){
    double r;
    while(~scanf("%lf", &r))
        printf("%.3lf\n", 4.0*r*r*r*PI/3.0);
    return 0;
}

