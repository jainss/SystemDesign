#include "MyHashMap.hpp"
#include <string>

int main () {
    MyHashMap<int, string> mymap(7);

    mymap.put(1, "hi");
    mymap.put(2, "my");
    mymap.put(3, "name");
    mymap.put(4, "is");
    mymap.put(5, "Shrayansh");
    mymap.put(6, "how");
    mymap.put(7, "are");
    mymap.put(8, "you");
    mymap.put(9, "friends");
    mymap.put(10, "?");

    cout << "Value for key 8: " << mymap.get(8) << endl;
    cout << "Value for key 10: " << mymap.get(10) << endl;

    return 0;
}