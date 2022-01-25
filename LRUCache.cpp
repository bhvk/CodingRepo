// #define PRINT
class LRUCache {
public:
    unordered_map<int,pair<int,int>::iterator>mp;
    list<pair<int,int>> l;
    // list<int> l;

    int n;
    int c = 0;
    LRUCache(int capacity) {
        n = capacity;
    }

    void bringKeyToFront(list<pair<int,int>> &l, pair<int,int>::iterator itr)
    {
      //This is wrong and hefty O(N) operation
        // for(auto it = l.begin(); it != l.end(); ++it)
        // {
        //   if((*it).first == p.first)
        //   {
        //      // cout<<(*it).first<<", ";
        //     l.erase(it);
        //     l.push_front(p);
        //     break;
        //   }
        // }
/*
The list::splice() is a built-in function in C++ STL which is used to transfer elements from one list to another. The splice() function can be used in three ways:

Transfer all the elements of list x into another list at some position.
Transfer only the element pointed by i from list x into the list at some position.
Transfers the range [first, last) from list x into another list at some position.

list1_name.splice (iterator position, list2)
                or
list1_name.splice (iterator position, list2, iterator i)
                or
list1_name.splice (iterator position, list2, iterator first, iterator last)

Parameters: The function accepts four parameters which are specified as below:

position – Specifies the position where the elements are to be transferred.
list2 – It specifies a list object of the same type which is to be transferred.
i – It specifies an iterator to the position of an element in list2 which is to be transferred.
first, last – Iterators specifying a range of elements in list2 which is to be transferred in list1. The range includes all the elements between first and last, including the element pointed by first but not the one pointed by last.

*/
        l.splice(l.begin(), l, itr);
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        // bringKeyToFront({key,val}, l);
        bringKeyToFront(l, m[key]);
        return mp[key]->second;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) //already exist
        {
            bringKeyToFront(l, mp[key]);
            mp[key]->second = value;
        }
        else
        {
            if(l.size() >= n)
            {
                mp.erase(l.back().first);
                l.pop_back();
            }
            l.push_front({key, value});
            mp[key] = l.begin();
        }
    }
};
