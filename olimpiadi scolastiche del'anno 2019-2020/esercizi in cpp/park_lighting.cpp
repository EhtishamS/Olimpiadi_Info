/*
Due to the coronavirus pandemic, city authorities obligated citizens to keep a 
social distance. The mayor of the city Semyon wants to light up Gluharniki park 
so that people could see each other even at night to keep the social distance.
The park is a rectangular table with n rows and m columns, where the cells of the 
table are squares, and the boundaries between the cells are streets. External borders 
are also streets. Every street has length 1. For example, park with n=m=2 has 12 
streets. You were assigned to develop a plan for lighting the park. You can put 
lanterns in the middle of the streets. The lamp lights two squares near it 
(or only one square if it stands on the border of the park).
*/

#include<bits/stdc++.h> 	
using namespace std;

int main ()
{
	int t;
	
	cin>>t; 
	
	while(t--){	
		int m, n; cin>>n>>m;
		int sum = n*m;
		if(sum%2==0) {
			sum/=2;
		}
		else{
			sum=(sum/2)+1;
		}
		cout<<sum<<endl;
	}
		
	return 0;
}


/*

qui non ha utilizzato il ciclo for.
int main()
{
	int T;cin>>T;
	while(T--){
		int m,n;cin>>m>>n;
		
		int sum=m*n;
		if(sum%2==0){
			sum/=2;
		} else{
			sum=sum/2+1;
		}
		
		cout<<sum<<endl;	
	}
	
	return 0;
}
*/
