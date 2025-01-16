#include <iostream>
#include <future>
#include <thread>
#include <chrono>

void asyncTask(std::promise<int>&& promise) {
    // Simulating an asynchronous task
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int result = 42; // Example result
    promise.set_value(result);
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    // Start async task
    std::thread t(asyncTask, std::move(promise));
    
    // Wait for the result
    std::cout << "Waiting for the result..." << std::endl;
    int result = future.get();  // Blocking call

    std::cout << "Result: " << result << std::endl;

    t.join();  // Wait for the thread to finish

    return 0;
}
