#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	set<vector<int>> set_res;

	vector<vector<int>> threeSum(vector<int>& nums) {
		res.clear();
		if (nums.size() < 3) return res;
		set_res.clear();
		vector<int> vec;

		sort(nums.begin(), nums.end());

		vector<int> arr = nums;
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		if (arr.size() == 1)
		{
			if (arr[0] == 0)
			{
				res.push_back(vector<int>({ 0,0,0 }));
				return res;
			}
			else
				return res;
		}

		for (int i = 0; i < nums.size() - 1; i++)
		{
			int l = i + 1;
			int r = nums.size() - 1;

			while (l < r)
			{
				if (nums[i] + nums[l] + nums[r] > 0)
				{
					r--;
				}
				else if (nums[i] + nums[l] + nums[r] < 0)
				{
					l++;
				}
				else
				{
					vector<int> vec;
					vec.push_back(nums[i]);
					vec.push_back(nums[l]);
					vec.push_back(nums[r]);
					set_res.insert(vec);
					r--;
					l++;
				}
			}
		}

		res.assign(set_res.begin(), set_res.end());

		return res;
	}
};

int main()
{
	Solution s;
	vector<int> input({ 0,0,0,0,0,0,0,0,0,0,0 });
	vector<vector<int>> ret = s.threeSum(input);


	return 0;
}