#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct word {
	word *ptr;
	string w;
};
word *dictionary[26];

void insert_inorder(string element) {
	int dict_index;
	word *cur;
	if (element[0] >= 'a'&& element[0] <= 'z')
		dict_index = element[0] - 'a';
	else
		dict_index = element[0] - 'A';
	if (dictionary[dict_index] == NULL)
	{
		dictionary[dict_index] = new word;
		dictionary[dict_index]->w = element;
		dictionary[dict_index]->ptr = NULL;
	}
	else
	{
		cur = dictionary[dict_index];
		while (true)
		{
			if (dictionary[dict_index]->w > element)
			{
				string temp;
				temp = cur->w;
				cur = new word;
				cur->w = element;
				cur->ptr = dictionary[dict_index];
				dictionary[dict_index] = cur;
				break;
			}
			word* temp;
			temp = cur->ptr;
			if (temp!=NULL && temp->w > element)
			{
				cur->ptr = new word;
				cur = cur->ptr;
				cur->w = element;
				cur->ptr = temp;
				break;
			}
			
			if (cur->ptr == NULL)
			{
				cur->ptr = new word;
				cur = cur->ptr;
				cur->w = element;
				cur->ptr = NULL;
				break;
			}
			cur = cur->ptr;
		}
		
		/*cout << cur->w << "\n";
		cout << cur << "\n";
		if (dictionary[dict_index] == NULL)
			cout << "NO\n";
		cout << dictionary[dict_index]->w << "\n";*/
	}
}

void print_dict() {
	word *cur;
	for (int i = 0; i < 26; i++) { // loop from A-Z 
		string le;
		le = 'a' + i;
		if (dictionary[i] == NULL)
			continue;
		cout << "Dict: " << le << "\n";
		cur = dictionary[i];
		while (true)
		{
			if (cur == NULL)
				break;
			cout << cur->w << "\n";
			cur = cur->ptr;
		}
		cout << "\n";
	}
}

int main() {
	// For Debugging, you cannot use this to demo.
	vector<string> list/*{"yell","yank"}*/;
	
	// Read file to get words
	fstream input;
	input.open("input_sample.txt");
	string s;
	do {
		input >> s;
		list.push_back(s);
	} while (!input.eof());
	// initialize dictionary pointer
	for (int i = 0; i < 26; i++) { 
		dictionary[i] = NULL;
	}

	for (int i = 0; i < list.size(); i++) {
		insert_inorder(list[i]);
	}

	print_dict();
	//cout << dictionary['r' - 'a']->w << "\n";
	char a;
	cout << "end" << endl;
	cin >> a; // used as system pause
}