#include <iostream>

int fib(int n){
    return n <= 1 ? n : fib(n - 1) + fib(n - 2);
}

int main(){
    std::cout << "Fibonacci Sequence Recursive @ (n = 9) -> " << fib(9) << std::endl;
    return 0;
}