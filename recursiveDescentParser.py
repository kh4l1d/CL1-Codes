'''
Author: Adesh Atole, Abhshek Bera, Piyush Galphat
Recursive Descent Parser for Sample Language

Grammar is: E->iE'
			E'->+iE'|e			(e=epsilon)

			This grammar accepts strings of the from: i+i+i+i+i and so on...
To inpmlement the program,
We write Function for each Non-Terminal like E and E'
and match() function to verify the terminal symbol

If a non-terminal has more than one production, then if-else cases are used
'''
string='i+i+i+i$'			#'$' indicates termination of string
p=0
flag=True

def E():
	global p
	if(string[p]=='i'):
		match('i')
		Ed()

def Ed():
	global p
	if(string[p]=='+'):
		match('+')
		match('i')
		Ed()
	else:
		return

def match(t):
	global p
	global flag
	if(string[p]==t):
		p+=1
	else:
		print("Error")
		flag=False

E()
if(string[p]=='$' and flag):
	print("Accepted!!")
else:
	print("Not Accepted!!")
