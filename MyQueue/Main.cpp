#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> Q;
	Q.Push(5);
	Q.Push(12);
	Q.Push(15);
	cout << Q.Front() << endl;
	Q.Pop();
	cout << Q.Front() << endl;
	Q.Pop();
	cout << Q.Front() << endl;
	Q.Pop();
	cout << Q.Front() << endl;
	system("pause");
	return 0;
}