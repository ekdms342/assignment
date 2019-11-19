#include <iostream>
#include <array>
using namespace std;

void print_arr(array<int, 16>& ar){
    for(auto s: ar) {
        cout << s;
    }
    cout << endl;
}

void code_symbol(int n) {
    int state = 0;
    if(n<0) {
        state = 1;
        n = -n;
    }
    array<int, 16> ar;
    for(int i=15; i>0; --i){
        ar[i] = n%2;
        n/=2;
    }
    ar[0] = state;
    print_arr(ar);
}

void one_complement(int n) {
    int state = 0;
    if(n<0) {
        n = -n;
        state = 1;
    }
    array<int, 16> ar;
    for(int i=15; i>=0; --i){
        ar[i] = n%2;
        n/=2;
    }

    if(state==1)
        for(int i=0; i<16; ++i) {
            ar[i] = !ar[i];
        }
    print_arr(ar);
}

void two_complement(int n) {
    int state = 0;
    if(n<0) {
        state = 1;
        n = -n;
    }
    array<int, 16> ar;
    for(int i=15; i>=0; --i){
        ar[i] = n%2;
        n/=2;
    }
    if(state==1){
        int n;
        for(n=15; ar[n]==0 && n>=0; --n)
            ;
        if(n>=0) {
            for(int i=n-1;i>=0;--i) {
                ar[i] = !ar[i];
            }
        }
    }
    print_arr(ar);
}

int main(void) {
    int n;
    cin >> n;
    code_symbol(n);
    one_complement(n);
    two_complement(n);
    return 0;
}
