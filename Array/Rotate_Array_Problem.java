/*
Algorithm: For rotating array left k times we will rotate array one by one i.r rotate array by one k times. For this we will use a for loop and 
call left_rotate_by_one() method k times.left_rotate_by_one() method will use a temp variable to rotate the array.
*/
package swati_java;
import java.util.Scanner;

public class Rotate_Array {
    //Method to rotate array
    public static void leftRotate(int a[], int k, int n)
    {
        for (int i = 0; i < k; i++)
            left_rotate_by_one(a, n);
    }
 
    //Method to rotate array by one only
    public static void left_rotate_by_one(int a[], int n)
    {
        int i, temp;
        temp = a[0];
        for (i = 0; i < n - 1; i++)
            a[i] = a[i + 1];
        a[n-1] = temp;
    }
  
    //Main method
    public static void main(String args[]){
        Scanner obj = new Scanner(System.in);
        
        //Getting Input from user
        System.out.print("Enter size of array: ");
        int n = obj.nextInt();
        
        int a[] = new int[n];
        for(int i=0;i<n;i++)
        {
            int val = obj.nextInt();
            a[i] = val;
        }
        
        System.out.print("Enter value of k i.e no of rotations you want to make: ");
        int k = obj.nextInt();
        leftRotate(a,k,n);
        
        //Printing outputs
        System.out.print("Array after " + k + " rotations: ");
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i] + " ");
        }
    }
}
/*
Time Complexity: O(n*k)
Space Complexity:   O(1)

Input:
Enter size of array: 7
1 2 3 4 5 6 7
Enter value of k i.e no of rotations you want to make: 2
Output:
Array after 2 rotations: 3 4 5 6 7 1 2

Input:
Enter size of array: 7
1 2 3 4 5 6 7
Enter value of k i.e no of rotations you want to make: 3
Output:
Array after 3 rotations: 4 5 6 7 1 2 3
*/