#include <iostream>

// Function to calculate the Jacobsthal number for a given n
int getJacobsthalNumber(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

int main(int, char **argv) {
    int j = getJacobsthalNumber(2);
    std::cout << "Starting Jacobsthal number: " << j << std::endl;

    int num = std::atoi(argv[1]);
    for (int i = j; i < num; ) {
        int k = i;

        do {
            j = getJacobsthalNumber(++k);
        } while (j == i);
        
	if (j >= num)
	{ 
	    j = i;
            break;
	}
        for (int m = j; m > i; m--) {
            std::cout << m << std::endl;
        }

        i = j;
    }

    for (int w = num; w > j; w--)
	   std::cout << w << std::endl; 
    return 0;
}

