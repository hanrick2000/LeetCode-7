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
};