#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

template <typename T, bool Closed>
class RangeSet {
private:
    struct Interval {
        T start;
        T end;

        Interval(T s, T e) : start(s), end(e) {}

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
    for (const auto& interval : intervals) {
        if (Closed ? (value >= interval.start && value <= interval.end) : (value > interval.start && value < interval.end))
            return true;
    }
    return false;
}

template <typename T, bool Closed>
void RangeSet<T, Closed>::addInterval(T start, T end) {
    intervals.push_back(Interval(start, end));
}

template <typename T, bool Closed>
size_t RangeSet<T, Closed>::countElements() const {
   if (intervals.empty()) return 0;

    std::sort(intervals.start, intervals.end, [](const Interval& a, const Interval& b) {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    });

    size_t count = 0;
    int last = -1;
    for (const auto& interval : intervals) {
        if (interval.start <= last) {
            count += interval.end - last + (Closed ? 1 : 0);
        } else {
            count += interval.end - interval.start + (Closed ? 1 : 0);
        }
        last = interval.end;
    }
    return count;
}