std::move() in modern C++


Syntax: The syntax of std::move() is:
cpp
複製程式碼
template <typename T>
constexpr std::remove_reference_t<T>&& move(T&& t) noexcept;
* T&& t: This is a forwarding reference (or universal reference) which can bind to both lvalues and rvalues.
* std::remove_reference_t<T>&&: This indicates that the function returns an rvalue reference to the type T after removing any reference qualifiers.


Use Cases:
* Moving Resources: When you have a resource (like dynamically allocated memory or a file handle) owned by an object and you want to transfer ownership of that resource to another object efficiently, you use std::move().
* Performance Optimization: Moving is typically faster than copying for large or complex objects because it avoids unnecessary duplication of resources.
* Avoiding Copies: Some types, like std::unique_ptr and move-only types, do not have copy constructors but do have move constructors. std::move() allows you to transfer ownership of such types.
Example:
cpp
複製程式碼
std::vector<int> source = {1, 2, 3, 4, 5};
std::vector<int> destination = std::move(source);  // Move source to destination

// After moving, source may be in a valid but unspecified state
// and should not be used without reinitialization.


Safety Considerations: After using std::move() on an object, the object itself may be in a "valid but unspecified" state, meaning its state is undefined but it is destructible and assignable. Always be cautious about accessing or using objects after they have been moved from.
