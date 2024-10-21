
n1 = int(input("Enter number of elements in football: "))
n2 = int(input("Enter number of elements in cricket: "))
n3 = int(input("Enter number of elements in badminton: "))

football = []
for i in range(n1):
    foot = input(f"Enter football element {i + 1}:")
    football.append(foot)

cricket = []
for i in range(n2):
    crick = input(f"Enter cricket element {i + 1}:")
    cricket.append(crick)

badminton = []
for i in range(n3):
    badm = input(f"Enter badminton element {i + 1}:")
    badminton.append(badm)


def union(a, b):
    union1 = []
    for i in range(len(a)):
        union1.append(a[i])

    for i in range(len(b)):
        count = 0
        for j in range(len(a)):
            if a[j] == b[i]:
                count = 1

        if count == 0:
            union1.append(b[i])

    return union1


def diff(c, b):
    difference = []

    for i in range(len(c)):
        difference.append(c[i])

    for i in range(len(b)):
        count = 0
        for j in range(len(c)):

            if c[j] == b[i]:
                count = 1
                difference.remove(b[i])

        # if count == 0:
        #     difference = difference


    return difference


def inter(a, b):
    intersection = []

    for i in range(len(a)):
        count = 0
        for j in range(len(b)):
            if b[j] == a[i]:
                count = 1

        if count == 1:
            intersection.append(a[i])

    return intersection

print(inter(football,cricket))
def list_op(c,b):
    list1 = inter(c,b)
    list2 = union(c,b)
    list3 = diff(list2,list1)

    return list3

def number1(a,b,c):
    list1 = union(b,c)
    list2 = diff(a,list1)

    count = 0
    for i in range(len(list2)):
        count += 1

    return count

def number2(a,b,c):

    list1 = union(a,b)
    list2 = diff(list1,c)

    count = 0
    for i in range(len(list2)):
        count += 1

    return count


print("List of students who play both cricket and  badminton is: ", union(cricket, badminton))
print("List of students who play cricket or badminton but not both is: ", list_op(cricket, badminton))
print("Number of students who play neither cricket nor badminton is: ", number1(football, cricket, badminton))
print("Number of students who play cricket and football but not badminton is: ", number2(cricket, football, badminton))

