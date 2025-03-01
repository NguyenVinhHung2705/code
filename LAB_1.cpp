// LAB 1. ngôn ngữ cơ bản

#include "iostream"
#include "iomanip"
using namespace std;
// bài 1
int two_sum_with_formula(int first_num, int second_num){
	return (first_num * first_num) + (second_num * second_num);
}
// bài 2
double F_to_C(double F){
	return 5* (F - 32) / 9;
}
// Bài 3
int biggest_num(int first, int second, int third){
	int temporary = first >= second ? first : second;
	return temporary >= third ? temporary : third;
}
// bài 4
void seconds_to_hour(int totalSeconds) {
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    std::cout << hours << " hours, " << minutes << " mins, " << seconds << " secs\n";
}
/* bài 5
 */
int first_sum(int n){
	int answer = 0;
	int i = 1;
	while(i<=n){
		answer += (1.0 / i);
		i++;
	}
	return answer;
}
int second_sum(int n){
	int answer = 0;
	int i = 1;
	while(i <= n){
		answer += i * i;
		i++;
	}
	return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	#endif
	int n;
	cin >> n;
	unsigned int fibonacci[2] = {0,1};
	for(int i = 2;i<=n;i++){
		fibonacci[i % 2] = fibonacci[0] + fibonacci[1];
		cout << "[" << i << "][" << i%2 << "] " <<fibonacci[i % 2] << '\n';
	}
	

}