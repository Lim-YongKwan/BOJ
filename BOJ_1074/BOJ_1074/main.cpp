//
//  main.cpp
//  BOJ_1074
//
//  Created by 임 용관 on 2022/05/03.
//

#include <iostream>
#include<math.h>
#define endl "\n"

using namespace std;

int zet(int n, int r, int c){
    
    if(n==0){
        return 0;
    }
    
    int half = pow(2,n-1);
    
    if(r >= half and c >= half){
        return 3*half*half+zet(n-1,r-half,c-half);
    }
    else if(r>=half and c<half){
        return 2*half*half+zet(n-1, r-half,c);
    }
    else if(r< half and c>=half){
        return half*half+zet(n-1, r,c-half);
    }
    else{
        return zet(n-1, r,c);
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int r, c;
    cin>>n>>r>>c;
    
    cout<<zet(n,r,c)<<endl;
    
    return 0;
}
