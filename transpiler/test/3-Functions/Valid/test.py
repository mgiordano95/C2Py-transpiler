a = None
def myFunction(a, b):
	i = 1
	return a + b

def main():
	a = 5
	b = 6
	c = a
	d = b
	myFunction(c, d)
	def myFunction2(c, d):
		print("Hello myFunction2!!!")

	myFunction2(4.2, 6.9)
	return 0

main()