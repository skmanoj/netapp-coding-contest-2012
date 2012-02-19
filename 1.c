/*
   Author: S.K.Manoj, IIIT-H
   Time complexity: O(n)
   Space Complexity: O(1)
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
char *output1[10000];
void fun(int n,char *s[])
{
   
   int len,j=0,sol;
   for(j=0;j<n;j++)
     output1[j]=malloc(sizeof(char)*8);
        
   for(j=0;j<n;j++)
   {
   char buf[8],end[8]="0";
   strcpy(buf,s[j]);
   sol=atoi(buf);
   if(sol<=0)
   {
     output1[j]="-1";
     continue;
   } 
   while(1)
   {
   len=strlen(buf);
   if(len==1)
   {
    strcat(end,buf);
    strcpy(buf,end);
    len=strlen(buf); 
   }
   int x=len,i;
   if(len>=2)
   {
   while(x>=2)
   {
     if('1'<=buf[x-1] && buf[x-1]<='9' && '0'<=buf[x-2] && buf[x-2]<='8')
     {
       buf[x-1]-=1;
       buf[x-2]+=1;
       if(x==len)
         break;
       int sum=0;  
       for(i=len-1;i>=x-1;i--)  
       {
          sum=sum+(buf[i]-'0');
          buf[i]='0';
       }
       for(i=len-1;i>=x-1;i--)
       {
         if(sum>=9)
         {
           buf[i]='0'+9;
           sum-=9;
         }  
         else if(sum<9)
         {
           buf[i]='0'+sum;  
           break;
         }  
       }  
          
   /*    for(i=len-1;i>x-1;i--)
       {
         if(buf[x-1]=='0')
           break;
         int diff='9'-buf[i];
         if(diff==0)
           continue;
         else if(buf[x-1]-diff >= '0')  
         {
           buf[i]+=diff;
           buf[x-1]-=diff;
         }  
         else if(buf[x-1]-diff < '0')  
         {
           buf[i]+=buf[x-1]-'0';
           buf[x-1]='0';
         }
       }*/
       break;
     }
    x--;
  }

  }
  if(sol==atoi(buf))
  {
//    strcat(end,buf);
//    strcpy(buf,end);
      output1[j]="-1"; 
      break;	 
//    continue;
  }  
  else
  {
    strcpy(output1[j],buf);
    break;
  }    
  }
  //end
  }
}

int main()
{
  int n=3;
  
  char *a[]={"0990","101000","50"};
  fun(n,a);
  int i=0;
  for(i=0;i<n;i++)
    printf("%s\n",output1[i]);
  return 0;
}