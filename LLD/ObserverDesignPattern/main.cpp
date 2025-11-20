#include "Observer/User.hpp"
#include "Observable/Product.hpp"


int main() {
    Product laptop("Gaming Laptop", 10);
    Product SmartPhone("Iphone15", 15);

    User user1("Alice", &laptop);
    User user2("Bob", &SmartPhone);
    User user3("John", &laptop);

    laptop.subscribeList(&user1);
    laptop.subscribeList(&user2);
    laptop.subscribeList(&user3);
    SmartPhone.subscribeList(&user2);
    SmartPhone.subscribeList(&user3);

    laptop.setStock(16);
    SmartPhone.setStock(2);
    SmartPhone.setStock(80);
    SmartPhone.notify();

    return 0;
}