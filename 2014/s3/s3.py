#Open input file
File = open("s3.in",'r')

#Read the number of tests to be run
T = int(File.readline())

#Run the number of tests
for i in range(T):

	#Read the number of carts in the test
	N = int(File.readline())

	#List containing the carts
	carts = []
	for j in range(N):
		carts.append(int(File.readline()))
	#List containing carts on branch
	branch = [0]
	#List containing carts at lake
	lake = [0]

	#The state flag
	state = "Y"

	#Run the test while the state is "Y" and all the carts haven't arrived at the lake
	while state == "Y" and lake[len(lake)-1] < N:
		if not len(carts) == 0 and carts[len(carts)-1] == lake[len(lake)-1] + 1:
			lake.append(carts.pop())
		elif branch[len(branch)-1] == lake[len(lake)-1] + 1:
			lake.append(branch.pop())
		elif not len(carts) == 0:
			branch.append(carts.pop())
		else:
			state = "N"
	print state
