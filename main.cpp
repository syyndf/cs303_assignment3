//Samuel Yohannes
//syyndf@umsystem.edu

#include <iostream>
#include <stack>
#include <cstring>
#include "Header.h"
#include "queue.h"
using namespace std;

int main() {

  //this is question 1
  cout<< "Question 1:" << endl;
  string infix;
  cout << "Enter infix expression : ";
  cin >> infix;
  if (isBalanced(infix)) {
    string postfix = infixToPostfix(infix);
    cout << "Expression has balanced parentheses." << endl;
    cout << "Postfix expression: " << postfix << endl;
  }
  else{
  cout << "Parentheses are not balanced, try again." << endl;
}
  //this is question 2
  cout << "Question 2:"<<endl;
  int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    int choice, item;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty?\n";
        cout << "5. Size\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to enqueue: ";
            cin >> item;
            q.enqueue(item);
            break;

        case 2:
            item = q.dequeue();
            if (item != -1) {
                cout << "Dequeued element: " << item << endl;
            }
            break;

        case 3:
            item = q.peek();
            if (item != -1) {
                cout << "Front element: " << item << endl;
            }
            break;

        case 4:
            if (q.isEmpty()) {
                cout << "Queue is empty\n";
            } else {
                cout << "Queue is not empty\n";
            }
            break;

        case 5:
            cout << "Queue size: " << q.size() << endl;
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
