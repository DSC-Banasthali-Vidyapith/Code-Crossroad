import java.util.Arrays;
import java.util.Scanner;

public class RotateArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter length of array: ");
        int len = in.nextInt();
        System.out.print("Enter numbers: ");
        int[] nums = new int[len];
        for (int i=0; i < len; i++){
            nums[i] = in.nextInt();
        }
        System.out.print("Enter number of rotations: ");
        int k = in.nextInt();
        System.out.println("Input Array: "+ Arrays.toString(nums));
        rotate(nums, k);
    }
    public static void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        rotateSubArray(nums, 0, n-k);
        rotateSubArray(nums, n-k, n);
        rotateSubArray(nums, 0 , n);
        System.out.println("Rotated Array: "+ Arrays.toString(nums));
    }
    public static void rotateSubArray(int[] nums, int start, int end){
        while(start < end){
            swap(nums, start, end-1);
            start++;
            end--;
        }
    }
    public static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

}
