#include <iostream>
#include <vector>

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
	std::vector<int> numbers;

	numbers.push_back(1);

	int temp = 2;
	numbers.push_back(temp);
 
	int* ptr = (int*)  malloc(sizeof(int));
	*ptr = 3;
	numbers.push_back(*ptr);

	for(int i = 0; i < numbers.size(); i++)
	{
		std::cout<<numbers[i]<<" ";
	}
	std::cout<<std::endl;

	if(numbers.size() != 0)
	{
		numbers.pop_back(); // Never actually used this
	}

	for(int i = 0; i < numbers.size(); i++)
	{
		std::cout<<numbers[i]<<" ";
	}
	std::cout<<std::endl;



	std::vector<MyClass*> objects1;

	objects1.push_back(new MyClass(11, 12));

	MyClass* temp2 = (MyClass*) malloc(sizeof(MyClass));
	temp2 = new MyClass(13, 14);
	objects1.push_back(temp2);

	for(int i = 0; i< objects1.size(); i++)
	{
		objects1[i]->print();
	}



	std::vector<MyClass> objects2;
	objects2.emplace_back(21, 22);
	objects2.emplace_back(23, 24);

	for(int i = 0; i< objects2.size(); i++)
	{
		objects2[i].print();
	}



	return 0;
}
