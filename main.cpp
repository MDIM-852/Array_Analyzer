#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void inputArray(vector<int>& a, int size);
void displayArray(vector<int>& a, int size);
int linearSearch(vector<int>& a, int size, int target);
int binarySearch(vector<int>& a, int size, int target);
int kadaneAlgorithm(vector<int>& a, int size);
void printLine();
void inputArray(vector<int>& a, int size) {
    for (int i = 0; i < size; ++i) {
        cin>>a[i];
    }
}
void displayArray(vector<int>& a,int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}
int linearSearch(vector<int>& a,int size,int target){
    for(int i=0;i<size;i++){
        if(a[i]==target){
            return i;
        }
    }
    return -1;
}
int binarySearch(vector<int>& a, int size, int target){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(a[mid] == target){
            return mid;
        }
        else if(a[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int kadaneAlgorithm(vector <int>& a,int size){
    int CurrSum=0;
    int MaxSum=INT_MIN;
    for(int i=0;i<size;i++){
        CurrSum+=a[i];
        if(CurrSum>MaxSum){
            MaxSum=CurrSum;
        }
        if(CurrSum<0){
            CurrSum=0;
        }
    }
    return MaxSum;
}
void printLine() {
    cout << "----------------------------------\n";
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> a(size);

    cout << "Enter elements:\n";
    inputArray(a, size);

    int choice;
    do {
        cout << "\n----- ARRAY ANALYZER MENU -----\n";
        cout << "1. Display Array\n";
        cout << "2. Linear Search\n";
        cout << "3. Binary Search\n";
        cout << "4. Maximum Subarray Sum (Kadane)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayArray(a, size);
        }
        else if (choice == 2) {
            int target;
            cout << "Enter element to search: ";
            cin >> target;

            int idx = linearSearch(a, size, target);
            if (idx != -1)
                cout << "Element found at index " << idx << endl;
            else
                cout << "Element not found\n";
        }
        else if (choice == 3) {
            int target;
            cout << "Enter element to search: ";
            cin >> target;

            sort(a.begin(), a.end());   // REQUIRED
            int idx = binarySearch(a, size, target);

            if (idx != -1)
                cout << "Element found at index " << idx << " (in sorted array)\n";
            else
                cout << "Element not found\n";
        }
        else if (choice == 4) {
            int maxSum = kadaneAlgorithm(a, size);
            cout << "Maximum Subarray Sum = " << maxSum << endl;
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
