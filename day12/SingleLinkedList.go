package data

import (
	"fmt"
)

type SingleNode struct {
	data interface{}
	next *SingleNode
}
type SingleLL struct {
	head *SingleNode
	tail *SingleNode
}

func (L *SingleLL) CreateNode(data interface{}) (NewNode *SingleNode) {
	NewNode = new(SingleNode)
	NewNode.data = data
	return
}

func (L *SingleLL) AppendNode(NewNode *SingleNode) {
	if L.head == nil {
		L.head = NewNode
		L.tail = NewNode
	} else {
		temp := L.tail
		temp.next = NewNode
		L.tail = NewNode
	}
}

func (L *SingleLL) FindNode(Data interface{}) (int, bool) {
	n := L.head

	i := 0
	for n != nil {
		if n.data == Data {
			return i, true
		}
		n = n.next
		i++
	}
	return i, false
}

func (L *SingleLL) InsertNode(i int, NewNode *SingleNode) bool {
	if L.head == nil {
		return false
	}

	n := L.head

	for i != 0 && n.next != nil {
		n = n.next
		i--
	}
	NewNode.next = n.next
	n.next = NewNode

	return true
}

func (L *SingleLL) DeleteNode(i int) bool {
	if L.head == nil {
		return false
	}
	if i == 0 {
		if L.head == L.tail {
			L.head = nil
			L.tail = nil
		} else {
			L.head = L.head.next
		}
		return true
	}
	n := L.head
	for i-1 != 0 && n != nil {
		n = n.next
		i--
	}
	switch {
	case n == nil:
		return false
	case n.next == L.tail:
		L.tail = n
		L.tail.next = nil
		return true
	default:
		n.next = n.next.next
		return true
	}
}
func (L *SingleLL) At(i int) (interface{}, bool) {
	if L.head == nil {
		return 0, false
	}

	n := L.head

	for n != nil && i != 0 {
		n = n.next
		i--
	}
	return n.data, true
}

func (L *SingleLL) PrintAllNode() {
	if L.head == nil {
		return
	}

	n := L.head

	for n != nil {
		fmt.Print(n.data, " ")
		n = n.next
	}
	fmt.Println()
}
