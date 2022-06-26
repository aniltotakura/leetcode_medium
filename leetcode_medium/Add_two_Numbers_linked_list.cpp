#include "TwoSumConfig.h"
#ifdef USE_HELPER
#   include "include.h"
#endif

using namespace std;

auto print_key_value = [](const auto &key, const auto &value){
        std::cout<< "Key:["<<key<<"] Value: ["<<value<<"]\n";
    };

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addList(ListNode *l1,ListNode *l2){

        if (!l1->next && !l2->next) {l1->next = l2; return l1;}
        else if(l1->next && !l2->next) return addList(l1->next,l2);
        else return l1;
        
}

ListNode* constructionList(vector<int>v){
        ListNode* head;
        ListNode* head2;
        ListNode* first;
        for (auto it = v.begin();it!=v.end();it++){
                
                if (it==v.begin()) {
                    head = new ListNode(*it);
                    head2= head;
                }
                else {
                    first = new ListNode(*it);
                    head = addList(head,first);
                }
        }
return head2;
}

ListNode* constructionListswapped(vector<int>v){
    ListNode* head;
    ListNode* first;
    ListNode* second;
    for (auto it = v.begin();it!=v.end();it++){
        if (it==v.begin()) head = new ListNode(*it);
        else if (!head->next) {
            first = new ListNode(*it);
            head->next = first;
        }
        else if (head->next!=nullptr && first->next==nullptr){
            second = new ListNode(*it);
            first->next = second;
            // cout<< "First null: "<< first<< endl;
        }
        else if(first->next!= nullptr){
            first = new ListNode(*it);
            second->next = first;
            // cout<< "secon null: "<< first<< endl;

        }
    }
return head;

}

