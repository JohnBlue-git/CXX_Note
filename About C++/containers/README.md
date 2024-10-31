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
- string& operator+=(...)
- void push_back(...)
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
- void push_back(T )
- void pop_back()
- auto insert (auto pos, const T& val)
- void insert (auto pos, size_t n, const T& val)
- void insert (auto pos, auto first, auto last)
- auto erase (auto pos)
- auto erase (auto first, auto last);
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
- auto erase(const auto first, const auto last)
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
- auto erase(const auto first, const auto last)
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
- auto erase(const auto first, const auto last)
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
- constructor
    ```c++
    #include <multiset>
    ```
- pair<auto, auto> equal_range(const T& )

## **std::map<T>**
- https://cplusplus.com/reference/map/map/
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
