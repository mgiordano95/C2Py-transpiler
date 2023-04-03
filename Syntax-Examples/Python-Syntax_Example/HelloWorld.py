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
elif number < floatNumber:
   print("The integer number is less than the float number.")
else:
   printf("The integer number is equal to the float number.\n")

print("--------------------------")
print("Print Fibonacci numbers with While Loop:")
while i < 11:
   print(array[i])
   i+=1

print("--------------------------")
array[2] = 100
print("Print Wrong Fibonacci numbers with While Loop:")
while j < 11:
   print(array[j])
   j+=1

print("--------------------------")
print("Type a number:")
numberInput = input()
print("Your number is: " + numberInput)