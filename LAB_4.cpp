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
#define ll long long
// LAB_4 recursion 2
class Solution {
private:

public:
    // bai 1 : ban dau co 2 vi trung, moi 1 gio vi trung se tang gap doi, sau 5 gio co bao nhieu vi trung?
    int after_n_hour(int hours){
        if(hours == 0){
            return 2;
        }
        return 2 * after_n_hour(hours - 1); // 2^5 = 64
    }
    // bai 2 : lai xuat 12%/nam, gui ngan hang 1000USD sau 30 nam se co bao nhieu tien
    double money_after_n_years(double money,int years){
        if(years == 0){
            return money;
        }        
        return money_after_n_years((money / 100) * 112, years - 1); // * 112 -> tang 12%
    }
    // bai 3 : Thap HaNoi

    void HanoiTower(int n, int i, int j, int k){
        if(n == 1){
            cout << n << " : " << (char)(i + 'A') << " -> " << (char)(j + 'A') << '\n';
        }
        else{
            HanoiTower(n-1, i,k,j);
            cout << n << " : " << (char)(i + 'A') << " -> " << (char)(j + 'A') << '\n';
            HanoiTower(n-1, k,j,i);
        }
    }

    // bai 4 : in dao nguoc so nguyen duong
    void reverse_interger(int num){
        if(num == 0){
            return;
        }
        cout << num % 10; 
        reverse_interger(num/10);
    }

    // bai 5 : count digits of an interger
    int count_digits(ll num){
        if(num <= 9 && num >= 0){ // con 1 chu so tra ve 1
            return 1; 
        }
        return 1 + count_digits(num / 10);
    }

    // bai 6 : count odd digits of an interger
    int count_odd_digits(ll num){
        if(num == 0){
            return 0;
        }
        int temporary_num = num % 10; // num = 10 -> temporary_num = 0
        if(temporary_num % 2 == 1){ // if odd
            return 1 + count_odd_digits(num/10); // add 1 
        }
        return count_odd_digits(num/10); 
    }

    // bai 7 : biggest digit of an interger
    int biggest_digit(int num, int max_digit = -1){
        if(num == 0 || max_digit == 9){ // max_digit = 9 -> da la so lon nhat -> return luon
            return max_digit;
        }
        if(num % 10 > max_digit){
            max_digit = num % 10; // cap nhat max_digit neu co digit lon hon           
        }        
        return biggest_digit(num/10,max_digit); // de quy chia lay nguyen 123 -> 12
    }

    // bai 8 : full of even digits
    bool only_even_digits(int num){
        if(num == 0){
            return true;
        }
        int temporary_num = num % 10;
        if(temporary_num % 2 == 1){
            return false;
        }

        return only_even_digits(num/10);
    }

    // bai 9 : log2(num) (int)
    int int_logarit_of_num(int num){
        if(num <= 1){
            return 0;
        }
        return 1 + int_logarit_of_num(num / 2);
    }

    // bai 10 : maximum divisor of two intergers
    int max_divisor(int first_num, int second_num){ 
        if(second_num == 0){
            return first_num;
        }
        return max_divisor(second_num, first_num % second_num); // thuat toan euclid
    }

    // bai 11 : find first digit of an interger
    int first_digit(int num){
        if(num <= 9){ // khi con 1 chu so thi do chinh la so dau tien
            return num;
        }
        return first_digit(num / 10); 
    }

    // bai 12 : find string length without using library function (using recursion)
    int string_length(const string& s, int s_index = 0){
        if(s[s_index] != '\0'){ // \0 là ki tu ket thuc cau
            return string_length(s,s_index+1); // 0 1 2 3 4 5
        }                                      // h e l l o \0
        return s_index;
    }

    // bai 13 : to hop chap k cua n c(n,k)
    int C(int n, int k){
        if(n == k || k == 0){
            return 1;
        }
        if(k > n){
            return 0;
        }
        return C(n-1,k) + C(n-1,k-1);
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
    cout << solution.after_n_hour(10) << '\n';
    cout << solution.money_after_n_years(1000,3) << '\n';
    solution.HanoiTower(3,0,2,1);
    solution.reverse_interger(112); cout << '\n';
    cout << solution.count_digits(99999) << '\n';
    cout << solution.count_odd_digits(123554) << '\n';
    cout << solution.biggest_digit(45413) << '\n';
    string is_only_even_digits = solution.only_even_digits(333) ? "True" : "False";
    cout << is_only_even_digits << '\n';
    cout << solution.int_logarit_of_num(333) << '\n';
    cout << solution.max_divisor(3,3) << '\n';
    cout << solution.first_digit(421) << '\n';
    cout << solution.string_length(" hel lo Worl d1 ") << '\n';
    cout << solution.C(9,4);
	
}

