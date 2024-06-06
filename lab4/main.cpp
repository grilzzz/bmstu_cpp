#include <iostream>
#include <vector>
#include <stdexcept> // для std::invalid_argument и std::out_of_range

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    void reduce() {
        int gcd = gcdEuclid(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

private:
    int gcdEuclid(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
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
        if (index >= fractions.size()) {
            throw std::out_of_range("Index out of range");
        }
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

        GcdIterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const GcdIterator& other) const {
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
            fraction.reduce();
        }

    private:
        int gcdEuclid(int a, int b) const {
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
    try {
        FractionContainer<Fraction> container;
        container.add(Fraction(4, 8));
        container.add(Fraction(2, 3));
        container.add(Fraction(10, 15));


        std::cout << 4 << std::endl << 1 << std::endl << 5 << std::endl;

        // for (auto it = container.begin(); it != container.end(); ++it) {
        //     std::cout << *it << std::endl;
        // }

        for (auto it = container.begin(); it != container.end(); ++it) {
            it.setGcd(1);
        }

        std::cout << "\nFractions after setting new nod:" << std::endl;
        for (size_t i = 0; i < container.size(); ++i) {
            Fraction& frac = container[i];
            std::cout << frac.numerator << "/" << frac.denominator << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
