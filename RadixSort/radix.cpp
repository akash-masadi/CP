#include <iostream>
#include <vector>
// Time complexity -O( digits *(3*n + base ) )
void print(const std::vector<int>& a) {
    int n = a.size();
    std::cout << n << ": ";
    for (int num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void countSort(std::vector<int>& a, int exp) {
    int n = a.size();
    std::vector<int> output(n, 0);
    std::vector<int> count(32, 0);

    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 16;
        count[digit+16]++;
    }

    for (int i = 1; i < 32; i++) {
        count[i] += count[i - 1];
    }
    print(count);

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 16; // +16 for handling negative numbers
        output[count[digit+16] - 1] = a[i];
        count[digit+16]--;
    }
    print(output);
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void radix(std::vector<int>& a) {
	int max=INT_MIN;
	for(int i=0;i<a.size();i++)
	{
		max=(max<abs(a[i]))?abs(a[i]):max;
	}
    for (int exp = 1; max/exp>=0; exp *= 16) {
        countSort(a, exp);
    }
}


int main() {
    std::vector<int> a = {-99, -54, -121223232, -23,-16, -1, -6, -69, -72, -87};
    
    std::cout << "Before sorting: ";
    print(a);

    radix(a);

    std::cout << "After sorting: ";
    print(a);

    return 0;
}
