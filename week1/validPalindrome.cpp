#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";

        if (s.size() == 1)
            return true;

        for (long long int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                str = str + s[i];
            }
        }

        transform(str.begin(), str.end(), str.begin(), ::tolower);

        long long int i = 0;
        long long int j = str.size() - 1;

        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};