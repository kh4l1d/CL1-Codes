// Author: Khalid - naam toh suna hi hoga
// Steps to run ->
// :~$ g++ yoyo.cpp -fopenmp
// :~$ ./a.out

#include<iostream>
#include<omp.h>
using namespace std;

int k = 0;

int partition(int a[],int l,int h)
{
  int i,j,temp,key;
  key = a[l];
  i = l + 1;
  j = h;
//bbbbbbbbbbbbbbbb
  while(1)
  {
    while((i < h) && (key >= a[i]))
      i++;

    while(key < a[j])
      j--;

    if(i<j)
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    else
    {
      temp = a[l];
      a[l] = a[j];
      a[j] = temp;
      return j;
    }
  }
}

void quicksort(int a[],int l,int h)
{
  int j;

    if(l<h)
    {
      j = partition(a,l,h);
      cout<<"Pivot element "<<j<<"has been found out by thread "<<k<<"\n\n";

      #pragma omp parallel sections
      {
        #pragma omp section
        {
          k++;
          quicksort(a,l,j-1);
        }

        #pragma omp section
        {
          k++;
          quicksort(a,j+1,h);
        }
      }
    }
}

int main()
{
  int n,i;
  cout<<"\nEnter the number of elements : ";
  cin>>n;
  int a[n];
  cout<<"\nEnter all "<<n<<" numbers : ";
  for(i=0;i<n;i++)
    cin>>a[i];

  quicksort(a,0,n-1);

  cout<<"\n\nAfter sorting using quick sort : \n";
  for(i=0;i<n;i++)
    cout<<a[i]<<"\t";

    cout<<"\n";
    return 0;
}
