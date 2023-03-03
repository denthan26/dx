#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode();
        ListNode* ptr = newList;
        int carry = 0;
        if (l1 == NULL || l2 == NULL) {
            if (l1 != NULL) {
                return l1;
            }
            else if (l2 != NULL) {
                return l2;
            }
            else {
                return NULL;
            }
        }
        if (l1->val == 0 || l2->val == 0) {
            if (l1->val != 0) {
                return l1;
            }
            else if (l2->val != 0) {
                return l2;
            }
            else {
                ListNode* s = new ListNode();
                s->val = 0;
                ptr->next = s;
                return newList->next;
            }
        }
        // ��������������
        while (l1 != NULL && l2 != NULL) {
            int x = l1->val;//l1��ֵ
            int y = l2->val;//l2��ֵ
            int sum = carry + x + y;//��ǰ��λ����ֵ

            if (sum / 10) {
                // ���sum/10����0��˵��sum��ֵС��10������ֱ�Ӳ���list
                // ���sum/10��=0��˵��sum����10����Ҫ��λ
                // sum����10�����
                ListNode* s = new ListNode();
                s->val = sum % 10;
                s->next = NULL;
                ptr->next = s;
                ptr = s;
                l1 = l1->next;
                l2 = l2->next;
                carry = sum / 10;
            }
            else {
                // sum<10
                ListNode* s = new ListNode();
                s->val = sum;
                s->next = NULL;
                ptr->next = s;
                ptr = s;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        //��һ����� l1 l2��û����
        //�ڶ������ l1���л���l2����
        if (l1 == NULL && l2 == NULL) {
            if (carry) {
                //carry = 1;
                ListNode* s = new ListNode();
                s->val = carry;
                s->next = NULL;
                ptr->next = s;
                return newList->next;
            }
            else {
                return newList->next;
            }
        }
        if (l1 != NULL) {
            while (l1 != NULL) {
                int x = l1->val;//l1��ֵ
                int sum = carry + x;//��ǰ��λ����ֵ

                if (sum / 10) {
                    ListNode* s = new ListNode();
                    s->val = sum % 10;
                    s->next = NULL;
                    ptr->next = s;
                    ptr = s;
                    l1 = l1->next;
                    carry = sum / 10;
                }
                else {
                    // sum<10
                    ListNode* s = new ListNode();
                    s->val = sum;
                    s->next = NULL;
                    ptr->next = s;
                    ptr = s;
                    l1 = l1->next;
                }
            }
            return newList->next;
        }
        if (l2 != NULL) {
            while (l2 != NULL) {
                int x = l2->val;//l1��ֵ
                int sum = carry + x;//��ǰ��λ����ֵ

                if (sum / 10) {
                    ListNode* s = new ListNode();
                    s->val = sum % 10;
                    s->next = NULL;
                    ptr->next = s;
                    ptr = s;
                    l1 = l1->next;
                    carry = sum / 10;
                }
                else {
                    // sum<10
                    ListNode* s = new ListNode();
                    s->val = sum;
                    s->next = NULL;
                    ptr->next = s;
                    ptr = s;
                    l1 = l1->next;
                }
            }
            return newList->next;
        }
        return NULL;
    }
};

int main() {
    return 0;
}