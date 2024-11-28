#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * 이진탐색(반복문)
 */
void binary_search_iterative(int* arr, int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid;
    // left가 right보다 작거나 같을 때까지 반복
    while (left <= right) {
        mid = (left + right) / 2; // 중간값
        // 중간값이 key와 같으면 인덱스 출력 후 종료
        if (arr[mid] == key) {
            printf("%d에서 탐색 완료\n", mid);
            return;
        }
            // 중간값이 key보다 작으면 left를 mid + 1로 변경
        else if (arr[mid] < key) {
            left = mid + 1;
        }
            // 중간값이 key보다 크면 right를 mid - 1로 변경
        else {
            right = mid - 1;
        }
    }
    printf("탐색 실패\n"); // key를 찾지 못한 경우
}

/**
 * 이진탐색(재귀)
 */
void binary_search_recursive(int* arr, int left, int right, int key) {
    // left가 right보다 크면 탐색 실패
    if (left > right) {
        printf("탐색 실패\n");
        return;
    }
    int mid = (left + right) / 2; // 중간값
    // 중간값이 key와 같으면 인덱스 출력
    if (arr[mid] == key) {
        printf("%d에서 탐색 완료\n", mid);
        return;
    }
        // 중간값이 key보다 작으면 left를 mid + 1로 변경
    else if (arr[mid] < key) {
        binary_search_recursive(arr, mid + 1, right, key);
    }
        // 중간값이 key보다 크면 right를 mid - 1로 변경
    else {
        binary_search_recursive(arr, left, mid - 1, key);
    }
}
/**
 * 순차탐색
 * 배열 앞에서부터 순서대로 탐색
 */
void sequential_search(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d에서 탐색 완료\n", i);
            return;
        }
    }
    printf("탐색 실패\n");
}

int main(void) {
    int arr1[10];
    int arr2[100];
    int arr3[1000];
    int start, end;
    int key;
    double duration;

    printf("10개의 숫자를 입력하세요:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    sequential_search(arr1, 10, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 10인 배열 순차탐색 실행시간: %f\n", duration);

    printf("100개의 숫자를 입력하세요:\n");
    for (int i = 0; i < 100; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    sequential_search(arr2, 100, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 100인 배열 순차탐색 실행시간: %f\n", duration);

    printf("1000개의 숫자를 입력하세요:\n");
    for (int i = 0; i < 1000; i++) {
        scanf("%d", &arr3[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    sequential_search(arr3, 1000, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 1000인 배열 순차탐색 실행시간: %f\n", duration);

    printf("10개의 숫자를 정렬된 순서로 입력하세요:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    binary_search_iterative(arr1, 10, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 10인 배열 이진탐색(반복문) 실행시간: %f\n", duration);

    printf("100개의 숫자를 정렬된 순서로 입력하세요:\n");
    for (int i = 0; i < 100; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    binary_search_iterative(arr2, 100, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 100인 배열 이진탐색(반복문) 실행시간: %f\n", duration);

    printf("1000개의 숫자를 정렬된 순서로 입력하세요:\n");
    for (int i = 0; i < 1000; i++) {
        scanf("%d", &arr3[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    binary_search_iterative(arr3, 1000, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 1000인 배열 이진탐색(반복문) 실행시간: %f\n", duration);

    printf("10개의 숫자를 정렬된 순서로 입력하세요:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("탐색할 숫자를 입력하세요:\n");
    scanf("%d", &key);

    start = clock();
    binary_search_recursive(arr1, 0, 9, key);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC; // 실행 시간 계산
    printf("크기 10인 배열 이진탐색(재귀) 실행시간: %f\n", duration);

}