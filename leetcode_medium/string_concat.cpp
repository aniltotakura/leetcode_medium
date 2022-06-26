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
        vector<int> indices;
        unordered_map< string, int> hash ={};
        unordered_map< string, int> wordHash ={};

        for(string s: words) wordHash[s]++;

        for( int i = 0; i < s.size(); i++) {
            string subString = s.substr(i, sub_string_length * word_length);
            unordered_map< string, int> wordHashTemp = wordHash;
            for(int j = 0; j < subString.size(); j = j + word_length) {
                string word = subString.substr(j, word_length);
                unordered_map< string, int>::iterator it = wordHashTemp.find(word);
                if( it != wordHashTemp.end() ) {
                    if (it->second > 1) it->second--;
                    else wordHashTemp.erase(it);
                }
                else break;
            }
            
            if (wordHashTemp.size() == 0) indices.push_back(i);
        }

        for (int i= 0; i< words.size(); i++) {
            
        }
        return indices;
    }

    vector<int> findSubstringOptimesed(string str, vector<string>& words) {
        int word_length = words[0].length();
        
        unordered_map<string, int> hash;
        for(string s: words) hash[s]++;
        
        vector<int> indices;
        for(int j = 0; j < word_length; j++) {
            unordered_map<string, int> hashTemp;
            int pos = j;
            for(int i = j; i < str.size() - word_length + 1; i += word_length) {
                string curr = str.substr(i, word_length);

                if(hash.find(curr) != hash.end()) {
                    hashTemp[curr]++;
                    while(hashTemp[curr] > hash[curr]) {
                        hashTemp[str.substr(pos, word_length)]--;
                        pos = pos + word_length;
                    }

                    int size = (i - pos + word_length) / word_length;
                    if(size == words.size()) {
                        // cout << j << " " << pos << " " << i << endl;
                        indices.push_back(pos);
                    }
                } else {
                    hashTemp.clear();
                    pos = i + word_length;
                }
            }

            // cout << "one loop ended\n";
        }
        
        return indices;
    }
};

int main()
{
    Solution solution;
    //          012345678901234567890123456
    string s = "barfoofoobarthefoobarman";
    vector<string> indices{"bar","foo","the"};

    auto start = chrono::high_resolution_clock::now();
    cout<<solution.findSubstringOptimesed(s, indices);
    cout << "time taken: "<< chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count()<<" ms\n";
}
