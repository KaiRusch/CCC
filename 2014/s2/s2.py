#Open file
File = open("s2.in",'r')

#Read the number of students
N = int(File.readline())

#Read the group of students
first = File.readline().split()
second = File.readline().split()

state = "good"
i = 0
#Iterate through names unless state becomes "bad"
while state == "good" and i <= len(first)-1:
	#Find the index in the first list of i's partner
	x = second.index(first[i])
	#Check that i is x's partner and vice versa
	#Check that students are not assigned to themselves
	if (not(first[i] == second[x] and second[i] == first[x])) or (first[i] == second[i]):
		#Throw "bad" flag
		state = "bad"
	i = i +1
print state






