/*THIS IS A PROGRAM THAT CONVERTS INFIX TO POSTFIX EXPRESSION
I HAVE USED STACK AS MY TECH
THIS PROGRAM BASICALLY DOES THIS:
(A+B) ->  AB+ */

#include <bits/stdc++.h>
using namespace std;

int precedence(char sym)
{
    if(sym == '^') return 4;
    if(sym == '*' || sym == '/') return 3;
    if(sym == '+' || sym == '-') return 2;
    if(sym == '(') return 1;
}

int main() {
    int t;
	cin >> t;
	while(t--) {
	    stack<char> stk;
	    string s, res="";
	    cin >> s;
	    for(int i=0; i<s.length(); i++) {
	        if(s[i]>=65 && s[i]<=90) {
	            res += s[i];
	        }
	        else if(stk.empty() && (s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-' || s[i]=='^')) {
	            stk.push(s[i]);
	        }
	        else if(s[i]=='(') {
	            stk.push(s[i]);
	        }
	        else if(s[i]==')') {
	            while(stk.top()!='(') {
	                res += stk.top();
	                stk.pop();
	            }
	            stk.pop();
	        }
	        else if(!stk.empty() && precedence(stk.top())>=precedence(s[i])) {
	            while(!stk.empty() && precedence(stk.top())>=precedence(s[i]) && stk.top()!='(')
                {
                    res += stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
	        }
	        else if(!stk.empty() && precedence(s[i])>precedence(stk.top())) {
                stk.push(s[i]);
	        }
	    }
	    while(!stk.empty()) {
	        res += stk.top();
	        stk.pop();
	    }
	    cout << res << "\n";
	}
	return 0;
}


/*Input:
3
(A+(B*C))
((A+B)*(Z+X))
((A+T)*((B+(A+C))^(C+D)))

Output:
ABC*+
AB+ZX+*
AT+BAC++CD+^* */

/*TIME COMPLEXITY
Worst case time complexity: Θ(n^2)
Average case time complexity: Θ(n^2)
Best case time complexity: Θ(n^2)
Space complexity: Θ(n)*/
