
class RandomizedSet {
    map<int,int> data;
    vector<int> vi;
    public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(0));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        map<int,int>::iterator iter;

        iter = data.find(val);
        if(iter != data.end())
            return false;

        data[val] = vi.size();
        vi.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        map<int,int>::iterator iter;

        iter = data.find(val);
        if(iter == data.end())
            return false;

        int back = vi.back();
        vi[iter->second] = back;
        vi.pop_back();

        data[back] = iter->second;
        data.erase(iter);

        return true;     
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % vi.size();
        return vi[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
