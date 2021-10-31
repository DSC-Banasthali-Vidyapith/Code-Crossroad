/*Given the head of a singly linked list, return true if it is a palindrome.*/


/*Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9*/
 
// The implemetation can be done via 3 menthods.

//ArrayList Code

public boolean isPalindromeBrute(ListNode head) 
    {
       ArrayList<Integer> list = new ArrayList<>();

        ListNode temp= head;
        while(temp != null) {
        list.add(temp.val);
        temp = temp.next;
    }

    for(int i =0; i < list.size() / 2;i++) 
    {
       if(list.get(i) != list.get(list.size() - 1 - i))
          return false;
    }

return true;
}


//Stack Code

public boolean isPalindrome(ListNode head) 
{
       if(head == null || head.next == null) 
           return true;

       Stack<Integer> stack = new Stack<>();
       ListNode slow = head, fast = head;

       ListNode temp = head;
       int c = 0;
       while(temp != null) 
       {
          c++;
          temp = temp.next;
       }

    while(fast != null && fast.next != null) 
       {
           stack.push(slow.val);
           slow = slow.next;
           fast = fast.next.next;
       }
    if((c&1) == 1) 
       {
           stack.push(slow.val);
       }

    while(!stack.isEmpty()) 
       {
          int v = stack.pop();
          if(v != slow.val) 
          {
             return false;
          }
          slow = slow.next;
        }
return true;
}



//Reverse list method

public boolean isPalindromeReverse(ListNode head) 
{
    if(head == null || head.next == null) return true;
    ListNode slow = head, fast = head;

    // make the slow pointer points to middle element
    
    // this is used to keep the slow to the left element in case of even length list
    
    while(fast.next != null && fast.next.next != null) 
    {
        slow = slow.next;
        fast = fast.next.next;
   	}

    // reverse the list on the right of slow

    ReverseLLIterative r = new ReverseLLIterative();
    slow.next = r.reverseLLIterative(slow.next);

    // increment the slow pointer by one
    slow = slow.next;

    while(slow != null) 
    {
        if(head.val != slow.val)
         return false;
        slow = slow.next;
        head = head.next;
    }

	return true;
}



//Testcases
//Input: head = [1,2,2,1]
//Output: true

//Input: head = [1,2]
//Output: false

//Time Complexity - O(N)
//Space Complexity - O(1)
 
