
class MyLinkedList {
    struct list_head {
        int val;
        struct list_head *next, *prev;
        list_head(int v) :val(v), next(NULL), prev(NULL) {}
    };
    struct list_head *data;
    int size;
    void list_add(struct list_head *head, struct list_head *list) {
        struct list_head *next = head->next;

        head->next = list;
        next->prev = list;

        list->next = next;
        list->prev = head;
    }
    void list_add_tail(struct list_head *head, struct list_head *list) {
        struct list_head *prev = head->prev;

        head->prev = list;
        prev->next = list;

        list->next = head;
        list->prev = prev;
    }
    void list_del(struct list_head *list) {
        struct list_head *next, *prev;

        next = list->next;
        prev = list->prev;

        next->prev = prev;
        prev->next = next;
    }
    public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        data = new list_head(-1);
        data->next = data;
        data->prev = data;

        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        list_head *list;

        for(list = data->next;list != data;list = list->next) {
            if(--index < 0)
                break;
        }

        return list->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        list_head *list = new list_head(val);

        list_add(data, list);
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        list_head *list = new list_head(val);

        list_add_tail(data, list);
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        list_head *list, *pos;

        if(index > size)
            return;

        for(list = data->next;list != data;list = list->next) {
            if(--index < 0)
                break;
        }

        size++;
        pos = new list_head(val);
        list_add_tail(list, pos);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        list_head *list;

        if(index > size)
            return;

        for(list = data->next;list != data;list = list->next) {
            if(--index < 0)
                break;
        }

        if(list == data)
            return;

        list_del(list);
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
