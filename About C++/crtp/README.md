# Curiously Recurring Template Pattern (CRTP)

## Overview
CRTP is a C++ idiom in which a class `Derived` inherits from a template class `Base`, using `Derived` itself as a template argument:

```cpp
template <typename T>
class Base { ... };

class Derived : public Base<Derived> { ... };

```

## Why use CRTP?

The primary goal of CRTP is **Static Polymorphism**. Unlike traditional inheritance which uses `virtual` functions and resolves calls at **runtime** via a vtable, CRTP resolves calls at **compile-time**.

### Key Benefits

* **Performance:** No vtable lookup overhead. Since the compiler knows the exact type at compile time, it can often inline the function calls.
* **Code Reuse:** You can implement common functionality in the `Base` class that depends on `Derived` specific logic (e.g., implementing an `increment()` method in Base that relies on a `getValue()` method in Derived).
* **Method Chaining:** CRTP is excellent for creating Fluent Interfaces where the base class methods need to return a reference to the specific derived type.

## How it Works

1. The `Base<Derived>` class provides a common interface.
2. Inside the base class, `this` is cast to `Derived*` using `static_cast`.
3. The compiler ensures that the `Derived` version of the method is called.
4. `Static Interface Enforcement`: We use `static_assert` (and C++20 `concepts`) to enforce the interface. Instead of a cryptic linker error or a runtime crash, the compiler tells you exactly what is missing during the build process.

## Limitations

* **No Heterogeneous Containers:** You cannot easily store `Dog` and `Cat` in a `std::vector<Animal*>` because `Animal<Dog>` and `Animal<Cat>` are technically two completely different, unrelated types.
* **Code Bloat:** Like all templates, excessive use can lead to larger binary sizes due to multiple instantiations.

# CRTP: Static Interface & Encapsulation

## The Concept
The **Curiously Recurring Template Pattern (CRTP)** is used here to create a **Static Interface**. Unlike `virtual` functions which rely on a runtime jump table (vtable), CRTP uses template instantiation to link calls at compile-time.

## Comparison: CRTP vs. Virtual Functions

| Feature | Virtual Functions | CRTP (Static) |
| :--- | :--- | :--- |
| **Dispatch** | Runtime (Indirect) | Compile-time (Direct) |
| **Inlining** | Rare | Common |
| **Binary Size** | Smaller (one class) | Larger (template bloat) |
| **Flexibility** | High (Heterogeneous lists) | Low (Static types only) |

## Why is CRTP faster?

- `Elimination of Indirection:` Virtual functions require a vtable lookup. The CPU has to find the object's vtable, find the function pointer, and then jump to that address. This can cause a "cache miss" if the vtable isn't in the CPU cache.

- `Inlining (The Real Speed Boost):` Because the compiler knows the exact function being called at compile-time, it can inline the code. This means it replaces the function call with the actual logic, eliminating the overhead of pushing/popping from the stack entirely.

- `Branch Prediction:` Modern CPUs are good at predicting branches, but "indirect jumps" (used by virtual functions) are harder for the CPU to predict than "direct jumps" (used by CRTP).
