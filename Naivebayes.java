import java.io.*;

public class Naivebayes
{
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static void main(String args[]) throws IOException
  {
    String[][] observations = new String[10][4];
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

    System.out.println("");
    System.out.println("Finding the job for the person who has -> ");
    System.out.println("Age >= 30");
    System.out.println("Qualification = MTech");
    System.out.println("Experience >= 5");
    System.out.println("");
    System.out.println("Looks like a pretty experienced guy !");
    System.out.println("");
    System.out.println("The prefferences for the job types are -> ");

    String[] uniqueJobs = new String[3];
    uniqueJobs[0] = "Consultancy";
    uniqueJobs[1] = "Service";
    uniqueJobs[2] = "Research";

    // whew that was a lot of typing

    // firstly, we find the probabilites of each unique job
    int[] uniqueJobsCount = new int[3];
    double[] uniqueJobsProbability = new double[3]; // float arithmetic is problematic - best stick with double

    for(int i=0;i<10;i++)
    {
      if(observations[i][0].equals(uniqueJobs[0]))  // Consultancy
        uniqueJobsCount[0]++;

      if(observations[i][0].equals(uniqueJobs[1]))  // Service
        uniqueJobsCount[1]++;

      if(observations[i][0].equals(uniqueJobs[2]))  // Research
        uniqueJobsCount[2]++;
    }

    // now that we've got the occurrences, let's get the probabilites
    for(int i=0;i<3;i++)
      uniqueJobsProbability[i] = ((double)uniqueJobsCount[i] / 10.0);  // double arithmetic

    // keep in mind the question in hand - that's how we're proceeding
    // let's consider the age >= 30 first
    // so we find the probabilites of respective jobs for age >= 30

    int[] ageGreaterThan30Count = new int[3];
    double[] ageProbability = new double[3];
    for(int i=0;i<10;i++)
    {
      int age = Integer.parseInt(observations[i][1]);

      if((observations[i][0].equals(uniqueJobs[0])) && (age>=30)) // Consultancy
        ageGreaterThan30Count[0]++;

      if((observations[i][0].equals(uniqueJobs[1])) && (age>=30)) // Service
        ageGreaterThan30Count[1]++;

      if((observations[i][0].equals(uniqueJobs[2])) && (age>=30)) // Research
        ageGreaterThan30Count[2]++;
    }

    for(int i=0;i<3;i++)
      ageProbability[i] = ((double)ageGreaterThan30Count[i] / (double)uniqueJobsCount[i]);

    // now we've got the respective ages probability
    // let's tackle the Qualification = MTech now

    int[] qualificationIsMtechCount = new int[3];
    double[] qualificationProbability = new double[3];
    for(int i=0;i<10;i++)
    {
      String qualification = observations[i][2];

      if((observations[i][0].equals(uniqueJobs[0])) && (qualification.equals("MTech"))) // Consultancy
        qualificationIsMtechCount[0]++;

      if((observations[i][0].equals(uniqueJobs[1])) && (qualification.equals("MTech"))) // Service
        qualificationIsMtechCount[1]++;

      if((observations[i][0].equals(uniqueJobs[2])) && (qualification.equals("MTech"))) // Research
        qualificationIsMtechCount[2]++;
    }

    for(int i=0;i<3;i++)
      qualificationProbability[i] = ((double)qualificationIsMtechCount[i] / (double)uniqueJobsCount[i]);
    // lastly, gotta take care of experience (the same way as age)
    int[] experienceGreaterThan5Count = new int[3];
    double[] experienceProbability = new double[3];
    for(int i=0;i<10;i++)
    {
      int experience = Integer.parseInt(observations[i][3]);

      if((observations[i][0].equals(uniqueJobs[0])) && (experience>=5)) // Consultancy
        experienceGreaterThan5Count[0]++;

      if((observations[i][0].equals(uniqueJobs[1])) && (experience>=5)) // Service
        experienceGreaterThan5Count[1]++;

      if((observations[i][0].equals(uniqueJobs[2])) && (experience>=5)) // Research
        experienceGreaterThan5Count[2]++;
    }

    for(int i=0;i<3;i++)
      experienceProbability[i] = ((double)experienceGreaterThan5Count[i] / (double)uniqueJobsCount[i]);

    // finally the main stuff is done
    // it's calculation time now

    double[] probabilityOfDoingJob = new double[3];

    for(int i=0;i<3;i++)
      probabilityOfDoingJob[i] = (uniqueJobsProbability[i] * ageProbability[i] * qualificationProbability[i] * experienceProbability[i]);

    System.out.println("Consultancy, with a probability of " + probabilityOfDoingJob[0]);
    System.out.println("Service, with a probability of " + probabilityOfDoingJob[1]);
    System.out.println("Research, with a probability of " + probabilityOfDoingJob[2]);
    System.out.println("");
  }
}
