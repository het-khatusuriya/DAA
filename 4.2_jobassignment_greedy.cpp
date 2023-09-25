/* 
pra4.2 AIM: Suppose you want to schedule N activities in a Seminar Hall. Start time and Finish time of activities are given by pair of (si,fi) for ith activity. Implement the program to maximize the utilization of Seminar Hall. (Maximum activities should be selected.)
 */

#include <iostream>
 using namespace std;
 int main()
{
	int n;
	cout<<"Enter size of activities :";
	cin>>n;
	int s[n],f[n];
	cout<<"Enter Start time :";
	for(int i=0;i<n;i++)
    	cin>>s[i];
	cout<<"Enter Finish time :";
	for(int i=0;i<n;i++)
    	cin>>f[i];
	int i=0,j=0;
	cout<<s[0]<<" "<<f[0]<<endl;
	for(i=1;i<n;i++){
    	if(f[j]<=s[i]){
        	cout<<s[i]<<" "<<f[i]<<endl;
        	j=i;
    	}
}
	return 0;
}
