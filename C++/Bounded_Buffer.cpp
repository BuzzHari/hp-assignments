/*
 * Bouded Buffer Problem.
 */
#include <cstdint>
#include <iostream>
#include <ratio>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

const unsigned int BUFFER_SIZE = 100;
int buf[BUFFER_SIZE];

std::mutex m;
std::condition_variable not_empty;
std::condition_variable not_full;

unsigned int in = 0, out = 0, size = 0, value = 0;


void producer() {
    while(true){
        std::unique_lock<std::mutex> lock(m);
        
        not_full.wait(lock, [](){return !(size == BUFFER_SIZE);});

        buf[in] = value;
        ++size;
        in = (in + 1) % BUFFER_SIZE;
        std::cout << "Produced value: " << value << " Current Size: " << size << std::endl;
        ++value;
        lock.unlock();
        not_empty.notify_all(); // Not empty anymore, can consume.

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    while(true) {
        std::unique_lock<std::mutex> lock(m);

        not_empty.wait(lock, [](){return !(size == 0);});
        
        std::cout<< " Consumed value: " << buf[out];
        --size;
        std::cout<< " Current Size: " << size << std::endl;

        out = (out+1) % BUFFER_SIZE;
        
        lock.unlock();
        not_full.notify_all(); // Not full anymore, can produce.

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}

