/*
*
* ProjectEuler.net
* Question 2: Even Fibonacci Numbers
* Sum up every even integer below 4 million of the fibonacci sequence.
* Implemneted in C++ using a class and stl stack.
* 20251025
* Joseph Frodella
*
*/

#include <stack>
#include <iostream>
using namespace std;

class fibonnaci  {

    int sum_;
    int a_;
    int b_;
    int target_;
    stack<int> fib_vals;

public:

    fibonnaci (int a = 1, int b = 2, int target = 4E6) : a_(a), b_(b), target_(target) {
        sum_ = 0;
        // Intizle stack with 0
        fib_vals.push(0);
        //cout << "Constructor called.\n";
    };

    const int getSum() { return sum_; }
    const int getTarget() { return target_; }
    const int geta() { return a_; }
    const int getb() { return b_; }
    const stack<int> get_stack() { return fib_vals; }

    stack<int> calculateFib();
    stack<int> isEvenFib();
    int calculateSum();
    void print();

    ~fibonnaci  () {
        //cout << "Destrcutor called. \n";
        while (!fib_vals.empty()) {
            fib_vals.pop();
        }
    }

};

// Calculate the fibonacci squence up to target_
stack<int> fibonnaci ::calculateFib()
{
    if ((a_ | b_ | target_) < 0) {
        // return error and empty stack if any input values less than 0;
        cout << "Must be non negative values.\n";
        return stack<int>();
    }

    int x = geta(), y = getb();
    // Push x and y onto stack
    fib_vals.push(x); fib_vals.push(y);
    int temp = 0;
    do {
        // calculate fibonnaci sequence 
        temp = y;
        // y = x + previous y
        y = (x + fib_vals.top());
        // Push y onto top of stack
        fib_vals.push(y);
        // x = y
        x = temp;
    } while (fib_vals.top() < getTarget()); 
    return fib_vals;
}
// Elimate odd numbers from stack
stack<int> fibonnaci ::isEvenFib() {

    // If stack is empty return empty stack.
    if (fib_vals.empty()) {
        return stack<int>();
    }

    stack<int> even;
    while (!fib_vals.empty()) {
        // If stack is odd pop value
        if ( (fib_vals.top() % 2) != 0) {
            fib_vals.pop();
        }
        else {
           // if stack is even val add to even stack.
           even.push(fib_vals.top());
           fib_vals.pop();
        }
    }

    // update fib_vals with even vals and return
    fib_vals = even;
    return fib_vals;
}
// Sum all even numbers in stack
int fibonnaci ::calculateSum() {
    // if nothing in stack return 0
    if (fib_vals.empty()) {
        return 0;
    }

    // while stack is not empty sum up the vals of stack
    while (!fib_vals.empty()) {
        // add top of stack value to sum
        sum_ += fib_vals.top();
        // get next stack value.
        fib_vals.pop();
    }
    
}
// Print out stack
void fibonnaci ::print() {
    stack<int> temp;
    temp = get_stack();
    cout << "\n";
    while (!temp.empty()) {
        cout << temp.top() << ", ";
        temp.pop();
    }
    cout << "\n";
}

int main(){

    int a, b, target;
    cout << "Enter first Fibonacci number (default 1): ";
    cin >> a;
    cout << "Enter second Fibonacci number (default 2): ";
    cin >> b;
    cout << "Enter target limit (default 4E6): ";
    cin >> target;

    // Call constructor instialize with 1, 2
    fibonnaci  obj(a, b, target);

    // call method to calculate fibonnaci sequence
    obj.calculateFib(); 
    // print out sequence
    cout << "The fib sequence from " << obj.geta() << " to "
        << obj.getTarget() << "is: ";
    obj.print();

    // Call method to get even values
    obj.isEvenFib();
    cout << "Only even fib numbers:";
    obj.print();

    // call method to sum even values
    obj.calculateSum();
    cout << "The sum of fib sequence from " << obj.geta() 
        << " less than " << obj.getTarget() 
        << " is: " << obj.getSum() << "\n";

    return 0;
}
