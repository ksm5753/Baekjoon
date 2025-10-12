#include <iostream>
#include <vector>
#include <set>

using namespace std;

void PrintVector(const vector<int>& v){
    for(int num : v){
        cout << num << " ";
    }
}

int main(){
    int n;

    cin >> n;

    vector <int> arr;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    set<int> unique_numbers_set(arr.begin(), arr.end());
    vector<int> unique_numbers_vector(unique_numbers_set.begin(), unique_numbers_set.end());

    PrintVector(unique_numbers_vector);
}

