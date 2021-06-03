#include <iostream>
#include <queue>

class MyClass
{
	public:

	int a, b;

	MyClass(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void print()
	{
		std::cout<<a<<","<<b<<std::endl;
	}
};

class MyComparisonClass
{
	public:

	int operator() (MyClass* object1, MyClass* object2) // Assume that object1 is above object2 in the heap. If you return 1, the objects are swapped
	{                                                   // In this case if obj1's sum is greater than obj2's sum we swap. The top of the heap has the lowest element
		return object1->a + object1->b > object2->a + object2->b;
	}
};

int main()
{
	std::priority_queue<int> maxHeap; // Multiply values by 1 for min heap
	maxHeap.push(1); // You have emplace as well just as you had it for vectors
	maxHeap.push(3);
	maxHeap.push(2);

	std::cout<<"Size of pq "<<maxHeap.size()<<std::endl;
	while(!maxHeap.empty())
	{
		std::cout<<maxHeap.top()<<" ";
		maxHeap.pop();
	}
	std::cout<<std::endl;



	std::priority_queue<MyClass*, std::vector<MyClass*>, MyComparisonClass> classHeap;
	classHeap.push(new MyClass(4,5));
	classHeap.push(new MyClass(2,3));
	classHeap.push(new MyClass(1,2));
	classHeap.push(new MyClass(3,4));

	std::cout<<"Size of pq "<<classHeap.size()<<std::endl;
	while(!classHeap.empty())
	{
		classHeap.top()->print();
		classHeap.pop();
	}



	return 0;
}