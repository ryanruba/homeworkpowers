#include <iostream>
class Pokemon {
public:
    virtual void attack() const = 0; 
    virtual void defend() const = 0; 
    virtual void evolve() = 0; 
    virtual void sleep() const = 0;
    virtual ~Pokemon() {} 
};

class ElectricPokemon : public Pokemon {
public:
    ElectricPokemon(int power) : powerLevel(power) {}
    // Getter 
    int getPowerLevel() const { return powerLevel; }

    void attack() const override {
        std::cout << "Electric Pokémon attacks with electricity!" << std::endl;
    }
    void defend() const override {
        std::cout << "Electric Pokémon defends with electric shield!" << std::endl;
    }
    void evolve() override {
        std::cout << "Electric Pokémon evolves into a stronger form!" << std::endl;
    }
    void sleep() const override {
        std::cout << "Electric Pokémon recharges while sleeping!" << std::endl;
    }
protected:
    int powerLevel; // Protected 
};
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int power) : ElectricPokemon(power) {}
    void attack() const override {
        std::cout << "Pikachu uses Thunderbolt!" << std::endl;
    }
    void defend() const override {
        std::cout << "Pikachu uses Quick Attack to dodge!" << std::endl;
    }
    void evolve() override {
        std::cout << "Pikachu is evolving into Raichu!" << std::endl;
    }
    void sleep() const override {
        std::cout << "Pikachu takes a nap to regain energy!" << std::endl;
    }
};
int main() {
    Pikachu pikachu(10);
    // Use the getter 
    std::cout << "Pikachu's Power Level: " << pikachu.getPowerLevel() << std::endl;
    pikachu.attack();
    pikachu.defend();
    pikachu.evolve();
    pikachu.sleep(); // Polymorphism 
    return 0;
}
