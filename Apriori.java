// Author: Khalid - naam toh suna hi hoga
// Steps to run ->
// :~$ javac Apriori.java
// :~$ java Apriori

import java.io.*;

class Apriori
{
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static void  main(String args[]) throws IOException
  {
      // first gotta initialize them items
    String[] transactions = new String[5];

    transactions[0] = "MangoOnionJarKeychainEggsChocolate";
    transactions[1] = "NutsOnionJarKeychainEggsChocolate";
    transactions[2] = "MangoAppleKeychainEggs";
    transactions[3] = "MangoToothbrushCornKeychainChocolate";
    transactions[4] = "CornOnionKeychainKnifeEggs";

    String[] uniqueItems = new String[11];

    uniqueItems[0] = "Mango";
    uniqueItems[1] = "Onion";
    uniqueItems[2] = "Jar";
    uniqueItems[3] = "Keychain";
    uniqueItems[4] = "Eggs";
    uniqueItems[5] = "Chocolate";
    uniqueItems[6] = "Nuts";
    uniqueItems[7] = "Apple";
    uniqueItems[8] = "Toothbrush";
    uniqueItems[9] = "Corn";
    uniqueItems[10] = "Knife";

      // whew - done with the initializing

    // displaying all the unique items first
    System.out.println("");
    System.out.println("Frequent Itemset 0 ->");
    System.out.print("{");
    for(int i=0;i<11;i++)
      System.out.print(uniqueItems[i]+",");
    System.out.print("}");

    // modify the code here for customizable confidence
    System.out.println("");
    System.out.println("Enter the minimum confidence in the range (0,1) ->");
    double confidence = 0.5;
    System.out.println("");


    // find the number of items in frequent item set 1
    int[] uniqueItemsCount = new int[11];
    for(int i=0;i<11;i++)
    {
      for(int j=0;j<5;j++)
      {
        if(transactions[j].contains(uniqueItems[i]))
          uniqueItemsCount[i]++;
      }
    }

    int frequentItemSet1Count = 0;
    for(int i=0;i<11;i++)
    {
      if(uniqueItemsCount[i] >= 3)
        frequentItemSet1Count++;
    }

    // initialize the frequent item set 1
    String[] frequentItemSet1 = new String[frequentItemSet1Count];
    for(int i=0,j=0;i<11;i++)
    {
      if(uniqueItemsCount[i] >= 3)  // BE CAREFUL - depends on confidence
        frequentItemSet1[j++] = uniqueItems[i];
    }

    // display the frequent item set 1
    System.out.println("");
    System.out.println("Frequent Itemset 1 ->");
    System.out.println("");
    System.out.print("{");
    for(int i=0;i<frequentItemSet1Count;i++)
      System.out.print(frequentItemSet1[i]+",");
    System.out.print("}");
    System.out.println("");


    // find the number of items in frequent item set 2
    int[][] twoPairCount = new int[frequentItemSet1Count][frequentItemSet1Count];
    for(int i=0;i<frequentItemSet1Count;i++)
    {
      for(int j=i+1;j<frequentItemSet1Count;j++)
      {
        for(int k=0;k<5;k++)
        {
          if((transactions[k].contains(frequentItemSet1[i])) && (transactions[k].contains(frequentItemSet1[j])))
            twoPairCount[i][j]++;
        }
      }
    }

    int frequentItemSet2Count = 0;
    for(int i=0;i<frequentItemSet1Count;i++)
    {
      for(int j=0;j<frequentItemSet1Count;j++)
      {
        if(twoPairCount[i][j] >= 3)
          frequentItemSet2Count++;
      }
    }

    // initialize the contents of frequent item set 2
    String[][] frequentItemSet2 = new String[frequentItemSet2Count][2];
    for(int i=0,k=0;i<frequentItemSet1Count;i++)
    {
      for(int j=0;j<frequentItemSet1Count;j++)
      {
        if(twoPairCount[i][j] >= 3)
          {
            frequentItemSet2[k][0] = frequentItemSet1[i];
            frequentItemSet2[k++][1] = frequentItemSet1[j];
          }
      }
    }

    // display frequent item set 2
    System.out.println("");
    System.out.println("Frequent Itemset 2 ->");
    System.out.print("{");
    for(int i=0;i<frequentItemSet2Count;i++)
      System.out.print("("+frequentItemSet2[i][0]+","+frequentItemSet2[i][1]+"),");
    System.out.print("}");
    System.out.println("");

    // find the number of items in frequent item set 3
    int[][][] threePairCount = new int[frequentItemSet1Count][frequentItemSet1Count][frequentItemSet1Count];
    for(int i=0;i<frequentItemSet1Count;i++)
    {
      for(int j=i+1;j<frequentItemSet1Count;j++)
      {
        for(int k=j+1;k<frequentItemSet1Count;k++)
        {
          for(int l=0;l<5;l++)
          {
            if((transactions[l].contains(frequentItemSet1[i])) && (transactions[l].contains(frequentItemSet1[j])) && (transactions[l].contains(frequentItemSet1[k])))
              threePairCount[i][j][k]++;
          }
        }
      }
    }

    int frequentItemSet3Count = 0;
    for(int i=0;i<frequentItemSet1Count;i++)
    {
      for(int j=0;j<frequentItemSet1Count;j++)
      {
        for(int k=0;k<frequentItemSet1Count;k++)
        {
          if(threePairCount[i][j][k] >= 3)
            frequentItemSet3Count++;
        }
      }
    }


    // initialize the contens of frequent item set 3
    String[][] frequentItemSet3 = new String[frequentItemSet3Count][3];
    for(int i=0,l=0;i<frequentItemSet1Count;i++)
    {
      for(int j=0;j<frequentItemSet1Count;j++)
      {
        for(int k=0;k<frequentItemSet1Count;k++)
        {
          if(threePairCount[i][j][k] >= 3)
          {
            frequentItemSet3[l][0] = frequentItemSet1[i];
            frequentItemSet3[l][1] = frequentItemSet1[j];
            frequentItemSet3[l++][2] = frequentItemSet1[k];
          }
        }
      }
    }

    // finally display frequent item set 3
    System.out.println("");
    System.out.println("Frequent Itemset 3 ->");
    System.out.print("{");
    for(int i=0;i<frequentItemSet3Count;i++)
      System.out.print("("+frequentItemSet3[i][0]+","+frequentItemSet3[i][1]+","+frequentItemSet3[i][2]+"),");
    System.out.print("}");
    System.out.println("");

  }
}
