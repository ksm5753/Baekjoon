#include <iostream>

using namespace std;

int main(){

    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    // 1부터 10000까지의 숫자가 나온 횟수를 저장할 배열
    int arr[10001] = {0}; // 크기는 넉넉하게 10001로

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        // 입력받은 숫자 a에 해당하는 인덱스의 값을 1 증가
    }

    // 1부터 10000까지의 숫자를 확인
    for(int i = 1; i <= 10000; i++){
        // arr[i]가 0이 아니면, 즉 숫자가 한번이라도 입력됐으면
        if(arr[i] > 0){
            // 그 횟수(arr[i])만큼 해당 숫자(i)를 출력
            for(int j = 0; j < arr[i]; j++){
                cout << i << "\n";
            }
        }
    }

    return 0;
}
