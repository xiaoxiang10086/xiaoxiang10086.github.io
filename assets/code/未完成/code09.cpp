/*
	用两个栈来实现队列 
*/
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
    	s1.push(value);
    }
    
    int deleteHead() {
    	if (s2.size() <= 0) {
    		while (s1.size() > 0) {
    			int data = s1.top();
    			s1.pop();
    			s2.push(data);
    		}
    	}

    	if (s2.size() == 0) 
    		return -1;

    	int res = s2.top();
    	s2.pop();
    	return res;
    }

private:
	stack<int> s1;
	stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

/*
	用两个队列来实现栈 
*/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
    	queue<int> temp;
    	temp.push(x);
    	while (!data.empty()) {
    		temp.push(data.front());
    		data.pop();
    	}
    	while (!temp.empty()) {
    		data.push(temp.front);
    		temp.pop();
    	}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = data.front();
        data.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
private:
    queue<int> data;
};