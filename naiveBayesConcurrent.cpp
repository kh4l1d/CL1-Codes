//Author - Kshitij Nikhal
// Steps to run ->
// :~$ g++ yoyo.cpp -fopenmp
// :~$ ./a.out

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <omp.h>


using namespace std;

int main(){

	string observations[10][4];

	observations[0][0] = "Consultancy";
    observations[1][0] = "Service";
    observations[2][0] = "Research";
    observations[3][0] = "Service";
    observations[4][0] = "Consultancy";
    observations[5][0] = "Research";
    observations[6][0] = "Research";
    observations[7][0] = "Service";
    observations[8][0] = "Consultancy";
    observations[9][0] = "Research";

    observations[0][1] = "30";
    observations[1][1] = "21";
    observations[2][1] = "26";
    observations[3][1] = "28";
    observations[4][1] = "40";
    observations[5][1] = "35";
    observations[6][1] = "27";
    observations[7][1] = "32";
    observations[8][1] = "45";
    observations[9][1] = "36";

    observations[0][2] = "Ph.D";
    observations[1][2] = "MTech";
    observations[2][2] = "MTech";
    observations[3][2] = "BTech";
    observations[4][2] = "MTech";
    observations[5][2] = "Ph.D";
    observations[6][2] = "BTech";
    observations[7][2] = "MTech";
    observations[8][2] = "BTech";
    observations[9][2] = "Ph.D";

    observations[0][3] = "9";
    observations[1][3] = "1";
    observations[2][3] = "2";
    observations[3][3] = "10";
    observations[4][3] = "14";
    observations[5][3] = "10";
    observations[6][3] = "6";
    observations[7][3] = "9";
    observations[8][3] = "17";
    observations[9][3] = "7";


    string uniqueJobs[3];
    uniqueJobs[0] = "Consultancy";
    uniqueJobs[1] = "Service";
    uniqueJobs[2] = "Research";

    int uniqueJobsCount[3];
    uniqueJobsCount[0] = 0;
    uniqueJobsCount[1] = 0;
    uniqueJobsCount[2] = 0;

    double uniqueJobsProbability[3];

    for(int i=0;i<10;i++){
    	if(observations[i][0] == uniqueJobs[0])
    		uniqueJobsCount[0]++;

    	if(observations[i][0] == uniqueJobs[1])
    		uniqueJobsCount[1]++;

    	if(observations[i][0] == uniqueJobs[2])
    		uniqueJobsCount[2]++;
    }

    #pragma omp parallel for
     for(int i=0 ; i<3 ; i++)
     	uniqueJobsProbability[i] = ((double)uniqueJobsCount[i] / 10.0);


     int ageGreaterThan30Count[3] = {0,0,0};
     double ageProbability[3] = {0,0,0};
      for(int i=0 ; i<10 ; i++){

      	int age = atoi(observations[i][1].c_str());
      	if(observations[i][0] == uniqueJobs[0] && (age >= 30))
    		ageGreaterThan30Count[0]++;

    	if(observations[i][0] == uniqueJobs[1]  && (age >= 30))
    		ageGreaterThan30Count[1]++;

    	if(observations[i][0] == uniqueJobs[2] && (age >= 30))
    		ageGreaterThan30Count[2]++;
    }

    #pragma omp parallel for
    for(int i=0;i<3;i++)
    	ageProbability[i] = ((double)ageGreaterThan30Count[i] / (double)uniqueJobsCount[i]);




  	int qualificationMtechCount[3] = {0,0,0};
    double qualificationProbability[3] = {0,0,0};
    for(int i=0 ; i<10 ; i++){
      	if(observations[i][0] == uniqueJobs[0] && (observations[i][2] == "MTech"))
    		qualificationMtechCount[0]++;

    	if(observations[i][0] == uniqueJobs[1]  && (observations[i][2] == "MTech"))
    		qualificationMtechCount[1]++;

    	if(observations[i][0] == uniqueJobs[2] && (observations[i][2] == "MTech"))
    		qualificationMtechCount[2]++;
    }

    #pragma omp parallel for
    for(int i=0;i<3;i++)
      qualificationProbability[i] = ((double)qualificationMtechCount[i] / (double)uniqueJobsCount[i]);


  	int experiance5Count[3] = {0,0,0};
    double experianceProbability[3] = {0,0,0};
    for(int i=0 ; i<10 ; i++){
    	int experiance = atoi(observations[i][3].c_str());

      	if((observations[i][0] == uniqueJobs[0]) && (experiance >=  5))
    		experiance5Count[0]++;

    	if((observations[i][0] == uniqueJobs[1])  && (experiance >= 5))
    		experiance5Count[1]++;

    	if((observations[i][0] == uniqueJobs[2]) && (experiance >=  5))
    		experiance5Count[2]++;
    }


    #pragma omp parallel for
    for(int i=0;i<3;i++)
      experianceProbability[i] = ((double)experiance5Count[i] / (double)uniqueJobsCount[i]);


  	double totalProbability[3] = {0,0,0};
  	#pragma omp parallel for
    for(int i=0;i<3;i++)
    	totalProbability[i] = (uniqueJobsProbability[i] * ageProbability[i] * qualificationProbability[i] * experianceProbability[i]);


    	cout<<"Consultancy "<<totalProbability[0]<<endl;
    	cout<<"Service "<<totalProbability[1]<<endl;
    	cout<<"Research "<<totalProbability[2]<<endl;

    	//cout<<"Highest"<<max(max(totalProbability[0],totalProbability[1]),totalProbability[2]);
    	double max = 0;
    	int index = 0;
    for(int i=0;i<3;i++){
    	if(totalProbability[i] > max){
    		max = totalProbability[i];
    		index = i;
    	}
    }

    cout<<"Highest probablity of "<<uniqueJobs[index]<<" with value "<<max;



	return 0;

}
