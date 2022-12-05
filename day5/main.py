




file = open('./test.txt', 'r')

Lines = file.readlines()

sum = 0
for line in Lines:
    #split line with .split(',)
    lines = line.split(',')
    line1 = lines[0]
    line2 = lines[1]
    sum += part2(line1, line2)

   

print(sum)

