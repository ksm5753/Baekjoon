#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second != b.second){
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> coords(n);
    
    for(int i = 0; i < n; i++){
        cin >> coords[i].first >> coords[i].second;
    }

    sort(coords.begin(), coords.end(), compare);

    for(int i = 0; i < n; i++)
        cout << coords[i].first << " " << coords[i].second << "\n";
}
