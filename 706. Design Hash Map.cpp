class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        bool found = false;
        for( auto & l : h ) {
            if( l.key == key ) {
                l.value = value;
                found = true;
            }
        }
        if( !found ) {
            MyHashMapT n;
            n.key = key;
            n.value = value;
            h.push_front(n);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if( h.empty() ) {
            return -1;
        }
        for( auto const& l : h ) {
            if( l.key == key ) {
                return l.value;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        bool found = false;
        list<MyHashMapT>::iterator it1;
        for( auto it=h.begin(); it!=h.end(); it++ ) {
            if( (*it).key == key ) {
                it1 = it;
                found = true;
            }
        }
        if( found ) {
            h.erase(it1);
        }        
    }
    
    struct MyHashMapT {
        int key;
        int value;
    };
    list<MyHashMapT> h;
};












struct MapNode
{
    int key,value;
    MapNode* next;
    MapNode()
    {
        key=value =-1;
        next = NULL;
    }
    MapNode(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class MyHashMap {
    int capacity =10;
    int size =0;
    MapNode * htbl = new MapNode[capacity];
    
    void ReHash()
    {
        cout<<"Rehash\n";
        int oldCap = capacity;
        int newCap = 2 * oldCap;
        MapNode * oldTbl = htbl, *temp;
        MapNode * newTbl = new MapNode[newCap];
        for(int i = 0; i<capacity; i++)
        {
            for(MapNode* old = htbl[i].next; old != NULL; temp)
            {
                temp = old->next;
                int newIndex = old->key % newCap;
                old->next = newTbl[newIndex].next;
                newTbl[newIndex].next = old;                
            }
            htbl = newTbl;
            capacity = newCap;
        }
    }
    
   
    bool contains(int key)
    {
        int index = key % capacity;
        for(MapNode * node = htbl[index].next; node != NULL; node = node->next)
        {
            if(node->key == key)
            {
                cout<<"contains true; ";
                return true;
            }
        }
        
        return false;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        if(contains(key))
        {
             int index = key % capacity;
             for(MapNode  *node = htbl[index].next; node != NULL; node = node->next)
            {            
                if(node->key == key)
                {                
                    cout<<"value updated put "<< value<<";  ";
                    node->value = value;
                     break;
                }
               
            }
        }
        else
        {
            if(capacity/(size+1)>10)
                ReHash();
            
            int index = key % capacity;
            MapNode* newNode = new MapNode(key,value);
            
            newNode->next = htbl[index].next;
            htbl[index].next = newNode;
        }
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
       // cout<<"get\n";
        int index = key % capacity;
        for(MapNode * node = htbl[index].next; node != NULL; node = node->next)
        {
            if(node->key == key)
                return node->value ;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
       // cout<<"remove\n";
        int index = key % capacity;
        MapNode* prev = &htbl[index];;
        for(MapNode  *node = htbl[index].next; node != NULL; node = node->next)
        {            
            if(node->key == key)
            {
                prev->next = node->next;
                delete node;
                break;
            }
            prev = node;
        }
        
    }
};