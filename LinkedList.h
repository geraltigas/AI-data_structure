//
// Created by 浆布 on 25/09/2021.
//

#ifndef AI_LINKEDLIST_H
#define AI_LINKEDLIST_H

template<typename T>
struct NodeFT {
    NodeFT<T> *front;
    T data;
    NodeFT<T> *back;

    NodeFT(T data, NodeFT<T> *front, NodeFT<T> *back);

    NodeFT(NodeFT<T> *front, NodeFT<T> *back);
};

template<typename T>
class LinkedList {
private:
    NodeFT<T> *nowAt;
    NodeFT<T> *blankNode;
    NodeFT<T> *head;
    NodeFT<T> *tail;
    unsigned int nowRank;
    unsigned int scale;

    NodeFT<T> *moveForward();

    NodeFT<T> *moveBackward();

public:
    LinkedList();
    ~LinkedList();
    NodeFT<T> *getNode(unsigned int rank);
    T getData(unsigned int rank);
    unsigned int getScale();
    bool isEmpty();
    NodeFT<T> *push(T data); //后入
    NodeFT<T> *enQueueR(T data); //后入
    NodeFT<T> *enQueueL(T data); //前入
    NodeFT<T> *insertAfter(int rank, T data);

    NodeFT<T> *insertBefore(int rank, T data);

    T pop();  // 后出
    T deQueue(); // 前出
    T popByRank(int rank); // 中出
    T operator[](int rank);
};

//--------

template<typename T>
T LinkedList<T>::operator[](int rank) {
    return getData(rank);
}

template<typename T>
NodeFT<T>::NodeFT(T data, NodeFT<T> *front, NodeFT<T> *back) {
    this->data = data;
    this->back = back;
    this->front = front;
}

template<typename T>
NodeFT<T>::NodeFT(NodeFT<T> *front, NodeFT<T> *back) {
    this->data = T();
    this->front = front;
    this->back = back;
}

template<typename T>
LinkedList<T>::LinkedList() {
    this->nowAt = new NodeFT<T>(nullptr, nullptr);
    this->nowRank = 0;
    this->scale = 0;
    this->blankNode = this->nowAt;
    this->head = this->nowAt;
    this->tail = this->nowAt;
};

template<typename T>
LinkedList<T>::~LinkedList<T>() {
    while (scale != 0){
        this->pop();
    }
    delete blankNode;
}

template<typename T>
NodeFT<T> *LinkedList<T>::push(T data) {
    if (scale == 0) {
        nowAt = new NodeFT<T>(data, blankNode, nullptr);
        blankNode->back = nowAt;
        head = nowAt;
        tail = nowAt;
        nowRank = 0;
        scale = 1;
    } else {
        tail->back = new NodeFT<T>(data, tail, nullptr);
        tail = tail->back;
        scale++;
    }
    return tail;
}

template<typename T>
NodeFT<T> *LinkedList<T>::enQueueR(T data) {
    return this->push(data);
}

template<typename T>
NodeFT<T> *LinkedList<T>::enQueueL(T data) {
    return this->insertBefore(data);
}

template<typename T>
NodeFT<T> *LinkedList<T>::moveForward() {
    if (nowAt->front != blankNode && scale != 0) {
        nowAt = nowAt->front;
        nowRank--;
        return nowAt;
    } else {
        return nowAt;
    }
}

template<typename T>
NodeFT<T> *LinkedList<T>::moveBackward() {
    if (scale != 0 && nowAt->back != nullptr) {
        nowAt = nowAt->back;
        nowRank++;
        return nowAt;
    } else {
        return nowAt;
    }
}

template<typename T>
NodeFT<T> *LinkedList<T>::insertAfter(int rank, T data) {
    if (rank < -1) {
        return nullptr;
    }
    if (rank == -1) {
        nowRank++;
        head = new NodeFT<T>(data, nullptr, head);
        blankNode->back = head;
        head->back->front = head;
        scale++;
        return head;
    } else if (scale == 0) {
        return nullptr;
    } else if (rank >= scale) {
        return nullptr;
    } else if (rank == scale - 1) {
        return this->push(data);
    } else {
        if (nowRank <= rank) {
            while (nowRank != rank) {
                moveBackward();
            }
        } else {
            while (nowRank != rank) {
                moveForward();
            }
        }
        scale++;
        nowAt->back = new NodeFT<T>(data, nowAt, nowAt->back);
        nowAt->back->back->front = nowAt->back;
        return nowAt->back;
    }
}

template<typename T>
NodeFT<T> *LinkedList<T>::insertBefore(int rank, T data) {
    if (rank <= -1) {
        return nullptr;
    } else {
        return insertAfter(rank + 1, data);
    }
}

template<typename T>
T LinkedList<T>::popByRank(int rank) {
    if (scale == 0 || rank < 0 || rank >= scale) {
        return T();
    } else if (rank == 0 && scale == 1) {
        nowAt = blankNode;
        nowRank = 0;
        scale = 0;
        tail = blankNode;
        head = blankNode;
        T data = head->back->data;
        delete head->back;
        head->back = nullptr;
        return data;
    } else if(rank == 0) {
        if(nowRank == 0){
            nowAt = nowAt->back;
            nowRank++;
        }
        scale--;
        nowRank--;
        head = head->back;
        T data = head->front->data;
        head->front = blankNode;
        delete blankNode->back;
        blankNode->back = head;
        return data;
    } else if (rank == scale - 1) {
        if (nowRank == rank){
            nowRank--;
            nowAt = nowAt->front;
        }
        scale--;
        tail = tail->front;
        T data = tail->back->data;
        delete tail->back;
        tail->back = nullptr;
        return data;
    } else {
        if (nowRank > rank){
            while (nowRank != rank+1){
                moveForward();
            }
        }else{
            while (nowRank != rank+1){
                moveBackward();
            }
        }
        scale--;
        nowRank--;
        NodeFT<T>* poin = nowAt->front;
        nowAt->front->front->back = nowAt;
        nowAt->front = nowAt->front->front;
        T data = poin->data;
        delete poin;
        return data;
    }
}

template<typename T>
T LinkedList<T>::deQueue() {
    return popByRank(0);
}

template<typename T>
T LinkedList<T>::pop() {
    return popByRank(scale-1);
}

template<typename T>
NodeFT<T>* LinkedList<T>::getNode(unsigned int rank){
    if (nowRank > rank){
        while (nowRank != rank){
            moveForward();
        }
    }else{
        while (nowRank != rank){
            moveBackward();
        }
    }
    return nowAt;
};

template<typename T>
T LinkedList<T>::getData(unsigned int rank) {
    return getNode(rank)->data;
}

template<typename T>
unsigned int LinkedList<T>::getScale() {
    return scale;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return (bool)scale;
}


#endif //AI_LINKEDLIST_H
