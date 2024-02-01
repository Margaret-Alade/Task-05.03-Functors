//
//  main.cpp
//  Task-05.03 Functors
//
//  Created by Маргарет  on 01.02.2024.
//

#include <iostream>
#include<vector>
#include<algorithm>

class func_div_by_3 {
    int sum;
    int count;
public:
    func_div_by_3() : sum{0}, count{0} {};
    
    void operator() (int a) {
        if (a % 3 == 0) {
            sum = sum + a;
            count++;
        }
    }
    int get_count() {
        return count;
    }
    
    int get_sum() {
        return sum;
    }
};


int main(int argc, const char * argv[]) {
    std::vector<int> vec {4,1, 3, 6, 25, 54};
    
    std::cout << "[IN]: ";
    
    for (int i : vec) {
        std::cout << i << " ";
    }
    
    std::cout << "\n";
    
    func_div_by_3 func;
    func = std::for_each(vec.begin(), vec.end(), func_div_by_3());
    std::cout << "[OUT]: get_sum() = " << func.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << func.get_count() << "\n";
    
    return 0;
    
}
