/*
描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）。 下图是一个含有5个结点的复杂链表。图中实线箭头表示next指针，虚线箭头表示random指针。为简单起见，指向null的指针没有画出。
示例:
输入:{1,2,3,4,5,3,5,#,2,#}
输出:{1,2,3,4,5,3,5,#,2,#}
解析:我们将链表分为两段，前半部分{1,2,3,4,5}为ListNode，后半部分{3,5,#,2,#}是随机指针域表示。
以上示例前半部分可以表示链表为的ListNode:1->2->3->4->5
后半部分，3，5，#，2，#分别的表示为
1的位置指向3，2的位置指向5，3的位置指向null，4的位置指向2，5的位置指向null
如下图:

示例1
输入：
{1,2,3,4,5,3,5,#,2,#}
复制
返回值：
{1,2,3,4,5,3,5,#,2,#}
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead) return pHead;    // 为空则直接返回空
        unordered_map<RandomListNode*, RandomListNode*> mp;    // 创建哈希表
 
        RandomListNode* dummy = new RandomListNode(0);    // 哨兵节点
 
        RandomListNode *pre = dummy, *cur = pHead;    // 指向哨兵和链表头的指针
 
        while(cur){
            RandomListNode* clone = new RandomListNode(cur->label);    // 拷贝节点
            pre->next = clone;    // 与上个结点连接
            mp[cur] = clone;    // 记录映射关系
            pre = pre->next;    // 指针移动
            cur = cur->next;
        }
 
        for(auto& [key, value] : mp){    // 遍历哈希表
            value->random = key->random == NULL ? NULL : mp[key->random];
        }
 
        delete dummy;    // 释放哨兵节点空间
        return mp[pHead];
    }
};
