
inputfile = open("../../studylog.txt", "r")
outputfile = open("../studylog.txt", "w")

for line in inputfile:
	outputfile.write(line.replace(';', ','))

inputfile.close()
outputfile.close()