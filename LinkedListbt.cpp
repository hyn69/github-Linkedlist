#include <iostream>
using namespace std;
struct NODE{
    int key;
    NODE* p_next;
};
struct List{
    NODE* p_head;
    NODE* p_tail;
};
NODE* createNode(int data) {
    NODE* p_node = new NODE;
    p_node -> key = data;
    p_node -> p_next = NULL; 
    return p_node;
}
void addHead(NODE* &pHead, int data) {
    NODE* p_cur = createNode(data);
    if (pHead == NULL) {
        pHead = p_cur;
    } else {
    p_cur -> p_next = pHead;
    pHead = p_cur;
    }
}
void erase1(NODE* &pHead) {
    //if (pHead == NULL) {
    //}
    NODE* temp = NULL;
    temp = pHead;
    pHead = pHead -> p_next;
    delete temp;
}
void eraseTail(NODE* &pHead) {
    if (pHead == NULL) {
        return;
    }
    NODE* temp = NULL;
    temp = pHead;
    while (temp -> p_next == NULL) {
        temp = temp -> p_next;
    }
    delete temp;
}
void eraseAll(NODE* &pHead) {
    NODE* temp = NULL;
    NODE* cur = pHead;
    temp = pHead;
    pHead = pHead -> p_next;
    delete temp;
    while (pHead != NULL) {
        temp = pHead;
        pHead = pHead -> p_next;
        delete temp;
    }
    //pHead = NULL;
    //delete temp;
    //delete cur;
}
void removeBefore(NODE* &pHead, int val) {
    NODE *prev = nullptr;
    NODE *after = pHead;
    val--;
    while (val--) {
        prev = after;
        after = after -> p_next;
    }
    prev -> p_next = after -> p_next;
    delete after;
    prev = nullptr;
    delete prev;
}
void removeAfter(NODE* &pHead, int val) {
    NODE* prev = pHead;
    NODE* after = pHead;
    while (val--) {
        prev = after;
        after = after -> p_next;
    }
    prev -> p_next = after -> p_next;
    delete after;
    prev = NULL;
    delete prev;
}
void addPos(NODE* &pHead, int data, int pos) {
    NODE* prev = pHead;
    NODE* after = pHead;
    pos--;
    while (pos--) {
        prev = after;
        after = after -> p_next;
    }
    NODE* p_add = new NODE;
    p_add -> key = data;
    prev -> p_next = p_add;
    p_add -> p_next = after;
}
void RemovePos(NODE* &pHead, int pos) {
    NODE* prev = pHead;
    NODE* after = pHead;
    while (pos--) {
        prev = after;
        after = after -> p_next;
    }
    prev -> p_next = after -> p_next;
    delete after;
    prev = NULL;
    delete prev;    
}
void addBefore(NODE* &pHead, int data, int val) {
    NODE* p_temp = pHead;
    NODE* p_prev = new NODE;
    while (p_temp -> key != val) {
        p_prev = p_temp;
        p_temp = p_temp -> p_next;
    }
    NODE* p_new = new NODE;
    p_new -> key = data;
    p_prev -> p_next = p_new;
    p_new -> p_next = p_temp;
}
void addAfter(NODE* &pHead, int data, int val) {
    NODE* p_add = pHead;
    NODE* p_after = nullptr;
    while (p_add -> key != val && p_add != NULL) {
        p_add = p_add -> p_next;
    }
    if (p_add -> key != val) {
        return;
    }
    p_after = p_add -> p_next;
    NODE* p_new = new NODE;
    p_new -> key = data;
    p_add -> p_next = p_new;
    p_new -> p_next = p_after;
}
void printList(NODE* &pHead) {
    NODE* p_temp = pHead;
    while (p_temp != NULL) {
        cout << p_temp -> key << ' ';
        p_temp = p_temp -> p_next;
    }
}
int countElements(NODE* &pHead) {
    NODE* p_temp = pHead;
    int count;
    while (p_temp != NULL) {
        count++;
    }
    return count;
}
 int countAppearance(NODE* &pHead, int value) {
    NODE *p_count = pHead;
    int count = 0;
    while (p_count != NULL) {
        if (p_count -> key == value) {
            count++;
        }
        p_count = p_count -> p_next;
    }
    return count;
}
NODE* reverseList(NODE* &pHead) {
    NODE* p_prev = NULL;
    NODE* p_temp = pHead;
    while (p_temp != NULL) {
        int data = p_temp -> key;
        addHead(p_prev, data);
        p_temp = p_temp -> p_next;
    }
    return p_prev;
}
int main() {
    int n;
    cout << "Input n: ";
    cin >> n;
    NODE* p_node = new NODE;
    int data;
    int temp = n;
    /*while (temp--) {
        cout << "Input data: ";
        cin >> data;
        addHead(p_node, data);
    }*/
    addHead(p_node, 1);
    cout << p_node -> key << endl;
    addHead(p_node, 2);
    cout << p_node -> key << endl;
    NODE* p_temp = reverseList(p_node);
   // cout << p_temp -> key;
    //addAfter(p_node, 10, 3);
    //n++;
    printList(p_temp -> p_next -> p_next);
    return 0;
}