#include <iostream>
#include <vector>
#include <chrono>

// --- Dynamic Polymorphism ---
struct BaseVirtual {
    virtual void tick() = 0;
    virtual ~BaseVirtual() = default;
};

struct DerivedVirtual : public BaseVirtual {
    void tick() override { /* very simple work */ }
};

// --- Static Polymorphism (CRTP) ---
template <typename T>
struct BaseCRTP {
    void tick() { static_cast<T*>(this)->impl(); }
};

struct DerivedCRTP : public BaseCRTP<DerivedCRTP> {
    void impl() { /* very simple work */ }
};

int main() {
    const int iterations = 100'000'000;

    // Measure Virtual
    DerivedVirtual v_obj;
    BaseVirtual* v_ptr = &v_obj;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations; ++i) {
        v_ptr->tick();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> v_dist = end - start;

    // Measure CRTP
    DerivedCRTP c_obj;
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i=0; i < iterations; ++i) {
        c_obj.tick();
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> c_dist = end2 - start2;

    std::cout << "Virtual: " << v_dist.count() << "s\n";
    std::cout << "CRTP:    " << c_dist.count() << "s\n";
    std::cout << "CRTP is " << v_dist.count() / c_dist.count() << "x faster\n";

    return 0;
}