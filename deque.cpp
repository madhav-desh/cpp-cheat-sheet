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

int main()
{
	std::deque<int> dq;
	dq.push_front(2); // You have emplace_front and emplace_back (similar to vectors)
	dq.push_back(3);
	dq.push_front(1);
	dq.push_back(4);

	for(int i = 0; i < dq.size(); i++)
	{
		std::cout<<dq[i]<<" ";
	}
	std::cout<<std::endl;

	std::cout<<dq.front()<<std::endl;
	dq.pop_front();

	std::cout<<dq.back()<<std::endl;
	dq.pop_back();

	for(int i = 0; i < dq.size(); i++)
	{
		std::cout<<dq[i]<<" ";
	}
	std::cout<<std::endl;



	std::deque<MyClass*> classDq;
	classDq.push_front(new MyClass(2,3));
	classDq.push_back(new MyClass(3,4));
	classDq.push_front(new MyClass(1,2));
	classDq.push_back(new MyClass(4,5));

	for(int i = 0; i < classDq.size(); i++)
	{
		classDq[i]->print();
	}

	classDq.front()->print();
	classDq.pop_front();

	classDq.back()->print();
	classDq.pop_back();

	for(int i = 0; i < classDq.size(); i++)
	{
		classDq[i]->print();
	}



	return 0;
}