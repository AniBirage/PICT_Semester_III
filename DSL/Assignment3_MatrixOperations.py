'''
Write a python program to compute following computation on 
matrix: 
 a) Addition of two matrices 
 b) Subtraction of two matrices 
 c) Multiplication of two matrices 
 d) Transpose of a matrix
 '''


class Matrix:

    def __init__(self, r1, c1, r2, c2):
        self.r1 = r1
        self.c1 = c1
        self.r2 = r2
        self.c2 = c2
        m1 = []
        print("Enter", (self.r1 * self.c1),
              "Elements for First Matrix(Press ENTER key after each Element)")
        for i in range(self.r1):
            a = []
            for j in range(self.c1):
                a.append(int(input()))
            m1.append(a)
            self.m3 = m1

        m2 = []
        print("Enter", (self.r2 * self.c2),
              "Elements for Second Matrix(Press ENTER key after each Element)")
        for i in range(self.r2):
            a = []
            for j in range(self.c2):
                a.append(int(input()))
            m2.append(a)
            self.m4 = m2

    def Addition(self):
        if ((self.r1 == self.r2) and (self.c1 == self.c2)):
            print("\nAddition of Matrices Is")
            for i in range(self.r1):
                for j in range(self.c1):
                    print((self.m3[i][j] + self.m4[i][j]), end="  ")
                print()

        else:
            print("\nAddition Not Possible")

    def Subtraction(self):
        if ((self.r1 == self.r2) and (self.c1 == self.c2)):
            print("\n*********SUBTRACTION*********")
            print("1.First Matrix-Second Matrix")
            print("2.Second Matrix-First Matrix")
            n = input("Enter Your Choice:")

            if (n == '1'):
                print("Subtraction of Matrices Is")
                for i in range(self.r1):
                    for j in range(self.c1):
                        print((self.m3[i][j] - self.m4[i][j]), end="  ")
                    print()

            elif (n == '2'):
                print("Subtraction of Matrices Is")
                for i in range(self.r1):
                    for j in range(self.c1):
                        print((self.m4[i][j] - self.m3[i][j]), end="  ")
                    print()

            else:
                print("Wrong Choice")

        else:
            print("\nSubtraction Not Possible")

    def Multiplication(self):
        if (self.c2 == self.r2):
            print("\n*********MULTIPLICATION*********")
            print("1.First Matrix×Second Matrix")
            print("2.Second Matrix×First Matrix")
            n = input("Enter Your Choice:")

            if (n == '1'):
                print("Multiplication of Matrices Is")
                for i in range(len(self.m3)):
                    for j in range(len(self.m4[0])):
                        s = 0
                        for k in range(len(self.m4)):
                            s = s + self.m3[i][k] * self.m4[k][j]
                        print(s, end="  ")
                    print()

            elif (n == '2'):
                print("Multiplication of Matrices Is")
                for i in range(len(self.m3)):
                    for j in range(len(self.m4[0])):
                        s = 0
                        for k in range(len(self.m4)):
                            s = s + self.m4[i][k] * self.m3[k][j]
                        print(s, end="  ")
                    print()

            else:
                print("Wrong Choice")

        else:
            print("\nMultiplication not Possible")

    def Transpose(self):
        print("\n*********TRANSPOSE*********")
        print("1.Transpose of First Matrix")
        print("2.Transpose of Second Matrix")
        n = input("Enter Your Choice:")

        if (n == '1'):
            print("Transpose of First Matrix")
            for j in range(self.c1):
                for i in range(self.r1):
                    print(self.m3[i][j], end="  ")
                print()

        elif (n == '2'):
            print("Transpose of Second Matrix")
            for j in range(self.c2):
                for i in range(self.r2):
                    print(self.m4[i][j], end="  ")
                print()

        else:
            print("Wrong Choice")

    def MENU(self):
        print("\n1.Addition of Matrices")
        print("2.Subtraction of Matrices")
        print("3.Multiplication of Matrices")
        print("4.Transpose of Matrices")
        print("5.Exit")
        return int(input("Enter your Choice:"))


print("For First Matrix")
r1 = int(input("Enter the Number of Rows:"))
c1 = int(input("Enter the Number of Columns:"))
print("For Second Matrix")
r2 = int(input("Enter the Number of Rows:"))
c2 = int(input("Enter the Number of Columns:"))
mObj = Matrix(r1, c1, r2, c2)

c = mObj.MENU()
while (True):
    if (c == 1):
        mObj.Addition()
    elif (c == 2):
        mObj.Subtraction()
    elif (c == 3):
        mObj.Multiplication()
    elif (c == 4):
        mObj.Transpose()
    elif (c == 5):
        break
    else:
        print("Wrong Choice")
    c = mObj.MENU()
print("!!THANK YOU!!")