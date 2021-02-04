#include <iostream>
#include <map>

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
    std::cout << "David's Staircase Possibilities For 10 Stairs @ (n = 10) -> " << stepPerms(10) << std::endl;
    return 0;
}