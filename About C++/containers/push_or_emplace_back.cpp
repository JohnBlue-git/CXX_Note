#include <iostream>
#include <vector>
using namespace std;

// Class
class GFG {
public:
	float x, y;
  // Parametric Constructor
	GFG(float x, float y)
	  : x(x), y(y)
    { cout << "Constructed" << endl; }
	// Copy Constructor
	GFG(const GFG& GFG)
		: x(GFG.x), y(GFG.y)
    { cout << "Copied" << endl; }
	// Move Constructor
	// (better to do this, becasue compiler will use move instead of copy as possible)
	GFG(const GFG&& GFG)
		: x(std::move(GFG.x)), y(std::move(GFG.y))
    { cout << "Moved" << endl; }
};

int main()
{
  vector<GFG> vertices;

  // if want to pre-allocate some space
  // , which could reduce the cost of resizing vector @@
  // because every time the size become bigger, a new vector will be created 
  vertices.reserve(4);
  // Note:
  // reserve() is used instead of using “vector<GFG> vertices(2)”
  // , as the below syntax sometimes doesn’t work 
  // because there is no default constructor defined in the class.

  // Everytime push_back a value to a vector
  // , cpp will create a new object > copy > move
  cout << "\n push_back" << endl;
  vertices.push_back(GFG(1, 2));
  vertices.push_back(GFG(1, 2));
  // output:
  //  push_back
  // Constructed
  // Moved
  // Constructed
  // Moved

  cout << "\n emplace_back" << endl;
  vertices.emplace_back(1, 2);
  vertices.emplace_back(1, 2);
  // output:
  // emplace_back
  // Constructed
  // Constructed

  // However !!! emplace_back() could have problems
  // 我们日常写代码，除了执行率之外，还要考虑可读性，理解成本等，虽然emplace_back 效率高些，但是它也是有缺点的，比如：
  vector< vector > vec1, vec2;
  // vec1.push_back(1000000);
  // vec2.emplace_back(1000000);
  // 第一行程序代码很好理解，往 容器vec1尾部加入 1000000 個，分配差不多近 4M 的内存空间，在编译的时候就会报错，能更早的发现问题。
  // 第二行程序代码那么它就构造了一个包含 1000000 个元素的容器，編譯時不會爆錯，所以會在runtime crash掉
  
	return 0;
}
