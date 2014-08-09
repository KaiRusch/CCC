#Count the points for each team
def count_points(winners):

	global T
	global WINS

	#Each teams points
	points = [0,0,0,0]

	if winners[0] == "W":
		points[0] = points[0] + 3
	elif winners[0] == "L":
		points[1] = points[1] + 3
	else:
		points[0] = points[0] + 1
		points[1] = points[1] + 1

	if winners[1] == "W":
		points[0] = points[0] + 3
	elif winners[1] == "L":
		points[2] = points[2] + 3
	else:
		points[0] = points[0] + 1
		points[2] = points[2] + 1

	if winners[2] == "W":
		points[0] = points[0] + 3
	elif winners[2] == "L":
		points[3] = points[3] + 3
	else:
		points[0] = points[0] + 1
		points[3] = points[3] + 1

	if winners[3] == "W":
		points[1] = points[1] + 3
	elif winners[3] == "L":
		points[2] = points[2] + 3
	else:
		points[1] = points[1] + 1
		points[2] = points[2] + 1

	if winners[4] == "W":
		points[1] = points[1] + 3
	elif winners[4] == "L":
		points[3] = points[3] + 3
	else:
		points[1] = points[1] + 1
		points[3] = points[3] + 1

	if winners[5] == "W":
		points[2] = points[2] + 3
	elif winners[5] == "L":
		points[3] = points[3] + 3
	else:
		points[2] = points[2] + 1
		points[3] = points[3] + 1

	print points
	if points[T-1] == max(points) and points.count(points[T-1]) == 1:
		WINS = WINS + 1


#Open the input file
File = open("s3.in",'r')

#Read the favorite team
T = int(File.readline())

#The number of times the favorite team could win the tournament
WINS = 0

#Read the number of games already played
G = int(File.readline())

#String containing the winners of all the games
winners = "------"
#2D list containing all possible games
games = [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

for i in range(G):
	line = File.readline().split()
	#Read the teams
	A = int(line[0])
	B = int(line[1])
	#Read the scores
	sA = int(line[2])
	sB = int(line[3])

	if sA > sB:
		result = "W"
	elif sA < sB:
		result = "L"
	else:
		result = "T"
	for i in range(6):
		if A == games[i][0] and B == games[i][1]:
			winners = winners[:i] + result + winners[i+1:]

count_points("WLTLLW")
	
