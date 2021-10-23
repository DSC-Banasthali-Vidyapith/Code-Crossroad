/*
Given a string str, find the length of the longest substring without repeating characters. 
Algorithm: For the solution of this problem we can use sliding window technique. In this whenever we encounter a repeated character 
we will remove the current window till the repeated string and then will further check for the new window. Basically, the idea is 
to scan the string from left to right, keeping track of the maximum length Non-Repeating Character Substring seen so far in result 
variable. Here,we have used two variables for length of current window:
1) j: (Ending index) Consider current index as ending index.
2) i: (Starting index) It will remain same if current character was not present in the previous window. If this is not the case then 
we will update it accordingly.
To check if the current character was present in the previous window or not, we are storing last index i.e the index of last occurence 
of every character in an array last_index[]. If last_index[str[j]] + 1 is more than previous i, then we updated the start index i. 
Else we will keep the value of i same. 
*/
#include<bits/stdc++.h>
using namespace std;

//Function to get the length of longest substring having non repetitive characters.
int LongestSubStr(string str)
{
    //Starting index
    int i=0;

    //To store result
    int result=0;

    //To store last index of each character
    vector<int> last_index(256,-1);

    for(int j=0;j<str.length();j++)
    {
        //Update value of i i.estarting index of window
        i=max(i,last_index[str[j]]+1);

        result=max(result,j-i+1);

        //Storing the last occurence of str[j]
        last_index[str[j]]=j;
    }
    
    return result;
}

//Main Function
int main()
{
    string str;

    //Take string from user
    cout << "Enter the string: ";
    cin >> str;

    //Printing the result
    cout << LongestSubStr(str);
}

/*
Time Complexity: O(N)
Space Complexity: O(N)

Input:
Enter the string: abcabcbb
Output:
3

Input:
Enter the string: bbbbb
Output:
1
*/