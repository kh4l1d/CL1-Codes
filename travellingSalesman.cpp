// Author: Huzefa Ali (zef78652@gmail.com)
// Steps to run ->
// :~$ g++ yoyo.cpp -fopenmp
// :~$ ./a.out
 
// ****  Fixed sequence of traversal - thanks Huzefa Ali ****

#include<iostream>
#include<omp.h>
using namespace std;
int x[5];
int matrix[4][4]={{0, 10, 15, 20},

                    {10, 0, 35, 25},

                    {15, 35, 0, 30},

                    {20, 25, 30, 0}

                  },cost=999;

void swap(int *x,int *y){
int temp=*x;
*x=*y;
*y=temp;

}

void copy(int *a,int n){
	int dist=0;
		#pragma omp parallel for
	for(int i=0;i<=n;i++){
		dist+=matrix[a[i%4]][a[(i+1)%4]];
	        x[i]=a[i%4];
		}
	if(cost>dist){
	cost=dist;
	}
  
}

void disp(int *x,int n){
	int i;
	cout<<"\npath followed is: "<<endl;
	for(i=0;i<n;i++)
	cout<<"city "<<x[i]<<"-->";
	cout<<"city "<<x[i]<<endl;
	
}

void permute(int *a,int i,int n){
	int j;	
	if(i==n){
	#pragma omp parallel sections
		{
		copy(a,n);
		}	
	}
	else{

		for( j=i;j<=n;j++){
		swap((a+i),(a+j));
		permute(a,i+1,n);
		swap((a+i),(a+j));
		}
	}
}

int main(){
	int n=4;
	int a[]={0,1,2,3};
	permute(a,0,n-1);
	cout<<"min cost is: "<<cost<<endl;
	disp(x,n-1);
	return 0;
}
