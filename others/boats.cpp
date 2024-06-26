#include <iostream>
#include <algorithm>

int main() {
    int num=0;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    int arr[num];
    std::cout << "Enter " << num << " integers: ";
    for (int i = 0; i < num; i++) {
        std::cin >> arr[i];
    }
    std::sort( arr, arr+num );
    for (int i = 0; i < num; i++) {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
