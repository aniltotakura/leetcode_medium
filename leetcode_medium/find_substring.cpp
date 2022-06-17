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
        int count = 0;
        int first_index = 0;
        map<deque<char>, int>::iterator it;
        deque<char> sub_string;
        vector<int> indices;
        map<deque<char>, int > map = {};
 
        for (int i = 0; i < s.size(); i++) {
            if (sub_string.size() == word_length) {
                sub_string.pop_front();
                sub_string.push_back(s.at(i));
            }
            else sub_string.push_back(s.at(i));
            this_thread::sleep_for(chrono::milliseconds(100));
            for (int j = 0; j < words.size(); j++) {
                if (sub_string == words[j]){
                    map.insert_or_assign(sub_string, i - (word_length -1));
                    cout<<map;
                    if (map.size() == sub_string_length) {
                        count = 0;
                        first_index = map.begin()->second;
                        for ( it = map.begin(); it != map.end(); it++ ) {
                                if (first_index > it->second) first_index = it->second;
                                count = count + it->second;
                        }
                        cout << "first_index: " << first_index<< " sub_string_length: " << sub_string_length<< " word_length: "<< word_length << "\n";
                        cout<< "count: "<< count << " calc: "<<( sub_string_length/2.0) * ((2*first_index) + ((sub_string_length -1) * word_length)) << " \n";
                        if (count  == ( sub_string_length/2.0) * ((2*first_index) + ((sub_string_length -1) * word_length)) )
                            indices.push_back((i+1) - word_length * sub_string_length);
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
    //          012345678901234567890123456
    string s = "wordgoodgoodgoodbestword";
    vector<string> indices{"word","good","best","good"};
    cout<<solution.findSubstring(s, indices);
}
