// Author: navinwbackup
// Steps to run ->
// :~$ g++ yoyo.cpp -fopenmp
// :~$ ./a.out

#include<iostream>
#include<omp.h>
using namespace std;

int graph[5][5],cost = 999;

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void copy_array(int *a, int n)
{
    int i, sum = 0;

    #pragma omp parallel for
      for(i = 0; i <= n; i++)   // notice the <=
      {
        sum += graph[a[i % 5]][a[(i + 1) % 5]];
      }

    if (cost > sum)
        cost = sum;
}

void permute(int *a, int i, int n)
{
   int j, k;

   if (i == n)
   {
     #pragma omp parallel sections
     {
        copy_array(a, n);
      }
   }
   else
   {
    #pragma omp parallel for
        for (j = i; j <= n; j++)
        {
          swap((a + i), (a + j));
          permute(a, i + 1, n);
          swap((a + i), (a + j));
        }
    }
}

int main()
{
    cout<<"Enter the elements for 5*5 array";
    for(int i=0;i<5;i++)
    {
        cout<<"\n Enter the elements of "<<i+1<< "th row :\t";
        for(int j=0;j<5;j++)
        {
            cin>>graph[i][j];
            cout<<"\t";
        }
        cout<<"\t";
    }
    int i, j;
    int a[] = {0, 1, 2, 3,4};
    int c = 0;

   permute(a, 0, 4);
   cout<<"\n\n\t\tminimum cost:"<<cost<<endl;
}
