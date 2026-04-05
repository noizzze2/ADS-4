// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int x = 0; x < len; x++) {
        for (int y = x + 1; y < len; y++) {
            if (arr[x] + arr[y] == value) {
                count++;
                while (y + 1 < len && arr[y] == arr[y + 1]) {
                    y++;
                }
            }
        }
        while (x + 1 < len && arr[x] == arr[x + 1]) {
            x++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int x = 0; x < len; x++) {
        int target = value - arr[x];
        int left = x + 1;
        int right = len - 1;
        int pos = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                pos = mid;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (pos != -1) {
            count++;
            while (x + 1 < len && arr[x] == arr[x + 1]) {
                x++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            int leftValue = arr[left];
            while (left < right && arr[left] == leftValue) {
                left++;
            }
            int rightValue = arr[right];
            while (left <= right && arr[right] == rightValue) {
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
