import numpy as np
import matplotlib.pyplot as plt
import linkedlist as ll

def Build_Stack(inputFile):
	
	stack = ll.LinkedList('q')

	for line in inputFile:
			stack.push(line)

	return stack


def Build_Program_Dict(stack):
	programs = {}
	print("\nProgram\t Marker\t Year\t Month\t Day\t Time")
	print("-"*50)
	while stack.size() != 0:
		line = (stack.pop()).split(",")
		program = line[0]
		marker = line[1]
		year = line[2]
		month = line[3]
		day = line[4]
		time = line[5].strip()
		timeStamp = (year, month, day, time)
		
		print(program + "\t " + marker + "\t " + year + "\t " 
			+ month + "\t "  + day + "\t " + time)

		if program not in programs:
			programs[program] = [timeStamp]
		else:
			programs[program].append(timeStamp)
	
	print("\n")
	return programs



def CleanFile():

	inputfile = open("../studylog.txt", "r")
	outputfile = open("studylog.txt", "w")

	for line in inputfile:
		outputfile.write(line.replace(';', ','))

	inputfile.close()
	outputfile.close()


def PrintBarChart(program_times):

	programs = program_times.keys()
	times = program_times.values()

	fig = plt.figure()
	width = 0.85
	ind = np.arange(len(times))
	plt.bar(ind, times, width/2, color='b')
	plt.xticks(ind + width / 4, programs)
	
	fig.autofmt_xdate()
	
	plt.ylabel('Hours')
	plt.title('Program Comparison by Hours')
	plt.show()
	