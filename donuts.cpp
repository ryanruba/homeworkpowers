#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <donuts.json>

// Struct to represent a donut option
struct DonutOption {
    std::string id;
    std::string name;
};

json loadJson(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
    return j;
}

// Function to display options and get user input
std::string chooseOption(const std::vector<DonutOption>& options) {
    for (const auto& option : options) {
        std::cout << option.id << ": " << option.name << std::endl;
    }

    std::string choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main() {
    // Load the JSON data
    json j = loadJson("donuts.json");

    // Parse the data into vectors of DonutOption
    std::vector<DonutOption> donutTypes;
    for (const auto& item : j["donut_types"]) {
        donutTypes.push_back({item["id"], item["name"]});
    }

    std::vector<DonutOption> batterTypes;
    for (const auto& item : j["batter_types"]) {
        batterTypes.push_back({item["id"], item["name"]});
    }

    std::vector<DonutOption> toppingTypes;
    for (const auto& item : j["topping_types"]) {
        toppingTypes.push_back({item["id"], item["name"]});
    }

    // Prompt the user to select a donut, batter, and topping
    std::cout << "Choose a donut type:" << std::endl;
    std::string donutChoice = chooseOption(donutTypes);

    std::cout << "Choose a batter type:" << std::endl;
    std::string batterChoice = chooseOption(batterTypes);

    std::cout << "Choose a topping type:" << std::endl;
    std::string toppingChoice = chooseOption(toppingTypes);

    // Find the selected donut, batter, and topping by their IDs
    std::string selectedDonut;
    for (const auto& option : donutTypes) {
        if (option.id == donutChoice) {
            selectedDonut = option.name;
            break;
        }
    }

    std::string selectedBatter;
    for (const auto& option : batterTypes) {
        if (option.id == batterChoice) {
            selectedBatter = option.name;
            break;
        }
    }

    std::string selectedTopping;
    for (const auto& option : toppingTypes) {
        if (option.id == toppingChoice) {
            selectedTopping = option.name;
            break;
        }
    }

    // Output the selected options
    std::cout << "You have ordered a " << selectedDonut << " donut with "
              << selectedBatter << " batter and " << selectedTopping << " topping." << std::endl;

    return 0;
}
