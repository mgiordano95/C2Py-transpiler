number = 6
letter = 'A'
str = "Hello, World!"
floatNumber = 6.3
floatDecimal = .7
array = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]

i = 0
j = 0

# Create a function
def myFunction():
   print("I just got executed!")

print("--------------------------")
print("Call the function:")
myFunction() # call the function

print("--------------------------")
print("Print integer:")
print(number)

print("--------------------------")
print("Print letter:")
print(letter)

print("--------------------------")
print("Print string:")
print(str)

print("--------------------------")
print("Print float:")
print(floatNumber)

print("--------------------------")
print("Print float:")
print(floatDecimal)

print("--------------------------")
print("Print If... Else:")
if number > floatNumber:
   print("The integer number is greater than the float number.")
else:
   print("The integer number is less than the float number.")

print("--------------------------")
print("Print While Loop:")
while i < 5:
   print(i)
   i+=1

print("--------------------------")
print("Print Fibonacci numbers with For Loop:")
for el in array:
   print(el)

print("--------------------------")
array[0] = 100
print("Print Wrong Fibonacci numbers with For Loop:")
for el in array:
   print(el)

print("--------------------------")
print("Type a number:")
numberInput = input()
print("Your number is: " + numberInput)