number = raw_input() + "0I"

values = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}

total = 0;

for x in range(0, len(number)-2,2):
	if values[number[x+1]] >= values[number[x+3]]:
		total = total + int(number[x])*values[number[x+1]]
	else:
		total = total - int(number[x])*values[number[x+1]]
	
print total
