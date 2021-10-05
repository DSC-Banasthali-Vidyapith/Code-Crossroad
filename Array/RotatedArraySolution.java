import java.util.Scanner;

public class Solution {

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements in an array: ");
        int n = input.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter the elements of the array: ");
        for(int i=0; i<n; i++)
        {
            arr[i] = input.nextInt();
        }
        System.out.print("By how many elements the array should be rotated: ");
        int D = input.nextInt();


        rotateArray(arr,n,D);

    }
    static void rotateArray(int[] arr, int n, int D)
    {
        System.out.print("Rotated array: ");

        for(int i=n-D; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }

        for(int i=0; i<n-D; i++)
        {
            System.out.print(arr[i] + " ");
        }


    }
}
