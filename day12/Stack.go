package data

type Stack struct {
	top   int
	size  int
	array []interface{}
}

func CreateStack(size int) (s *Stack) {
	s = new(Stack)
	s.top = -1
	s.size = size
	s.array = make([]interface{}, size, size)
	return
}

func (s *Stack) Push(data interface{}) bool {
	if s.top == s.size-1 {
		return false
	}
	s.top++

	s.array[s.top] = data

	return true
}

func (s *Stack) Pop() (interface{}, bool) {
	if s.top == -1 {
		return nil, false
	}
	ret := s.array[s.top]
	s.top--
	return ret, true
}

func (s *Stack) IsFull() bool {
	return s.top == s.size-1
}

func (s *Stack) IsEmpty() bool {
	return s.top == -1
}
