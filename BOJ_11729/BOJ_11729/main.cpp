//
//  main.cpp
//  BOJ_11729
//
//  Created by 임 용관 on 2022/05/03.
//

#include <iostream>
#include<math.h>
#define endl "\n"
using namespace std;

void hanoi(int a, int b, int n){
    
    if(n==1){
        cout<<a<<' '<<b<<endl;
        return;
    }
    hanoi(a,6-a-b,n-1);
    cout<<a<<' '<<b<<endl;
    hanoi(6-a-b,b,n-1);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    hanoi(1,3,n);
    
    return 0;
}
