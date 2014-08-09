#Checks if all digits are unique
def unique(year):
	string = str(year)
	for i in string:
		if string.count(i) > 1:
			return False
	return True

#Open input file
File = open("s1.in",'r')

#Read the year
year = int(File.readline())

year = year + 1

#Increment year while it is not unique
while unique(year) == False:
	year = year + 1
print year
