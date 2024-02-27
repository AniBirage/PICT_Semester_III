'''
Write a python program to store first year percentage of 
students in array. Write function for sorting array of floating 
point numbers in ascending order using quick sort and 
display top five scores.
'''


class QSort:

    def Partition(self, lt, l, h):
        i = (l - 1)
        pvt = lt[h]
        for j in range(l, h):
            if (lt[j] > pvt):
                i = i + 1
                lt[i], lt[j] = lt[j], lt[i]
        lt[i + 1], lt[h] = lt[h], lt[i + 1]
        return (i + 1)

    def Quick(self, lt, l, h):
        if (l < h):
            p = sObj.Partition(lt, l, h)
            sObj.Quick(lt, l, p - 1)
            sObj.Quick(lt, p + 1, h)


lt = []
k = int(input("Enter the Number of Students:"))
print("Enter the Percentage of Students")
for i in range(k):
    a = float(input())
    lt.append(a)

sObj = QSort()
sObj.Quick(lt, 0, (k - 1))
print("The Top Five Scores Are:")
for i in range(5):
    print(lt[i], "%")

