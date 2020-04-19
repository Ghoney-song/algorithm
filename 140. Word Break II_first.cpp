class Solution {
public:
	vector<string> ret;

	void wb(string s, int idx, string sub, unordered_set<string>& dict)
	{
		string temp;
		string ori(sub);
		int ori_idx = idx;
		for (int i = idx; i < s.size(); i++)
		{
			temp.push_back(s[i]);
			cout << "temp : " << temp << endl;
			auto iter = dict.find(temp);
			if (iter != dict.end())
			{
				if (i + 1 == s.size())
				{
					sub += temp;
					cout << "found!! sub : " << sub << endl;
					ret.push_back(sub);
					return;
				}
				temp.push_back(' ');
				sub += temp;
				cout << "before sub : " << sub << endl;
				wb(s, i + 1, sub, dict);
				temp.pop_back();
				sub = ori;
				cout << "after sub : " << sub << endl;
			}
			else if (i + 1 == s.size())
			{
				break;
			}
		}
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict;
		ret.clear();
		string sub;

		for (int i = 0; i < wordDict.size(); i++)
		{
			dict.insert(wordDict[i]);
		}

		wb(s, 0, sub, dict);

		return ret;
	}
};