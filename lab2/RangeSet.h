#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <numeric>

template <typename T, bool Closed>
class RangeSet {
private:
    struct Interval {
        T start;
        T end;

        bool operator<(const Interval& other) const {
            return end < other.start;
        }
    };

    std::vector<Interval> intervals;

public:
    bool contains(T value) const;
    void addInterval(T start, T end);
    size_t countElements() const;
};

template <typename T, bool Closed>
bool RangeSet<T, Closed>::contains(T value) const {
    for (Interval interval : this->intervals) {
        if (Closed) {
            if (value >= interval.start && value <= interval.end) {
                return true;
            }
        } else {
            if (value > interval.start && value < interval.end) {
                return true;
            }
        }
    }
    return false;
}

template <typename T, bool Closed>
void RangeSet<T, Closed>::addInterval(T start, T end) {
    intervals.push_back(Interval{start, end});
}

template <typename T, bool Closed>
size_t RangeSet<T, Closed>::countElements() const {

    std::cout << this->intervals.size() << std::endl;

    for (int i = 0; i < intervals.size(); i++) {
        std::cout << this->intervals[i].start << std::endl;
    }


    // Сливаем пересекающиеся интервалы

    // std::vector<Interval> merged;
    // T currentStart = intervals[0].start;
    // T currentEnd = intervals[0].end;
    size_t count = 0;
    // int last = -1;
    // for (const auto& interval : intervals) {
    //     if (interval.start <= last) { // Есть пересечение
    //         count += interval.end - last + (Closed ? 1 : 0);
    //     } else { // Нет пересечения
    //         count += interval.end - interval.start + (Closed ? 1 : 0);
    //     }
    //     last = interval.end;
    // }

    // Подсчитываем количество уникальных элементов в слиянных интервалах
    // size_t count = 0;
    // for (const auto& interval : merged) {
    //     count += interval.end - interval.start + (Closed ? 1 : 0);
    // }

    return count;
}