## **std::string**
- https://cplusplus.com/reference/string/string/
- constructor
    ```c++
    #include <string>

    std::string s0 ("Initial string");
    std::string s1 (s0.begin(), s0.begin() + 3);
    ```
- char& front() const
- char& back() const
- size_t length() const
- char& at(size_t ) const
- auto begin()
- auto rbegin()
- auto cbegin() const
- int compare (const string& ) const
- char& operator[] (size_t ) const
- string& operator+=(char )
- string& operator+=(string )
  - O(N)
- void push_back(char )
  - O(1)
- void pop_back()
- string substr (size_t pos = 0, size_t len = npos) const
- string& erase (size_t pos = 0, size_t len = npos)
- how to split string
    ```c++
    #include <sstream>
    #include <string>

    int main()
    {
        // Split the expression into tokens
        stringstream ss(exp);
        string token;
        string expArr[5];
        int i = 0;
        while (getline(ss, token, ' ')) {
            expArr[i++] = token;
        }
          // turn to int
          int first = stoi(expArr[0]);
          int second = stoi(expArr[2]);
        // turn to string
        string resStr = to_string((int)res);
    }	
    ```

## **std::vector<T>**
- https://cplusplus.com/reference/vector/vector/
- it is C array with warpping
- constructor
    ```c++
    #include <vector>

    std::vector<int> c2(2, 400); // {400, 400}

    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int));
    ```
- char& front() const
- char& back() const
- size_t size() const
- char& at(size_t ) const
- auto begin()
- auto rbegin()
- auto cbegin() const
- void push_back(const T& )
- void push_back(T&& )
- void pop_back()
- auto insert (auto it_pos, const T& val)
- void insert (auto it_pos, size_t n, const T& val)
- void insert (auto it_pos, auto it_first, auto it_last)
- void emplace (auto it_pos, ...)
- auto erase (auto it_pos)
- auto erase (auto it_first, auto it_last);
- void clear()
- T at(size_type n)
  - with exception
- T operator[] (size_type n)
  - no-throw guarantee. Otherwise, the behavior is undefined.

## **std::list<T>**
- https://cplusplus.com/reference/list/list/
- it is doubly-linked list with warpping
- constructor
    ```c++
    #include <algorithm>
    #include <iostream>
    #include <list>
     
    int main()
    {
        // Create a list containing integers
        std::list<int> l = {7, 5, 16, 8};
     
        // Add an integer to the front of the list
        l.push_front(25);
        // Add an integer to the back of the list
        l.push_back(13);
     
        // Insert an integer before 16 by searching
        auto it = std::find(l.begin(), l.end(), 16);
        if (it != l.end())
            l.insert(it, 42);
     
        // Print out the list
        std::cout << "l = { ";
        for (int n : l)
            std::cout << n << ", ";
        std::cout << "};\n";
    }
    ```
- char& front() const
- char& back() const
- size_t size() const
- char& at(size_t ) const
- auto begin()
- auto rbegin()
- auto cbegin() const
- void push_back(const T& )
- void push_back(T&& )
- void push_front(const T& )
- void push_front(T&& )
- void pop_back()
- void pop_front()
- auto insert (auto it_pos, const T& val)
- void insert (auto it_pos, size_t n, const T& val)
- void insert (auto it_pos, auto it_first, auto it_last)
- void emplace (auto it_pos, ...)
- auto erase (auto it_pos)
- auto erase (auto it_first, auto it_last);
- void clear()

## std::tuple<...>
- https://cplusplus.com/reference/tuple/tuple/
- constructor
    ```c++
    #include <tuple>

    std::tuple<int, int> tup = std::make_tuple(..., ...); 
    ```
- get
    ```c++
    std::get<0>(bar) = 100;
    ```
- unpack
    ```c++
    int myint; char mychar;
    std::tie (myint, mychar) = tup2;                            // unpack elements
    std::tie (std::ignore, std::ignore, myint, mychar) = tup3;  // unpack (with ignore)
    auto& [one, two] = tup2;       // for c++17
    ```

## **std::unordered_set<T>**
- https://cplusplus.com/reference/unordered_set/unordered_set/
- constructor
    ```c++
    #include <unordered_set>
    ```
- size_t size() const
- auto begin()
- auto cbegin() const
- pair<auto, bool> insert(const T& )	
- pair<auto, bool> insert(T&& )
- auto erase(const auto pos)
- size_t erase(const T& )
- auto erase(auto it_first, auto it_last)
- void clear()
- auto find(const T& )
- size_t count(const T ) const

## **std::unordered_multiset<T>**
- https://cplusplus.com/reference/unordered_set/unordered_multiset/
- constructor
    ```c++
    #include <unordered_multiset>
    ```
- pair<auto, auto> equal_range(const T& )

## **std::unordered_map<T>**
- https://cplusplus.com/reference/unordered_map/unordered_map/
- it is a hash table
- constructor
    ```c++
    #include <unordered_map>
    ```
- size_t size() const
- auto begin()
- auto cbegin() const
- insert
    ```c++
    std::pair<std::string,double> myshopping("baking powder",0.3);
    myrecipe.insert(myshopping);                                     // copy insertion
    
    myrecipe.insert(std::make_pair<std::string,double>("eggs",6.0)); // move insertion
    ```
- auto erase(const auto pos)
- size_t erase(const T& )
- auto erase(const auto it_first, const auto it_last)
- void clear()
- auto find(const T& )
- size_t count(const T ) const 
- T& operator[](const T& )
- foreach
    ```c++
    for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
    }
    ```

