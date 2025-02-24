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
    // bai 1 : liet ke day nhi phan co do dai n
    void binary_size_k(vector<string>& binary_combination,string binary,int n){
        if(binary.length() == n){
            binary_combination.push_back(binary);
            return;
        }
        binary_k_size(binary_combination,permutation + '1',n);
        binary_k_size(binary_combination,permutation + '0',n);   
    }
    // bai 2 : liet ke tap con k phan tu
    void subset_size_k(vector<vector<int>>& answer,vector<int>& nums,vector<int>& permutation,vector<bool>& visited, int n){
        if(permutation.size() == n){
            answer.push_back(permutation);
            return;
        }
        for(int i = 0; i<nums.size();i++){
            if(!visited[i]){
                permutation.push_back(nums[i]);
                visited[i] = true;
                subset_size_k(answer,nums, permutation,visited,n);
                permutation.pop_back();
                visited[i] = false;
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
    vector<vector<int>> answer;
    vector<int> permutation;
    vector<int> nums = {1,2,3,4};
    vector<bool> visited(nums.size()+1, false);
    int n;
    cin >> n;
    solution.subset_size_k(answer,nums,permutation,visited,n);
    for(int i = 0;i<answer.size();i++){
        for(int j = 0;j<answer[i].size();j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}

