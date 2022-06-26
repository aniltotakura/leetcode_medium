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
                cout<<"i: "<< i;
            }
            max = std::max( max, j - i + 1);
            cout <<"max: "<< max << " J: "<< j<< "\n";
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
    auto start = chrono::high_resolution_clock::now();
    cout<<solution.lengthOfLongestSubstring(s);
    cout << "time taken: "<< chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count()<<" ms\n";
}