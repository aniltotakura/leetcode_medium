#ifndef UTILS_H
#define UTILS_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include<vector>
#include<deque>
#include<map>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const deque<T> &v) {
    os <<"[";
    for (auto it= v.begin(); it != v.end();it++){
        os<<*it;
        if (it!=v.end()-1) os << ",";
    }
    os<<"]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T> &v) {
    os <<"[";
    for (auto it= v.begin(); it != v.end();it++){
        os<<*it;
        if (it!=v.end()-1) os << ",";
    }
    os<<"]\n";
    return os;
}

template <typename T,typename V>
ostream& operator<<(ostream& os, const multimap<T,V> &v) {
    os <<"the hash multi map is : {";
    for (const auto &[key,value]:v){
        os<<"("<<key<<","<<value<<")";
        
    }
    os<<"}\n";
    return os;
}
template <typename T,typename V>
ostream& operator<<(ostream& os, const map<T,V> &v) {
    os <<"the hash multi map is : {";
    for (const auto &[key,value]:v){
        os<<"("<<key<<","<<value<<")";
        
    }
    os<<"}\n";
    return os;
}

template <typename T,typename V>
ostream& operator<<(ostream& os, const unordered_map<T,V> &v) {
    os <<"the unordered_map is : {";
    for (const auto &[key,value]:v){
        os<<"("<<key<<","<<value<<")";
        
    }
    os<<"}\n";
    return os;
}
#endif