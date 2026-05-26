#include <iostream>
#include <thread>
#include <semaphore>

constexpr int NUM_ITERATIONS = 1000000;
constexpr int NUM_ITERATIONS_2 = 500000;

int counter = 0;
std::binary_semaphore door(1); //1 war offen 0 ist zu

void increment_loop() {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        door.acquire();
        counter++;
        door.release();
    }
}

void increment_loop_2() {
    for (int i = 0; i < NUM_ITERATIONS_2; i++) {
        door.acquire();
        counter++;
        door.release();
    }
}

int main() {


    std::thread t1{increment_loop};
    std::thread t2{increment_loop};
    std::thread t3{increment_loop_2};
    
    t1.join();
    t2.join();
    t3.join();


    std::cout << "Endwert: " << counter << "\n";
}