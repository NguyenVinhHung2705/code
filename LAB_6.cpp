// LAB 6. SORT

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
class Sort{
private:
	int findSmallestNum(int arrayInput[], int arraySize, int beginIndex){
		int minNumIndex = beginIndex - 1;

		for(int i = beginIndex;i<arraySize;i++){
			if(arrayInput[i] < arrayInput[minNumIndex]){
				minNumIndex = i;
			}
		}
		return minNumIndex;
	}
	void Swap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	int partition(int arrayInput[], int beginIndex, int endIndex){
		int pivot = arrayInput[endIndex];
		int i = beginIndex - 1;
		for(int j = beginIndex;j<=endIndex-1;j++){
			if(arrayInput[j] < pivot){
				i++;
				Swap(arrayInput[j], arrayInput[i]);
			}
		}
		i++;
		Swap(arrayInput[i], arrayInput[endIndex]);
		return i;
	}
	void merge(int leftArray[], int rightArray[], int arrayInput[], int leftArraySize, int rightArraySize){
		int i = 0, l = 0, r = 0;
		while(l < leftArraySize && r < rightArraySize){
			if(leftArray[l] < rightArray[r]){
				arrayInput[i] = leftArray[l];
				l++;
				i++;
			}else{
				arrayInput[i] = rightArray[r];
				r++;
				i++;
			}
		}
		while(l < leftArraySize){
			arrayInput[i] = leftArray[l];
			l++;
			i++;
		}
		while(r < rightArraySize){
			arrayInput[i] = rightArray[r];
			r++;
			i++;
		}
	}
public:
	void selectionSort(int arrayInput[], int arraySize){
		for(int i = 0;i<arraySize - 1;i++){
			int tmp = findSmallestNum(arrayInput, arraySize,i + 1);
			if(tmp != i){
				Swap(arrayInput[i], arrayInput[tmp]);
			}
		}
	}
	void insertionSort(int arrayInput[], int arraySize){
		for(int i = 1;i<arraySize;i++){
			int pivot = arrayInput[i];
			int j = i - 1;
			while(j >= 0 && arrayInput[j] > pivot){
				arrayInput[j + 1] = arrayInput[j];
				j--;
			}
			arrayInput[j+1] = pivot;
		}
	}
	void bubbleSort(int arrayInput[], int arraySize){
		for(int i = 0;i<arraySize;i++){
			for(int j = 1;j<arraySize - i;j++){
				if(arrayInput[j] < arrayInput[j-1]){
					Swap(arrayInput[j], arrayInput[j-1]);
				}
			}
		}
	}
	void quickSort(int arrayInput[], int beginIndex, int endIndex){
		if(beginIndex >= endIndex){
			return;
		}
		int pivot = partition(arrayInput,beginIndex,endIndex);
		quickSort(arrayInput, beginIndex, pivot - 1);
		quickSort(arrayInput, pivot + 1, endIndex);
	}
	void mergeSort(int arrayInput[], int arraySize){
		if(arraySize <= 1){
			return;
		}
		int mid = arraySize / 2;
		int leftArray[mid];
		int rightArray[arraySize - mid];

		int i = 0;
		int j = 0;
		for(i;i<arraySize;i++){
			if(i < mid){
				leftArray[i] = arrayInput[i];
			}else{
				rightArray[j] = arrayInput[i];
				j++;
			}
		}
		mergeSort(leftArray, mid);
		mergeSort(rightArray, arraySize - mid);
		merge(leftArray, rightArray, arrayInput, mid, arraySize - mid);
	}
};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	#endif
	Sort sort;
	int n;
	cin >> n;
	int arrayInput[n];
	for(auto &num : arrayInput){
		cin >> num;
	}
	sort.mergeSort(arrayInput,n);
	for(auto const& num: arrayInput){
		cout << num << " ";
	}
	
	
	

}