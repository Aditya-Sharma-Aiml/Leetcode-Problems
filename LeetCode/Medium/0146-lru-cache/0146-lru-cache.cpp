class LRUCache {
public:
    class Node{

        public :

        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
        }  
    };

    int cap;
    unordered_map<int, Node*>mpp;
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);


    LRUCache(int capacity) {

        cap = capacity;
        head->next = tail;
        tail->prev = head;

    }

    void addNode(Node* newNode){

        Node* temp = head -> next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode){

        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;

    }
    
    int get(int key) {

        if(mpp.find(key) != mpp.end()){

            Node* res = mpp[key];

            mpp.erase(key);

            deleteNode(res);
            addNode(res);

            mpp[key] = head->next;

            return res->val;


        }
        return -1;
        
    }
    
    void put(int key, int val) {


        if(mpp.find(key) != mpp.end()){

            Node* existNode = mpp[key];

            mpp.erase(key);

            deleteNode(existNode);

            
        }
        
        if(cap == mpp.size()){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, val));
        mpp[key] = head->next;


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */