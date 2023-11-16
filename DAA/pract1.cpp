#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Fibo {
    public:
    int recursive_fib(int n) {
        if(n<=1)
            return n;

        return recursive_fib(n-1) + recursive_fib(n-2);
    }

    void iterative_fib(int n) {
        int t1 = 0;
        int t2 = 1;
        int next;
        for(int i=1; i<=n; i++) {
            if(i==1)
            {
                cout<<t1<<' ';
                continue;
            }
            if(i==2) {
                cout<<t2<<' ';
                continue;
            }
            next = t1 + t2;
            t1 = t2;
            t2 = next;

            cout<<next<<' ';
        }
    }
};

int main() {
    int n; cin>>n;

    Fibo fib = Fibo();

    fib.iterative_fib(n);
    cout<<endl;
    for(int i=0; i<n; i++) {
        cout<<fib.recursive_fib(i)<<' ';
    }
    cout<<endl;

    return 0;
}
