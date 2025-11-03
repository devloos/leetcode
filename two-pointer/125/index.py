# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Need to grab length of list
        Split List
        Reverse second half
        Merge into first list
        """

        size = 0
        curr = head

        while curr:
            size += 1
            curr = curr.next

        l1 = head
        l2 = None
        i = size // 2

        curr = head
        while curr and i > 0:
            i -= 1

            if i <= 0:
                l2 = curr.next
                curr.next = None
                continue

            curr = curr.next

        prev = None
        curr = l2

        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp

        l2 = prev

        curr = l1
        prev = None
        while curr and l2:
            iso = l2
            l2 = l2.next

            tmp = curr.next
            curr.next = iso
            iso.next = tmp

            prev = iso
            curr = tmp

        if l2:
            prev.next = l2
