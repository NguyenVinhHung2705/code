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
    
    void binary_size_k(string binary,int n){
        if(binary.length() == n){
            cout << binary << '\n';
            return;
        }
        binary_size_k(binary + '1',n);
        binary_size_k(binary + '0',n);   
    }
    

    //bai 2 : liet ke tap con k phan tu
    
    // void find_combination(vector<int>& nums,vector<int>& permutation,vector<bool>& visited, int n, int i){
    //     if(permutation.size() == n){
    //         printArray(permutation);
    //         return;
    //     }
    //     int size = nums.size();
    //     for(i; i<size;i++){
    //         if(!visited[i]){
    //             permutation.push_back(nums[i]);
    //             visited[i] = true;
    //             find_combination(nums, permutation,visited,n,i+1);
    //             permutation.pop_back();
    //             visited[i] = false;
    //         }
    //     }
    // }
    
    
    // bai 3: 
    
    void find_permutation(vector<int>& nums,vector<int>& permutation,vector<bool>& visited, int n){
        if(permutation.size() == n){
            printArray(permutation);
            return;
        }
        int size = nums.size();
        for(int i = 0; i<size;i++){
            if(!visited[i]){
                permutation.push_back(nums[i]);
                visited[i] = true;
                find_permutation(nums, permutation,visited,n);
                permutation.pop_back();
                visited[i] = false;
            }
        }
    }
    

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

    // void printSolution(vector<vector<int>>& board, int n) {
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             cout << board[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "----------------\n";
    // }   
    // bool isValid(std::vector<vector<int>>& board, int row , int col){
    //     int n = board.size();
    //     int col_left = col, col_right = col;
    //     for(row; row >= 0; row--){
    //         if( 
    //             (col_left >= 0 && board[row][col_left] == 1) || 
    //             (col_right < n && board[row][col_right] == 1) || 
    //             (board[row][col] == 1)
    //         )
    //         {
    //             return false;
    //         }
    //         col_left--;
    //         col_right++;
    //     }
    //     return true;
    // }

    // void solveNQueen(vector<vector<int>>& board, int n, int row){
    //     if(row >= n){
    //         printSolution(board,n);
    //         return;  
    //     } 
    //     for(int col = 0;col<n;col++){
    //         if(isValid(board,row, col)){
    //             board[row][col] = 1;
    //             solveNQueen(board,n, row + 1);
    //             board[row][col] = 0;
    //         }
    //     }
    // }
    void printArray(vector<int>& a) {
        for(const auto& c : a) {
            cout << c << " ";
        }
        cout << '\n';
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
    // int n;
    // cin >> n;
    // solution.binary_size_k(permutation,n);

    // vector<int> permutation;
    // vector<int> nums = {1,2,3,4};
    // vector<bool> visited(nums.size()+1, false);
    // int n;
    // cin >> n;
    // if(n > nums.size()) {
    //     cout << "Khong co chuoi con" ;
    //     return 0;
    // }
    // solution.subset_size_k(nums,permutation,visited,n);

    vector<int> permutation;
    vector<int> nums = {1,2,3,4};
    vector<bool> visited(nums.size()+1, false);
    int n;
    cin >> n;
    if(n > nums.size()) {
        cout << "Khong co chuoi con" ;
        return 0;
    }
    solution.find_permutation(nums,permutation,visited,n);
    
    // int n;
    // cin >> n;
    // vector<int> current;
    // solution.findCombinations(current, 1, 0, n);

    // int n;
    // cin >> n;
    // vector<vector<int>> board(n,vector<int>(n,0));
    // solution.solveNQueen(board,n,0);
}

