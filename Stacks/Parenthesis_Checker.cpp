 // Anisha Singh
 // EEE
 // BV'23

#include <iostream>
#include <stack>

using namespace std;

bool check_parenthesis(string str) 			 //Boolean Function to check the given expression 
{
	stack <char> s;

	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{' )
		{
			s.push(str[i]);    					//Push the element into stack
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

	return s.empty();

}

int main()
{

	string exp;
	cin>>exp;

	if (check_parenthesis(exp))   			 //Calling the function
      cout << "true";
   else
      cout << "false";
}


   // Input : [(a+b)]
   // Output:  True

   // Input : [)]
   // Output:  False
 
 	// Time Complexity : O(n)
 	// Space Complexity : O(n)
	


