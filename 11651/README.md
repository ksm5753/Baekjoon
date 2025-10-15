# [백준] 11651번: 좌표 정렬하기 2

[문제 링크](https://www.acmicpc.net/problem/11651)

## 🎯 문제 요약

N개의 2차원 좌표를 주어진 정렬 기준에 맞게 정렬하는 문제.
1. y좌표가 증가하는 순서
2. y좌표가 같으면 x좌표가 증가하는 순서

## ✨ 핵심 로직

`std::sort` 함수와 **사용자 정의 비교 함수(Custom Comparator)**를 활용하여 문제를 해결했다.

`std::pair<int, int>` 자료구조를 사용하여 좌표를 저장했다. `pair`의 기본 정렬은 `first` 멤버를 우선으로 비교하기 때문에, y좌표를 우선 비교하는 새로운 규칙을 함수로 직접 정의하여 `sort`에 전달해야 했다.

```cpp
// 사용자 정의 비교 함수
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    // 1. y좌표가 다르다면 y좌표를 기준으로 오름차순 정렬
    if (a.second != b.second) {
        return a.second < b.second;
    }
    // 2. y좌표가 같다면 x좌표를 기준으로 오름차순 정렬
    return a.first < b.first;
}

// sort 함수 호출
sort(coords.begin(), coords.end(), compare);
```

## 📚 배운 점 (Today I Learned)

### `const`와 참조자(`&`)의 조합

비교 함수 `bool compare(const pair<int, int>& a, ...)` 에서 `const &`를 사용하는 이유에 대해 깊이 이해했다.

- **`&` (참조자)**: `sort` 알고리즘은 비교 함수를 수없이 호출한다. 이때마다 `pair` 객체가 통째로 복사되면 심각한 성능 저하가 발생한다. 참조자를 사용하면 객체의 복사 없이 원본에 직접 접근(별명 부여)하므로 매우 효율적이다.
- **`const` (상수)**: 참조자를 통해 원본에 접근할 때, 비교 함수가 실수로 원본 데이터를 수정하는 것을 컴파일 단계에서 막아주는 안전장치이다. 즉, **효율(참조자)과 안정성(const)을 모두 챙기는 C++의 표준적인 객체 전달 방식**임을 배웠다.

### 입출력 속도 최적화

좌표의 개수 N이 최대 100,000개이므로, C++의 입출력 속도를 높이는 아래 코드는 시간 초과를 피하기 위해 필수적이다.
```cpp
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
```
