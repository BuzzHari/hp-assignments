/*
 * Dining Philospher Problem.
 * Solved using the resourse herarchy solution.
 *
 * As performance is not the need here, using mutex for printing, 
 * so the log doesn't doesn't interleave. 
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <memory>

using namespace std;

#define NO_OF_PHILOSOPHERS 5

mutex print;

class Philosopher {
    private:
        int position;
        mutex *leftFork;
        mutex *rightFork;

    public:
        Philosopher(int pos, mutex *lf, mutex *rf):
            position(pos), leftFork(lf), rightFork(rf) {}

        void think() {
            print.lock();
            cout << "Philosopher "<< position << ": *In deep thought about noodles*\n";
            print.unlock();
            this_thread::sleep_for(chrono::milliseconds(5000));
            print.lock();
            cout << "Philosopher "<< position << ": Eureka!! I have discoverd the secret of these noodles \n";
            print.unlock();
        }

        void takeForks() {
            
            // First guy has to take the left fork first.
            // Rest have to take the right first.
            if(position == 1) {
                leftFork->lock();
                rightFork->lock();
            } else {
                rightFork->lock();
                leftFork->lock();
            }
        }

        void eat() {
            print.lock();
            cout << "Philosopher "<< position << ": *Starts eating the tasty aff noodles*\n";
            print.unlock();
            this_thread::sleep_for(chrono::milliseconds(5000));
            print.lock();
            cout << "Philosopher "<< position << ": Man! I am full af\n";
            print.unlock();
        }

        void returnForks() {
            rightFork->unlock();
            leftFork->unlock();
        }

        void dine() {
            while(1) {
                think();
                takeForks();
                eat();
                returnForks();
            }
        }


};

void create_forks(vector<shared_ptr<mutex>>& forks) {
    for(int i = 0; i < NO_OF_PHILOSOPHERS; ++i)
        forks.push_back(make_shared<mutex>());
}

void start_threads(vector<thread>& threads, vector<shared_ptr<Philosopher>> philosophers) {
    for(int i = 0; i < NO_OF_PHILOSOPHERS; ++i) 
        threads.push_back(thread(&Philosopher::dine, philosophers[i]));

}

int main() {
    
    vector<shared_ptr<mutex>> forks;
    vector<shared_ptr<Philosopher>> philosophers;
    vector<thread>  threads;

    create_forks(forks);
    
    for(int i = 0; i < NO_OF_PHILOSOPHERS; ++i) {
        philosophers.push_back(make_shared<Philosopher>(
                        i+1,
                        forks[i].get(),
                        forks[(i+1)%NO_OF_PHILOSOPHERS].get()
                    )
                );
    }
    

    start_threads(threads, philosophers);
    
    for(auto &thread: threads)
        thread.join();

    return 0;
}
