//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

这题和clone graph很像，只不过允许不同节点值重复，由于还有随机指针，所以要拷贝这样一个linkelist，需要将给定的linked list里面的节点同新建的节点用hashtable 关联起来。按照next指针走，一个个链接。

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        
        RandomListNode* p = head, *newhead = new RandomListNode(p->label);
        unordered_map<RandomListNode*,RandomListNode*> mymap;
        
        mymap[head] = newhead;

        while(p) {
            RandomListNode* node = mymap[p];
            if(p->next) {
                RandomListNode* nextnode;
                if(mymap.find(p->next)!=mymap.end()) {
                    nextnode = mymap[p->next];
                }
                else {
                    nextnode = new RandomListNode(p->next->label);
                    mymap[p->next] = nextnode;
                }
                node->next = nextnode;
            }
        
            if(p->random) {
                RandomListNode* randomnode;
                if(mymap.find(p->random)!=mymap.end()) {
                    randomnode = mymap[p->random];
                }
                else {
                    randomnode = new RandomListNode(p->random->label);
                    mymap[p->random] = randomnode;
                }
                node->random = randomnode;
            }
            p = p->next;
            
        }
        
        return newhead;
    }
    
    这题额外O（1）空间只能这么做。分为三步：
       A->B->C   
    1) A->A'->B->B'->C->C' 克隆到后面
    2) A->A'->B->B'->C->C' 赋值随机指针
    3）把连边复原成A->B->C 和 A'->B'->C'
    
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(!head) return head;
        
        RandomListNode* p = head,*q;
        
        while(p) {
            RandomListNode* p_cpy = new RandomListNode(p->label);
            p_cpy->next = p->next;
            p->next = p_cpy;
            p = p_cpy->next;
        }
        
        p = head;
        
        while(p) {
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        } 
        
        p = head, q = head->next, head = q;
        
        while(q) {
            p->next = q->next;
            if(q->next) q->next = p->next->next;
            
            p = p->next;
            q = q->next;
        }
        
        return head;
    }
};