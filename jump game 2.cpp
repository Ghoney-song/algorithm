#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int curStep = 0, i = 0, n = nums.size(), level = 0;

		while (curStep < n - 1) {
			level++;
			int preStep = curStep;
			for (; i <= preStep; ++i) {
				curStep = max(curStep, i + nums[i]);
			}
		}

		return level;
	}
};

void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().jump(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}