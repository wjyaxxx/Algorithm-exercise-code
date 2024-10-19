import re

def calculate_dice_rolls(command):
    dice_rolls = {}
    results = re.findall(r'(\d*)d(\d+)', command)
    for num, sides in results:
        num = 1 if num == '' else int(num)
        if sides in dice_rolls:
            dice_rolls[sides] += num
        else:
            dice_rolls[sides] = num

    sorted_dice_rolls = sorted(dice_rolls.items(), key = lambda x: x[0])
    for sides, num in sorted_dice_rolls:
        print(sides, num)

    values = re.split(r'(\d*)d(\d+)', command)
    values = [x for x in values if x]

    min_result = 0
    max_result = 0
    operation = '+'

    for value in values:
        if value.isdigit():
            if operation == '+':
                min_result += int(value)
                max_result += int(value)
            else:
                min_result -= int(value)
                max_result -= int(value)
        elif value in ['+', '-']:
            operation = value
        else:
            num, sides = 1 if value[:-2] == '' else int(value[:-2]), int(value[-1:])
            min_result += num
            max_result += num * sides

    print(min_result, max_result)

command = "d6+3d5+2-2d3+2d5"
calculate_dice_rolls(command)
