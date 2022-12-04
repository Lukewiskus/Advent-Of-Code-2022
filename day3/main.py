
sum = 0
file = open('./input.txt', 'r')
Lines = file.readlines()
sum = 0


def sumValue(item1, item2):
    #loop through each char of item1
    for char1 in item1:
        #loop through each char of item2
        for char2 in item2:
            if(ord(char1) == ord(char2)):
                #tell if char1 is uppercase
                if(char1.isupper()):
                  return ord(char1) - 64 + 26
                else:
                    return ord(char1) - 96
    return 0

# for line in Lines:
#     item1 = line[:len(line)//2]
#     item2 = line[len(line)//2:]

    
#     sum += sumValue(item1, item2)

def sumValueP2(item1, item2, item3):
    #loop through each char of item1
    for char1 in item1:
        #loop through each char of item2
        for char2 in item2:
            for char3 in item3:
                if(ord(char1) == ord(char2) == ord(char3)):
                    #tell if char1 is uppercase
                    if(char1.isupper()):
                      return ord(char1) - 64 + 26
                    else:
                        return ord(char1) - 96
    return 0
#loop through lines in a group of three 
for i in range(0, len(Lines), 3):
    item1 = Lines[i]
    item2 = Lines[i+1]
    item3 = Lines[i+2]
    #print each item
    sum += sumValueP2(item1, item2, item3)
    
print(sum)