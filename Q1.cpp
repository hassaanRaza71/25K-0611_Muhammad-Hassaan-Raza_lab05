#include <iostream>
#include <string>
using namespace std;

class Restraunt;   
class Order;       

class Customer {
public:
    string name;

    void place_order(Restraunt* r, string food);
};

class Restraunt {
public:
    string name;

    void take_order(Order* o) {
        cout << "Order received by " << name << endl;
    }
};

class Order {
public:
    static int current_id;
    int id;
    string fooditem;
    Customer* customer;
    Restraunt* restraunt;

    Order(string food_item, Customer* C, Restraunt* R) {
        id = ++current_id;
        fooditem = food_item;
        customer = C;
        restraunt = R;
    }

    void show() {
        cout << "Order ID: " << id << endl;
        cout << "Customer: " << customer->name << endl;
        cout << "Food: " << fooditem << endl;
        cout << "Restaurant: " << restraunt->name << endl;
    }
};

int Order::current_id = 0;


void Customer::place_order(Restraunt* r, string food) {
    Order* o = new Order(food, this, r);
    r->take_order(o);
    o->show();
}

int main() {
    Customer C = {"Hassaan"};
    Restraunt R = {"BBQ Tonight"};

    C.place_order(&R, "Biryani");
    Customer C2 = {"Ahmed"};
    Restraunt R2 = {"BBQ Tonight"};

    C2.place_order(&R, "Biryani");

    return 0;

}