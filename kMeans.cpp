// Author: Khalid - naam toh suna hi hoga
// Steps to run ->
// :~$ g++ yoyo.cpp
// :~$ ./a.out

#include<iostream>
#include<math.h>
using namespace std;

// be wary of float arithmetic

int main()
{
  float points[7][3];   // considering 7 points
  float centroids[2][3];  //  considering 2 centroids
  float oldCentroids[2][3];
  int clusterCount[2];    // clusterCount[0] = no. of points in cluster 0, clusterCount[1] = no. of points in cluster 1
  /* first column               second column                 third column */
  /*     ^                             ^                            ^         */
  /* all x co-ordinates         all y co-ordinates            all cluster IDs*/

  // initializing the x&y co-ordinates of all points (the cluster IDs will be assigned later)

  points[0][0] = -1.0;
  points[0][1] = -1.0;

  points[1][0] = 1.5;
  points[1][1] = -2.0;

  points[2][0] = 3.0;
  points[2][1] = 4.0;

  points[3][0] = 5.0;
  points[3][1] = 7.0;

  points[4][0] = 3.5;
  points[4][1] = 6.0;

  points[5][0] = 9.5;
  points[5][1] = 12.0;

  points[6][0] = 14.5;
  points[6][1] = 16.5;

  // initializing the x&y co-ordinates of the 2 chosen centroids (randomly chosen from points)

  centroids[0][0] = points[0][0]; // first centroid is point 0
  centroids[0][1] = points[0][1];
  centroids[0][2] = 0;            // first centroid belongs to cluster 0

  centroids[1][0] = points[3][0]; // second centroid is point 3
  centroids[1][1] = points[3][1];
  centroids[1][2] = 1;            // second centroid belongs to cluster 1

  cout<<"\nThe original centroids are -> \n";
  cout<<"("<<centroids[0][0]<<","<<centroids[0][1]<<") and ("<<centroids[1][0]<<","<<centroids[1][1]<<") !!!";

  bool hasAchievedPerfectCentroids = false;
  int i;

  while(!hasAchievedPerfectCentroids) // the loop should run till we get the perfect centroids
  {

  for(i=0;i<2;i++)
  {
    oldCentroids[i][0] = centroids[i][0];
    oldCentroids[i][1] = centroids[i][1];
    oldCentroids[i][2] = centroids[i][2]; // good cpp practice to initialize stuff - coz there's no auto garbage collection
  }


  // now we assign the cluster IDs to each point

  for(i=0;i<7;i++)
  {
    float min = 10000.0;
    for(int j=0;j<2;j++)
    {
      // use distance formula
    float distance = sqrtf((powf((centroids[j][1] - points[i][1]),2))+(powf((centroids[j][0]) - points[i][0],2)));

      if(distance < min)  // find the minimum distance of each point to each cluster
      {
        min = distance;
        points[i][2] = j;   // points which are closer to a cluster get that clusterID
      }
    }
  }

  // now each point has a cluster ID

  // it's time to find the new centroids
  // but firstly,let's reintialize the existing centroids (THE CLUSTER IDS REMAIN THE SAME !!)

  for(i=0;i<2;i++)
  {
    centroids[i][0] = 0;
    centroids[i][1] = 0;
  }

  // we simply find the centroids - average style (for EACH cluster)
  // find the sum of all points in each cluster and divide them by the number of points in that cluster

  clusterCount[0] = 0;
  clusterCount[1] = 0;

  for(i=0;i<7;i++)
  {
    if(points[i][2] == 0)   // belongs to cluster 0
    {
      clusterCount[0]++;
      centroids[0][0] += points[i][0];
      centroids[0][1] += points[i][1];
    }
    else    // belongs to cluster 1
    {
      clusterCount[1]++;
      centroids[1][0] += points[i][0];
      centroids[1][1] += points[i][1];
    }
  }

  for(i=0;i<2;i++)
  {
    centroids[i][0] = (centroids[i][0] / clusterCount[i]);  // be careful of the indices
    centroids[i][1] = (centroids[i][1] / clusterCount[i]);
  }

  hasAchievedPerfectCentroids = true; // assuming we have got the perfect centroids

  for(i=0;i<2;i++)  // if oldCentroids are the same as centroids -  it means we have achieved perfect centroids
  {
    if((centroids[i][0] != oldCentroids[i][0]) || (centroids[i][1] != oldCentroids[i][1]))
    {
      hasAchievedPerfectCentroids = false;  // if there's even a slight mismatch, we have not yet achieved perfect centroids
      break;
    }
  }

}
  // finally done !!

  cout<<"\n\nPoint"<<"\t\t"<<"Cluster ID"<<"\n";

  for(i=0;i<7;i++)
    cout<<(i+1)<<"\t\t"<<points[i][2]<<"\n";

  cout<<"\n\nAnd the new centroids are -> \n";
  cout<<"("<<centroids[0][0]<<","<<centroids[0][1]<<") and ("<<centroids[1][0]<<","<<centroids[1][1]<<") !!!\n\n";

  return 0;
}
