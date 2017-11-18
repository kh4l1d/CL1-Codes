import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


/**
 * @author Kshitij Mhatre
  Steps to run ->
 :~$ javac Apriori.java
 :~$ java Apriori
 */
public class Apriori {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String ip=sc.nextLine();
		ArrayList<ArrayList<String>> trans= new ArrayList<>();
		Set<String> uniItem = new HashSet<>();
		
		while(!ip.equals("-1")){			
			String[] items=ip.split(" ");
			ArrayList<String> transaction= new ArrayList<>();			 
			for (String item : items) {
				transaction.add(item);
				uniItem.add(item);
			}
			trans.add(transaction);
			ip=sc.nextLine();
		}
		//System.out.println("Enter minimum support");
		int minSupport=sc.nextInt();
		System.out.println(uniItem);	//to display all unique items..remove if not needed
		
		int support;
		HashMap< ArrayList<String>,Integer> can= new HashMap<>();
		
		//System.out.println(can.isEmpty());
		//combination 1 2 3.. of uni-items in can
		//for  set in combinations.. if transaction contains all till can not empty
		int size=1;
		ArrayList<ArrayList<String>> combinations = new ArrayList<>();
		combinations= combinationsUtil(uniItem,size);
		
		do{
			can= new HashMap<>();
			for (ArrayList<String> itemSet : combinations) {
				support=0;
				for (ArrayList<String> transaction : trans) {
					if(transaction.containsAll(itemSet))
						support++;
				}
				if(support >= minSupport)
					can.put(itemSet, support);
			}
			
			System.out.println("Iteration no "+size);
			System.out.println(can);
			
			
			uniItem= new HashSet<String>();
			for (Map.Entry<ArrayList<String>, Integer> entry : can.entrySet()) {
				if(entry.getValue() >= minSupport)
					uniItem.addAll(entry.getKey());
			}
			size++;
			combinations=combinationsUtil(uniItem,size);
			
			
		}while(!can.isEmpty() );
		
	}

	/*
	takes unique items and returns combinations of given size
	*/
	private static ArrayList<ArrayList<String>> combinationsUtil(Set<String> uniItem, int size) {
		// 
		String[] data= new String[size];
		ArrayList<ArrayList<String>> combins = new ArrayList<>();
		combine(combins,uniItem,data,0,uniItem.size()-1,0,size);
		System.out.println(combins);		//to display possible combinations of items..remove if not needed
		return combins;
	}

	/**
	* @param combins container to store all combinations formed
	* @param data temp variable to store current combination
	* @param index place to add next item in data/current combination
	*/
	private static void combine(ArrayList<ArrayList<String>> combins, Set<String> uniItem, String[] data, int start, int end, int index, int size) {
		
		if(index==size){
			ArrayList<String> temp= new ArrayList<>();
			for (String string : data) {
				temp.add(string);				
			}
			combins.add(temp);
			return;
		}
		
		for (int i=start; i<=end && end-i+1 >= size-index; i++)
        {
			String[] arr = Arrays.copyOf(uniItem.toArray(), uniItem.toArray().length, String[].class);
            data[index] = arr[i];
            combine(combins,uniItem, data, i+1, end, index+1, size);
        }
		
	}
/*
 *
 //sample input
 //each line enter words corresponding to items eg, "a", "orange"
 //-1 marks end of all transactions(input)
 //3 is minimum support
a b c
a b c d
a b d 
a d b c
a c d
-1
3
 */
}
