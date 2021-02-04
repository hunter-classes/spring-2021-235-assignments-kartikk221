#include <iostream>
#include <map>

/* Fibonacci - Recursive No Cache */
int fib(int n){
    return n <= 1 ? n : fib(n - 1) + fib(n - 2);
}

/* Fibonacci - Recursive Cache Map */
std::map<int, int> fib_cache = {};
int fib_cache_register(int n){
    if(n <= 1) return n;
    int a = n - 1;
    int b = n - 2;

    if(fib_cache.count(a) > 0){
        a = fib_cache[a];
    } else {
        a = fib_cache_register(a);
        fib_cache[n - 1] = a;
    }

    if(fib_cache.count(b) > 0){
        b = fib_cache[b];
        fib_cache[n - 2] = b;
    } else {
        b = fib_cache_register(b);
    }

    return a + b;
}

int fib_cache_calculate(int n){
    for(int i = 0; i < n; i++){
        fib_cache_register(n);
    }
    return fib_cache_register(n);
}

/* Fibonacci - Loop */
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
    // std::cout << "Fibonacci Sequence Recursive @ (n = 9) -> " << fib(9) << std::endl;
    // std::cout << "Fibonacci Sequence Loop @ (n = 9) -> " << fib_iter(9) << std::endl;
    for(int i = 0; i < 500; i++){
        std::cout << "fibonacci @ " << i << " -> " <<  fib_cache_calculate(i) << std::endl;
    }

    return 0;
}