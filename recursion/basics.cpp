#include <iostream>

int fib(int n){
    return n <= 1 ? n : fib(n - 1) + fib(n - 2);
}

int fib_iter(int n){
    int prev_number = 0;
    int next_number = 1;
    for(int i = 1; i <= n; i++){
        int sum = prev_number + next_number;
        prev_number = next_number;
        next_number = sum;
    }
    return prev_number;
}

int main(){
    std::cout << "Fibonacci Sequence Recursive @ (n = 9) -> " << fib(21) << std::endl;
    std::cout << "Fibonacci Sequence Loop @ (n = 9) -> " << fib_iter(21) << std::endl;
    return 0;
}