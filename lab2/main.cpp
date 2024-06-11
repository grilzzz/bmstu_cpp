#include "RangeSet.h"
#include <iostream>

int main() {
    RangeSet<int, true> rs;
    rs.addInterval(1, 5);
    rs.addInterval(10, 20);
    // rs.addInterval(1, 20);

    std::cout << "Contains 3: " << rs.contains(3) << std::endl; // true
    std::cout << "Contains 6: " << rs.contains(5) << std::endl; // false
    std::cout << "Count of elements: " << rs.countElements() << std::endl; // 16

    RangeSet<double, false> rsd;
    rsd.addInterval(1.5, 3.5);
    std::cout << "Contains 3.5: " << rsd.contains(3.5) << std::endl; // false

    return 0;
}