class MyCircularQueue {
public:
int K;
vector<int>deq;
int front,rare,cc;
    MyCircularQueue(int k) {
       K=k;
       deq=vector<int>(K,0); 
       front =0;
       rare=K-1;
       cc=0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        rare=(rare+1)%K;
        deq[rare]=value;
        cc++;
        return true;

        
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%K;
        cc--;
        return true;
        
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return deq[front];
        
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return deq[rare];
    }
    
    bool isEmpty() {
      return cc==0 ; 
    }
    
    bool isFull() {
     return cc==K;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */