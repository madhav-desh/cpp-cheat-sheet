#include <iostream>
#include <unordered_set>

class MyClass
{
	private:

	int a, b;

	public:

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
	std::unordered_set<int> intSet;
	intSet.insert(1); // There's emplace here as well similar to vectors
	intSet.insert(2);
	intSet.insert(3);

	std::cout<<intSet.size()<<std::endl;

	for(int x: intSet)
	{
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;

	int element = 2;
	if(intSet.find(element) != intSet.end())
	{
		std::cout<<"Element "<<element<<" found\n";
	}
	else
	{
		std::cout<<"Element "<<element<<" not found\n";
	}

	intSet.erase(2);

	for(int x: intSet)
	{
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;

	if(intSet.find(element) != intSet.end())
	{
		std::cout<<"Element "<<element<<" found\n";
	}
	else
	{
		std::cout<<"Element "<<element<<" not found\n";
	}

	// Probably wouldn't use sets for classes as the key would be the object itself. Probably just use maps instead



	return 0;
}