"""
We can use Trie and Min Heap to get the k most frequent words efficiently. The idea is to use Trie for searching existing words adding new words efficiently. Trie also stores count of occurrences of words. A Min Heap of size k is used to keep track of k most frequent words at any point of time

Trie and Min Heap are linked with each other by storing an additional field in Trie ‘indexMinHeap’ and a pointer ‘trNode’ in Min Heap. The value of ‘indexMinHeap’ is maintained as -1 for the words which are currently not in Min Heap (or currently not among the top k frequent words). For the words which are present in Min Heap, ‘indexMinHeap’ contains, index of the word in Min Heap. The pointer ‘trNode’ in Min Heap points to the leaf node corresponding to the word in Trie.

Following is the complete process to print k most frequent words from a file.
Read all words one by one. For every word, insert it into Trie. Increase the counter of the word, if already exists. Now, we need to insert this word in min heap also. For insertion in min heap, 3 cases arise:
1. The word is already present. We just increase the corresponding frequency value in min heap and call minHeapify() for the index obtained by “indexMinHeap” field in Trie. When the min heap nodes are being swapped, we change the corresponding minHeapIndex in the Trie. Remember each node of the min heap is also having pointer to Trie leaf node.
2. The minHeap is not full. we will insert the new word into min heap & update the root node in the min heap node & min heap index in Trie leaf node. Now, call buildMinHeap().
3. The min heap is full. Two sub-cases arise. 
….3.1 The frequency of the new word inserted is less than the frequency of the word stored in the head of min heap. Do nothing.
….3.2 The frequency of the new word inserted is greater than the frequency of the word stored in the head of min heap. Replace & update the fields. Make sure to update the corresponding min heap index of the “word to be replaced” in Trie with -1 as the word is no longer in min heap.
4. Finally, Min Heap will have the k most frequent words of all words present in given file. So we just need to print all words present in Min Heap. 
"""

from queue import PriorityQueue

MAX_CHARS = 26
MAX_WORD_SIZE = 30

# A Trie node
class TrieNode:
	def __init__(self):
		self.isEnd = False
		self.frequency = 0
		self.indexMinHeap = -1
		self.child = [None] * MAX_CHARS

# A Min Heap node
class MinHeapNode:
	def __init__(self, root, frequency, word):
		self.root = root
		self.frequency = frequency
		self.word = word

# A Min Heap
class MinHeap:
	def __init__(self, capacity):
		self.capacity = capacity
		self.count = 0
		self.array = [None] * capacity

# A utility function to create a new Trie node
def newTrieNode():
	trieNode = TrieNode()
	return trieNode

# A utility function to create a Min Heap of given capacity
def createMinHeap(capacity):
	minHeap = MinHeap(capacity)
	return minHeap

# A standard function to build a heap
def buildMinHeap(minHeap):
	n = minHeap.count - 1
	for i in range((n - 1) // 2, -1, -1):
		minHeapify(minHeap, i)

# Inserts a word to heap, the function handles the 3 cases explained above
def insertInMinHeap(minHeap, root, word):
	# Case 1: the word is already present in minHeap
	if root.indexMinHeap != -1:
		minHeap.array[root.indexMinHeap].frequency += 1
		# Percolate down
		minHeapify(minHeap, root.indexMinHeap)
	# Case 2: Word is not present and heap is not full
	elif minHeap.count < minHeap.capacity:
		count = minHeap.count
		minHeap.array[count] = MinHeapNode(root, root.frequency, word)
		root.indexMinHeap = minHeap.count
		minHeap.count += 1
		buildMinHeap(minHeap)
	# Case 3: Word is not present and heap is full. And frequency of word
	# is more than root. The root is the least frequent word in heap,
	# replace root with a new word
	elif root.frequency > minHeap.array[0].frequency:
		minHeap.array[0].root.indexMinHeap = -1
		minHeap.array[0].root = root
		minHeap.array[0].root.indexMinHeap = 0
		minHeap.array[0].frequency = root.frequency
		minHeap.array[0].word = word
		minHeapify(minHeap, 0)

# Inserts a new word to both Trie and Heap
def insertUtil(root, minHeap, word, dupWord):
	if root is None:
		root = newTrieNode()
	
	if word:
		insertUtil(root.child[ord(word[0]) - ord('a')], minHeap, word[1:], dupWord)
	else:
		if root.isEnd:
			root.frequency += 1
		else:
			root.isEnd = True
			root.frequency = 1
		insertInMinHeap(minHeap, root, dupWord)

# Add a word to Trie and min heap. A wrapper over the insertUtil
def insertTrieAndHeap(word, root, minHeap):
	insertUtil(root, minHeap, word, word)

# A utility function to show results. The min heap
# contains the k most frequent words so far, at any time
def displayMinHeap(minHeap):
	for i in range(minHeap.count):
		print(f"{minHeap.array[i].word}: {minHeap.array[i].frequency}")

# The main function that takes a file as input, adds words to heap
# and Trie, finally shows results from the heap
def printKMostFreq(file_path, k):
	# Create a Min Heap of Size k
	minHeap = createMinHeap(k)

	# Create an empty Trie
	root = None

	# Read words one by one from the file. Insert the word in Trie and Min Heap
	with open(file_path, 'r') as file:
		for line in file:
			words = line.split()
			for word in words:
				insertTrieAndHeap(word, root, minHeap)

	# The Min Heap will have the k most frequent words, so print Min Heap nodes
	displayMinHeap(minHeap)
	
# This is the standard minHeapify function. It updates the minHeapIndex in Trie when two nodes are swapped in the min heap
def minHeapify(minHeap, idx):
	left = 2 * idx + 1
	right = 2 * idx + 2
	smallest = idx

	if left < minHeap.count and minHeap.array[left].frequency < minHeap.array[smallest].frequency:
		smallest = left

	if right < minHeap.count and minHeap.array[right].frequency < minHeap.array[smallest].frequency:
		smallest = right

	if smallest != idx:
		# Update the corresponding index in the Trie node
		minHeap.array[smallest].root.indexMinHeap = idx
		minHeap.array[idx].root.indexMinHeap = smallest

		# Swap nodes in the min heap
		minHeap.array[smallest], minHeap.array[idx] = minHeap.array[idx], minHeap.array[smallest]
		minHeapify(minHeap, smallest)

# Driver program to test the above functions
if __name__ == "__main__":
	k = 5
	file_path = "/file.txt"
	try:
		printKMostFreq(file_path, k)
	except FileNotFoundError:
		print("File doesn't exist.")
