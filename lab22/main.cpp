#include "RangeSet.h"
#include <iostream>

int main() {
    RangeSet<int, true> rs;
    rs.addInterval(1, 5);
    rs.addInterval(10, 20);

    std::cout << "5: " << rs.contains(5) << std::endl;
    std::cout << "6: " << rs.contains(6) << std::endl; 
    std::cout << "n elements: " << rs.countElements() << std::endl; 

    RangeSet<double, false> rsd;
    rsd.addInterval(1.5, 3.5);
    std::cout << "3.5: " << rsd.contains(3.5) << std::endl;

    return 0;
}