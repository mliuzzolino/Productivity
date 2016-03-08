class Node(object):

	def __init__(self, theData, theNextNode):
		self.data = theData
		self.nextNode = theNextNode

	def get_data(self):
		return self.data

	def get_nextNode(self):
		return self.nextNode

	def set_data(self, theData):
		self.data = theData

	def set_nextNode(self, theNextNode):
		self.nextNode = theNextNode

