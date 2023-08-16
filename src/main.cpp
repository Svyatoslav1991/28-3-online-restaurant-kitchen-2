#include <iostream>
#include <thread>
#include "functions.h"

int main() {
    std::cout << "\tTASK 28.3 ONLINE RESTAURANT KITCHEN\n\n";


    std::thread t1(foodOrder);
    std::thread t2(cooking);
    std::thread t3(delivery);

    t1.detach();
    t2.detach();
    t3.join();
        
    std::cout << "\nFOOD DELIVERED\n";

    return 0;
}