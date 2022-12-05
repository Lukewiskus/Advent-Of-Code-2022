
def part2(line1, line2):
    first = line1.split('-')
    start1 = first[0]
    end1 = first[1]


    second = line2.split('-')
    start2 = second[0]
    end2 = second[1]

    #turn start1 and end1 into ints
    start1 = int(start1)
    end1 = int(end1)

    #turn start2 and end2 into ints
    start2 = int(start2)
    end2 = int(end2)

    #make a list from start1 to end1
    list1 = list(range(start1, end1+1))
    list2 = list(range(start2, end2+1))

    for i in list1:
        if i in list2:
            return 1
    return 0
def part1(line1, line2):
    first = line1.split('-')
    start1 = first[0]
    end1 = first[1]


    second = line2.split('-')
    start2 = second[0]
    end2 = second[1]

    #see if the range of start1 to end 1 is within the range of start2 to end2
    if(int(start1) >= int(start2) and int(end1) <= int(end2)):
        return 1
    #see if the range of start2 to end 2 is within the range of start1 to end1
    elif(int(start2) >= int(start1) and int(end2) <= int(end1)):
        return 1
    return 0

file = open('./input.txt', 'r')

Lines = file.readlines()

sum = 0
for line in Lines:
    #split line with .split(',)
    lines = line.split(',')
    line1 = lines[0]
    line2 = lines[1]
    sum += part2(line1, line2)

   

print(sum)

