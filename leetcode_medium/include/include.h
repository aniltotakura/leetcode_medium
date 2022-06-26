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
#include <chrono>
#include <thread>
#include <boost/functional/hash.hpp>
#include <cstdlib>
#include <chrono>


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

template <typename T_0, typename T_1> 
std::ostream& operator<<( std::ostream& os, const std::map<T_0, T_1>& m){
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
std::ostream& operator<<( std::ostream& os, const std::deque<T_0>& m){
    std::cout<<"{";
    if (m.size() > 0){
        for (auto it = m.begin(); it != m.end(); it++){
            std::cout<<" "<<*it;
        }
    }
    std::cout<<" }";
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

bool operator==( std::deque<char> q, const std::string s){
    if (q.size() == s.size() && q.size() > 0 && s.size() > 0 ){
        for (int i = 0; i < s.size(); i++){
            if(q.at(i) == s.at(i));
            else return false;
        }
        return true;
    }
    return false;
}

template <typename Container> // we can make this generic for any container [1]
struct container_hash {
    std::size_t operator()(Container const& c) const {
        return boost::hash_range(c.begin(), c.end());
    }
};


template <typename T_0, typename T_1> 
std::ostream& operator<<( std::ostream& os, const std::unordered_map< T_0, T_1, container_hash<T_0> >& m ){
    std::cout<<std::endl<<std::endl;
    if (m.size() > 0){
        for (const auto& [first, second] : m){
            std::cout<<"|    "<<first;
            std::cout<<" "<<second<<"    |";
            std::cout<<std::endl;
        }
    }
}

template < typename T_0, typename T_1> 
std::ostream& operator<<( std::ostream&os, const std::pair <T_0, T_1>& p) {
    std::cout <<"[ " << p.first << " " << p.second<<" ]";
}