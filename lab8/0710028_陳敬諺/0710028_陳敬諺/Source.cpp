#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void Heapify(vector<int> &arr, int i,int hs) {
	int le = 2 * i;
	int	ri = 2 * i + 1;
	int smallest;
	if (le <= hs && arr[le] < arr[i])
		smallest = le;
	else 
		smallest = i;
	if (ri <= hs && arr[ri] < arr[smallest])
		smallest = ri;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		Heapify(arr, smallest , hs);
	}
	//cout << "yes\n"; 
}

void BuildHeap(vector<int> &arr) {
	int hs = arr.size();
	for (int i = hs / 2; i >= 1; i--)
		Heapify(arr, i, hs - 1);
}

void Heapsort(vector<int> &A) {
	A.insert(A.begin(), 0);
	BuildHeap(A);
	int hs = A.size() - 1;
	for (int i = A.size()-1; i >= 2; i--) {
		swap(A[1], A[i]);
		hs--;
		Heapify(A, 1, hs);
	}
	A.erase(A.begin());
}

int main() {
	fstream input;
	input.open("lab8_input.txt");
	vector<int> num;
	int c,len;
	if (!input)
		cout << "?????\n";
	else
	{
		input >> len;
		while (input >> c && !input.eof())
		{
			num.push_back(c);
		}
		Heapsort(num);
		for (int i = 0; i < num.size(); i++)
			cout << num[i] << " ";
		cout << "\n";
	}
	system("pause");
	return 0;
}