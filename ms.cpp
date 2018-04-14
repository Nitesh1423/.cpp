#include<iostream>
#include<conio.h>
int time,Total_processes;
using namespace std;
int main()
{
 cout<<"process: Please enter the number: "<<endl;
 int Proc=0;
 cin>>Proc;
 
 cout<<"Please enter the burst times "<<endl;
 cin>>time;
 int Bst[20][10];
 
 
 for(int i =0;i<Proc;++i)
 {
  cin>>Bst[i][0];
  Bst[i][1]=Bst[i][0]; 
  
  Bst[i][2]=0; 
  
  Bst[i][3]=0; 
  
  Bst[i][4]=0; 
  
 }
 int t=0;
 cout<<"Please enter the time quantum: ";
 cin>>t;
 while(1)
 {
  bool resume = 0;
  for(int i =0;i<Proc;++i)
  {
   if(Bst[i][4]==0)
   {
    resume = 1;
    break;
   }
  }
 
  if(resume)
  {
   for(int i =0;i<Proc;++i)
   {
    if(Bst[i][1]<=time)
    {
     for(int j=0;j<Proc;++j)
     {
      if(i==j)
       continue;
      else if(Bst[j][4]==0)
      Bst[j][2]+=Bst[i][1];
     }
     Bst[i][1]=0;
     Bst[i][4]=1;
    }
    else if(Bst[i][1]>t)
    {
     Bst[i][1]-=t;
     for(int j =0;j<Proc;++j)
     {
      if(i==j)
       continue;
      else if(Bst[j][4]==0)
      Bst[j][2]+=t;
     }
    }
   }
  }
  else if(!resume)
   break;
 }
 float AvgWaitTime =0, AvgTurnAroundTime =0;
 
  for(int i=0;i<Proc;++i)
  {
     Bst[i][3] = Bst[i][0]+Bst[i][2];
  AvgWaitTime+=Bst[i][2];
  AvgTurnAroundTime+=Bst[i][3];
  }
  AvgWaitTime/=Proc;
  AvgTurnAroundTime/=Proc;
 
   
   for(int i = 0;i<Proc;++i)
   {
     cout<<"Total_Processesess ID is =  "<<i<<endl;
     cout<<"Burst time is = "<<Bst[i][0]<<endl;
     cout<<"Waiting time is= "<<Bst[i][2]<<endl;
     cout<<"Turn Around Time  is= "<<Bst[i][3]<<endl;
     cout<<endl<<endl;
   }
   cout<<"Average turn around time is = "<<AvgTurnAroundTime<<endl;
   cout<<"Average waiting time is = "<<AvgWaitTime<<endl;
}
