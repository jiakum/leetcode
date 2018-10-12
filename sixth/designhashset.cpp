
class MyHashSet {
#define MYHASH_BITS (12)
#define MYHASH_NODES (1 << MYHASH_BITS)
    struct list_head {
        int val;
        struct list_head *next, *prev;
        list_head(int v = INT_MIN) : val(v) {}
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
    MyHashSet() {
        for(int i = 0;i < MYHASH_NODES;i++) {
            struct list_head *head = &pdata[i];

            head->next = head;
            head->prev = head;
        }
    }

    void add(int key) {
        int index = hashfn(key);
        struct list_head *head = &pdata[index], *list;

        for(list = head->next;list != head;list = list->next) {
            if(list->val == key) {
                return;
            }
        }

        list = new list_head(key);
        list_add(head, list);
    }

    void remove(int key) {
        int index = hashfn(key);
        struct list_head *head = &pdata[index], *list;

        for(list = head->next;list != head;list = list->next) {
            if(list->val == key) {
                list_del(list);
                delete list;
                break;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = hashfn(key);
        struct list_head *head = &pdata[index], *list;

        for(list = head->next;list != head;list = list->next) {
            if(list->val == key) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
