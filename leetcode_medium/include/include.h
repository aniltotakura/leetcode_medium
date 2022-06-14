#include<stdio.h>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <deque>
#include <queue>
#include <set>

template <typename T, typename = void>
struct is_iterable : std::false_type{};

template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))
                                  >
                   >: std::true_type{}; 

template <typename T0>
std::ostream& operator<<(std::ostream& os , const std::vector<T0>& v){
    std::cout<<"[";
    for (T0 t : v){
        std::cout<<" "<< t;
    }
    std::cout<<"]";
}

template <typename T_in> 
std::ostream& operator<<(std::ostream &os, const std::vector<std::vector<T_in>>& v){
    std::cout<<"[";
    for ( std::vector<T_in> t : v){
        if (is_iterable<T_in>()){
            break;
        }
        else
        {
            std::cout<<"[";
            for (T_in t_in : t){
                std::cout<<t_in;
            }
            std::cout<<"]"<<std::endl;
        }
    }
    std::cout<<"]"<<std::endl;
}
template <typename T_0, typename T_1> 
std::ostream& operator<<( std::ostream& os, const std::unordered_map<T_0, T_1>& m){
    std::cout<<std::endl<<std::endl;
    if (m.size() > 0){
        for (const auto& [first, second] : m){
            std::cout<<"|    "<<first;
            std::cout<<" "<<second<<"    |";
            std::cout<<std::endl;
        }
    }
}

template <typename T_0> 
std::ostream& operator<<( std::ostream& os, const std::set<T_0>& m){
    std::cout<<std::endl<<"{";
    if (m.size() > 0){
        for (auto it = m.begin(); it != m.end(); it++){
            std::cout<<" "<<*it;
        }
    }
    std::cout<<" }"<<std::endl;
}

template <typename T>
class FixedQueue : public std::deque<T> {
public:
    FixedQueue(int len): MaxLen{len}{}
    void push(const T& value) {
        if (this->size() == MaxLen) {
           this->pop_front();
        }
        this->push_back(value);
    }
private: 
    int MaxLen;
};