# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, node = None):
        self.val = x
        self.next = node

def addTwoNumbers(l1, l2):
    tl1 = l1
    tl2 = l2
    res = ListNode(-1)
    carry = 0
    tres = res
    while(tl1 or tl2 or carry > 0):
        l1val = tl1.val if tl1 else 0
        l2val = tl2.val if tl2 else 0
        adds = l1val + l2val + carry
        cur = adds % 10
        tres.next = ListNode(cur)
        tres = tres.next
        carry = adds // 10
        if tl1:
            tl1 = tl1.next
        if tl2:
            tl2 = tl2.next
    return res.next
    
    
    
if __name__ == "__main__": 
    list1 = ListNode(2, ListNode(4, ListNode(6)))
    list2 = ListNode(5, ListNode(6, ListNode(4)))
    resNode = addTwoNumbers(list1, list2)
    while(resNode):
        print(resNode.val)
        resNode = resNode.next