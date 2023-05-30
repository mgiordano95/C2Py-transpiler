def main():
	x = 3
	y = 7
	if y > x + 3:
		print("y is greater than x plus 3")
	if  not(x > 5 and y >= 10):
		print("x is equal to   " + x)
		print("y is equal to   " + y)
	else:
		z = x + y
		print("The sum of x and y is equal to   " + z)

	return 0

main()