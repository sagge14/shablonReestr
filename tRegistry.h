//
// Created by Sg on 06.09.2022.
//
#include <map>
#include <iostream>
#include <vector>
using namespace std;
template<typename T1, typename T2>
class tRegistry
{
    multimap<T1,T2> reg;
public:
    void deleteAll(T1 value);
    void add(T1 key, T2 value);
    void findAll(T1 key, vector<T2>& vResult) const;
    void printAll(T1 key) const;
};

template<typename T1, typename T2>
void tRegistry<T1, T2>::deleteAll(T1 value) {
    reg.erase(value);
}

template<typename T1, typename T2>
void tRegistry<T1, T2>::add(T1 key, T2 value) {
    reg.insert(make_pair(key,value));
}

template<typename T1, typename T2>
void tRegistry<T1, T2>::findAll(T1 key, vector<T2>& vResult) const {

    pair<typename multimap<T1,T2>::const_iterator, typename multimap<T1,T2>::const_iterator> result =reg.equal_range(key);

    for (typename multimap<T1,T2>::const_iterator it = result.first; it != result.second; it++)
        vResult.push_back(it->second);

}

template<typename T1, typename T2>
void tRegistry<T1, T2>::printAll(T1 key) const{

    vector<T2> vResult;
    findAll(key, vResult);

    if(vResult.empty())
    {
        cout << "No one elements with key = " << key << "!" << endl;
        return;
    }

    cout << "All elements with key = " << key << ":" << endl;

    for(const auto e:vResult)
        cout << " - " << e << endl;
}
