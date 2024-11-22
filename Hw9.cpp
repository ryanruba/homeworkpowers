#include <iostream>
#include <string>
using namespace std;
class Rock {
public: 
    void attack() {
        cout << "You swing at the rock" << endl;
    }
    void attack(int damage) {
        cout << "You attack the rock for " << damage << " damage" << endl;
    }

    void attack(string spell, int damage) {
        cout << "You cast the spell '" << spell << "' and deal " << damage << " magic damage" << endl;
    }
};
int main() {
    Rock rock;
    rock.attack();      
    rock.attack(15);                 
    rock.attack("Spell Smasher", 20);     
    return 0;
}
