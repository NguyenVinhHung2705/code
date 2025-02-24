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
int get_interger_length(int input){
    int count = 0;
    while(input != 0){
        count++;
        input /= 10;
    }
    return count;
}
void change_value_of_an_array_with_interger_digit(int array_from_interger[], int array_size, int input){
    for(int i = 0;i<array_size;i++){
        array_from_interger[i] = input % 10;
        input /= 10;
    }
}

void Swap(int& a, int& b){
    int temp = a;
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
    return (rand() % 100) - (rand() % 100);
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

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt", "w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // #endif
    // bai 1 : create static array
    srand(time(0));
    int n;
    cout << "Nhap kich thuoc static array: ";cin >> n;
    int static_array[n] = {0};
    for(int i = 0;i<n;i++){
        static_array[i] = get_random_num(); // get_random_number
        insert_element_increasing_order(static_array, i); // insert element
    }
    for(auto const& num : static_array){ // for each (range based for loop)
        cout << num << " ";
    }
    // bai 1 : create dynamic array
    cout << '\n'; cout << "Nhap kich thuoc dynamic array: ";cin >> n; 
    int *dynamic_array = new int[n]; // dynamic memory allocation
    for(int i = 0;i<n;i++){
        dynamic_array[i] = get_random_num();
    }
    for(int i = 0;i<n;i++){
        cout << dynamic_array[i] << " ";
    }
    cout << '\n';
    delete dynamic_array;
    // bai 2 : tao mang so nguyen tu so nguyen
    int input; cout << "Nhap so nguyen: ";cin >> input;
    int array_size = get_interger_length(input);
    int array_from_interger[array_size] = {0};
    change_value_of_an_array_with_interger_digit(array_from_interger,array_size,input);
    for(auto const& num : array_from_interger){
        cout << num << " ";
    }
    // bai 3 : even -> odd -> zero
    cout << '\n'; cout << "Nhap kich thuoc mang: ";cin >> n; // n da duoc declare
    int even_odd_zero[n];
    queue<int> even_nums;
    queue<int> odd_nums;
    cout << '\n';
    for(int i = 0;i<n;i++){
        even_odd_zero[i] = get_random_num();
        if(even_odd_zero[i] % 2 == 0 && even_odd_zero[i] != 0){
            even_nums.push(even_odd_zero[i]);
        }else if(even_odd_zero[i] % 2 != 0 && even_odd_zero[i] != 0){
            odd_nums.push(even_odd_zero[i]);
        }
    }

    // normal travel
    cout << "In binh thuong: ";
    for(auto const& num : even_odd_zero){
        cout << num << " ";
    }
    // even -> odd -> zero travel
    cout << '\n';
    cout << "In chan le 0: ";
    for(int i = 0;i<n;i++){
        if(!even_nums.empty()){
            cout << even_nums.front() << " ";
            even_nums.pop();
        }else if(!odd_nums.empty()){
            cout << odd_nums.front() << " ";
            odd_nums.pop();
        }else{
            cout << 0 << " ";
        }
    }

    // bai 3 : zero -> negative -> positive
    cout << '\n' << "Nhap kich thuoc mang: ";cin >> n; // n da duoc declare
    int zero_nega_posi[n];
    queue<int> negative_nums;
    queue<int> positive_nums;
    cout << '\n';
    for(int i = 0;i<n;i++){
        zero_nega_posi[i] = get_random_num();
        if(zero_nega_posi[i] < 0 && zero_nega_posi[i] != 0){
            negative_nums.push(zero_nega_posi[i]);
        }else if(zero_nega_posi[i] > 0 && zero_nega_posi[i] != 0){
            positive_nums.push(zero_nega_posi[i]);
        }
    }

    // normal travel
    cout << '\n' << "In theo kieu binh thuong: ";
    for(auto const& num : zero_nega_posi){
        cout << num << " ";
    }
    // zero -> nega -> posi
    cout << '\n' << "In theo 0 am duong: ";
    int count_zero = n - (negative_nums.size() + positive_nums.size());
    for(int i = 0;i<count_zero;i++){
        cout << 0 << " ";
    }
    for(int i = count_zero;i<n;i++){
        if(!negative_nums.empty()){
            cout << negative_nums.front() << " ";
            negative_nums.pop();
        }else{
            cout << positive_nums.front() << " ";
            positive_nums.pop();
        }
    }
    
}



/*
1. Tạo mảng số nguyên
- Có số phần tử xác định - DONE
- Mảng động, xài bao nhiêu tạo bấy nhiêu (tham khảo tr302, sách Quách Tuấn
Ngọc) - DONE
2. Nhập dữ liệu (mảng tĩnh)
- Nhập mảng từ bàn phím - DONE
- Tạo mảng bằng cách lấy số ngẫu nhiên - DONE
- Nhập mảng, sau khi nhập xong, mảng đã được sắp xếp tăng dần. - DONE
- Tạo mảng từ dãy số nguyên. Vd: Nhập số: 5963, tách số tạo mảng a[3;6;9;5] - DONE
3. In mảng - duyệt mảng (mảng tĩnh)
- in theo thứ tự bình thường - DONE
- in các số chẵn -> lẻ -> các số bằng 0 - DONE
- in số 0 --> âm -> dương - DONE

4. Với mảng tĩnh, tìm kiếm theo điều kiện: Tìm tất cả số
âm, tìm số lớn nhất, tìm số chẵn, tìm số nguyên tố
5. Chèn, xóa phần tử trong mảng
- Xóa tại vị trí thứ k
- Tỉa bớt phần tử giống nhau, chỉ giữ lại 1 phần tử đại
diện.

6. Chuyển các phần tử >0 về cuối mảng, <0 về đầu
mảng, =0 về giữa mảng
*/
