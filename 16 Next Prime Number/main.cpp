//
//  main.cpp
//  16 Next Prime Number
//
//  Created by Greg Salvesen on 11/18/16.
//  Copyright © 2016 DVS. All rights reserved.
//

#include <iostream>
#include <cmath>

// Checks if the given number is prime
bool checkIfPrime(int n) {
    //If the number is less than 2, then it is not prime
    if(n < 2) {
        return false;
    }
    //If the number is 2, then it is prime
    if(n == 2) {
        return true;
    }
    //If the number is even and not 2, then it is not prime
    if(n % 2 == 0) {
        return false;
    }
    // Checks all odd numbers less than the square root of the number to see if any of them divide evenly, if they do return false, otherwise return true
    for(int i = 3; i < sqrt(n) + 1; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
    
}

int main(int argc, const char * argv[]) {
    std::cout << "==========\nThis program takes a number, and either tells you that it's prime, or if it isn't finds the next prime number.\n==========" << std::endl;
    std::cout << "Enter a number: ";
    int num = 0;
    std::cin >> num;
    int primeNum = num;
    
    // Checks each odd number after the number given until it finds the next prime.
    while(!checkIfPrime(primeNum)) {
        if(primeNum < 2) {
            primeNum = 2;
        } else if(primeNum % 2 == 0) {
            primeNum++;
        } else {
            primeNum += 2;
        }
    }
    
    if(num == primeNum) {
        std::cout << num << " is a prime number!" << std::endl;
    } else {
        std::cout << num << " is not prime. The next prime number is " << primeNum << std::endl;
    }

    
    return 0;
}
