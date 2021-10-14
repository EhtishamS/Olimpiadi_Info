/*
Linear Kingdom has exactly one tram line. It has n stops, 
numbered from 1 to n in the order of tram's movement. At the 
i-th stop ai passengers exit the tram, while bi passengers 
enter it. The tram is empty before it arrives at the first 
stop. Also, when the tram arrives at the last stop, all 
passengers exit so that it becomes empty.Your task is to 
calculate the tram's minimum capacity such that the number 
of people inside the tram at any time never exceeds this 
capacity. Note that at each stop all exiting passengers 
exit before any entering passenger enters the tram.
*/

/*
es: input 
4
0 3
2 5
4 2
4 0
es:output
6
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
	int n, a, b, max=0;
	
	FILE* puntatore_fileR = fopen ("input.txt", "r");
	FILE* puntatore_fileW = fopen ("output.txt", "w");
	
	fscanf(puntatore_fileR, "%d", &n);
	
	while(n--){
		fscanf(puntatore_fileR, "%d %d", &a, &b);
		if(max-a+b>max){
			max=(max-a)+b;
		}
	}
	
	fprintf(puntatore_fileW, "%d", max);
	
	fclose(puntatore_fileR);
	fclose(puntatore_fileW);
}
