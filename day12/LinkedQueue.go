package data

type LinkedQueue struct {
	back  *DoubleNode
	front *DoubleNode
}

func CreateLQueue() *LinkedQueue {
	return new(LinkedQueue)
}

func (q *LinkedQueue) IsEmpty() bool {
	return q.back == nil
}

func (q *LinkedQueue) Put(data interface{}) {
	NewNode := new(DoubleNode)
	NewNode.data = data
	if q.back == nil {
		q.back = NewNode
		q.front = NewNode
	} else {
		q.back.next = NewNode
		NewNode.prev = q.back
		q.back = NewNode
	}
}

func (q *LinkedQueue) Get() (interface{}, bool) {
	if q.IsEmpty() {
		return nil, false
	}
	ret := q.front.data
	if q.back == q.front {
		q.back = nil
		q.front = nil
	} else {
		q.front = q.front.next
		q.front.prev = nil
	}
	return ret, true
}
