Can't create, edit, or upload … Not enough storage. Get 100 GB of storage for ₹130.00 ₹35.00/month for 2 months.
# Write a Python program to store roll numbers of student in array who attended
# training program in random order. Write function for searching whether particular
# student attended training program or not, using Linear search and Sentinel search.


# Using Linear Search
def lin(a, num, target):
    for i in range(num):
        if a[i] == target:
            return f"Student is present at {i}"

    return "Student is not present in the training program"


# Using Sentinel Search method
def sen(a, num, target):
    last = target
    a.append(last)

    j = 0

    while a[j] != target:
        j += 1

    if j < num:
        return f"Student is present at {j}"
    else:
        return "Student is not present in the training program"


# Write a Python program to store roll numbers of student array who attended training
# program in sorted order. Write function for searching whether particular student
# attended training program or not, using Binary search and Fibonacci search


# Using Binary Search , using iteration
def biniter(a, m, target):
    i = 0
    j = m - 1
    while (i <= j):
        mid = int((i + j) / 2)
        if a[mid] == target:
            return f"Student is present at {mid}"
        elif a[mid] < target:
            i = mid + 1
        else:
            j = mid - 1
    return "Student is not present in the training program"


# Using Binary Search , using recursion
def binrec(a, i, j, target):
    if i != j:
        if a[j] == target:
            return f"Student is present at {j}"

        else:
            mid = int((i + j) / 2)
            if a[mid] == target:
                return f"Student is present at {mid}"

            elif a[mid] < target:
                binrec(a, mid + 1, j, target)

            elif a[mid] > target:
                binrec(a, i, mid - 1, target)

        return "Student is not present in the training program"


def fibo(a, m, target):
    fib1 = 1
    fib2 = 0
    fib = fib1 + fib2

    while fib < m:
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2
    offset = -1

    while fib >1:

        i = min(offset+1, m-1)

        if a[i]<target:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i

        elif a[i] == target:
            return f"Student is present at {i}"

        else:
            fib = fib2
            fib1 -= fib2
            fib2 = fib - fib1

    if a[offset + 1] == target:
        return f"Student is present at {offset + 1}"

    return "Student is not present in training program"


class Search:
    def __init__(self, a, students, key, n):
        students = []
        self.students = students

        n = int(input("Enter number of students : "))
        self.n = n

        key = int(input("Enter student to be searched: "))
        self.key = key

        a = int(input(
            "Enter the feature you want to find:\n 1.Linear Search\n 2. Sentinel Search\n 3. Binary Search("
            "iterative)\n 4. Binary Search(Recursion)\n 5. Fibonacci search\n"))
        self.a = a

    def sortornot(self):
        if self.a == 1 or self.a == 2:
            for i in range(self.n):
                i = int(input(f"Student in random order {i + 1}: "))
                self.students.append(i)
        elif self.a == 3 or self.a == 4 or self.a == 5:
            for i in range(self.n):
                i = int(input(f"Student in sorted order {i + 1}: "))
                self.students.append(i)
        else:
            print("You have entered invalid number")

    def find(self):
            if self.a == 1:
                print(lin(self.students, self.n, self.key))
            elif self.a == 2:
                print(sen(self.students, self.n, self.key))
            elif self.a == 3:
                print(biniter(self.students, self.n, self.key))
            elif self.a == 4:
                print(binrec(self.students, 0, self.n - 1, self.key))
            elif self.a == 5:
                print(fibo(self.students, self.n, self.key))
            else:
                print("You have entered invalid number")


op = int
n = int
stud= []
key = int
search = Search(op,stud,key,n)
search.sortornot()
search.find()
