# Author: Unknown
# Steps to run (make sure the 8queens.json file is in the same directory as the code) ->
# :~$ python yoyo.py

import json
inf=open("8queens.json")
board=json.loads(inf.read())
board=board["matrix"]
for i in board:
	print(i)

def issafe(row,col):
	for i in range(8):
		for j in range(8):
			if(board[i][j]==1): #if a queen exists here, then check if it attacks our queen
				if(row==i):
					return False
				if(col==j):
					return False
				if(abs(row-i)==abs(col-j)):
					return False
	return True

def place(col):
	if(col>=8):		#if all 8 queens are placed, then finish
		print("\t\tCompleted...")
		return True
	for i in range(8):	#checking for all rows in that column
		if(issafe(i,col)):	#is it safe?
			board[i][col]=1 #queen is placed here
			if(place(col+1)==True):	#recursive call to place next queen
				return True
			board[i][col]=0		#if not placed, then backtrack, i.e it sets to zero and the loop iterates to check for next position
	return False

# observe the json file and place(1) - the first queen MUST be placed in the first column
if(place(1)==True):
	print("solution found")
else:
	print("Solution not possible")
for i in board:
	print(i)
