#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "string"
#include "set"
#include "map"
#include "stack"
#include "queue"
#include "unordered_map"
using namespace std;
// Sử dụng recursion
class Solution{

public:
    //bai 1 : liet ke day nhi phan co do dai n
    /*
    // void binary_size_k(vector<string>& binary_combination,string binary,int n){
    //     if(binary.length() == n){
    //         binary_combination.push_back(binary);
    //         return;
    //     }
    //     binary_k_size(binary_combination,permutation + '1',n);
    //     binary_k_size(binary_combination,permutation + '0',n);   
    // }
    */

    //bai 2 : liet ke tap con k phan tu
    /*
    void find_combination(vector<vector<int>>& answer,const vector<int>& nums,vector<int>& permutation,vector<bool>& visited, int n, int i){
        if(permutation.size() == n){
            answer.push_back(permutation);
            return;
        }
        int size = nums.size();
        for(i; i<size;i++){
            if(!visited[i]){
                permutation.push_back(nums[i]);
                visited[i] = true;
                find_combination(answer,nums, permutation,visited,n,i+1);
                permutation.pop_back();
                visited[i] = false;
            }
        }
    }
    */
    
    // bai 3: 
    /*
    void find_permutation(vector<vector<int>>& answer,const vector<int>& nums,vector<int>& permutation,vector<bool>& visited, int n){
        if(permutation.size() == n){
            answer.push_back(permutation);
            return;
        }
        int size = nums.size();
        for(int i = 0; i<size;i++){
            if(!visited[i]){
                permutation.push_back(nums[i]);
                visited[i] = true;
                subset_size_k(answer,nums, permutation,visited,n);
                permutation.pop_back();
                visited[i] = false;
            }
        }
    }
    */

    // bai 4: 
    // void findCombinations(vector<int>& current, int start, int sum, int n) {
    //     if (sum == n) { 
    //         // In kết quả
    //         for (int i = 0; i < current.size(); i++) {
    //             cout << current[i] << (i == current.size() - 1 ? "\n" : " + ");
    //         }
    //         return;
    //     }
        
    //     for (int i = start; i <= n - sum; i++) { 
    //         current.push_back(i);  
    //         findCombinations(current, i, sum + i, n);  
    //         current.pop_back();  
    //     }
    // }

    // bai 5: 
    void printSolution(vector<vector<int>>& board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----------------\n";
    }   
    bool isValid(std::vector<vector<int>>& board, int i , int j){
        int n = board.size();
        int j_left = j, j_right = j;
        for(;i>=0;i--){
            if( (j_left >= 0 && board[i][j_left] == 1) || 
                (j_right < n && board[i][j_right] == 1) || 
                (board[i][j] == 1)
            )
            {
                return false;
            }
            j_left--;
            j_right++;
        }
        return true;
    }

    void solveNQueen(vector<vector<int>>& board, int n, int row){
        if(row >= n){
            printSolution(board,n);
            return;  
        } 
        for(int j = 0;j<n;j++){
            if(isValid(board,row, j)){
                board[row][j] = 1;
                solveNQueen(board,n, row + 1);
                board[row][j] = 0;
            }
        }
    }

};



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	#endif
    Solution solution;
    // string permutation = "";
    // unordered_map<char, bool> store_value;vector<string> binary_combination;
    // int n;
    // cin >> n;
    // solution.binary_k_size(binary_combination,permutation,n);
    // for(auto& x : binary_combination){
    //     cout << x << '\n';
    // }

    // vector<vector<int>> answer;
    // vector<int> permutation;
    // vector<int> nums = {1,2,3,4};
    // vector<bool> visited(nums.size()+1, false);
    // int n;
    // cin >> n;
    // if(n > nums.size()) {
    //     cout << "Khong co chuoi con" ;
    //     return 0;
    // }
    // solution.subset_size_k(answer,nums,permutation,visited,n);
    // for(int i = 0;i<answer.size();i++){
    //     for(int j = 0;j<answer[i].size();j++){
    //         cout << answer[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // vector<vector<int>> answer;
    // vector<int> permutation;
    // vector<int> nums = {1,2,3,4};
    // vector<bool> visited(nums.size()+1, false);
    // int n;
    // cin >> n;
    // if(n > nums.size()) {
    //     cout << "Khong co chuoi con" ;
    //     return 0;
    // }
    // solution.find_combination(answer,nums,permutation,visited,n,0);
    // for(int i = 0;i<answer.size();i++){
    //     for(int j = 0;j<answer[i].size();j++){
    //         cout << answer[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    // int n;
    // cin >> n;
    // vector<int> current;
    // solution.findCombinations(current, 1, 0, n);

    int n;
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n,0));
    solution.solveNQueen(board,n,0);
}

