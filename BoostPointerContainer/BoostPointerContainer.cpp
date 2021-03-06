#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>
#include <set>
#include <array>
#include <algorithm>
#include <functional>
#include <memory>
#include <iostream>

int main()
{
	boost::ptr_vector<int> v;
	v.push_back(new int{ 1 });
	v.push_back(new int{ 2 });
	v.push_back(new int{ 3 });

	std::cout << v.back() << std::endl;

	boost::ptr_set<int> s;
	s.insert(new int{ 4 });
	s.insert(new int{ 12 });
	std::cout << *s.begin() << std::endl;

	std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> v1;
	v1.insert(std::unique_ptr<int>(new int{ 4 }));
	v1.insert(std::unique_ptr<int>(new int{ 12 }));
	std::cout << **v1.begin() << std::endl;

	boost::ptr_vector<int> vec;
	std::array<int, 3> arr{ {0, 1, 2} };
	std::copy(arr.begin(), arr.end(), boost::ptr_container::ptr_back_inserter(vec));
	std::cout << vec.size() << std::endl;

	std::cin.get();
}

