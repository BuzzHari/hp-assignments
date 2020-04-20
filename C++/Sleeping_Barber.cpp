/*
 * Sleeping Barber.
 *
 * A real simple implementation. 
 * To better simulate it, random time can be used for sleep,
 * and a queue can be used for the waiting room.
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <condition_variable>

using namespace std;

#define SEATS 5

mutex accessWRSeats;
mutex custReady;

condition_variable cust;

int numberOfFreeWRSeats = SEATS;

void Barber() {
    while(1) {
        unique_lock<mutex> custlock(custReady);
        //Wait for customer.
        cust.wait(custlock, [](){
                    if(SEATS - numberOfFreeWRSeats == 0){
                        cout << "Barber Sleeping his ass off\n";
                        return false;
                    }
                    return true;
                });
        // One waiting room seats becomes free.
        cout<<"cust.wait done\n";
        unique_lock<mutex> seatLock(accessWRSeats);
        numberOfFreeWRSeats += 1;
        cout << "Customer going for hair cut\n";
        seatLock.unlock();
        cout<< "Barber cutting hair\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void Customer() {
    while(1) {
        unique_lock<mutex> seatLock(accessWRSeats);
        if( numberOfFreeWRSeats > 0 ) {
            numberOfFreeWRSeats -= 1; // Occupy a free seat.
            cust.notify_all(); // Customer there for hair cut. Notify barber.
            cout << "Cutomer in waiting room: " << SEATS - numberOfFreeWRSeats << endl;
            seatLock.unlock();
        } else {
            cout << "Waiting room full: " << numberOfFreeWRSeats<<endl; 
            seatLock.unlock();
        }
            this_thread::sleep_for(chrono::seconds(2));
    }
}

int main() {
    

    thread barber_thread(Barber);
    thread customer_thread(Customer);

    barber_thread.detach();
    customer_thread.detach();
    this_thread::sleep_for(chrono::seconds(560));
    return 0;
}
