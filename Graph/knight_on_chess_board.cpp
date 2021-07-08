/* Algorithm :
It gives the minimum number of steps taken by knight to reach
it's target position by bfs traversal.*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if the position is valid or not.
bool isvalid(int a,int b,int n)
{
    if(a>=1 && a<=n && b>=1 && b<=n)
        return true;
    
    return false;
}

// Function to calculate the minimum steps to reach the target.
int minStepByKnight(int knightPos[], int targetPos[], int N) {
    
    //queue to store minimum dist and position of knight in pairs.
    queue<pair<int,pair<int,int> > > q;
    
    //to keep account of visited positions.
    vector<vector<bool> > visited(N+1,vector<bool>(N+1,false));
    
    // All the possibilities where the knight can move.
    //Please refer at the end of file for more explanation.
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
    
    q.push(make_pair(0,make_pair(knightPos[0],knightPos[1])));
    
    visited[knightPos[0]][knightPos[1]] = true;
    
    while(!q.empty())
    {
        pair<int,pair<int,int> > temp = q.front();
        q.pop();
        int x = temp.second.first;
        int y = temp.second.second;
        int d = temp.first;
        
        if(x==targetPos[0] && y==targetPos[1])
            return d;
            
        for(int i=0;i<8;i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            
            if(isvalid(a,b,N) && !visited[a][b])
            {
                visited[a][b] = true;
                q.push(make_pair(d+1,make_pair(a,b)));
            }
        }  
    } 
}

// main function
int main() {
    int N;
    int a, b, c, d;
    cout<<"Enter the size of board"<<endl;
    cin >> N;
    cout<<"Enter the Knight position"<<endl;
    cin >> a >> b;
    cout<<"Enter the target position"<<endl;
    cin >> c >> d;
    int knightPos[] = {a, b};
    int targetPos[] = {c, d};
    cout<<"Minimum steps by knight to reach target position is: ";
    cout << minStepByKnight(knightPos, targetPos, N) << endl;
    return 0;
}


// O(8N^2) --> worst case time complexity.
// O(N^2) --> space complexity to store visited positions.
/*Input 1: 
Enter the size of board
6
Enter the Knight position
3 3
Enter the target position
2 6
Minimum steps by knight to reach target position is: 2*/

// 6 * 6 chess board
/*   ___________________________________________________
    |      |         |       |        |        |        |
    |      |   1*  __|_______|__ 2*   |        |        |
    |______|_________|___|___|________|________|________|
    |      |         |   |   |        |        |        |
    | 3* __|_________|___|___|________|__* 4   | Target |
    |______|_________|___|___|________|________|________|
    |      |         | knight|        |        |        |
    |      |         |  (~)  |        |        |        |
    |______|_________|___|___|________|________|________|
    |      |         |   |   |        |        |        |
    | 5 *__|_________|___|___|________|__ * 6  |        |
    |______|_________|___|___|________|________|________|
    |      |         |   |   |        |        |        |
    |      |  7 * ___|___|___|___ * 8 |        |        |
    |______|_________|_______|________|________|________|
    |      |         |       |        |        |        |
    |      |         |       |        |        |        |
    |______|_________|_______|________|________|________|

*/

/*Input 2:
Enter the size of board
5
Enter the Knight position
1 2
Enter the target position
3 4
Minimum steps by knight to reach target position is: 4 */
