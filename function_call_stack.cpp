/*
 * Course: COEN 2220 - Programming 2
 * Name: [Sebastian Ortiz]
 * Lab: Lab 10 - Stacks & Queues
 * Description: Practice - a dynamic stack of active function calls
 * Due date: [10/23/2026]
 */

#include <iostream>
#include <string>
using namespace std;

class FunctionCallStack
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Define Node with string functionName and Node *next.
    struct Node
    {
        string functionName;
        Node *next;
    };
    // TODO (Part C): Declare Node *top for the node that must leave next.
    Node *top;

public:
    // TODO (Part C): Write a constructor that creates an empty stack.
    FunctionCallStack()
    {
        top=nullptr;
    }
    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write isEmpty as a const member function.
    bool isEmpty() const
    {
        return top==nullptr;
    }
    // TODO (Part D): Write push to add a function name at top.
    void push(const string& functionName)
    {
        Node *newNode = new Node;
        newNode->functionName = functionName;
        newNode->next = top;
        top = newNode;
    }
    // TODO (Part D): Write pop. It returns bool and uses string& removedFunctionName.
    bool pop(string& removedFunctionName)
    {
        if (isEmpty())
        {
            return false;
        }
        Node *nodeToDelete = top;
        removedFunctionName = top->functionName;
        top = top->next;
        delete nodeToDelete;
        return true;
    }
    // TODO (Part D): Write peek. It returns bool and uses string& topFunctionName.
    bool peek(string& topFunctionName) const
    {
        if (isEmpty())
        {
            return false;
        }
        topFunctionName = top->functionName;
        return true;
    }
    // TODO (Part D): Write a destructor that releases every dynamic node.
    ~FunctionCallStack()
    {
        while (!isEmpty())
        {
            string dummy;
            pop(dummy);
        }
    }
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Create a FunctionCallStack object.
    FunctionCallStack stack;
    // TODO (Part D): Push main, loadSchedule, and formatSchedule in that order.
    stack.push("main");
    stack.push("loadSchedule");
    stack.push("formatSchedule");
    // TODO (Part D): Use peek and pop to demonstrate LIFO with descriptive output.
   string topFunctionName;
    if (stack.peek(topFunctionName))
    {
        cout << "Top function: " << topFunctionName << endl;
    }       
    if (stack.pop(topFunctionName))
    {
        cout << "Popped function: " << topFunctionName << endl;
    }
    

    // TODO (Part D): Pop remaining calls, then demonstrate an unsuccessful pop on an empty stack.
    while (stack.pop(topFunctionName))
    {
        cout << "Popped function: " << topFunctionName << endl;
    }
   stack.pop(topFunctionName) ? cout << "Popped function: " << topFunctionName << endl : cout << "Stack is empty, cannot pop." << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * D1 — Adding formatSchedule
 * When push("formatSchedule") executes, what must newNode->next receive before top
 * changes? Explain why reversing those two assignments would lose the previous top.
 * Answer: When push("formatSchedule") executes, newNode->next must receive the current value of top before top changes. 
 * This is because newNode->next needs to point to the previous top node in order to maintain the linked list structure of the stack.
 * If we reversed those two assignments and changed top first, we would lose the reference to the previous top node, breaking the link and losing the rest of the stack.
 *
 * D2 — Returning from a function
 * After main, loadSchedule, and formatSchedule are pushed in that order, list the
 * order in which three successful pop calls must return their names. Explain LIFO.
 * Answer: The order in which the three successful pop calls must return their names is:
    1. formatSchedule       
    2. loadSchedule
    3. main
    Lifo is defined as last in first out, meaning the first item to be removed is the last item that was added.
    You can think of it like a stack of panckaes. When you stack them, the last pancake you put on the stack is the first on you eat.
 *
 * D3 — Destructor order
 * Why must the destructor save a next-node address before deleting the current node?
 * Answer: The destructor must save the next-node address before deleting the current node because once the current node is deleted, its memory is deallocated and accessing its next pointer would lead to undefined behavior.
 * This behavior is called a dangling pointer, which can cause crashes or unpredictable output in the program.
 * 
 */