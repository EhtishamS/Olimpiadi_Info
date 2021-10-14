#include<bits/stdc++.h>

using namespace std;

int main ()
{
  int coordinate, num=5, flag=0, cont=0, sum=0;

  cin>>coordinate;

  while(coordinate!=0)
  {
    if(num<=coordinate)
    {
      cont++;
      coordinate=coordinate-num;
    }
    else if(num>coordinate)
    {
      for(int i=1; i<=5&&flag==0;i++)
      {
        if(coordinate==i)
        {
          cont++;
          flag=1;
          coordinate=0;
        }
      }
    }
  }
  cout<<cont;
}
