/*
implement two stack - input stack, output stack

1. push()
add to input stack - O(1)

Note - if input stack is empty then initialize first push elem to peekElem.

2. pop()
check if output stack is empty
if not then push all element of input stack to output stack

now top element of output stack must pop

3. peek()
check if output is empty then peekElement (which we have initialized) is peek
if not, then top element of output is peek

4. empty()
if both input and output stack is empty then only queue is emoty

******************
TC - Amortized O(1)
It means it's O(N) sometimes and manytimes it's O(1)

*/

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    int peekElement = -1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekElement = x;
        }
        input.push(x); // this we have to do everytime 
    }
    
    int pop() {
        if(output.empty()){
            // input -> output O(N)
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top(); // O(1)
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty()) return peekElement;

        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;

        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

