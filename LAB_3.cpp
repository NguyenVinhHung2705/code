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
private:
    unordered_map<int, long long> store_value; // map có key : int, value : long long, lưu số fibonacci đã tính
public:
    // bai 1 : tinh N!
    int factorial_of_number(int number){
        if(number == 1){
            return 1;
        }
        return number * factorial_of_number(number - 1); // ex: n = 5 -> 5 * 4 * 3 * 2 * 1
    }
    // bai 2 : fibonacci
    
    int Fibonacci(int number){
        if(number == 0){
            return 0;
        }else if(number == 1){
            return 1;
        }
        return Fibonacci(number-2) + Fibonacci(number-1); // o(2^n) time complexity
    }
    /* better solution, use map to store fibonacci, time complexity change from o(2^n) to o(n)
    long long Fibonacci(int number){
        if(number == 1){
            return 1;
        }else if(number == 0){
            return 0;
        }else if(store_value[number] != 0){
            return store_value[number];
        }
        store_value[number] = Fibonacci(number-1) + Fibonacci(number-2);
        return store_value[number];
    }
    */
    // bai 3 : decimal to binary
    string dec_to_bin(int number){
        if(number == 0){
            return "0";
        }
        char get_num = ((number % 2) + '0'); // 0(int) + '0'(48) == '0' / 1(int) + '0'(48) == '1'
        return  dec_to_bin(number / 2) + get_num ;
    }
    // bai 4 : (n * (n+1)) / 2
    int sum_of_n_number(int n){
        if(n == 0){
            return 0;
        }
        return n + sum_of_n_number(n-1);
    }
    // bai 5 : sum_of_odd_num from 1-> 2n + 1
    int sum_of_odd_num(int n){
        if(n == 0){
            return 1;
        }
        
        return ((2 * n) + 1) + sum_of_odd_num(n-1);    
    }
    // bai 6 : product_of_odd_num from 1 -> 2n + 1
    int product_of_odd_num(int n){
        if(n == 0){
            return 1;
        }
        
        return ((2 * n) + 1) * product_of_odd_num(n-1);
    }
    // bai 7 : tong 1^2 -> n^2
    int sum_of_power(int n){
        if(n == 1){
            return 1;
        }
        return (n*n) + sum_of_power(n-1);
    }
};



int main(){
	/* có thể bỏ phần này để chạy ở màn hình console thay vì đọc ghi file
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	#endif
	*/ 
    Solution solution;
    cout << solution.Fibonacci(9);
    string answer = solution.dec_to_bin(6);
    cout << '\n' << answer;
    cout << '\n' << solution.sum_of_odd_num(3);
    cout << '\n' << solution.product_of_odd_num(3);
    cout << '\n' << solution.sum_of_power(3);
}

