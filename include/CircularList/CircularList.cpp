// CircularList.cpp : Defines the entry point for the application.
//

#include "CircularList.h"

using namespace std;

int main()
{
	CircularList<int> testCircle;

	for (int i = 0; i < 10; i++)
		testCircle.push_front(i);

	cout << "Head is: " << testCircle.front() << endl;
	cout << "Tail is: " << testCircle.back() << endl;


}