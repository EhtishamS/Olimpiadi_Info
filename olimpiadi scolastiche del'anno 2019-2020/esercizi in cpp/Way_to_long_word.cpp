#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int main (){
	char word[MAX];
	
	int n, i=0;
	cin>>n;
	
	while(i<n){
		cin>>word;
		i++;
	}
	
	for(i=0;i<n;i++){
		if(i=0){
			cout<<word[i];
		}
	}
	int temp;
	temp = strlen(word);
	temp = temp -2;
	cout<<temp;
	temp = strlen(word);
	cout<<word[temp];
	
}
