#ifndef PTR_STACK_H
#define PTR_STACK_H

#include <vector>

template <typename T>
class PtrStack {
private:
    std::vector<T*> stack;

public:
    PtrStack& operator<<(T* ptr) {
        stack.push_back(ptr);
        return *this;
    }

    PtrStack& operator>>(T* &ptr) {
        ptr = stack.back();
        stack.pop_back();
        // ptr = stack.pop_back();
        // return ptr
        return *this;
    }

    bool empty() const {
        return stack.empty();
    }

    T& operator*() {
        return *stack.back();
    }

    T* operator->() {
        return stack.back();
    }
};

#endif // PTR_STACK_H