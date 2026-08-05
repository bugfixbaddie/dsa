class MyCircularDeque {
public:
    int K;
    vector<int> deq;
    int front, rear, cc;

    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(K, 0);

        front = 0;
        rear = K - 1;
        cc = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        front = (front - 1 + K) % K;
        deq[front] = value;
        cc++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % K;
        deq[rear] = value;
        cc++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % K;
        cc--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        rear = (rear - 1 + K) % K;
        cc--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return deq[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return deq[rear];
    }

    bool isEmpty() {
        return cc == 0;
    }

    bool isFull() {
        return cc == K;
    }
};