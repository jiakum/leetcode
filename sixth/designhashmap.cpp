
class MyHashMap {    
#define MYHASH_BITS (12)
#define MYHASH_NODES (1 << MYHASH_BITS)
    struct list_head {
        int key, val;
        struct list_head *next, *prev;
        list_head(int k = -1, int v = INT_MIN) : key(k), val(v) {}
    };
    struct list_head pdata[MYHASH_NODES];

    void list_add(struct list_head *head, struct list_head *list) {
        struct list_head *next = head->next;

        next->prev = list;
        head->next = list;

        list->next = next;
        list->prev = head;
    }
    void list_del(struct list_head *list) {
        struct list_head *next = list->next, *prev = list->prev;

        next->prev = prev;
        prev->next = next;
    }
    static int hashfn(int val) {
        int key = 0, i;

        for(i = 0;i < 31;i += MYHASH_BITS) {
            key += (val & ((MYHASH_NODES - 1) << i)) >> i;
        }

        key &= MYHASH_NODES - 1;
        return key;
    }
    public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i = 0;i < MYHASH_NODES;i++) {
            struct list_head *head = &pdata[i];

            head->next = head;
            head->prev = head;
        }
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hashfn(key);
        struct list_head *head = &pdata[index], *list;

        for(list = head->next;list != head;list = list->next) {
            if(list->key == key) {
                list->val = value;
                return;
            }
        }

        list = new list_head(key, value);
        list_add(head, list);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hashfn(key);
        struct list_head *head = &pdata[index], *list;

        for(list = head->next;list != head;list = list->next) {
            if(list->key == key) {
                return list->val;
            }
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hashfn(key);
        struct list_head *head = &pdata[index], *list;

        for(list = head->next;list != head;list = list->next) {
            if(list->key == key) {
                list_del(list);
                delete list;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
