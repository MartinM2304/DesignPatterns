#include <iostream>
#include <stdexcept>

class Duck {
public:
    virtual void quack() const {
        std::cout << "Quack! Quack!" << std::endl;
    }
    virtual void swim() const {
        std::cout << "Swimming gracefully." << std::endl;
    }
    virtual ~Duck() = default;
};

// Проблематичен подклас, който имитира пате, но има външно изискване
class ElectronicRubberDuck : public Duck {
private:
    bool hasBatteries;

public:
    ElectronicRubberDuck(bool batteries) : hasBatteries(batteries) {}

    void quack() const override {
        if (hasBatteries) {
            std::cout << "Electronic Quack! (from batteries)" << std::endl;
        } else {
            // Тук е проблемът: нарушава LSP.
            // Базовият клас Duck не очаква методът quack да се провали
            // или да има такива зависимости.
            std::cout << "Silence... needs batteries." << std::endl;
            // Или по-лошо: throw std::runtime_error("No batteries!");
        }
    }

    void swim() const override {
        // Може би плуването също зависи от батерии? Или не?
        std::cout << "Electronic duck waddles on water." << std::endl;
    }
};

void makeTheDuckQuack(const Duck& d) {
    std::cout << "--- Testing a duck ---" << std::endl;
    d.quack();
    std::cout << "----------------------" << std::endl;
}

int main() {
    Duck regularDuck;
    makeTheDuckQuack(regularDuck); // Работи коректно

    ElectronicRubberDuck workingDuck(true);
    makeTheDuckQuack(workingDuck); // Работи коректно

    ElectronicRubberDuck deadDuck(false);
    makeTheDuckQuack(deadDuck); // ПРОБЛЕМ: Не кряка, както се очаква от Duck.
                               // Това нарушава LSP, защото deadDuck не може да замени Duck без промяна в поведението.
    return 0;
}