#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void countUp()
{
	for(int i = 0; i <= 20; i++)
	{
		cout << "Thread 1 Count Up: " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void countDown()
{
	for(int i = 20; i >= 0; i--)
	{
		cout << "Thread 2 Count Down: " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
	cout << "Starting Thread 1..." << endl;
	thread thread1(countUp);
	thread1.join();
	cout << "\nStarting Thread 2..." << endl;
	thread thread2(countDown);
	thread2.join();
	cout << "\nProgram Complete." << endl;
	return 0;
}
