from datetime import datetime

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.s = {}
        self.size = 0


    def get(self, key: int) -> int:
        if key in self.s:
            val = self.s[key][0]
            self.s[key] = (val, datetime.now())
            return val
        
        return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.s:
            self.s[key] = (value, datetime.now())
            return

        if self.size == self.cap:
            min_key = None
            min_ts = datetime.now()
            
            for l_key, tup in self.s.items():
                if tup[1] <= min_ts:
                    min_key = l_key
                    min_ts = tup[1]
            
            del self.s[min_key]

            self.size -= 1

        self.s[key] = (value, datetime.now())
        self.size += 1
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)