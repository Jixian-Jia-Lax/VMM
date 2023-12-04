#include <iostream>
#include <unordered_map>
#include <list>

class TLB {
private:
    std::unordered_map<int, int> TLBTable; // Map from page number to frame number
    std::list<int> lruList; // List to track the least recently used pages
    int capacity; // TLB capacity

public:
    explicit TLB(int size) : capacity(size) {}

    bool lookup(int pageNumber) {
        auto it = TLBTable.find(pageNumber);
        return it != TLBTable.end();
    }

    // Function to access the frame number for a given page number
    int accessPage(int pageNumber) {
        auto it = TLBTable.find(pageNumber);
        if (it != TLBTable.end()) {
            // Page found in TLB
            // Move this page to the front of the LRU list
            lruList.remove(pageNumber);
            lruList.push_front(pageNumber);
            return it->second;
        } else {
            // Page not found, handle page fault, and add new entry
            return addPage(pageNumber,10);
        }
    }

    // Function to add a page to the TLB
    int addPage(int pageNumber,int frameNumber) {
        if (TLBTable.size() >= capacity) {
            // TLB is full, remove the least recently used entry
            int lruPage = lruList.back();
            lruList.pop_back();
            TLBTable.erase(lruPage);
        }

        // Add new entry
        TLBTable[pageNumber] = frameNumber;
        lruList.push_front(pageNumber);

        return frameNumber;
    }
};
//
//int main() {
//    TLB tlb(5); // Create a TLB with 5 entries
//
//    // Example usage
//    int frame = tlb.accessPage(3);
//    std::cout << "Frame number for page 3: " << frame << std::endl;
//
//    // Add more pages and access them...
//
//    return 0;
//}
