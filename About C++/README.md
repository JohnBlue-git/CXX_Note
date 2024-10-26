# Modern Cpp 在追求什麼?

When you come to the Modern CPP, CPP is more than just an object-oriented C. It also pursues Type-SAFE, MetapRographing and Static/Compile Time Error. It also contains the characteristics of functions. It's completely different.

If I want to tell me the most important thing I think Modern C ++ comes out, I will choose RAII and MOVE. Before Modern C ++, you will find a lot of new/delete and replication in CODE, which means that we often need to manually ensure our resources. The life cycle, and RAII and MOVE helped us do this, and did well, but the core concept of C ++ also changed.

There are many examples in modern C ++, and then among many changes, I think this is the most important change, and most of the other changes are actually grammar sugar, but SPEC will define this grammar sugar similar to "semantic" definitions. , Or to say that certain conditions are like a new concept that defines new concepts and continues to stack new concepts in this concept, but essentially the whole of grammar sugar, so it is a very important factor in C ++.

# C++ standard

## C++ 11
RAII \
std::move \
smart pointer \
...\

## C++ 14
std::make_unique<T> \
Lambda capture initializers: [capture_var = expression](parameters) { /* body */ } \
... \

## C++ 17
std::optional \
...\


