/*
 * Course: COEN 2220 - Programming 2
 * Name: [Sebastian Ortiz]
 * Lab: Lab 10 - Stacks & Queues
 * Description: Practice - a dynamic queue of tutoring requests
 * Due date: [10/23/2026]
 */

#include <iostream>
#include <string>
using namespace std;

class TutoringQueue
{
private:
    struct Node
    {
        string studentId; // Store one student waiting for tutoring.
        Node *next;       // Point to the student immediately behind this one.
    };

    Node *front; // Point to the student who must be served next.
    Node *rear;  // Point to the student most recently added.

public:
    TutoringQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~TutoringQueue()
    {
        while (front != nullptr)
        {
            Node *nodeToDelete = front;
            front = front->next; // Advance before releasing the current node.
            delete nodeToDelete;
        }

        rear = nullptr;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    // ===== Resolve these TODOs now (Part E) =====

    // TODO (Part E): Write enqueue to add newStudentId at rear.
    void enqueue(const string &newStudentId)
    {
        Node *newNode = new Node{newStudentId, nullptr};
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // TODO (Part E): Write dequeue. It returns bool and uses string& dummyID.
    bool dequeue(string &dummyID)
    {
        if (isEmpty())
        {
            return false;
        }

        Node *nodeToDelete = front;
        dummyID = nodeToDelete->studentId;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete nodeToDelete;
        return true;
    }
};

int main()
{
    cout << boolalpha;

    // TODO (Part E): Create a TutoringQueue object.
    TutoringQueue queue;
    // TODO (Part E): Add TU-301, TU-318, and TU-327 in that arrival order.
    queue.enqueue("TU-301");
    queue.enqueue("TU-318");
    queue.enqueue("TU-327");
    // TODO (Part E): Dequeue and print the first two served student IDs.
    string dummyID;
    if (queue.dequeue(dummyID))
    {
        cout << "Served student ID: " << dummyID << endl;
    }
    if (queue.dequeue(dummyID))
    {
        cout << "Served student ID: " << dummyID << endl;
    }
    // TODO (Part E): Dequeue the last student, then print whether the queue is empty.
    if (queue.dequeue(dummyID))
    {
        cout << "Served student ID: " << dummyID << endl;
    }
    cout << "Is queue empty? " << queue.isEmpty() << endl;
    // TODO (Part E): Add TU-340 after the queue becomes empty, dequeue it, and print its ID.
    queue.enqueue("TU-340");
    if (queue.dequeue(dummyID))
    {
        cout << "Served student ID after empty queue: " << dummyID << endl;
    }

    return 0;
}

/*
 * Analysis Answers
 *
 * E1 — First arrival
 * Why must the first call to enqueue assign newNode to both front and rear?
 * Answer: The fist call must assing a newNode to both front and rear because when the queue is empty, both should point to the same node(nullptr), the only node in the queue. 
 * This ensures that the queue maintains its structure and allows for enqueue and dequeue to properly work.
 *
 * E2 — Last departure
 * After dequeue removes the only remaining node, what must happen to rear and why?
 * Answer: After dequeue removes the only remaining node, rear must be set to nullptr. 
 * This is done when the queue becomes empty, both front and rear should point to nullptr because there are no nodes in the queue.
 *
 * E3 — FIFO evidence
 * List the expected service order for TU-301, TU-318, and TU-327. Explain why this
 * differs from the return order of the function-call stack in Part D.
 * Answer: The expected service order for TU-301, TU-318, and TU-327 is:
    1. TU-301
    2. TU-318
    3. TU-327
   This is different to the example in part D because while the stack is a LIFO structure, the queue is a FIFO structure.
   FIFO is defined as fist in first out, meaning the first item to be removed is the first item that was added.
 *
 */