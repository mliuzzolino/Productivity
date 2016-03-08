
def Calculate_Time(programs):
	
	program_time_dict = {}
	for program in programs:
		print("Program: {}".format(program))
		program_data_length = len(programs[program])
		program_times = []
		for i in range(program_data_length):
			program_timestamp = programs[program][i]
			#print(program_timestamp)
			program_times.append((program_timestamp[2], program_timestamp[3]))
			

		tot_diff = Calculate_Different(program_times)
		print("{}'s total time: {:.5} hours".format(program, tot_diff))
		print("\n")

		program_time_dict[program] = tot_diff


	return program_time_dict



def Calculate_Different(program_times):
	total_difference = 0
	j = 0
	time_segment = []
	for i in range(len(program_times)):
		if (i % 2 == 0):
			time_segment.append(program_times[i])

		else:
			time_segment.append(program_times[i])
			j += 1

		if j % 2 != 0:
			time_segment_difference = Calculate_Time_Seg_Difference(time_segment)

			total_difference += time_segment_difference

			j = 0
			time_segment = []


	return total_difference


def Calculate_Time_Seg_Difference(time_segment):
	time_seg_diff = 0

	start_day = int(time_segment[0][0])
	start_time = time_segment[0][1]
	end_day = int(time_segment[1][0])
	end_time = time_segment[1][1]

	start_time_list = start_time.split(':')
	end_time_list = end_time.split(':')

	start_hour = int(start_time_list[0])
	start_minute = int(start_time_list[1])
	start_sec = int(start_time_list[2])

	end_hour = int(end_time_list[0])
	end_minute = int(end_time_list[1])
	end_sec = int(end_time_list[2])

	if start_day == end_day:
		hour_difference = end_hour - start_hour
		minute_difference = (end_minute - start_minute) / 60.
		second_difference = (end_sec - start_sec) / 3600.

		time_seg_diff = hour_difference + minute_difference + second_difference

	else:
		hour_difference = (end_hour + 24 ) - start_hour
		minute_difference = (end_minute - start_minute) / 60.
		second_difference = (end_sec - start_sec) / 3600.

		time_seg_diff = hour_difference + minute_difference + second_difference


	return time_seg_diff
