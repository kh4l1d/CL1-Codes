// Author: geeksforgeeks
// Steps to run ->
// :~$ g++ yoyo.cpp
// :~$ ./a.out

// Check out this video for the working of code - https://www.youtube.com/watch?v=R6BQ3gBrfjQ
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item
{
  float weight;
  int value;
};

struct Node
{
  int profit,bound,level;
  float weight;
};

bool cmp(Item a,Item b)
{
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

int bound(Node u,int n,int W,Item arr[])
{
  if(u.weight >= W)
    return 0;

  int j = u.level + 1;
  int totalWeight = u.weight;
  int profitBound = u.profit;
    
  while((j<n) && (totalWeight + arr[j].weight <= W))
  {
    totalWeight += arr[j].weight;
    profitBound += arr[j].value;
    j++;
  }

  if(j<n)
    profitBound += (W - totalWeight) * (arr[j].value/arr[j].weight); // get remaining fractional value
  return profitBound;
}

int knapsack(int W,Item arr[],int n)
{
  sort(arr,arr+n,cmp);

  queue<Node> Q;
  Node u,v;

  u.level = -1;
  u.profit = u.weight = 0;
  int maxProfit = 0;
  Q.push(u);

  while(!Q.empty())
  {
    u = Q.front();
    Q.pop();

    if(u.level == -1)
      v.level = 0;

    if(u.level == (n-1))
      continue;

    v.level = u.level + 1;
    v.profit = u.profit + arr[v.level].value;
    v.weight = u.weight + arr[v.level].weight;
    if((v.weight <= W) && (v.profit > maxProfit))
      maxProfit = v.profit;
    v.bound = bound(v,n,W,arr);
    if(v.bound > maxProfit)
      Q.push(v);

    v.profit = u.profit;
    v.weight = u.weight;
    v.bound = bound(v,n,W,arr);
    if(v.bound > maxProfit)
      Q.push(v);
  }
  return maxProfit;
}

int main()
{
  int W = 55;
  Item arr[] = {{10,60},{20,100},{30,120}};
  int n = sizeof(arr) / sizeof(arr[0]);
  int answer = knapsack(W,arr,n);
  cout<<endl<<"Max profit is = "<<answer<<endl;
  return 0;
}
