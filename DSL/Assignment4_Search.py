'''
a) Write a Python program to store roll numbers of student in 
array who attended training program in random order. Write 
function for searching whether particular student attended 
training program or not, using Linear search and Sentinel 
search.
b) Write a Python program to store roll numbers of student 
array who attended training program in sorted order. Write 
function for searching whether particular student attended 
training program or not, using Binary search and Fibonacci 
search.
'''

class Search:

    def __init__(self, lt, k, n):
        self.lt = lt
        self.k = k
        self.n = n

    def Linear(self):
        f = 0
        for i in range(0, self.k):
            if (self.lt[i] == self.n):
                t = i
                f = 1
        if (f == 1):
            print("\nElement", n, "is Present At Index", t)
        else:
            print("\nElement is Not Present in the List")

    def Sentinel(self):
        last = self.lt[self.k-1]
        self.lt[self.k-1] = self.n
        i = 0
        while (self.lt[i] != self.n):
            i = i+1
        self.lt[k-1] = last
        if ((i < self.k-1) or (self.lt[self.k-1] == self.n)):
            print("\nElement", n, "is Present At Index", i)
        else:
            print("\nElement is Not Present in the List")

    def Sort(self):
        for i in range(0, self.k-1):
            for j in range(self.k-1):
                if (self.lt[j] > self.lt[j+1]):
                    t = self.lt[j]
                    self.lt[j] = self.lt[j+1]
                    self.lt[j+1] = t
        print("\nSorted List of Roll Numbers")
        for i in range(0, self.k):
            print(self.lt[i], end=" ")
        print()
        return self.lt

    def Binary(self):
        sObj.Sort()
        f = 0
        l = 0
        h = (self.k-1)
        m = 0
        while (l <= h):
            m = (l+h)//2
            if (self.n > self.lt[m]):
                l = m+1
            elif (self.n < self.lt[m]):
                h = m-1
            else:
                print("\nElement", n, "is Present at Index", m)
                f = 1
                break
        if (f == 0):
            print("\nElement is Not Present in the List")

    def Fibonacci(self):
        sObj.Sort()
        f = 0
        a = 0
        b = 1
        c = a+b
        while (c < self.k):
            a = b
            b = c
            c = a+b
        os = -1
        while (c > 1):
            i = min(os+a, self.k-1)
            if (self.lt[i] < self.n):
                c = b
                b = a
                a = c-b
                os = i
            elif (self.lt[i] > self.n):
                c = a
                b = b-a
                a = c-b
            else:
                print("Element", n, "is Present at Index", i)
                f = 1
                break
        if (f == 0 and b != 0 and self.lt[os+1] == self.n):
            print("Element", n, "is Present at Index", os)
            exit
        if (f == 0):
            print("Element is Not Present in the List")

    def MENU(self):
        print("\n*********MENU*********")
        print("1.Linear Search")
        print("2.Sentinel Search")
        print("3.Binary Search")
        print("4.Fibonacci Search")
        print("5.Exit")
        return int(input("Enter your choice:"))


lt = []
k = int(input("Enter Number of Students who Attended Training Program:"))
print("Enter Roll Number of Students who Attended Training Program:")
for i in range(0, k):
    a = int(input())
    lt.append(a)
n = int(input("Enter Roll Number to be Searched For:"))

sObj = Search(lt, k, n)

c = sObj.MENU()
while (True):
    if (c == 1):
        sObj.Linear()
    elif (c == 2):
        sObj.Sentinel()
    elif (c == 3):
        sObj.Binary()
    elif (c == 4):
        sObj.Fibonacci()
    elif (c == 5):
        break
    else:
        print("Wrong Choice")
    c = sObj.MENU()
print("!!THANK YOU!!")
