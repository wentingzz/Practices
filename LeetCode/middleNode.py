# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        tmp = head
        middle = head
        while(tmp.next):
            tmp = tmp.next
            middle = middle.next
            if tmp.next:
                tmp = tmp.next
            else:
                break
        return middle
#        slow = fast = head
#        while fast and fast.next:
#            slow = slow.next
#            fast = fast.next.next
#        return slow