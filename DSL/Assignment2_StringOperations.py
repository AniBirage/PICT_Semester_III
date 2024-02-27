'''
Write a Python program to compute following operations on
String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular
character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
(Do not use string built-in functions)
'''


class Strings:

    def __init__(self, st):
        self.st = st

    def Longest(self):
        self.st = self.st + " "
        longw = ""
        w = ""
        lon = 0
        for i in self.st:
            if i != ' ':
                w = w + i
            else:
                l1 = len(w)
                if l1 > lon:
                    longw = w
                w = ""
        print("Longest Word:" + longw)

    def count(self, c):
        cc = 0
        for i in self.st:
            if (i == c):
                cc += 1
        return cc

    def Palindrome(self):
        sr = ""
        for i in self.st:
            sr = i + sr
        if sr == self.st:
            print("The Entered String is Palindrome")
        else:
            print("The Entered String is not Palindrome")

    def Index(self, ss):
        l1 = len(self.st)
        l2 = len(ss)
        for i in range(l1 - l2 + 1):
            if st[i:i + l2] == ss:
                return i

    def Word(self):
        s1 = " " + st + " "
        lt = []
        n = 0
        l = len(s1)
        for i in range(l):
            if (i != 0 and s1[i] == " "):
                lt.append(s1[n + 1:i])
                n = i
        for i in set(lt):
            print(i, "\t\t\t", lt.count(i))

    def MENU(self):
        print("***************************MENU***************************")
        print("1.To Diplay word with Longest Length")
        print("2.To Determine the Frequency of Occurence of Particular Character in String")
        print("3.To Check whether given String is Palindrome or Not")
        print("4.To Display the Index of First Appearance of the Substring")
        print("5.To Count the Occurence of Each Word in the String")
        print("6.Exit")
        return int(input("Enter your Choice:"))


st = input("Enter a String:")
sObj = Strings(st)

ch = sObj.MENU()
while (True):
    if ch == 1:
        sObj.Longest()

    elif ch == 2:
        c = input("Enter a Character:")
        print("Character", c, "is present", sObj.count(c), "Times")

    elif ch == 3:
        sObj.Palindrome()

    elif ch == 4:
        subs = input("Enter a Substring:")
        print("First Appearance of", subs, "is at Index", sObj.Index(subs))

    elif ch == 5:
        print("Word\t\t\tFrequency")
        sObj.Word()

    elif ch == 6:
        break

    else:
        print("Wrong Choice")
    ch = sObj.MENU()
print("!!THANK YOU!!")

