#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;


/*
populate vector with n integers
*/
void populateVector(vector<int> &intVec, unsigned int n);

/*
Populate vector with n elements

Return time taken to display a vector of n elements
WITH checks for out of bound memory reference
If an out of bound memory reference occurs,
it return -1
*/
double displayWithChecking(unsigned int n);

/*
Populate vector with n elements

return time taken to display a vector of n elements
WITH OUT checks for out of bound memory reference
*/
double display(unsigned int n);

void main()
{
	/*
	Store # of elements for each vector that is tested
	*/
	vector<unsigned int> *totalElements = new vector<unsigned int>;

	/*
	Store the time taken (in seconds) to output all elements
	for each vector that is tested WITH runtime sematic error checking
	*/
	vector<double> *checkedDurations = new vector<double>;

	/*
	Store the time taken (in seconds) to output all elements
	for each vector that is tested WITH OUT runtime sematic error checking
	*/
	vector<double> *durations = new vector<double>;

	/*
	Test with datasets of different sizes
	*/
	for (unsigned int i = 5000; i <= 3125000; i *= 5)
	{
		totalElements->push_back(i);

		checkedDurations->push_back(displayWithChecking(i));

		durations->push_back(display(i));
	}


	/*
	Display results
	*/
	cout << setw(2) << "# of elements" << setw(20 - 2) << "With Checking" << setw(20) << "Without Checking" << endl;

	for (unsigned int i = 0; i < totalElements->size(); i++)
	{
		cout << setw(2) << totalElements->at(i) << setw(20) << checkedDurations->at(i) << setw(20) << durations->at(i) << endl;
	}

	//garbage collection
	delete totalElements;
	delete checkedDurations;
	delete durations;

	system("PAUSE");
}



double displayWithChecking(unsigned int n)
{
	vector<int> intVec;

	populateVector(intVec, n);

	clock_t start;

	start = clock();

	//Display vector WITH checking for out of bound memory reference
	for (unsigned int i = 0; i < intVec.size(); i++)
	{
		if (i >= 0 && i < intVec.size())
		{
			cout << intVec[i] << endl;
		}
		else
		{
			return -1;
		}
	}

	return (clock() - start) / (double)CLOCKS_PER_SEC;
}


double display(unsigned int n)
{
	vector<int> intVec;

	populateVector(intVec, n);

	clock_t start;

	start = clock();

	//Display vector WITH OUT checking for out of bound memory reference
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