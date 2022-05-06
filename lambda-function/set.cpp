/** Как имплементировать лямбда функцию, не зная выводимого типа?
 * Как передать выводимый тип такой функции в другое место? **/

#include <iostream>
#include <vector>
#include <set>

int main() {
	std::vector<int> v = {3, 6, 5, 2, 8, 6, 9};

	auto f = [](int x, int y) {
		return std::abs(x - 5) < std::abs(y - 5);
	};
	
	std::set<int, decltype(f)> s(f);

	for (auto x : v) { s.insert(x);}
	for (auto x : s) { std::cout << x << ' '; }
}
