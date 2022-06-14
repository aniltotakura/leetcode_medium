#include "TwoSumConfig.h"
#ifdef USE_HELPER
#   include "include.h"
#endif

using namespace std;
                        /* brute force method */
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         unsigned int i = 0;
//         while (true)
//         {
//             for(i; i< numbers.size(); i++ )
//             {
//                 if (( numbers[i] + numbers[i+1] ) == target)
//                 {return vector<int> {(int)i, (int)i+1};}
//             }
//             i++;
//         }
        
        
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, unsigned int> hash_map;
        for(unsigned int i = 0; i< numbers.size(); i++ )
        {
            auto it =hash_map.find( target - numbers[i] );
            if (it != hash_map.end())
                {
                    return vector<int> {(int)i, (int)it->second};
                }
            else
                {
                    hash_map.insert({numbers[i], i});
                }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {2,3,4};
    cout<<solution.twoSum(numbers, 6);
}