## **std::unordered_multimap<T>**
- https://cplusplus.com/reference/unordered_map/unordered_multimap/
- it is a hash table
- constructor
    ```c++
    #include <unordered_multimap>
    ```
- pair<auto, auto> equal_range(const T& )

## **std::set<T>**
- https://cplusplus.com/reference/set/set/
- constructor
    ```c++
    #include <set>
    ```
- size_t size() const
- auto begin()
- auto rbegin()
- auto cbegin() const
- pair<auto, bool> insert(const T& )	
- pair<auto, bool> insert(T&& )
- auto erase(const auto pos)
- size_t erase(const T& )
- auto erase(auto it_first, auto it_last)
- void clear()
- auto find(const T& )
- size_t count(const T ) const 
- bound
    ```c++
    for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

    itlow=myset.lower_bound (30);                //       ^
    itup=myset.upper_bound (60);                 //                   ^

    myset.erase(itlow,itup);                     // 10 20 70 80 90
    ```

## **std::multiset<T>**
- https://cplusplus.com/reference/set/multiset/
- it is a sorted tree
- constructor
    ```c++
    #include <multiset>
    ```
- pair<auto, auto> equal_range(const T& )

## **std::map<T>**
- https://cplusplus.com/reference/map/map/
- it is a sorted tree
- constructor
    ```c++
    #include <map>
    ```
- size_t size() const
- auto begin()
- auto cbegin() const
- insert
    ```c++
    std::pair<std::string,double> myshopping("baking powder",0.3);
    myrecipe.insert(myshopping);                                     // copy insertion
    
    myrecipe.insert(std::make_pair<std::string,double>("eggs",6.0)); // move insertion
    ```
- auto erase(const auto pos)
- size_t erase(const T& )
- auto erase(const auto first, const auto last)
- void clear()
- auto find(const T& )
- size_t count(const T ) const 
- T& operator[](const T& )
- foreach
    ```c++
    for (auto& x : mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
    }
    ```
- bound
    ```c++
    for (int i=1; i<10; i++) mymap.insert(i*10, ...); // 10 20 30 40 50 60 70 80 90

    itlow=mymap.lower_bound (30);                //       ^
    itup=mymap.upper_bound (60);                 //                   ^

    mymap.erase(itlow,itup);                     // 10 20 70 80 90
    ```

## **std::multimap<T>**
- https://cplusplus.com/reference/map/multimap/
- it is a sorted tree
- constructor
    ```c++
    #include <multimap>
    ```
- pair<auto, auto> equal_range(const T& )

## **std::stack<T>**
- https://cplusplus.com/reference/stack/stack/
- constructor
    ```c++
    #include <stack>
    ```
- void push(T )
- T& top()
- void pop()

## **std::queue<T>**
- https://cplusplus.com/reference/queue/queue/
- constructor
    ```c++
    #include <queue>
    ```
- void push(const T& )
- void push(T&& )
- T& front()
- void pop()

## **std::priority_queue<T>**
- https://cplusplus.com/reference/queue/priority_queue/
- constructor
    ```c++
    #include <queue>          // std::priority_queue
    #include <vector>         // std::vector
    #include <functional>     // std::greater

    int myints[]= {10,60,50,20};

    // descending
    std::priority_queue<int> descend(myints,myints+4); // default std::less<int>
    while (!descend.empty())
    {
    std::cout << ' ' << descend.top();
    descend.pop();
    }
    std::cout << '\n';

    // ascending
    std::priority_queue<int, std::vector<int>, std::greater<int>> ascend(myints,myints+4);
    while (!ascend.empty())
    {
    std::cout << ' ' << ascend.top();
    ascend.pop();
    }
    std::cout << '\n';
    ```
- void push(const T& )
- void push(T&& )
- const T& top() const
- void pop()

## Thread safety of containers

### Definition of thread safe:
In multi-threaded computer programming, a function is thread-safe when it can be invoked or accessed concurrently by multiple threads without causing unexpected behavior, race conditions, or data corruption.

### Only const member functions are thread safe !
Concurrent access to elements of a container is safe, even if different threads are accessing different elements, provided no thread is modifying the container structure. \

official: \
https://en.cppreference.com/w/cpp/container

online discussion: \
https://stackoverflow.com/questions/12931787/c11-stl-containers-and-thread-safety

conclude:
- it's thread safe to access distinct elements of the same container (const means no structure changes).
- Also, modifying the same element from multiple threads without synchronization can lead to a data race. So protection shall be implemented

sample code to do the protection:
```c++
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex vectorMutex; // Mutex to protect the vector

// Function to perform some operation on elements of a vector
void processVector(std::vector<int>& vec) {
    vectorMutex.lock();
    vec.push_back(1);
    vectorMutex.unlock();
}
void processVar(int& var) {
    var += 1;
}



int main() {
    // Create a vector with some initial values
    std::vector<int> numbers;
    int num = 0;

    // Define the number of threads to use
    int numThreads = 1000;

    // Create threads
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(processVector, std::ref(numbers)));
        threads.push_back(std::thread(processVar, std::ref(num)));
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Output the modified vector
    std::cout << "Modified vector:" << std::endl;
    //for (int num : numbers) {
    //    std::cout << num << " ";
    //}
    std::cout << numbers.size() << std::endl;
    std::cout << num << std::endl;

    return 0;
}
```
