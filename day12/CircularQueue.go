package data

type CircularQueue struct {
	size  int
	front int
	back  int
	array []interface{}
}

func CreateCQueue(size int) (Queue *CircularQueue) {
	Queue = new(CircularQueue)
	Queue.array = make([]interface{}, size+1, size+1)
	Queue.size = size + 1
	Queue.front = 0
	Queue.back = 0
	return
}

func (q *CircularQueue) IsEmpty() bool {
	return q.back == q.front
}

func (q *CircularQueue) IsFull() bool {
	return (q.back+1)%q.size == q.front
}

func (q *CircularQueue) Put(data interface{}) bool {
	if q.IsFull() {
		return false
	}
	q.array[q.back] = data
	q.back++
	q.back %= q.size
	return true
}

func (q *CircularQueue) Get() (interface{}, bool) {
	if q.IsEmpty() {
		return nil, false
	}
	ret := q.array[q.front]
	q.front++
	q.front %= q.size
	return ret, true
}
