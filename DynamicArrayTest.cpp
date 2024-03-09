#include <iostream>
#include <string.h>

#include "DynamicArray.hh"

int main() {
    DynamicArray dp1;
    DynamicArray dp2 = DynamicArray(10);

    //Default Constructor Test
    int pass1 = 0;
    if(dp1.getSize() == 0 || dp1.getCapacity() == 1) {
        pass1++;
    }
    if (dp2.getSize() == 0 || dp2.getCapacity() == 10) {
        pass1++;
    }
    std::cout << "Objects Initialized: " << pass1 << "/2\n";
    
    //Push Tests
    int pass2 = 0;
    bool correct = true;
    for(int i = 0; i < 11; i++) {
        try {
            dp2.push_back(i);
        } catch (...) {
            correct = false;
            break;
        }
    }
    if(!correct) {
        std::cout << "Push Elements Fail\n";
    } else {
        pass2++;
    }
    
    if(dp2.getSize() == 11 || dp2.getCapacity() == 20) {
        pass2++;
    } else {
        std::cout << "Array Modifications Fail\n";
    }

    correct = true;
    for(int i = 0; i<11; i++) {
        if (dp2.getNum(i) != i){
            correct = false;
            break;
        }
    }
    if (!correct) {
        std::cout << "Order of Elements Test Fail\n";
    } else {
        pass2++;
    }
    std::cout << "Push Elements Tests: " << pass2 << "/3\n";

    //Pop Tests
    int pass3 = 0;
    correct = true;

    dp1.pop_back();
    if (dp1.getSize() == 0 and dp1.getCapacity() == 1) {
        pass3++;
    }

    for (int i = 0; i < 6; i++) {
        dp2.pop_back();
    }
    if (dp2.getSize() == 5 and dp2.getCapacity() == 5) {
        pass3++;
    }
    std::cout << "Pop Elements Tests: " << pass3 << "/2\n";

    //Insert and Delete Tests
    int pass4 = 0;
    
    dp1.insertAt(3,3);  //Fails to insert
    std::cout<<dp1.getSize();
    if(dp1.getSize() == 0) {
        pass4++;
    }
    dp2.insertAt(10,2);
    if (dp2.getNum(2) == 10) {
        pass4++;
    }
    dp2.deleteAt(2);
    if (dp2.getNum(2) == 2) {
        pass4++;
    }
    std::cout << "Insert/Delete Elements Tests: " << pass4 << "/3\n\n";

    std::cout << "Total Score: " << pass1+pass2+pass3+pass4 << "/10\n";
    return EXIT_SUCCESS;
}