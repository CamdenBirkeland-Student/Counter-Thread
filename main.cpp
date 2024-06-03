#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx; // Mutex for synchronization

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Count Up: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Count Down: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

int main() {
    std::thread thread1(countUp);
    thread1.join(); // Wait for the first thread to finish

    std::thread thread2(countDown);
    thread2.join(); // Wait for the second thread to finish

    return 0;
}