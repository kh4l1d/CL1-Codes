// Author: Khalid - naam toh suna hi hoga
// Steps to run ->
// :~$ g++ yoyo.cpp
// :~$ ./a.out

#include<iostream>
using namespace std;

int main()
{
    int n,i,key;

    cout<<"\nEnter the length of array :";
    cin>>n;

    int a[n];

    cout<<"\nPlease enter all "<<n<<" numbers in ascending order :";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"\nPlease enter the number to be searched : ";
    cin>>key;

    int left=0,right=(n-1);
    int mid=((left+right)/2);

    while(left <= right)
    {
        if(a[mid] == key)
        {
            cout<<"\n"<<key<<" was found at position "<<(mid+1)<<" !!";
            break;
        }
        else if(a[mid] < key)
            left = mid+1;
        else
            right = mid-1;

        mid = ((left+right)/2);   // remember to modify the mid
    }

    if(left > right)
        cout<<"\nThe number "<<key<<" is not in the array of numbers you entered.";

    return 0;
}
