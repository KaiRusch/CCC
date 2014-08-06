# The Reading Class
class Reading:
	def __init__(self, r, f):
		self.reading = r
		self.frequency = f

#Initialize the frequencies list
F = []
for i in range(1001):
	F.append(Reading(i,0))

#Gets the number of sensors
N = input()

#Read input and increase frequency of read input
for i in range(N):
	F[input()].frequency += 1

#Sort the frequencies list 
for i in range(1, 1001):
	current = F[i]
	j = i - 1
	while j >= 0 and (F[j].frequency < current.frequency or (F[j].frequency == current.frequency and F[j].reading < current.reading)):
		F[j+1] = F[j]
		j = j-1
	F[j+1] = current

#Check for multiple same frequency readings
high = F[0].frequency == F[2].frequency
secondHigh = F[0].frequency != F[1].frequency and F[1].frequency == F[2].frequency

if high:
	i = 1
	while i < 1001 and F[0].frequency == F[i].frequency:
		i = i+1
	print abs(F[0].reading - F[i-1].reading)
elif secondHigh:
	i = 3
	m = abs(F[0].reading - F[1].reading)
	while i < 1001 and F[1].frequency == F[i].frequency:
		m = max(m, abs(F[0].reading - F[i].reading))
		i = i + 1 
	print m
else:
	print abs(F[0].reading - F[1].reading)
		

