fileName = str(input())
file = open(fileName, 'r')
filed = file.readlines()

startpoint = input()
endpoint = input()


for line in filed:
    line = line.strip("\n")
    if line >= startpoint and line <= endpoint:
        print(line)
file.close()
