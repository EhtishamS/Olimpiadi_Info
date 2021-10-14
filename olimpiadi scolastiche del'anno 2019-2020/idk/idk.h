#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 100

// Pulizia console Windows
void cls() 
{
    system("cls");
}

// Pulizia console OS basati su Unix
void clear() 
{
    system("clear");
}

// Generatore di numeri casuali da 0 a randMax
int randNum(int randMax) 
{
    int randNum;
    
    srand(time(0));
    randNum = 1 + rand() % randMax;
    
    return randNum;
}

int num pari(int num)
{
	int div=2, i;
	
	if(num%2==0)
	{
		i=num;
	}
	return i;
}

int num primo(int num)
{
	int div=2, i, primo=1;
	
	char num_primo[MAX]; 
	
	while((div<num) && (primo = 1))
	{
		if(div%2==0)
		{
			primo = 0;
		}
		div++;
	}
	
	if (primo == 1)
	{
		num_primo = "Il numero non e' primo!";
	}
	else
	{
		num_primo = "Il numero e' primo!";
	}
	
	return num_primo;
}

int fatt_num(int num)
{
	int ris=1;
	
	for(i=0;i<num;i++)
	{
		ris = ris*i;
	}
	return ris;
}




/*Bool primo(int num) 
{
    int contatore, i;
    _Bool esito;
    
    contatore = 0;

    for (i = 0; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            contatore++;
        }
    }
    
    if (contatore == 1)
    {
        esito = 0;
    }
    else
    {
        esito = 1;
    }
    
    return esito;
}*/

