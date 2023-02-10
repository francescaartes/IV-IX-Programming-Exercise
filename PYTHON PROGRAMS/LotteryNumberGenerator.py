import random

size = 7
lottery_numbers = [random.randint(0, 9) for i in range(size)]
print("Lottery Numbers: ", *lottery_numbers)