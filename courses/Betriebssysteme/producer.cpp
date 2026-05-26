#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>
#include <mutex>

int REPEATS = 10000;
std::vector<int> items;
int item_counter = 0;
bool blocked = false;
std::mutex mtx;

void producer(){
    for (int i = 0; i < REPEATS; i++) {
        mtx.lock();
        items.push_back(item_counter);
        item_counter++;
        std::cout <<"producer: " << item_counter << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}
void consumer() {
    for(int i = 0; i < REPEATS; i++) {
        mtx.lock();
        if(!items.empty()){
            item_counter--;
            std::cout << "Consumer: " << items.back() << std::endl;
            items.pop_back();
        }
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main() {
    std::thread prod{producer};
    std::thread cons1{consumer};
    std::thread cons2{consumer};

    // Das Programm läuft 2 Sekunden, um das Chaos zu beobachten
    std::this_thread::sleep_for(std::chrono::seconds(2));

    prod.join();
    cons1.join();
    cons2.join();

    std::cout << "Programm beendet.\n";
    return 0;
}