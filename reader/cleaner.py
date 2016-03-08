
inputfile = open("../studylog.txt", "r")
outputfile = open("../studylog_cleaned.txt", "w")

for line in inputfile:
	outputfile.write(line.replace(';', ','))

inputfile.close()
outputfile.close()