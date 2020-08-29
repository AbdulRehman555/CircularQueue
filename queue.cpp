#include<iostream>
using namespace std;
#define SIZE 10
class CQueue {
	int arr[SIZE];
	int front;
	int rear;
public:
	CQueue();
	void enqueue(int);
	int dequeue();
};
CQueue::CQueue() {
	for (int i = 0; i < SIZE; i++)
		arr[i] = 0;
	front = rear = -1;
}
void CQueue::enqueue(int value) {
	
	if ((rear == SIZE-1 && front == 0) || (front == rear + 1)) {
		cout << "Overflow\n";
	}
	else {
		if (front == -1 && rear == -1) {
			front = rear=0;
			arr[rear] = value;
		}
		else {
			if ((rear == SIZE - 1) && (front > 0)) 
				rear = -1;
			arr[++rear] = value;
		}
	}
}
int CQueue::dequeue() {
	if (front == -1) {
		cout << "Underflow\n";
		return -999;
	}
	
	int item = arr[front];
	if (front == rear) {
		front = rear = -1;
		return item;
	}
	if (front == SIZE-1) {
			front = 0;
			return item;
	}
		
	front++;
	return item;
}
int main() {
	CQueue CQ;
	CQ.enqueue(1);
	CQ.enqueue(2);
	CQ.enqueue(3);
	CQ.enqueue(4);
	CQ.enqueue(89);
	cout << CQ.dequeue() << endl;
	cout << CQ.dequeue() << endl;
	cout << CQ.dequeue() << endl;

	CQ.enqueue(5);
	CQ.enqueue(6);
	CQ.enqueue(7);

	cout << CQ.dequeue() << endl;
	cout << CQ.dequeue() << endl;
	cout << CQ.dequeue() << endl;
	cout << CQ.dequeue() << endl;
	cout << CQ.dequeue() << endl;
	system("pause");
	return 0;
}