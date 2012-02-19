/*
   Author: S.K.Manoj, IIIT-H
   Used dynamic programming to calculate output
   Time complexity: O(n^2)
   Space Complexity: O(n^2)
   input output format:
   manoj@manoj-laptop:~/Desktop/netapp$ gcc 2.c -Wall
   manoj@manoj-laptop:~/Desktop/netapp$ ./a.out 
   163 ->output
*/
#include<stdio.h>
#include<malloc.h>
int output1;
int max(int a,int b)
{
   if(a>=b)
     return a;
   return b;  
}
void dp(int n,char *s)
{
  int **val,i,j,**a;
  a=malloc(sizeof(int*)*n);
  for(i=0;i<n;i++)
    a[i]=malloc(sizeof(int)*n);
   i=1;
   int x=0,y=0;
   while(1)
   {
     if(s[i]<'0' || s[i] > '9')
     {
       i++;
       continue;
     }
   else
     {
       while(y<n)
       {
       int val=s[i]-'0';
       i++;
       while(s[i]!=',' && s[i]!=')')
       {
         val=(val*10)+(s[i]-'0');
         i++;
       }
       a[x][y]=val;
       y++;
       i++;
       }
       x++;
       y=0;
     }  
     if(x==n)
         break;
   }   
  val=malloc(sizeof(int*)*(n+1));
  for(i=0;i<n+1;i++)
    val[i]=malloc(sizeof(int)*(n+1));
  for(i=0;i<n+1;i++)
  {
    val[i][0]=0;
    val[0][i]=0;
  }  
  for(i=1;i<n+1;i++)
  {
    for(j=1;j<n+1;j++)
    {
       val[i][j]=max(val[i-1][j],val[i][j-1])+a[i-1][j-1];
    }
  }
  output1=val[n][n];
}
int main()
{
  dp(4,"(1,7,5,2),(5,12,3,6),(100,9,23,16),(16,4,5,9)");
  printf("%d",output1);
  return 0;
}