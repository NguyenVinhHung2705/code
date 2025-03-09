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
#include "cstdlib"
#include "ctime"
using namespace std;
// LAB_5 ARRAY
void sieveEratosthenes(vector<bool>& prime, int n){
    prime[0] = false; prime[1] = false;
    for(int i = 2;i*i<=n;i++){
        if(prime[i] == true){
            for(int j = i * i;j<=n;j+=i){
                prime[j] = false;
            }    
        }
    }
}

void findPrime(int arr[], int n, vector<bool>& prime){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] > 1 && prime[arr[i]]){
            cout << arr[i] << " ";
            ++count;
        }
    }
    if(count == 0){ 
        cout << "khong co so nguyen to\n";
    }
    cout << '\n';
}

int get_integer_length(int input){
    return log10(input) + 1;
}

void Solve(int array_from_integer[], int array_size, int input){
    for(int i = 0;i<array_size;i++){
        array_from_integer[i] = input % 10;
        input /= 10;
    }
}

template <typename T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

void insert_element_increasing_order(int static_array[], int begin_index){
    int pivot = static_array[begin_index];
    while(begin_index > 0 && pivot < static_array[begin_index - 1]){
        static_array[begin_index] = static_array[begin_index - 1];
        begin_index--;
    }
    static_array[begin_index] = pivot;
}

int get_random_num(){   
    return rand() % 301 - 100;
}

void sort_static_array_increasing_order(int static_array[], int array_size){
    int loop_size = array_size;
    for(int i = 0;i<loop_size;i++){
        for(int j = 1;j<loop_size - i;j++){
            if(static_array[j] < static_array[j - 1]){
                Swap(static_array[j], static_array[j - 1]);
            }
        }
    }
}

void Print(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void getValueIncreasing(int arr[],int n, string isRandom = "none"){
    if(isRandom == "none"){
        int x;
        for(int i = 0;i<n;i++){
            cin >> x;
            arr[i] = x;
            insert_element_increasing_order(arr, i);
        }
    }else if(isRandom == "random"){
        for(int i = 0;i<n;i++){
            arr[i] = get_random_num(); // get_random_number
            insert_element_increasing_order(arr, i);
        }
    }   
}

void getValue(int arr[],int n, string isRandom = "none"){
    if(isRandom == "none"){
        int x;
        for(int i = 0;i<n;i++){
            cin >> x;
            arr[i] = x;
        }
    }else if(isRandom == "random"){
        for(int i = 0;i<n;i++){
            arr[i] = get_random_num();
        }
    }
}

// bai 3 func
void PrintZeroNegaPosi(int arr[], int n){
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            cout << arr[i] << " ";
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i] < 0){
            cout << arr[i] << " ";
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i] > 0){
            cout << arr[i] << " ";
        }
    }
    cout << '\n';
}

void PrintEvenOddZero(int arr[], int n){
    for(int i = 0;i<n;i++){
        if(arr[i] != 0 && arr[i] % 2  == 0){
            cout << arr[i] << " ";
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i] % 2  != 0){
            cout << arr[i] << " ";
        }
    }
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            cout << arr[i] << " ";
        }
    }
    cout << '\n';
}

//bai 4 func
void findNegative(int arr[], int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] < 0){
            cout << arr[i] << " ";
            ++count;
        }
    }
    if(count == 0){
        cout << "khong co so thoa man";
    }
    cout << '\n';
}

void findPositive(int arr[],int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] >= 0){
            cout << arr[i] << " ";
            ++count;
        }
    }
    if(count == 0){
        cout << "khong co so thoa man";
    }
    cout << '\n';
}

int biggestNum(int arr[],int n){
    int maxNum = arr[0];
    for(int i = 1;i<n;i++){
        if(maxNum < arr[i]){
            maxNum = arr[i];
        }
    }
    return maxNum;
}

void deleteElement(int arr[], int& n, int k){
    if(k > n || k <= 0){
        return;
    }
    for(int i = k;i<n;i++){
        arr[i-1] = arr[i];
    }
    n--;
}

void deleteDuplicate(int arr[], int& n){
    sort_static_array_increasing_order(arr,n);
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[index++] = arr[i];
        }
    }
    n = index;
}

void negaZeroPosi(int arr[],int n){
     int left = 0, mid = 0, right = n - 1;

    while (mid <= right) {
        if (arr[mid] < 0) {  // Nếu số âm, đổi chỗ với phần đầu
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }
        else if (arr[mid] == 0) { // Nếu là số 0, bỏ qua
            mid++;
        }
        else { // Nếu là số dương, đổi chỗ với phần cuối
            swap(arr[mid], arr[right]);
            right--;
        }
    }
}
int main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r",stdin);
   freopen("output.txt", "w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   #endif

    // bai 1 : create static array
    srand(time(0));
    int n;
    cin >> n;
    // int static_array[n] = {0};
    // getValueIncreasing(static_array,n);
    // Print(static_array,n);

    // bai 1 : create dynamic array 
    // int *dynamic_array = new int[n];
    // getValue(dynamic_array,n);
    // Print(dynamic_array,n);
    // delete[] dynamic_array;


    // bai 2 : tao mang so nguyen tu so nguyen
    // int input;
    // cin >> input;
    // int array_size = get_integer_length(input);
    // int array_from_integer[array_size] = {0};
    // Solve(array_from_integer,array_size,input);
    // Print(array_from_integer,array_size);

    //bai 3 : even -> odd -> zero
   // int Bai3[n];
   // getValue(Bai3,n);
   // Print(Bai3,n);
   // PrintEvenOddZero(Bai3,n);
   // PrintZeroNegaPosi(Bai3,n);

    // bai 4 : tim kiem theo dieu kien    
    // int bai4[n];
    // getValue(bai4,n,"random");
    // Print(bai4,n);
    // findNegative(bai4,n); // - tim so am
    // int big = biggestNum(bai4,n); // tim so lon nhat
    // cout << "So lon nhat: " << big << '\n';
    // findPositive(bai4,n); // tim so nguyen duong    
    // vector<bool> prime(1000,true);   
    // sieveEratosthenes(prime, 1000);   
    // findPrime(bai4,n,prime);
    
    // bai 5:
    // int bai5[n];
    // int k; cin >> k;
    // getValue(bai5,n,"random");
    // Print(bai5,n);
    // deleteDuplicate(bai5,n);
    // Print(bai5,n);

    // bai 6:
    int bai6[n];
    getValue(bai6,n,"random");
    Print(bai6,n);
    negaZeroPosi(bai6,10);
    Print(bai6,n);
    
}
