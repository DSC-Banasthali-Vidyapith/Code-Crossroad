 /***
 
 ALGORITHM -:
 
 ~ We traverse the digits in the input number one by one. 
 ~ For a particular digit, we add append all the alphabets associated with it at the end of the existing words/combinations formed by previous digits.
 ~ Thus, when we reach our last digit of the input number, the 'result' vector stores all the possible words formed by previous 'n-1' digits.
 ~ Now, we'll be appending each associated alphabet (with the last digit) at the end of all these existing words, thus, finally giving us all possible words formed from given input number.
 
 ***/ 
 
 #include<bits/stdc++.h>
 using namespace std;
 
    vector<string> allPossibleWords(vector<int>& num) 
    {
        // returning empty vector if input is empty
        if (num.size() == 0)
            return {};
        
        vector<string> result;
        result.push_back("");  
        
        // storing the mapping of digits to letters in the map
        unordered_map<int, string> map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        
        // traversing on the input number and operating on one digit at a time
        for (int i = 0; i < num.size(); i++)
        {
            string mappedLetters = map[num[i]]; // storing the associated alphabets (with the digit) separately
            
            vector<string> temp; 
            
            // taking one associated alphabet at a time and adding it at the end of the existing strings(combinations) in the result vector
            // and then storing the new combinations in temp vector
            for (int j = 0; j < mappedLetters.size(); j++)
                for (int k = 0; k < result.size(); k++)
                    temp.push_back(result[k] + mappedLetters[j]);
             
            // updating our result vector with temp vector which stores the new combinations
            result.swap(temp);
        }
        
        return result;
    }

int main ()
{
	int n;
	cout << "Enter the number of digits in the number" << endl;
	cin >> n;
	
	vector<int> num(n);
	cout << "Enter the digits of the number" << endl;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	vector<string> result = allPossibleWords(num);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	
	cout << endl;
	
 	return 0;
}
/***

TIME COMPLEXITY : O(4^n) 
Explanation : In the worst case, all the digits may have 4 associated alphabets. Now, for 1st digit there are 4 options. Then, for each of these 4 options, there will be 4 more options (coming from next digit) and so on. This continues till the number of digits, i.e., 'n'. Thus, the resultant time complexity.  
 
 
SPACE COMPLEXITY : O(1)
Explanation : Ignoring the space occupied by the input and output vector, the only major space occupied is by the map. But since the space occupied by it is independent of our input, it will be costant space usage. 
 
 ***/

/***

1) Input number: 5
   Output: j k l
   
2) Input number: 234
   Output:
   adg adh adi aeg aeh aei afg afh 
   afi bdg bdh bdi beg beh bei bfg 
   bfh bfi cdg cdh cdi ceg ceh cei 
   cfg cfh cfi
   
 ***/
