class Node:
    def __init__(self, val, nextv=None):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self, head):
        if head:
            self.head = Node(head[0])
            tmp = self.head
            for i in range(1, len(head)):
                tmp.next = Node(head[i])
                tmp = tmp.next
        else:
            self.head = None

def rev(node):
    if node.next is None:
        return node, node
    head, tail = rev(node.next)
    tail.next = node
    return head, node

def reverse(node):
    head, tail = rev(node)
    tail.next = None
    return head
        
llist = LinkedList([1,2,3,4])
llist = reverse(llist.head)
tmp = llist
while(tmp):
    print(tmp.val)
    tmp = tmp.next