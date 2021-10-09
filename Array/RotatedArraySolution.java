class Solution {
    public void rotate(int[] nums, int k)
    {
       //if k > length of array for that case
    k = k % nums.length;
    
    //reverse 1st part
    reverse(nums, 0, nums.length-k-1);
    
    //reverse 2nd part
    reverse(nums, nums.length-k, nums.length-1);
    
    //now reverse the full arrary
    reverse(nums, 0, nums.length-1);
        
        
    }
    
     public static void reverse(int[] nums, int s, int e){
    
    int i = s;
    int j = e;
    
    while(i < j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        
        i++;
        j--;
    } 
}
}
