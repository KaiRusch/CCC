#Open input file
File = open("s2.in",'r')

#Read max weight
W = int(File.readline())

#Read number of carts
N = int(File.readline())

#List containing cart weights
carts = [0,0,0]

#Read cart weights
for i in range(N):
	carts.append(int(File.readline()))

#The number of carts which have crossed
C = 0

while carts[C] + carts[C+1] + carts[C+2] + carts[C+3] <= W and C <= N - 2:
	C = C+1
print C
