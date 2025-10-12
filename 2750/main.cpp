#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std; // 실무에서는 이름 충돌의 위험이 있어 사용을 지양하는 것이 좋음

int main() {
    // 입출력 속도 향상 (알고리즘 풀이 시 유용)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // std::sort를 사용하여 벡터를 오름차순으로 정렬
    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << '\n'; // std::endl 보다 '\n'이 더 빠름
    }

    return 0;
}
