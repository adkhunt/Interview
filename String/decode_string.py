def remove_consecutive(string, k):

	stack = []
	count = 0

	for i in string:

		if len(stack):
			result = stack[-1]
			if list(result.keys())[0] == i:
				count = result[i] + 1
			else:
				count = 1
			stack.append({i:count})

		else:
			count = 1
			stack.append({i:count})

		result = stack[-1]
		if result[i] >= k:
			tmp_count = k
			while count != 0:
				stack.pop()
				count -= 1

	final_string = ""

	while len(stack):
		result = stack.pop()
		char = list(result.keys())[0]
		final_string += char

	return final_string[::-1]

if __name__ == "__main__":

	a = ""
	a = input ("Enter String: ")

	k = int(input("Enter number to remove consecutive chars."))

	final_string = remove_consecutive(a, k)
	print (final_string)
