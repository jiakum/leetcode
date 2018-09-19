
class LRUCache {
    private:
        struct priv_data {
            int key;
            int val;
            priv_data *next, *prev;
            priv_data(int k, int v) : key(k), val(v){}
        };
        priv_data *head;
        map<int, priv_data*> kmap;

        void list_add(priv_data *newdata) {
            priv_data *next = head->next;

            newdata->next = next;
            next->prev = newdata;

            head->next = newdata;
            newdata->prev = head;
        }      
        void list_add_tail(priv_data *newdata) {
            priv_data *prev = head->prev;

            newdata->next = head;
            newdata->prev = prev;

            head->prev = newdata;
            prev->next = newdata;
        }    
        void list_del(priv_data *deldata) {
            priv_data *next = deldata->next;
            priv_data *prev = deldata->prev;

            next->prev = prev;
            prev->next = next;
        }
    public:
        LRUCache(int capacity) {
            head = new priv_data(INT_MIN, INT_MIN);
            head->next = head;
            head->prev = head;
            int i;
            for(i = 1;i <= capacity;i++) {
                priv_data *data = new priv_data(-i, -i);
                list_add(data);
                kmap[-i] = data;
            }
        }

        int get(int key) {
            map<int, priv_data*>::iterator iter;

            iter = kmap.find(key);
            if(iter != kmap.end()) {
                priv_data * data = iter->second;
                list_del(data);
                list_add(data);
                return data->val;
            }
            return -1;
        }

        void put(int key, int value) {
            map<int, priv_data*>::iterator iter;

            iter = kmap.find(key);
            if(iter != kmap.end()) {
                priv_data * data = iter->second;
                list_del(data);
                list_add(data);
                data->val = value;
                return ;
            }

            priv_data *last = head->prev;
            int del = last->key;

            list_del(last);
            last->key = key;
            last->val = value;
            list_add(last);

            kmap.erase(del);
            kmap[key] = last;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
