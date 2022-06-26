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
        int first_index = -1;
        map<int, deque<char>>::iterator it;
        deque<char> sub_string;
        vector<int> indices;
        map<int, deque<char> > cm = {};
        map<string, int> wc = {};
        map<string, pair<int,deque<int>>> cwc = {};
        map<string, vector<pair<int, int>>> mws = {};

        for (int j = 0; j< words.size(); j++)
        {
            if (wc.find(words.at(j)) == wc.end()) wc[words.at(j)] = 1;
            if (mws.find(words.at(j)) == mws.end()) mws[words.at(j)] = {};
            else wc[words.at(j)]++;
            cwc.insert_or_assign(words.at(j), make_pair(0,deque<int>{}));
        }
        cout<<"WC: "<<wc;
        cout<<"CWC: "<<cwc;
        cout<< "mws: "<< mws;

        for (int i = 0; i < s.size(); i++) {
            if (sub_string.size() == word_length) {
                sub_string.pop_front();
                sub_string.push_back(s.at(i));
            }
            else sub_string.push_back(s.at(i));
            this_thread::sleep_for(chrono::milliseconds(100));
            // cout<<"sub_string is: "<< sub_string<< "\n";
            for (map<string, int>::iterator ite = wc.begin(); ite != wc.end(); ite++) {
                if (sub_string == ite->first){
                    //increase the count of the found word in the cwc hashmap
                    cwc[ite->first].first++;
                    count++;

                    if( cwc[ite->first].first > 1 ){
                            mws[ite->first].push_back(make_pair(cwc[ite->first].second.back(), cwc[ite->first].second.back() + i - (word_length - 1)));
                    }
                    if( cwc[ite->first].first >= ite->second) {
                        cwc[ite->first].second.pop_front();
                        cwc[ite->first].second.push_back(i - (word_length -1)); 
                    }
                    else cwc[ite->first].second.push_back(i - (word_length -1));

                    
                    
                    cout << "cwc: " << cwc;
                    //cout << "mws: " << mws;
                    
                    if (count >= sub_string_length) {
                        int sum = 0;
                        first_index = -1;
                        cout<<"first_index before loop: "<< first_index<<"\n";
                        for( auto const& [key,value] : cwc) {
                            for (auto x = value.second.begin(); x != value.second.end(); x++) {
                                sum = sum + *x;
                                if (first_index == -1) first_index = *x;
                                else if (first_index > *x) first_index = *x;
                            }
                        }
                        cout<<"first_index after loop: "<< first_index<<"\n";
                        cout << "first_index: " << first_index<< " sub_string_length: " << sub_string_length<< " word_length: "<< word_length << "\n";
                        cout<< "sum: "<< sum << " calc: "<<( sub_string_length/2.0) * ((2*first_index) + ((sub_string_length -1) * word_length)) << " \n";
                        if (sum  == ( sub_string_length/2.0) * ((2*first_index) + ((sub_string_length -1) * word_length)) )
                        indices.push_back((i+1) - word_length * sub_string_length);
                    }
                    cout<<"first_index: "<< first_index<<"\n";
                   
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
