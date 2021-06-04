#include <iostream>
#include <unordered_map>

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
	std::unordered_map<int, std::string> firstMap;
	firstMap.emplace(1, "First one"); // Prefer using emplace instead of insert as it constructs the pair for us
	firstMap.emplace(1, "Second one");
	firstMap[2] = "Two";
	firstMap[3] = "First three";
	firstMap[3] = "Second three";

	std::cout<<firstMap.size()<<std::endl;

	for(auto x: firstMap)
	{
		std::cout<<x.first<<","<<firstMap[x.first] /* Can also used x.second here */ <<" ";
	}
	std::cout<<std::endl;



	std::unordered_map<std::string, MyClass*> secondMap;
	secondMap.emplace("One", new MyClass(1,2));
	secondMap["Two"] = new MyClass(2,3);
	secondMap.emplace("Three", new MyClass(3,4));
	secondMap["Four"] = new MyClass(4,5);

	for(auto x: secondMap)
	{
		std::cout<<x.first<<",";
		x.second->print();
	}

	std::string key = "Two";
	if(secondMap.find(key) != secondMap.end())
	{
		std::cout<<"Pair with key "<<key<<" found\n";
	}
	else
	{
		std::cout<<"Pair with key "<<key<<" not found\n";
	}

	free(secondMap["Two"]);
	secondMap.erase("Two");
	free(secondMap["Four"]);
	secondMap.erase("Four");

	for(auto x: secondMap)
	{
		std::cout<<x.first<<",";
		x.second->print();
	}

	if(secondMap.find(key) != secondMap.end())
	{
		std::cout<<"Pair with key "<<key<<" found\n";
	}
	else
	{
		std::cout<<"Pair with key "<<key<<" not found\n";
	}



	return 0;
}