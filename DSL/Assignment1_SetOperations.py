'''
In second year computer engineering class, group A student’s play cricket, group B students
play badminton and group C students play football. Write a Python program using functions
to compute following: - a) List of students who play both cricket and badminton b) List of
students who play either cricket or badminton but not both c) Number of students who play
neither cricket nor badminton d) Number of students who play cricket and football but not
badminton. (Note- While realizing the group, duplicate entries should be avoided, Do not
use SET built-in functions)
'''


def I(l1, l2):
    l3 = []
    for v in l1:
        if v in l2:
            l3.append(v)
    return l3


def U(l1, l2):
    l3 = l1.copy()
    for v in l2:
        if v not in l3:
            l3.append(v)
    return l3


def D(l1, l2):
    l3 = []
    for v in l1:
        if v not in l2:
            l3.append(v)
    return l3


def sD(l1, l2):
    l3 = []
    D1 = D(l1, l2)
    D2 = D(l2, l1)
    l3 = U(D1, D2)
    return l3


def CB(l1, l2):
    l3 = I(l1, l2)
    print("List of students who play both Cricket and Badminton is:", l3)


def eCB(l1, l2):
    l3 = sD(l1, l2)
    print("List of students who play either Cricket or Badminton but not both is:", l3)


def nCB(l1, l2, l3):
    l4 = D(l1, U(l2, l3))
    return len(l4)


def CBF(l1, l2, l3):
    l4 = D(I(l1, l2), l3)
    return len(l4)


CompClass = []
a = int(input("Enter Number of Students in COMP Class:"))
print("Enter the Names of", a, "Students(Press ENTER key after Each Students Name):")
for i in range(0, a):
    e = input()
    CompClass.append(e)
print("All Students in Comp Class:" + str(CompClass))

fg = 1
while fg == 1:
    Cricket = []
    c = int(input("Enter Number of Students who Play Cricket:"))
    print("Enter the Names of", c,
          "Students who Play Cricket(Press ENTER key after Each Students Name):")
    for i in range(0, c):
        ec = input()
        Cricket.append(ec)
    lt = []
    for i in Cricket:
        if i not in lt:
            lt.append(i)
    if Cricket != lt:
        fg = 1
    else:
        fg = 0
print("Students who Play Cricket are:" + str(Cricket))

fg = 1
while fg == 1:
    Badminton = []
    b = int(input("Enter Number of Students who Play Badminton:"))
    print("Enter the Names of", b,
          "Students who Play Badminton (Press ENTER key after Each Students Name):")
    for i in range(0, b):
        eb = input()
        Badminton.append(eb)
    lt = []
    for i in Badminton:
        if i not in lt:
            lt.append(i)
    if Badminton != lt:
        fg = 1
    else:
        fg = 0
    print("Students who Play Badminton are:" + str(Badminton))

fg = 1
while fg == 1:
    Football = []
    f = int(input("Enter Number of Students who Play Football:"))
    print("Enter the Names of", f,
          "Students who Play Football(Press ENTER key after Each Students Name):")
    for i in range(0, f):
        ef = input()
        Football.append(ef)
    lt = []
    for i in Football:
        if i not in lt:
            lt.append(i)
    if Football != lt:
        fg = 1
    else:
        fg = 0
print("Students who Play Football are:" + str(Football))

f = 1
while f == 1:
    print("***************************MENU***************************")
    print("1.List of Students who play both Cricket and Badminton")
    print("2.List of Students who play either Cricket or Badminton but not both")
    print("3.Number of Students who play neither Cricket nor Badminton")
    print("4.Number of Students who play Cricket and Football but not Badminton")
    print("5.Exit")
    n = int(input("Enter your Choice:"))

    if n == 1:
        CB(Cricket, Badminton)
        ch = input("\nDo you want to continue(Y/N):")
        if ch == "Y":
            f = 1
        else:
            f = 0
            print("\n!!Thank You!!")

    elif n == 2:
        eCB(Cricket, Badminton)
        ch = input("Do you want to continue(Y/N):")
        if ch == "Y":
            f = 1
        else:
            f = 0
            print("\n!!Thank You!!")

    elif n == 3:
        print("\nNumber of Students who play neither Cricket nor Badminton:", nCB(
            CompClass, Cricket, Badminton))
        ch = input("Do you want to continue(Y/N):")
        if ch == "Y":
            f = 1
        else:
            f = 0
            print("\n!!Thank You!!")

    elif n == 4:
        print("\nNumber of students who play cricket and football but not badminton:", CBF(
            Cricket, Football, Badminton))
        ch = input("Do you want to continue(Y/N):")
        if ch == "Y":
            f = 1
        else:
            f = 0
            print("\n!!Thank You!!")

    elif n == 5:
        f = 0
        print("\n!!Thank You!!")

    else:
        print("\nWrong Choice")
        ch = input("Do you want to continue(Y/N):")
        if ch == "Y":
            f = 1
        else:
            f = 0
            print("\n!!Thank You!!")
