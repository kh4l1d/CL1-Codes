// Author: navinwbackup
// Steps to run ->
// :~$ g++ yoyo.cpp -fopenmp
// :~$ ./a.out

// For a more detailed explanation on the working of this code, check out the following link ->
// http://stackoverflow.com/questions/22587033/using-circular-permutations-to-reduce-traveling-salesman-complexity

#include<iostream>
#include<omp.h>
using namespace std;

int graph[5][5],cost = 9999;

void swap (int *x, int *y)  // the sequence of traversing cities will be traversed
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void copy_array(int *a, int n)  // got the optimal sequence - now find the optimal cost
{
    int i, sum = 0;

    #pragma omp parallel for
      for(i = 0; i < n; i++)   // the error was here - there was no need of <= - credits to Karan Chawda
      {
        sum += graph[a[i % 5]][a[(i + 1) % 5]]; // works similar to a counter
      }

    if (cost > sum)
        cost = sum;
}

void permute(int *a, int i, int n)
{
   int j, k;

   if (i == n)  // found the right permutation - all cities have been covered
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


void display_sequence(int *a,int n)
{
  int i;
  cout<<"\nThe sequence of cities to be traversed is - \n";
  for(i=0;i<n;i++)
    cout<<"City "<<a[i]<<" ->\t";
  cout<<"City "<<a[i]<<"\n";  // display all 5 cities
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
    int a[] = {0, 1, 2, 3,4}; // these are the cities to be traversed

   permute(a, 0, 4);
   cout<<"\n\n\t\tMinimum cost = "<<cost<<endl;
   display_sequence(a,4);

   return 0;
}
