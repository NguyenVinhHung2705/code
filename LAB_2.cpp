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

class Solution{
private:
    void Swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void reverse_string(string& input){
        int left = 0;
        int right = input.length() - 1;
        while(left < right){
            Swap(input[left], input[right]);
            left++;
            right--;
        }
    }
public:
    // bai 1
    int sum_of_number(int input){
        return (input * (input + 1)) / 2;        
    }
    /*
    int sum_of_number(int input){
        int answer = 0;
        for(int i = 1;i<=input;i++){
            answer += i;
        }
        return answer;
    }
    */

    // bai 2
    string dec_to_bin(int decimal){
        string answer = "";
        while(decimal != 0){
            answer = (char)((decimal % 2) + '0') + answer;
            decimal /= 2;
        }
        return answer;
    }    
    // bai 3
    bool isPalindrome(int input){
        int temp_num = 0;
        int modify_num = input;
        while(modify_num != 0){
            int get_num = modify_num % 10;
            temp_num = (temp_num * 10) + get_num;
            modify_num /= 10;
        }
        return temp_num == input; // true = palindrome
    }
    // bai 4
    bool isArmstrong(int number){
        int temporary = number;
        while(temporary != 0){
            int num = temporary % 10;
            int power_of_three = num * num * num;
            number -= power_of_three;
            temporary /= 10;
        }
        return number == 0;
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
    int n;
    cin >> n;
	cout << solution.sum_of_number(n);
    cout << '\n' << solution.dec_to_bin(25);
    cout << '\n' << solution.isPalindrome(1212);
    string answer = solution.isArmstrong(15) ? "True" : "False";
    cout << '\n' << answer;
}

