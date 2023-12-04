#include <iostream>
#include <vector>
#include <cstdint> // For uint32_t
#include <random>  // For random number generation

class Workload {
public:
    std::vector<int> addresses;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;


    Workload(int numOfAddresses) :distribution(0, numOfAddresses) {
        // You can seed the generator with a fixed value for reproducible results
        // generator.seed(1234);
    }

    // Generate a specified number of random virtual memory addresses
    void generate(size_t workloadSize) {
        for (size_t i = 0; i < workloadSize; ++i) {
            addresses.push_back(distribution(generator));
        }
    }

    // Adds a virtual memory address to the workload
    void addAddress(int address) {
        addresses.push_back(address);
    }

    // Returns the virtual memory address at the given index
    int getAddress(int index) const {
        if (index < addresses.size()) {
            return addresses[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Returns the total number of addresses in the workload
    size_t size() const {
        return addresses.size();
    }

    // Prints all addresses in the workload
    void print() const {
        for (auto address : addresses) {
            std::cout << "Virtual Memory Address: " << address << std::endl;
        }
    }
};

//int main() {
//    Workload workload;
//
//    // Generate a list of 5 random virtual memory addresses
//    workload.generate(5);
//
//    // Print the generated workload
//    workload.print();
//
//    return 0;
//}
