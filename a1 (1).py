SIZE = 100

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class HashTableC:
    def __init__(self):
        self.ht = [Node(-1) for _ in range(SIZE)]
        
    def hashFunction(self, data):
        return data % SIZE
    
    def insert(self, data):
        index = self.hashFunction(data)
        if self.ht[index].data == -1:
            print("No collision occurred while inserting")
            self.ht[index].data = data
        else:
            print("Collision occurred while inserting!")
            node = self.ht[index]
            while node.next:
                node = node.next
            node.next = Node(data)
            
    def printHashTable(self):
        for i in range(SIZE):
            node = self.ht[i]
            while node:
                print(node.data, end=" -> ")
                node = node.next
            print("None")
    
    def search(self, data):
        index = self.hashFunction(data)
        node = self.ht[index]
        while node:
            if node.data == data:
                print("Phone Number found in the directory!")
                return
            node = node.next
        print("Phone Number not present in the directory!")

class HashTableLP:
    def __init__(self):
        self.ht = [-1] * SIZE
        
    def hashFunction(self, data):
        return data % SIZE
    
    def insert(self, data):
        index = self.hashFunction(data)
        if self.ht[index] == -1:
            print("No collision occurred while inserting")
            self.ht[index] = data
        else:
            print("Collision occurred while inserting")
            while True:
                index += 1
                if index == SIZE:
                    index = 0
                if self.ht[index] == -1:
                    self.ht[index] = data
                    return
                    
    def printHashTable(self):
        for data in self.ht:
            if data != -1:
                print(data)
    
    def search(self, data):
        index = self.hashFunction(data)
        if self.ht[index] == data:
            print("Phone Number found in the directory!")
            return
        temp = index
        while True:
            index += 1
            if index == SIZE:
                index = 0
            if index == temp:
                print("Phone Number not found in the directory!")
                break
            if self.ht[index] == data:
                print("Phone Number found in the directory!")
                return

method = int(input("Enter 1 for chaining method\nEnter 2 for linear probing method\n"))

if method == 1:
    ht = HashTableC()
elif method == 2:
    ht = HashTableLP()
else:
    print("Please enter a valid method!")

while True:
    choice = int(input("Enter 1 to insert a Phone Number in the directory\n"
                       "Enter 2 to search a Phone Number in the directory\n"
                       "Enter 3 to Print the directory\n"
                       "Enter 4 to quit\n"))
    if choice == 1:
        n = int(input("Enter the count of Phone Numbers to be inserted: "))
        for _ in range(n):
            x = int(input("Enter the Phone Number to be inserted: "))
            if len(str(x)) != 10:
                print("Please enter a valid number!")
            else:
                ht.insert(x)
    elif choice == 2:
        x = int(input("Enter the Phone Number to be searched in the directory: "))
        ht.search(x)
    elif choice == 3:
        ht.printHashTable()
    elif choice == 4:
        print("Thanks for trying out my code :)")
        break
    else:
        print("Please Enter a valid choice!")
