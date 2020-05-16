//Implementing a circular Queue

class MyCircularQueue {
private:
    int head; int tail; int n; vector<int>v;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        // v = new vector<int>(k);
        head = -1;
        tail = -1;
        n = k;
        vector<int> temp(k);
        v = temp;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if(isFull())
            return false;
        if((tail+1)%n != head)
        {
            v[(tail+1)%n] = value;
            tail = (tail+1)%n;
            if(head == -1)// && tail == -1)
                head = 0;
            return true;
        }
        return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        if(head == tail){
            head = -1; tail =-1;
            return true;
        }
        v[head] = -1;
        head = (head+1)%n;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty() || head == -1)
            return -1;
        return v[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty() || tail == -1)
            return -1;
        return v[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if((head == -1 && tail == -1))
            return true;
        return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        if((tail+1)%n == head)
            return true;
        return false;
        //OR simply  return ((tail+1)%n) == head;
    }
};


/**
Sample : TC

["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
[[6],[6],[],[],[],[5],[],[],[],[],[],[]]

 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
