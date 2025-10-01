#include<iostream>
using namespace std;
 ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; 
            } else {
                
                current = current->next;
            }
        }
        
        return head;
    }
int main() {

   
    return 0;
};