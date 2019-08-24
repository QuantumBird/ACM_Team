#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T --){
        int b, p, f, h, c;
        cin>>b>>p>>f>>h>>c;
        if(2*(p + f) <= b){
            cout<<(h*p + f*c)<<endl;
        }else{
            int cando = b / 2;
            int ans = 0;
            if(h > c){
                if(cando >= p){
                    ans += p*h;
                    cando -= p;
                }else{
                    ans += cando*h;
                    cando = 0;
                }
                if(cando >= f){
                    ans += f*c;
                    cando -= f;
                }else{
                    ans += cando*c;
                    cando = 0;
                }
            }else{
                if(cando >= f){
                    ans += f*c;
                    cando -= f;
                }else{
                    ans += cando*c;
                    cando = 0;
                }
                if(cando >= p){
                    ans += p*h;
                    cando -= p;
                }else{
                    ans += cando*h;
                    cando = 0;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}