/**Функция sort() третьим аргументом принимает компаратор.
 * Его можно задать как структуру с операторов сравнения - это долго и неудобно
 * можно записать короткую lambda функцию, прямо внутри третьего аргумента **/
#include <iostream>
#include <vector>
#include <algorithm>

struct Compare{
	bool operator() (int x, int y) const {
		return x > y;
	}
};

int main() {
	//comparator
	std::vector<int> v1 = {3, 4, 5, 6, 1};
	std::sort(v1.begin(), v1.end(), Compare());
	for (auto x : v1) std::cout << x;
  	//lambdas 
	std::vector<int> v2 = {3, 4, 5, 6, 1};
	std::sort(v2.begin(), v2.end(),
			[](int x, int y) {
			return x > y;
			});
	for (auto x : v2) std::cout << x;
}
