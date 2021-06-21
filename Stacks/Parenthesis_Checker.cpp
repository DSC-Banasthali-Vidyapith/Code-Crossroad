/*  We are going to solve this question using Stack. If the current character is ‘(‘ or ‘{‘ or ‘[‘ then push it to stack otherwise pop it and check
whether the popped bracket is corresponding starting bracket of the current character, then it is fine otherwise that is not balanced.*/

#include <iostream>
#include <stack>

using namespace std;

//Boolean Function to check the given expression if it is valid or not
bool check_parenthesis(string str) 			 
{
	stack <char> s;

	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{' )
		{
			//Push the element into stack
			s.push(str[i]);    					
		}

		else
		{
			switch(str[i])
			{
				case ')':
				 if(s.empty() || s.top()!='(')
				 {
				 	return false;
				 }
				 else
				 {
				    s.pop();      
				 }
				 
				 break;

				case ']':
				  if(s.empty() || s.top()!='[')
				  {
				  	return false;
				  }
				  else
				 {
				    s.pop();      
				 }
				 
				  break;

				case '}':
				 if(s.empty() || s.top()!='{')
				 {
				 	return false;
				 }
				 else
				 {
				    s.pop();      
				 }
				 
				 break;
				 
				default: ;
			}
		}
	}
	
	//Check if the stack is empty
	return s.empty();

}

int main()
{

	string exp;
	cin>>exp;
	
	//Calling the function
	if (check_parenthesis(exp))   			 
      cout << "true";
   else
      cout << "false";
}

/* Input : [(a+b)]
   Output:  True

   Input : [)]
   Output:  False
 
   Time Complexity : O(n)
   Space Complexity : O(n). */
	


