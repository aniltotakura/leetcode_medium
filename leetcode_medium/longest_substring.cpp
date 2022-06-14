#include "TwoSumConfig.h"
#ifdef USE_HELPER
#   include "include.h"
#endif

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map< char, int> hash ={};
        int max = 0;
        for( int i = 0, j = 0; j < s.size(); j++) {
            auto it = hash.find(s[j]);
            if (it != hash.end()) {
                i = std::max(hash.find(s[j])->second, i);
            }
            max = std::max( max, j - i + 1);
            hash.insert_or_assign(s[j], j + 1);
            cout<<hash;
        }
        return max;
        
    }
};

int main()
{
    Solution solution;
    string s = "abcabcabcabc";
    cout<<solution.lengthOfLongestSubstring(s);
}