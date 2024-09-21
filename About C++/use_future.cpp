#include <iostream>
#include <thread>
#include <functional> // callback type
#include <future>     // async

void onTaskComplete(int result) {
    std::cout << "Task completed with result: " << result << std::endl;
}

// A function that runs asynchronously and calls the callback
void asyncFunction(std::function<void(int)> callback, int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    callback(x);
}

int main() {
    int value = 10;

    //
    // std::async
    //

    // Run the async function with the callback
    std::future<void> result = std::async(std::launch::async,
        asyncFunction,
            onTaskComplete, value
        );

    // Do other work while the async function runs
    std::cout << "Doing other work in main thread..." << std::endl;

    // Wait for the async function to complete
    result.get(); // type ret = result.get(); if return value

    //
    // With lambda function
    //
    
    // Perform the task asynchronously
    std::async(std::launch::async, 
        [&value] () {
            // Simulate a long-running task
            std::this_thread::sleep_for(std::chrono::seconds(2));
            // Call the callback with the result
            onTaskComplete(value);
        });

    // Do other work while the task is running
    std::cout << "Doing other work..." << std::endl;

    // Wait for a key press to keep the program running
    std::cin.get();

    return 0;
}
