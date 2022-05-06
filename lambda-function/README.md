# Lambda functions(c++11)
## syntax
- lambda сделаны хорошо
```C++
[/*capture*/]</*optional template params*/> (/*params*/) /*specifiers*/ {
  /*body*/
};
```
## capture list
- main не является внешней областью видимости lambda. Можно считать, что лямбда - это operator()()
- внешние элементы можно захватывать, причем, разными путями
- захваченные элементы можно инициализировать произвольными выражениями
	- инициализация по ссылке вводит в зависимость от времени жизни элемента
- ресурсы класса можно захватывать через захват `this` (`*this` по значению)
```c++
int foo = 0;
std::vector<int> bar;
[&foo]() {} // By reference 
[foo]() {} // By value
[bar = std::move(bar)]() {} // Declare **new** bar copy to bar
[&]() {}  // Capture everything by reference (discouraged)
[=]() {}  // Capture everything by value (you must know what you do)
[&, foo] {} // foo by value, other by reference
```
- переменные, захваченные по значению - `const` 
- **спецификатор** `mutable` изменяет это
## implementation
- по умолчанию, компилятор автоматически выводит возвращаемый тип(см *set.cpp*)
- возвращаемый тип можно указать явно с помощью `->` в спецификаторах
- тип параметров может быть `auto`, тогда компилятор создает шаблонный оператор вызова функции
```c++
auto auto_lambda = [](const auto& x, ... ){}; // Обобщенное лямбда-выражение

auto l = [bar = std::move(bar)]<typename T>(const T& x) {};

auto f = []( )->T {};
```
## lambdas as objects
[insights](https://cppinsights.io)



