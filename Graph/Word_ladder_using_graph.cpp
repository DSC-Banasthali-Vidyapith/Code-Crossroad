/*Algorithm:
1. We will use BFS traversal and first push the starting word in the queue. 
2. Run a loop until the queue is empty
3. Traverse all words that adjacent (differ by one character) to it and push the word in a queue (for BFS)
4. Keep doing so until we find the target word or we have traversed all words and return count of no of transformation if end word
is present in the dictionary and if not will return 0.

*/

#include <bits/stdc++.h>
using namespace std;

 int ladderLength(string begin, string end, vector<string>& wordList) 
 {
        int n=wordList.size(),l=0,i,j;
        
        unordered_set<string>s; // Using set for considering one word at once
        
        for(i=0;i<n;i++)
            s.insert(wordList[i]); //inserting words in set
        
        if(s.find(end)==s.end()) //if end word is not in dictionary
            return 0;

        queue<string>q;
        q.push(begin); //pushing start
        
        while(!q.empty())
        {
            int m=q.size();
            l++; //counting transformation
            
            for(i=0;i<m;i++) //all adjacent words with difference of 1 character
            {
                string temp=q.front();
                q.pop();
                
                for(j=0;j<temp.size();j++)
                {
                    char t=temp[j];
                    
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[j]=ch; //creating adjacent word
                        
                        if(temp==end) //end word is found
                            return l+1;
                        if(s.find(temp)==s.end()) //current word is not in dictionary
                            continue;
                        
                        s.erase(temp); //removing from set
                        q.push(temp); //pushing into queue
                    }
                    temp[j]=t;
                }
            }
        }
        
        
        return 0;
        
}

int main() 
{
    int n;
    vector<string>wordList;
    string s,start,end;
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        wordList.push_back(s); // Input of Dictionary
    }
    cin>>start>>end; //Start and end word
    
    int ans=ladderLength(start,end,wordList);
    cout<<ans;
    return 0;
	
}

/*
Time Complexity: O(N*M*26)
N-> Number of words in WordList
M-> Length of each word
Space Complexity: O(N)

Test case1:
Input:
n= 6
WordList[]= hot dot dog lot log cog
start= hit
end= cog
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Testcase2:
Input:
n= 5
WordList[]= hot dot dog lot log
start= hit
end= cog
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/