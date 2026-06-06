#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>&arr, int size){
    int i, j, key;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int BinarySearch(const vector<int>& arr, int lowstart, int highstart, int target){
    int low = lowstart;
    int high = highstart;
    while(low <= high){
        int mid = low + (high - low)/2    ;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
    }
     return -1;
}

int main(){
    int N, X;
    cin>>N>>X;

    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    InsertionSort(arr, N);

    int Total_Sama = 0;

    for(int i = 0; i < N; i++){

        if (i > 0 && arr[i] == arr[i-1]){
            continue;
        }

        int Elemen = arr[i];
        int Target_Pencarian = X - Elemen;


        int Index_Ditemukan = BinarySearch(arr, i + 1, N - 1, Target_Pencarian);

        if(Index_Ditemukan != -1){
            Total_Sama++;
            }
        
        }
    cout<<Total_Sama<<endl;
}