template <typename T,typename V>
ostream& operator<<(ostream& os, const ListNode* l) {
    ListNode* ptr = l;
    os <<"the list node is : [";
    while(ptr){
        os<<ptr->val<<",";
        ptr=ptr->next;
    }
    os<<"]\n";
    return os;
}
void printList(ListNode* head, string l)
{
    ListNode* ptr = head;
    cout << l+" -> ";
    while (ptr!=nullptr)
    {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    
 
    cout << "nullptr"<<std::endl;
    //  while (head!=nullptr)
    // {
    //     cout << head << " -> ";
    //     head = head->next;
    // }
    //  cout<<std::endl;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        int carry = 0, l1val = 0, l2val =  0, sum = 0;
        while (l1!= nullptr || l2 != nullptr) {
            l1val = (l1 != nullptr) ? l1->val : 0;
            l2val = (l2 != nullptr) ? l2->val : 0;
            sum = l1val + l2val + carry;
            // temp->next = new ListNode(sum % 10);
            carry = sum /10;
            cout << "l1val "<< l1val<< " l2val "<< l2val<< " carry "<<carry<< endl;
            if (l1 != nullptr) {
                l1->val = sum %10;
                temp->next = l1;
                l1 = l1->next;
            } 
            if (l2 != nullptr) {
                l2->val = sum %10;
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }
        return head->next;
    }

    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* first =  new ListNode();
        ListNode* second =  new ListNode();
        int carry = 0;

        if (head->next == nullptr) {
            head->val =(l1-> val + l2->val)%10;
            carry = (l1-> val + l2->val  + carry)/10;
            l2 = l2->next;
            l1 = l1->next;
        }
        
        if (!l1 && !l2) {
            if (carry != 0) {
                head->next = new ListNode(carry);
            }
            return head;
        }
        else if (l1 && !l2) {
            int temp =  (l1-> val + carry)/10;
            l1->val = (l1-> val + carry)% 10;
            carry = temp;
            head->next = l1;
            if (l1->next == nullptr) {
                    if (carry != 0) {
                        l1->next = new ListNode(carry);
                        return head;
                    }
            }
            l1 = l1->next;
            while(l1){
                
                temp = (l1-> val + carry)/10;
                l1->val = (l1-> val + carry)% 10;
                carry = temp;
                if (l1->next == nullptr) {
                    if (carry != 0) {
                        l1->next = new ListNode(carry);
                        return head;
                    }
                }
                l1 = l1->next;
            }
            return head;
        }
        else if (l2 && !l1) {
            int temp =  (l2-> val + carry)/10;
            l2->val = (l2-> val + carry)% 10;
            carry = temp;
            head->next = l2;
            if (l2->next == nullptr) {
                    if (carry != 0) {
                        l2->next = new ListNode(carry);
                        return head;
                    }
            }
            l2 = l2->next;
            while(l2){
                temp = (l2-> val + carry)/10;
                l2->val = (l2-> val + carry)%10;
                carry = temp;
                if (l2->next == nullptr) {
                    if (carry != 0) {
                        l2->next = new ListNode(carry);
                        return head;
                    }
                }
                l2 = l2->next;
            }
            return head;
        }
        
        
        while (l1->next && l2->next) {

            if (head->next == nullptr && first->next == nullptr){
                first = new ListNode((l1-> val + l2->val+ carry)%10);
                head->next = first;
                second->next = first;

            }
            else if (first->next == nullptr) {
                second = new ListNode((l1-> val + l2->val+ carry)%10);
                first->next = second;
            }
            else if (first->next != nullptr) {
                first = new ListNode((l1-> val + l2->val + carry)%10);
                second->next = first;
            }
            carry = (l1-> val + l2->val  + carry)/10;
            
            l2 = l2->next;
            l1 = l1->next;
        }

        if (first->next == nullptr) {
            second = new ListNode((l1-> val + l2->val+ carry)%10);
            if (head->next == nullptr) head->next = second;
            else first->next = second;
            carry = (l1-> val + l2->val  + carry)/10;
            l2 = l2->next;
            l1 = l1->next;
            if (l1) {
                int temp =  (l1-> val + carry)/10;
                l1->val = (l1-> val + carry)% 10;
                carry = temp;
                second->next = l1;
                if (l1->next == nullptr) {
                        if (carry != 0) {
                            l1->next = new ListNode(carry);
                            return head;
                        }
                }
                l1 = l1->next;
                while(l1){
                    int temp =  (l1-> val + carry)/10;
                    l1->val = (l1-> val + carry)% 10;
                    carry = temp;
                    if (l1->next == nullptr) {
                        if (carry != 0) {
                            l1->next = new ListNode(carry);
                            return head;
                        }
                    }
                    l1 = l1->next;
                }
                
            }
            else if (l2) {
                int temp =  (l2-> val + carry)/10;
                l2->val = (l2-> val + carry)% 10;
                carry = temp;
                second->next = l2;
                if (l2->next == nullptr) {
                        if (carry != 0) {
                            l2->next = new ListNode(carry);
                            return head;
                        }
                }
                l2 = l2->next;
                while(l2){
                    int temp =  (l2-> val + carry)/10;
                    l2->val = (l2-> val + carry)% 10;
                    carry = temp;
                    if (l2->next == nullptr) {
                        if (carry != 0) {
                            l2->next = new ListNode(carry);
                            return head;
                        }
                    }
                    l2 = l2->next;
                }
            }
            else if (carry != 0) {
                second->next = new ListNode(carry);
            }
            
        }
        else if (first->next != nullptr) {
            first = new ListNode((l1-> val + l2->val + carry)%10);
            if (head->next == nullptr) head->next = first;
            else second->next = first;
            carry = (l1-> val + l2->val  + carry)/10;
            l2 = l2->next;
            l1 = l1->next;
            if (l1) {
                int temp =  (l1-> val + carry)/10;
                l1->val = (l1-> val + carry)% 10;
                carry = temp;
                first->next = l1;
                if (l1->next == nullptr) {
                        if (carry != 0) {
                            l1->next = new ListNode(carry);
                            return head;
                        }
                }
                l1 = l1->next;
                while(l1){
                    int temp =  (l1-> val + carry)/10;
                    l1->val = (l1-> val + carry)% 10;
                    carry = temp;
                    if (l1->next == nullptr) {
                        if (carry != 0) {
                            l1->next = new ListNode(carry);
                            return head;
                        }
                    }
                    l1 = l1->next;
                }
                
            }
            else if (l2) {
                int temp =  (l2-> val + carry)/10;
                l2->val = (l2-> val + carry)% 10;
                carry = temp;
                first->next = l2;
                if (l2->next == nullptr) {
                        if (carry != 0) {
                            l2->next = new ListNode(carry);
                            return head;
                        }
                }
                l2 = l2->next;
                while(l2){
                    int temp =  (l2-> val + carry)/10;
                    l2->val = (l2-> val + carry)% 10;
                    carry = temp;
                    if (l2->next == nullptr) {
                        if (carry != 0) {
                            l2->next = new ListNode(carry);
                            return head;
                        }
                    }
                    l2 = l2->next;
                }
            }
            else if (carry != 0) {
                first->next = new ListNode(carry);
            }
            if (head->next == nullptr) {
                head->next = first;
            }
        }


        return head;
        
    }
};

int main() {

    Solution solution;
    vector<int> v2{2,8,9,9,9,9,8,9,9,9};
    vector<int> v1{8,1,2};
    ListNode* l1 = constructionList(v1);
    printList(l1,"l1");
    ListNode* l2 = constructionList(v2);
    printList(l2,"l2");
    auto now = chrono::high_resolution_clock().now();
    ListNode* result = solution.addTwoNumbers(l1,l2);
    std::cout<< chrono::duration_cast<chrono::microseconds> (chrono::high_resolution_clock().now()-now).count()<<" ns"<<std::endl;
    printList(result,"r0");
}