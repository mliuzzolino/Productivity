import nodes as n


class LinkedList(object):

	def __init__(self, dataStruct_type):
		self.DStype = dataStruct_type		# 's' = stack, 'q' = queue
		self.head = None
		self.listSize = 0

	def pop(self):
		if self.head == None:
			print("*** Warning: No elements in structure. ***")
			return

		target = self.head.get_data()

		if self.head.get_nextNode() == None:
			self.head = None
			self.listSize = 0

		else:
			nextNode = self.head.get_nextNode()
			self.head = nextNode
			self.listSize -= 1


		return target
		

	def push(self, theData):
		if self.listSize == 0:
			self.head = n.Node(theData, None)

		elif self.DStype == 's':
			self.head = n.Node(theData, self.head)
			
		elif self.DStype == 'q':

			currentNode = self.head
			while True:
				if currentNode.get_nextNode() == None:
					break
				else:
					currentNode = currentNode.get_nextNode()

			currentNode.set_nextNode(n.Node(theData, None))	

		self.listSize += 1



	def size(self):
		return self.listSize


	def traverse(self):
		currentNode = self.head
		while currentNode != None:
			
			print(currentNode.get_data())
			currentNode = currentNode.get_nextNode()



		
