/* 4.4 AIM: Cashier at any mall needs to give change of an amount to customers many times in a day. Cashier has multiple number of coins available with different denominations which is described by a set C. Implement the program for a cashier to find the minimum number of coins required to find a change of a particular amount A. Output should be the total number of coins required of given denominations. Check the program for following test cases:
Is the output of Test case 2 is optimal? Write your observation.

*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
 using namespace std;
int main()
{
    int c,n;
    cout<<"Enter available coines size : ";
    cin>>n;
    int deno[n];
    for(int i=0;i<n;i++)
        cin>>deno[i];
    cout<<"Enter Number of change for : ";
    cin>>c;
    sort(deno,deno+n,greater<int>());
    vector<int> res;
    if(c==0)
        cout<<"Enter Some value";
    else{
        /*a:*/
        for(int i=0;i<n;i++){
        	if(c==0){
            	cout<<"change of coins are : ";
            	for (int x : res)
                	cout << x << " ";
            	break;
        	}
        	else{
            	if(deno[i]<=c){
                	res.push_back(deno[i]);
                	c-=deno[i];
           	     i=-1;
                	continue;
                	/*goto a;*/
            	}
        	}
        }
    }
    return 0;
}
