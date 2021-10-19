/*
 	Given an unsorted array of integers, return the length of the longest consecutive elements sequence.
 	Algorithm:
 	1. Taking the size of array and the array as the input.
 	2. Removing the duplicate elements using a HashSet.
 	3. Creating the new sorted array after removing duplicates.
 	4. In linear time, checking the length of all chunks of consecutive window and comparing it with previous, if greater->swap.
 	5. Printing the final answer which is the maximum of all.
 	
 */
import java.util.*;
public class Longest_Consecutive_Sequence
{
	int solve(int arr[])
	{
		// function which evaluates the length of Longest Consecutive Sequence
		HashSet<Integer> hs=new HashSet<Integer>();
		for(int n: arr)
			hs.add(n);
		
		if(hs.size()==1)
			return 1;
		
		Object objArr[]=hs.toArray();
		
		int nums[]=new int[hs.size()];
		int j=0;
		for(Object o: objArr)
		{
			nums[j]=(int)o;
			j++;
		}
		Arrays.sort(nums);
		
		
		int ans=0;
		for(int i=1;i<nums.length;i++)
		{
			int temp=1;
			while(i<nums.length && nums[i-1]+1==nums[i])
			{
				temp++;
				i++;
			}
			ans=Math.max(ans,temp);
		}
		return ans;
	}
	public static void main(String args[])
	{
		Scanner Sc=new Scanner(System.in);
		
		System.out.println("Enter no of elements: ");
		int n=Sc.nextInt();
		int arr[]=new int[n];
		System.out.println("enter array");
		for(int i=0;i<n;i++)
			arr[i]=Sc.nextInt();
		
		Longest_Consecutive_Sequence obj=new Longest_Consecutive_Sequence();
		System.out.println("ans= "+obj.solve(arr));
		
		Sc.close();
	}
}
/*
 	Sample Input 1:
  	Enter no of elements: 
	6
	enter array
	100 4 200 1 3 2
	
	Sample Output 1:
	ans= 4
	
	
	
	Sample Input 2:
	Enter no of elements: 
	10
	enter array
	0 3 7 2 5 8 4 6 0 1
	
	Sample Output 2:
	ans= 9
	
	
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(N)
*/