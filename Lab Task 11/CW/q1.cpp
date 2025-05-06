#include <iostream>
#include <memory>
#include <exception>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type requested from container.";
    }
};

class Placeholder {
public:
    virtual ~Placeholder() = default;
    virtual unique_ptr<Placeholder> clone() const = 0;
};

template<typename T>
class Holder : public Placeholder {
public:
    T value;

    Holder(const T& val) : value(val) {}
    
    unique_ptr<Placeholder> clone() const override {
        return make_unique<Holder<T>>(value);
    }
};

class TypeSafeContainer {
private:
    unique_ptr<Placeholder> content;

public:
    template<typename T>
    void store(const T& val) {
        content = make_unique<Holder<T>>(val);
    }

    template<typename T>
    T get() const {
        auto derived = dynamic_cast<Holder<T>*>(content.get());
        if (!derived) {
            throw BadTypeException();
        }
        return derived->value;
    }
};

int main() {
    TypeSafeContainer container;

    container.store<string>("Test string");

    try {
        cout << "Stored string: " << container.get<string>() << endl;

        int num = container.get<int>();
        cout << "Number: " << num << endl;
    } catch (const BadTypeException& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
