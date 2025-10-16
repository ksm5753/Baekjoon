#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 1. 원본 좌표들을 입력받는다.
    vector<int> original(n);
    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    // 2. 좌표들을 복사하여 정렬 및 중복 제거를 수행한다.
    vector<int> sorted_unique = original; // 사본 생성

    // 2-1. 정렬
    sort(sorted_unique.begin(), sorted_unique.end());
    // 2-2. unique + erase로 중복 원소 제거
    sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());

    // 3. 원본 좌표 각각에 대해 압축된 좌표(인덱스)를 찾는다.
    for (int i = 0; i < n; i++) {
        // lower_bound는 sorted_unique 벡터에서 original[i] 값 이상의 첫 위치를 가리키는 반복자(iterator)를 반환한다.
        // 이 반복자에서 벡터의 시작 주소를 빼면 그것이 바로 인덱스(0부터 시작)가 된다.
        auto it = lower_bound(sorted_unique.begin(), sorted_unique.end(), original[i]);
        cout << (it - sorted_unique.begin()) << " ";
    }

    return 0;
}
