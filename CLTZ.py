def collatz(n):
    i = 1
    while n!=1:
        i = i+1
        if n%2==0:
            n = n/2
        else:
            n = 3*n+1
    return i;

def main():
    while 1:
        try:
            n = input()
        except:
            break
        print collatz(n)

main()
