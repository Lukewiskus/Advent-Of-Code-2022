#I used python for speed, got part 1 at 7878 and part two at 8235, try to be faster next time silly

def calcualteShape(player2):
    if(player2 == "X"):
        return 1
    if(player2 == "Y"):
        return 2
    if(player2 == "Z"):
        return 3

#A for rock
#B for paper
#C for scissors
#X for loss
#Y for draw
#Z for win

def findShapeReturnScore(player1, player2):
    if player1 == 'A' and player2 == 'X': #rock vs loss
        return 0 + 3
    elif player1 == 'A' and player2 == 'Y': #rock vs draw
        return 1 + 3 #draw plus 1 for rock
    elif player1 == 'A' and player2 == 'Z': #rock vs win
        return 2 + 6 #win plus 2 for paper
    elif player1 == 'B' and player2 == 'X': #rock
        return 1 + 0 
    elif player1 == 'B' and player2 == 'Y': #paper
        return 3 + 2 
    elif player1 == 'B' and player2 == 'Z': #scissors
        return 3 + 6 
    elif player1 == 'C' and player2 == 'X': #paper
        return 0 + 2 
    elif player1 == 'C' and player2 == 'Y': #scissors
        return 3 + 3 
    elif player1 == 'C' and player2 == 'Z': #rock
        return 6 + 1 

def calculateWin(player1, player2):
    if player1 == 'A' and player2 == 'X':
        return 3 #Tie
    elif player1 == 'A' and player2 == 'Y':
        return 6 #win 
    elif player1 == 'A' and player2 == 'Z':
        return 0 #lose
    elif player1 == 'B' and player2 == 'X':
        return 0 #loss
    elif player1 == 'B' and player2 == 'Y':
        return 3 #Tie
    elif player1 == 'B' and player2 == 'Z':
        return 6 #win
    elif player1 == 'C' and player2 == 'X':
        return 6 #Win
    elif player1 == 'C' and player2 == 'Y':
        return 0 #Loss
    elif player1 == 'C' and player2 == 'Z':
        return 3 #tie

sum = 0
file = open('./input.txt', 'r')
Lines = file.readlines()
sum = 0

for line in Lines:
    print("here")
    player1, player2 = line.split()
    sum += findShapeReturnScore(player1, player2)
    print(player1 + " " + " + player2 " + player2 )

print(sum)
