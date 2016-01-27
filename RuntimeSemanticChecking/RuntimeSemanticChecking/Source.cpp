#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <iomanip>
//#define NDEBUG
//#include <assert.h>
#include <stdexcept>
using namespace std;


/*
vector populated with n integers
*/
void populateVector(vector<int> &intVec, unsigned int n);

/*
return time taken to display a vector of n elements
WITH assertion that checks for out of bound memory reference
*/
double displayWithException(unsigned int n);

/*
return time taken to display a vector of n elements
WITH OUT assertion that checks for out of bound memory reference
*/
double display(unsigned int n);

void main()
{
	vector<unsigned int> *totalElements = new vector<unsigned int>;
	vector<double> *exceptionDurations = new vector<double>;
	vector<double> *durations = new vector<double>;




	for (unsigned int i = 1000; i <= 625000; i *= 5)
	{
		totalElements->push_back(i);

		exceptionDurations->push_back(displayWithException(i));

		durations->push_back(display(i));



	}

	cout << setw(2) << "# of elements" << setw(20 - 2) << "With Exceptions" << setw(20) << "Without Exceptions" << endl;

	for (unsigned int i = 0; i < totalElements->size(); i++)
	{
		cout << setw(2) << totalElements->at(i) << setw(20) << exceptionDurations->at(i) << setw(20) << durations->at(i) << endl;



	}

	//garbage collection
	delete totalElements;
	delete exceptionDurations;
	delete durations;

	//interesting way of displaying the contents of a vector
	//copy(assertDurations->begin(), assertDurations->end(), ostream_iterator<double>(cout, " "));




	system("PAUSE");
}



double displayWithException(unsigned int n)
{
	vector<int> intVec;

	populateVector(intVec, n);

	clock_t start;

	start = clock();

	//Display Vector with exception checking for out of bound memory reference
	for (unsigned int i = 0; i <= intVec.size(); i++)
	{
		//assert(i >= 0 && i < intVec.size());
		if (i >= 0 && i < intVec.size())
		{
			cout << intVec[i] << endl;
		}
		else
		{
			return -1;
		}

		/*
		try {
		cout << intVec[i] << endl;
		}
		catch (const out_of_range& oor) {
		cerr << "Out of Range error: " << oor.what() << '\n';
		}
		*/
	}

	return (clock() - start) / (double)CLOCKS_PER_SEC;
}

double display(unsigned int n)
{
	vector<int> intVec;

	populateVector(intVec, n);

	clock_t start;

	start = clock();

	//Display Vector with assertion checking for out of bound memory reference
	for (unsigned int i = 0; i < intVec.size(); i++)
	{
		cout << intVec[i] << endl;
	}

	return (clock() - start) / (double)CLOCKS_PER_SEC;
}

void populateVector(vector<int> &intVec, unsigned int n)
{
	// Populate vector
	for (unsigned int i = 0; i < n; i++)
	{
		intVec.push_back(i);
	}
}