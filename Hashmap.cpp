#include <bits/stdc++.h>
using namespace std;

struct bucket{
    set<int> s;
    
    void add(int x){
        s.insert(x);
    }

    void remove(int x){
        if(s.lower_bound(x) != s.end() ){
            s.erase(x);
        }
    }

    bool find(int x){
        if(s.lower_bound(x) != s.end() ){
            return 1;
        }

        return 0;
    } 

};

class hashmap {
    int number_of_buckets;
    bucket* container;

    int hash_function(int x){
        return x % number_of_buckets;
    }

    public :

    hashmap(int buckets_req){
        number_of_buckets = buckets_req;
        container = new bucket[buckets_req];
    }


    void insert(int x){
        container[hash_function(x)].add(x); 
    }

    void remove(int x){
        container[hash_function(x)].remove(x);
    }

    bool find(int x){
        container[hash_function(x)].find(x);
    }


};


int main(){
    hashmap mp(10);

    mp.insert(2);
    mp.insert(1);
    mp.insert(400);

    cout<<mp.find(1)<<mp.find(400)<<mp.find(1)<<endl;


    return 1;
    
}
