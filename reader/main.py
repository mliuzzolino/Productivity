
import modules.tools as tools
import modules.timetools as timetools

def main():

	tools.CleanFile()
	inputFile = open("studylog.txt", "r")
	stack = tools.Build_Stack(inputFile)
	programs = tools.Build_Program_Dict(stack)

	program_times = timetools.Calculate_Time(programs)

	tools.PrintBarChart(program_times)


if __name__ == "__main__":
	main()