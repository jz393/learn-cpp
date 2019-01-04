//  Created by Jane Zhang on 1/3/19.
//  Copyright © 2019 Jane Zhang. All rights reserved.
//  Arrays/Vectors and Strings (simple methods) in C++

#include <iostream>
#include <vector>
using namespace std;

/*##################Leetcode question 890#####################*/

/* Return whether numerical vector is always increasing/decreasing 
*/
bool isMonotonic(vector<int>& arr) {
    //compare first two different ints
    int len = arr.size(); //length method
    int i = 0;
    int j = 1;

    while (j < len && arr[i] == arr[j]) {
        i++;
        j++;
    }

    //see if constant 
    if (j + 1 == len) {
        return true;
    }

    //see if increasing
    else if (arr[i] < arr[j]) {
        for (int k = j; k <= len - 2; k++){
            if (arr[k] > arr[k+1]) return false;
        }
        return true;
    } 

    //see if decreasing
    else {
        for (int k = j; k <= len - 2; k++){
            if (arr[k] < arr[k+1]) return false;
        }
        return true;
    }
}

/*##################Selection Sort##########################*/

/* Find and return index of minumum value in vector */
int findMin(vector<int>& arr, int start) {
    int minInd = start;
    int minVal = arr[start];

    for (int i = start + 1; i < arr.size(); i++) {
        if (arr[i] < minVal){
            minInd = i;
            minVal = arr[i];
        }
    }

    return minInd;
}

/* Swap arr[i] and arr[j] in place */
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/* Implement selection sort on numerical vector in-place */
void selectionSort(vector<int>& arr, int start){
    if (start < arr.size() - 1){
        int ind = findMin(arr, start);
        swap(arr, start, ind);
        selectionSort(arr, start+1); 
    }
}

/*###################Leetcode Question 125########################*/

/* Return whether or not string is palindrome */
bool isPalindrome(string s) {
    int start = 0;
    int end = s.length();

    while (start < end){
        if (! isalnum(s[start])) {
            start ++;
        }

        else if (! isalnum(s[end])){
            end --;
        }

        else if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }

        else {
            start ++;
            end --;
        }    
    }

    return true;
}

/*#################Run Everything##########################*/

/* Main Function */
int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(6);
    arr.push_back(9);
    arr.push_back(8);
    //TODO: any better way to do this?
    cout << "Starting methods\n";

    bool monotonic = isMonotonic(arr);
    cout << "Calling isMonotonic " << endl ;
    cout << monotonic << endl; 


    cout << "Calling selectionSort" << endl;
    selectionSort(arr, 0);
    for (std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); ++i){
        std::cout << *i << ' ';
    }
    cout << endl;

    string s = "hello world";
    cout << s << endl;


}