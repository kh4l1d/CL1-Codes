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
    while((i < h) && (key >= a[i])) // increment i value when the key is greater or equal to the Ith element of the array 
      i++;

    while(key < a[j]) // decrement from the right side till it is greater then key 
      j--;

    if(i<j) //swap the elements only if this condition satisfies 
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    else // this is when we finally get the keys actual position and then we divide the whole array in 2 parts (< pivot(key) >)
    {
      temp = a[l];
      a[l] = a[j];
      a[j] = temp;
      return j;
    }
  }
}

void quicksort(int a[],int l,int h) //l=lower bound h= upper bound ie first and last element of the array/subarray
{
  int j;

    if(l<h)
    {
      j = partition(a,l,h);
      cout<<"Pivot element "<<j<<"has been found out by thread "<<k<<"\n\n";

      #pragma omp parallel sections // just recursively do the same things for the sub arrays 
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
  cout<<"\nEnter the number of elements in the array that you want to sort: ";
  cin>>n;
  int a[n];
  cout<<"\nEnter all "<<n<<" numbers : ";
  for(i=0;i<n;i++)
    cin>>a[i];

  quicksort(a,0,n-1);

  cout<<"\n\nAfter sorting using quick sort we get : \n";
  for(i=0;i<n;i++)
    cout<<a[i]<<"\t";

    cout<<"\n";
    return 0;
}
