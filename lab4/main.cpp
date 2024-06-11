#include <iostream>
#include <vector>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int den) : numerator(num), denominator(den) {}

};



template <typename T>
class FractionContainer {
private:
    std::vector<T> fractions;

public:
    void add(const T& fraction) {
        fractions.push_back(fraction);
    }

    T& operator[](size_t index) {
        return fractions[index];
    }

    size_t size() const {
        return fractions.size();
    }

    class GcdIterator {
    private:
        FractionContainer<T>& container;
        size_t index;

    public:
        GcdIterator(FractionContainer<T>& cont, size_t idx) : container(cont), index(idx) {}

        GcdIterator operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const GcdIterator other) const {
            return index != other.index;
        }

        int operator*() const {
            T& fraction = container[index];
            return gcdEuclid(fraction.numerator, fraction.denominator);
        }

        void setGcd(int newGcd) {
            T& fraction = container[index];
            int oldGcd = gcdEuclid(fraction.numerator, fraction.denominator);
            fraction.numerator = (fraction.numerator / oldGcd) * newGcd;
            fraction.denominator = (fraction.denominator / oldGcd) * newGcd;
        }

    private:
        int gcdEuclid(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    };

    GcdIterator begin() {
        return GcdIterator(*this, 0);
    }

    GcdIterator end() {
        return GcdIterator(*this, fractions.size());
    }
};




int main() {
    FractionContainer<Fraction> container;
    container.add(Fraction(4, 8));
    container.add(Fraction(2, 3));
    container.add(Fraction(10, 15));


    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i].denominator << std::endl;
    }

    for (auto it = container.begin(); it != container.end(); ++it) {
        it.setGcd(1);
    }

    std::cout << "\nFractions after setting new nod:" << std::endl;
    for (size_t i = 0; i < container.size(); ++i) {
        Fraction& frac = container[i];
        std::cout << frac.numerator << "/" << frac.denominator << std::endl;
    }

    return 0;
}
