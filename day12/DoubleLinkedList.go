package data

import (
	"fmt"
)

type DoubleNode struct {
	data interface{}
	next *DoubleNode
	prev *DoubleNode
}

type DoubleLL struct {
	head *DoubleNode
	tail *DoubleNode
}

func (L *DoubleLL) CreateNode(data interface{}) (NewNode *DoubleNode) {
	NewNode = new(DoubleNode)
	NewNode.data = data
	return
}

func (L *DoubleLL) AppendNode(NewNode *DoubleNode) {
	if L.head == nil {
		L.head = NewNode
		L.tail = NewNode
	} else {
		L.tail.next = NewNode
		NewNode.prev = L.tail
		L.tail = NewNode
	}
}

func (L *DoubleLL) FindNode(Data interface{}) (int, bool) {
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

func (L *DoubleLL) InsertNode(i int, NewNode *DoubleNode) bool {
	if L.head == nil {
		return false
	}

	n := L.head

	for i != 0 && n.next != nil {
		n = n.next
		i--
	}

	NewNode.next = n.next
	NewNode.next.prev = NewNode
	n.next = NewNode

	return true
}

func (L *DoubleLL) DeleteNode(i int) bool {
	if L.head == nil {
		return false
	}
	if i == 0 {
		if L.head == L.tail {
			L.head = nil
			L.tail = nil
		} else {
			L.head = L.head.next
			L.head.prev = nil
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
		n.next.prev = n
		return true
	}
}
func (L *DoubleLL) At(i int) (interface{}, bool) {
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

func (L *DoubleLL) PrintAllNode() {
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
func (L *DoubleLL) PrintAllNodeReverse() {
	if L.tail == nil {
		return
	}

	n := L.tail

	for n != nil {
		fmt.Print(n.data, " ")
		n = n.prev
	}
	fmt.Println()
}
