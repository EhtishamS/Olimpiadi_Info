/*
Giorgio, famous university teacher, tomorrow is going to do the surveillance 
during his exam of Compet-itive Programming. In fact, even though the students are 
usually very honest, there is always someonethat tries to cheat. To prevent it, 
Giorgio is studying a disposition for the students in the room thatmaximizes the 
distance between each student.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

int main (){
	int i, R, C, K;
	
	FILE* puntatore_fileW = fopen ("output.txt", "w");
	FILE* puntatore_file = fopen("input.txt", "r");
	if(puntatore_file == NULL || puntatore_fileW == NULL){
		printf("file non aperto correttamento!");
		exit(0);
	}
	fscanf(puntatore_file, "%d %d %d", &R, &C, &K);
	
	int prim, sec;
	if(R%K==0){
		prim = R/K;
	}
	else{
		prim = (R/K)+1;
	}
	
	if(C%K==0){
		sec = C/K;
	}
	else{
		sec = (C/K)+1;
	}
	int num;
	num = prim*sec;
	fprintf(puntatore_fileW, "%d", num);		
	fclose(puntatore_file);
	fclose(puntatore_fileW);
}
