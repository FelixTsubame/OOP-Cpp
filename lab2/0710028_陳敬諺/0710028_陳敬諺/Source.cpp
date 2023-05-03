#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class my_class {
	public:
		int x, y;
			
			int gcd(int x, int y) {
				this->x = x;
				this->y = y;
				if (x%y == 0)
					return y;
				else
				{
					return gcd(y, x%y);
				}
			}
			int lcm(int x, int y) {
				this->x = x;
				this->y = y;
				return x * y / gcd(x, y);
			}

			string getGcdLcm() {
				this->x = x;
				this->y = y;
				string str;
				str = "GCD:" + to_string(gcd(x, y)) + " LCM:" + to_string(lcm(x, y)) + "\n";
				return str;
			}
		
};

int main() {
	ifstream input;
	input.open("input.txt");
	ofstream output; 
	output.open("output.txt");
	int n,x,y;
	
	input >> n;
	while (n--) {
		input >> x >> y;
		my_class num(x, y);
		output << num.getGcdLcm(x,y);
	}
	input.close();
	output.close();

	return 0;
}