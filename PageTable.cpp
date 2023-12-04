#include <iostream>
#include <unordered_map>

class PageTable {
public:
    std::unordered_map<int, int> table; // Maps virtual page numbers to frame numbers

    void generate(int size){
        int i;
        for (i =0; i< size; i++){
            this->insert(i,rand()%10000);
        }
    }
    // Inserts or updates a page table entry
    void insert(int virtualPageNumber, int frameNumber) {
        table[virtualPageNumber] = frameNumber;
    }

    // Prints the page table contents
    void print() const {
        for (const auto& entry : table) {
            std::cout << "Virtual Page: " << entry.first
                      << ", Frame Number: " << entry.second << std::endl;
        }
    }

    // Optional: Lookup a frame number by virtual page number
    bool lookup(int virtualPageNumber) const {
        auto it = table.find(virtualPageNumber);
        if (it != table.end()) {
            return true;
        }
        return false;
    }
};

//int main() {
//    PageTable pageTable;
//
//    // Inserting entries into the page table
//    pageTable.insert(1, 100); // Virtual page 1 mapped to frame 100
//    pageTable.insert(2, 200); // Virtual page 2 mapped to frame 200
//
//    // Printing the page table
//    pageTable.print();
//
//    // Optional: Lookup example
//    uint32_t frameNumber;
//    if (pageTable.lookup(1, frameNumber)) {
//        std::cout << "Frame number for virtual page 1: " << frameNumber << std::endl;
//    } else {
//        std::cout << "Virtual page 1 not found in the page table." << std::endl;
//    }
//
//    return 0;
//}
