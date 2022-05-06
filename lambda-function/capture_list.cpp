/**Примеры над capture list
 * mutable
 * как захватить по константной ссылке что-то тяжелое
 * захват ресурсов класса 
 * проблема смерти объекта раньше, чем сработает lambda
 * решение пробелемы выше**/

#include <iostream>
#include <vector>

void MutableExample() {
	int count = 0;

	auto f = [count](auto x, auto y) mutable {
		++count;
		std::cout << count << '\n';
		return x < y;
	};
	std::vector<int> v = {3, 6, 5, 2, 8, 6, 9};
	std::sort(v.begin(), v.end(), f);
	for (auto x : v) std::cout << x << ' ';

	std::cout << "\nmain_count: " << count ;
}

void ConstRefExample() {
	int foo = 5; // very weight variable
	auto f = [bar = std::cref(foo)](auto x, auto y) {
		// cref get const reference
		//...doing smth with bar
		return x < y;
	};
}

void ThisExample() {
	struct S {
		auto get_function() {
			auto f = [this](auto x) {
				// захват a был невозможен, тк это не локальная переменная
				return x + a;
			};
			return f;
		}
		int a = 0 ;
	};

	S var{5};
	/*
	auto f = var.get_function();
	std::cout << f(10); // 10 + 5 
	*/
	auto f = S{5}.get_function(); // f - от временного объекта класса
	std::cout << f(10); // объект класса умер, а функция вызывается - UB!
	/// РЕШЕНИЕ: ... auto f = [a = a](auto x) { ...
	///	ИЛИ: ... auto f = [*this](auto x) { ...
}

int main() {
	std::cout << "MutableExample\n";
	MutableExample();
	ConstRefExample();
	std::cout << "\nThisExample\n";
	ThisExample();
}	
