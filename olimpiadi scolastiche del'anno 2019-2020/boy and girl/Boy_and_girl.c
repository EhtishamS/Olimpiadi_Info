/*
Those days, many boys use beautiful girls' photos as avatars in forums. So it is 
pretty hard to tell the gender of a user at the first glance. Last year, our hero 
went to a forum and had a nice chat with a beauty (he thought so). After that they 
talked very often and eventually they became a couple in the network. But yesterday, 
he came to see "her" in the real world and found out "she" is actually a very strong 
man! Our hero is very sad and he is too tired to love again now. So he came up with 
a way to recognize users' genders by their user names. This is his method: if the
number of distinct characters in one's user name is odd, then he is a male, otherwise 
she is a female. You are given the string that denotes the user name, please help our 
hero to determine the gender of this user by his method.
*/

/*
output, if is a girl than say "CHAT WITH HER!" otherwise "IGNORE HIM!"
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100


int main (){
	
	char username[MAX];
	FILE* puntatore_fileW = fopen("output.txt", "w");
	FILE* puntatore_fileR = fopen("input.txt","r");
	
	if(puntatore_fileR == NULL){
		printf("file non aperto correttamente!");
		exit(0);
	}
	
	while(!feof(puntatore_fileR)){
		fgets(username, MAX, puntatore_fileR);
	}
	
	
	char vetout[MAX];
	
	if(strlen(username)%2==0){
		strcpy(vetout, "chat with her!");
	}
	else{
		strcpy(vetout, "chat with him!");
	}

	
	fprintf(puntatore_fileW,"%s", vetout);
	
	fclose(puntatore_fileW);
	fclose(puntatore_fileR);
	
	return 0;
}
