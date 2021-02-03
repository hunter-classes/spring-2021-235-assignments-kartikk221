#include <iostream>
#include <map>

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

/* David's Staircase Problem */
std::map<int, int> steps_cache = {};
int stepPerms(int n) {
    switch(n){
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        default:
            if(steps_cache.count(n) > 0)
                return steps_cache[n];
            steps_cache[n] = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
            return steps_cache[n];
    }
}

int main(){
    std::cout << "Fibonacci Sequence Recursive @ (n = 9) -> " << fib(9) << std::endl;
    std::cout << "Fibonacci Sequence Loop @ (n = 9) -> " << fib_iter(9) << std::endl;
    std::cout << "David's Staircase Possibilities For 10 Stairs @ (n = 10) -> " << stepPerms(10) << std::endl;
    return 0;
}