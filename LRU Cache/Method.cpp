//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.


//lru算法要点：
//get 如果cache命中，在访问队列中，将该点删除，移到队首。 否则返回－1.
//set 如果命中，则在访问队列中，将该点删除，移到队首，修改该点的值。否则，需要插入，
//插入时又分为两种情形，i)cache没满，将key value插入队头。ii)cache满了，先删了队尾,再插入队头。
//如果使用一个双向链表，在给定节点的同时，增删队头队尾都可以用O(1).但是问题是如何给定一个key就确定是双向链表中哪一个节点？这样得用O(n)时间。
//所以我们得配合使用hashtable,根据一个key, 能哈西 这个链表的指针。这样我们就可以做到O(1)时间。 所以用map<int,list<pair<key,value>::iterator>这样一个结构。无论什么操作，只要涉及到队列操作，都应该改hashmap，就算只是get,因为你将该点移到了队头，iterator也会变，所以也得重设map.还有需要特别注意的是一旦取得了list的it, 对其引用要在任何修改list的操作之前。




class LRUCache{
    
    unordered_map<int,list<pair<int,int>>::iterator> mymap;
    list<pair<int,int>> mylist;
    int cap;
    
public:
    
    LRUCache(int capacity) {
        cap= capacity;
    }
    
    int get(int key) {
        
        auto it = mymap.find(key);
        
        if(it!=mymap.end()) {    //cache命中，
            
            int res = it->second->second;

            mylist.erase(it->second);
            mylist.push_front(make_pair(key,res));
            mymap[key] = mylist.begin();
            
            return res;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        auto it = mymap.find(key);
        
        if(mymap.find(key)!=mymap.end()) {   //cache命中
            
            mylist.erase(it->second);
            
            mylist.push_front(make_pair(key,value));
            
            mymap[key] = mylist.begin();

        }
        
        else {
            
            if(mylist.size()==cap) {
                int k = mylist.back().first;
                
                mylist.pop_back();
                mymap.erase(k);
            }
            
            mylist.push_front(make_pair(key,value));
                
            mymap[key] = mylist.begin();

        }

    }
};