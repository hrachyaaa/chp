#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 10; 

int findMissingNumber(int arr[], int n) {
    int missing = n + 1;
    
    for (int i = 1; i <= n; ++i) {
        missing ^= i;
    }

    for (int i = 0; i < n; ++i) {
        missing ^= arr[i];
    }
    
    return missing;
}

int main() {
    
    int nums[MAX_SIZE]; 
    
    
    std::srand(std::time(0));

    
    for (int i = 0; i < MAX_SIZE; ++i) {
        nums[i] = std::rand() % (MAX_SIZE + 1); 
    }

    int missing = findMissingNumber(nums, MAX_SIZE);
    std::cout << "The missing number is: " << missing << std::endl;
    
    return 0;
}
