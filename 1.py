
def word_list(s):
    word = ''
    words = []
    for i in range(len(s)):
        if s[i] != ' ':
            word += s[i]
        else:
            words.append(word)
            word = ''
    words.append(word)
    return words


def length(s):
    count = 0
    for i in range(len(s)):
        if s[i] != ' ':
            count += 1

    return count


def long(s):
    l = word_list(s)
    max = (l[0])
    for i in range(1, len(l)):
        if (length(l[i]) > length(max)):
            max = l[i]

    return max


def split_char(s):
    char = []
    for i in range(len(s)):
        char.append(s[i])

    return char


def freq(s, a):
    count = 0
    # char_list = split_char(s)
    for i in range(len(s)):
        if (s[i] == a):
            count += 1

    return count


def occ_word(s, a):
    count = 0
    words = word_list(s)
    for i in range(len(words)):
        if (words[i] == a):
            count += 1

    return count

def palindrome(s):
    k = 0
    j = len(s)-1
    for i in range(int(len(s)/2)):
        if s[k]==s[j]:
            k += 1
            j -= 1
        else:
            return "not a palindrome"

        return "palindrome"

def substr(s,word):
    for i in range(len(s)):
        if s[i:i+length(word)] == word:
            return i

class string_operation:

    def __init__(self,a):
        a = int(input("Which operation do you want to calculate\n 1. Longest word of string\n 2. Frequency of "
                      "character of string\n 3. Occurrence of word in string\n"
                      "4. To check if string is palindrome or not\n  5. To find first index of occurrence of string\n"))
        self.a = a

    def find(self):
        if self.a == 1:
            print("Longest word in the string is: ", (long(s)))

        elif self.a == 2 :
            print("Frequency of char", c, "is: ", (freq(s, c)))

        elif self.a == 3:
            print("Frequency of ", word, "is: ", (occ_word(s, word)))

        elif self.a == 4:
            print(s, "is a", palindrome(s))

        elif self.a == 5:
            print("Index of", string, "int the string is: ", substr(s, string))

        else:
            print("Invalid input given")


s = str(input("Enter your string:"))
c = str(input("Enter character to find occurrences of it in the string: "))
word = str(input("Enter the word to find occurrences of it in the string: "))
string = str(input("Enter the string to find occurrences of it in the string: "))

op = int
operation = string_operation(op)
operation.find()

