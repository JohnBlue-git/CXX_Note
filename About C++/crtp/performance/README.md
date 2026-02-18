## Performance: CRTP vs Virtual

### Why CRTP Wins
1. **No VTable:** Avoids the pointer indirection and potential cache misses of the Virtual Method Table.
2. **Inlining:** Enables the compiler to copy-paste the function body into the call site.
3. **Optimizations:** Allows for constant folding and loop unrolling across the interface boundary.

### How to Measure It: The "Easy" Way
The best way to measure micro-benchmarks in C++ is using Google Benchmark or a simple high-resolution timer.

The Experiment:
We will create a large array of objects and call a small method millions of times.

Warning: To get an accurate measurement, you must use compiler optimization (-O3). Without optimization, the compiler won't inline the CRTP code, and both will feel similarly slow.

```bash
g++ -std=c++20 -O3 benchmark.cpp -o benchmark
./bench
```

### Measurement Results
In synthetic benchmarks involving 100M iterations of simple method calls:
* **Virtual Functions:** ~0.15s - 0.30s
* **CRTP:** < 0.01s (Often optimized to near-zero)

```bash
.../CXX_Note/About C++/crtp/performance (main) $ ./compare 
Virtual: 9e-08s
CRTP:    3e-08s
CRTP is 3x faster
```

### Limitations

I also have compile without optmization, and the result was bad:
```bash
Virtual: 0.197256s
CRTP:    0.281535s
CRTP is 0.700646x faster
```
