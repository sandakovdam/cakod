#include <iostream>

int main()
{
    const int n = 11;
    int numbers[n] {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
    int min = 0;
    int max = n - 1;
    int mid = (max + min) / 2; //4
    bool flag = false;
    while (max >= min && !flag) {
        mid = (max + min) / 2;
        if (numbers[mid] % 2 == 0 && numbers[mid - 1] % 2 != 0) {
            flag = true;
        }
        else if (numbers[mid] % 2 == 0) {
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    std::cout << mid;
}

