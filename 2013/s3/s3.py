def playAllGames(g):
	i = 0
	while g[i] > 0:
		i = i + 1
	gameWin 


#Open the input file
File = open("s3.in",'r')

#Read the favorite team
T = int(File.readline())

#Read the number of games already played
G = int(File.readline())

convert = {[1,2]:0,[1,3]:1,[1,4]:2,[2,3]:3,[2,4]:4,[3,4]:5}

#2D List containing the winner of each game
games = [-1,-1,-1,-1,-1,-1]

for i in range(G):
	line = File.readline().split()
	#Read the teams
	A = int(line[0])
	B = int(line[1])
	#Read the scores
	sA = int(line[2])
	sB = int(line[3])


	if sA >  sB:
		games[convert[[A,B]]] = A
	elif sA < sB:
		games[convert[[A,B]]] = B
	else:
		games[convert[[A,B]]] = 0
