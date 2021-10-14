/*
The translation from the Berland language into the Birland language is not an easy 
task. Those languages are very similar: a berlandish word differs from a birlandish 
word with the same meaning a little: it is spelled (and pronounced) reversely. For 
example, a Berlandish word code corresponds to a Birlandish word edoc. However, 
it's easy to make a mistake during the «translation». Vasya translated word s from 
Berlandish into Birlandish as t. Help him: find out if he translated the word 
correctly.
*/

/*
Input: code = odec OK
	   add = ada NO
*/

#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int main(){
	char T[MAX],S[MAX],temp[MAX];
	
	cin>>temp;
	cin>>S;
	
	for(int i=0;i<strlen(T);i++){
		for(int j=strlen(T);j>=0;j--){
			T[i]=temp[j];
			cout<<T[i];
		}
	}
	
	if(S==T){
		cout<<"OK";
	}
	else{
		cout<<"NO";
	}
}
