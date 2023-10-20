/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>flat;
    int i;
    vector<int> solve(vector<NestedInteger> &nestedList) {
        vector<int>res;
        for(auto& ni: nestedList) {
            if(ni.isInteger()) {
                res.push_back(ni.getInteger());
            } else {
                auto subList = solve(ni.getList());
                res.insert(res.end(), subList.begin(), subList.end());
            }
        }
        return res;
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flat = solve(nestedList);
        i = 0;
    }
    
    int next() {
        return flat[i++];
    }
    
    bool hasNext() {
        return i < flat.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */