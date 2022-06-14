#include "TwoSumConfig.h"
#ifdef USE_HELPER
#   include "include.h"
#endif

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sub_string_length = words.size();
        int word_length = words.at(0).size();
        string sub_string;
        set<string> set_string;
        vector<int> indices;

        for (int i = 0; i < s.size(); i = i + word_length) {
            sub_string = s.substr(i, word_length );
            cout<< "sub_string is " << sub_string << "  i: " << i << "  word_length: " << word_length <<endl;
            for (int j = 0; j < words.size(); j++) {
                if (sub_string == words[j]){
                    if (set_string.insert(sub_string).second == true) {
                        if (set_string.size() == sub_string_length) {
                            indices.push_back(i - (word_length -1) * sub_string_length);
                            cout<<set_string;
                            set_string.clear();
                            cout<<"set stirng clear in result\n";
                        }
                        cout<<set_string;
                    }
                    else {
                        set_string.clear();
                        cout<<"set stirng clear in else\n";
                        set_string.insert(sub_string);
                        cout<<set_string;
                    }
                }
            }
            
        }

        return indices; 
    }
};

int main()
{
    Solution solution;
    string s = "barfoofoobarthefoobarman";
    vector<string> indices{"bar","foo","the"};
    cout<<solution.findSubstring(s, indices);
}