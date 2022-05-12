# STL


STRUCTURE C++|STRUCTURE|indexing|push_back|push_front|find|insert *iterator*| erase *iterator* | iterator category 
-----------| ------ | ----- | ---- | ---- | ---- | ---- | ---- | ----
**vector** | dynamic array | <span style = "color:green">O(1) |<span style="color:orange"> O(1) amort|- |<span style = "color:red"> O(n) | <span style = "color:red">O (n) | <span style = "color:red">O(n)| contiguous
**deque**  | bidir array   | <span style = "color:green">O(1) |<span style="color:orange"> O(1) amort| <span style="color:orange"> O(1) amort | <span style = "color:red">O(n) |<span style = "color:red"> O(n)|<span style = "color:red"> O(n)|random_access
**list/forward_list**| list | - |<span style="color:green"> O(1)|<span style="color:green">O(1)| <span style = "color:red">O(n)|<span style="color:green">O(1)|<span style="color:green">O(1)|bidirectional/forward
**set/map**| red-black trees|<span style="color:blue">O(log n)|-|-|<span style="color:blue">O(log n)|<span style="color:blue">O(log n)|<span style="color:blue">O(log n)| bidirectional
**unordered map/set**| hash-table|<span style="color:orange">O(1) expected| -|-|<span style="color:orange">O(1) expected|<span style="color:orange">O(1) expected|<span style="color:orange"> O(1) expected| forward

[UNORDERED MAP](./unordered_map)
