//suppose each virtual address is of length 16 bit.
//4 bits offset and 12 bits page number

#define PAGESIZE 1<<4
#define NUMBEROFPAGES 1<<12
#define TLBSIZE 100
#define OFFSET 4

#include "WorkLoad.cpp"
#include "PageTable.cpp"
#include "TLB.cpp"

int getPageNumber(int virtualAddress){
    return virtualAddress / PAGESIZE;

}

int main(){

    int workloadSize = 1000000;

    TLB tlb(TLBSIZE);
    PageTable pageTable;
    pageTable.generate(NUMBEROFPAGES);
    Workload workload(1<<16);
    workload.generate(workloadSize);

    int hit =0;
    int miss = 0;

    for(int i=0; i<workloadSize;i++){
        int virtualAddress = workload.getAddress(i);
        int pageNumber = getPageNumber(virtualAddress);

        if(tlb.lookup(pageNumber)){
            hit ++;
            tlb.accessPage(pageNumber);
        }
        else{

            tlb.addPage(pageNumber,pageTable.lookup(pageNumber));
            miss ++;
            tlb.lookup(pageNumber);
        }

    }
    std :: cout << "Hit :" << hit << "Miss : "<<miss << "\n";
    std :: cout << "Hitrate = " << hit* 100.0 /miss *100 <<"%  \n";

    return 0;





}