'''
Write a python program to store second year percentage of
students in array. Write function for sorting array of floating-
point numbers in ascending order using a) Insertion sort
b) Shell Sort and display top five scores
'''


class Sort:

    def __init__(self, lt, k):
        self.lt = lt
        self.k = k

    def Insertion(self):
        for i in range(1, self.k):
            t = self.lt[i]
            j = i - 1
            while ((j >= 0) and (t > self.lt[j])):
                self.lt[j + 1] = self.lt[j]
                j = j - 1
            self.lt[j + 1] = t
        print("The Top Five Scores Are:")
        for i in range(5):
            print(self.lt[i], "%")

    def Shell(self):
        g = self.k // 2
        while (g > 0):
            for i in range(g, self.k):
                t = lt[i]
                j = i
                while ((j >= g) and (t > self.lt[j - g])):
                    self.lt[j] = self.lt[j - g]
                    j -= g
                self.lt[j] = t
            g = g // 2
        print("The Top Five Scores Are:")
        for i in range(5):
            print(self.lt[i], "%")

    def MENU(self):
        print("\n*********MENU*********")
        print("1.Insertion Sort")
        print("2.Shell Sort")
        print("3.Exit")
        return int(input("Enter your Choice:"))


lt = []
k = int(input("Enter the Number of Students:"))
print("Enter the Percentages of Students")
for i in range(0, k):
    a = float(input())
    lt.append(a)

sObj = Sort(lt, k)

c = sObj.MENU()
while (True):
    if (c == 1):
        sObj.Insertion()
    elif (c == 2):
        sObj.Shell()
    elif (c == 3):
        break
    else:
        print("Wrong Choice")
    c = sObj.MENU()
print("\n!!THANK YOU!!")

